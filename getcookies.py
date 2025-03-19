from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.common.keys import Keys
import time

def get_csrf_and_cookies(username, password):
    # Configure Chrome options
    options = webdriver.ChromeOptions()
    # options.add_argument("--headless")  # Optional: run in headless mode
    options.add_argument("--disable-gpu")
    options.add_argument("--window-size=1920,1080")
    
    driver = webdriver.Chrome(options=options)
    driver.get("https://leetcode.com/accounts/login/")
    time.sleep(5)  # Allow the page to load

    # Extract CSRF token from cookies
    csrf_token = None
    for cookie in driver.get_cookies():
        if cookie['name'] == 'csrftoken':
            csrf_token = cookie['value']
            break
    
    if not csrf_token:
        print("CSRF token not found.")
        driver.quit()
        return None, None
    
    print(f"Initial CSRF Token: {csrf_token}")

    # Perform login
    try:
        driver.find_element(By.ID, "id_login").send_keys(username)
        driver.find_element(By.ID, "id_password").send_keys(password)
        driver.find_element(By.ID, "id_password").send_keys(Keys.RETURN)
    except Exception as e:
        print(f"Login Error: {e}")
        driver.quit()
        return None, None

    time.sleep(7)  # Allow time for login to complete

    # Verify successful login
    if "login" in driver.current_url:
        print("Login failed. Please check your credentials.")
        driver.quit()
        return None, None

    print("Login successful!")

    # Extract updated cookies and CSRF token after login
    updated_csrf_token = None
    cookies = driver.get_cookies()

    for cookie in cookies:
        if cookie['name'] == 'csrftoken':
            updated_csrf_token = cookie['value']
            break

    print(f"Updated CSRF Token: {updated_csrf_token}")
    print(f"Login Cookies: {cookies}")
    
    driver.quit()
    return updated_csrf_token, cookies

# Example Usage
username = "sam5854"
password = "Samarth@2004"
csrf_token, cookies = get_csrf_and_cookies(username, password)

if csrf_token and cookies:
    print("Successfully retrieved CSRF Token and Cookies.")
else:
    print("Failed to retrieve CSRF Token and Cookies.")
