import html
import re
import time
import requests
from utils.solution_scraper import Booking
import utils.cookies as cookies

def clean_code(html_string):
    """Remove HTML tags and unescape HTML characters."""
    text = re.sub(r'<[^>]+>', '', html_string)
    text = html.unescape(text)
    return text

def check_code_execution(interpret_id, headers):
    while True:
        response = requests.post(
            f'https://leetcode.com/submissions/detail/{interpret_id}/check/', 
            headers=headers
        ).json()
        print(f"Code execution response: {response}")
        if response['state'] == "SUCCESS":
            if response['status_msg'] != 'Accepted':
                print("Execution Failed")
                return False
            else:
                return True
        else:
            time.sleep(3)

def check_code_submission(submission_id, headers):
    while True:
        response = requests.post(
            f'https://leetcode.com/submissions/detail/{submission_id}/check/', 
            headers=headers
        ).json()
        print("Submitting solution")
        print(f"Code submission response: {response}")
        if response['state'] == "SUCCESS":
            if response['status_msg'] != 'Accepted':
                print("Submission Failed")
                return False
            else:
                print("Submission Successful")
                print("Submission Successful")
                return True
        else:
            time.sleep(3)

def convert_title_to_slug(title):
    # Remove special cases for LeetCode slugs
    title = title.replace('(x, n)', 'x-n').replace('(x)', 'x')
    title = re.sub(r'[^a-zA-Z0-9\s-]', '', title)  # Remove non-alphanumeric except spaces and hyphens
    title = re.sub(r'\s+', '-', title.strip())  # Replace spaces with hyphens
    return title.lower()

def get_leetcode_question_title(problem_id) -> str:
    url = "https://leetcode.com/api/problems/all/"
    response = requests.get(url)
    if response.status_code != 200:
        print("Failed to fetch problems list")
        raise Exception("Failed to fetch problems list")
    data = response.json()
    for item in data["stat_status_pairs"]:
        if item["stat"]["frontend_question_id"] == problem_id:
            title = item["stat"]["question__title"]
            return convert_title_to_slug(title)
    print("Problem not found")
    return "Problem not found"

def get_solution_babes(problem_num):
    with Booking(teardown=True) as bot:
        bot.land_first_page()
        return bot.find_solution(problem=problem_num)

def connect_to_browser(title_slug, headers, problem_num):
    print(f"Processing: {title_slug}")
    
    input_data_query = {
        "query": """
            query consolePanelConfig($titleSlug: String!) {
                question(titleSlug: $titleSlug) {
                    exampleTestcaseList
                }
            }
        """,
        "variables": {"titleSlug": title_slug},
        "operationName": "consolePanelConfig"
    }
    input_data = requests.post('https://leetcode.com/graphql/', headers=headers, json=input_data_query).json()
    input_data = input_data['data']['question']['exampleTestcaseList']
    data_input = "\n".join(input_data)
    
    correct_solution = get_solution_babes(problem_num)
    if not correct_solution:
        print(f"No solution found for {title_slug}")
        return False
    else:
        print(f"Fetched correct solution for {title_slug}")
    
    problem_id_query = {
        "query": """
        query questionTitle($titleSlug: String!) {
            question(titleSlug: $titleSlug) {
                questionId
            }
        }
        """,
        "variables": {"titleSlug": title_slug},
        "operationName": "questionTitle"
    }
    problem_id_response = requests.post('https://leetcode.com/graphql/', headers=headers, json=problem_id_query).json()
    problem_id = problem_id_response['data']['question']["questionId"]
    
    run_code_data = {
        "lang": "cpp",
        "question_id": problem_id,
        "typed_code": correct_solution,
        "data_input": data_input
    }
    run_code_url = f'https://leetcode.com/problems/{title_slug}/interpret_solution/'
    run_code_response = requests.post(run_code_url, headers=headers, json=run_code_data)
    print(f"Run code response: {run_code_response.json()}")
    if not check_code_execution(run_code_response.json()['interpret_id'], headers):
        return False

    submit_code_data = {
        "lang": "cpp",
        "question_id": problem_id,
        "typed_code": correct_solution
    }
    submit_code_url = f'https://leetcode.com/problems/{title_slug}/submit/'
    submit_code_response = requests.post(submit_code_url, headers=headers, json=submit_code_data).json()
    return check_code_submission(submit_code_response['submission_id'], headers)

def start_program():
    with open('problem_num.txt', 'r') as file:
        problem_num = int(file.read().strip())

    with open('problem_num.txt', 'w') as file:
        file.write(str(problem_num + 1))

    title_slug = get_leetcode_question_title(problem_num)

    headers = {
        'Host': 'leetcode.com',
        'Content-Type': 'application/json',
        'Cookie': cookies.COOKIES,
        'X-Csrftoken': cookies.CRFTOKEN,
        'User-Agent': 'Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/134.0.0.0 Safari/537.36',
        'Accept': '/',
        'Origin': 'https://leetcode.com',
        'Referer': f'https://leetcode.com/problems/{title_slug}/',
        'Sec-Fetch-Site': 'same-origin',
        'Sec-Fetch-Mode': 'cors',
        'Sec-Fetch-Dest': 'empty',
        'Accept-Encoding': 'gzip, deflate',
        'Accept-Language': 'en-US,en;q=0.9',
    }

    if connect_to_browser(title_slug, headers, problem_num):
        print(f"Successfully submitted problem {problem_num}: {title_slug}")
    else:
        print(f"Failed to submit problem {problem_num}: {title_slug}")
