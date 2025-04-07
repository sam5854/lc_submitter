import traceback
from bs4 import BeautifulSoup
import time
from selenium import webdriver
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver.common.by import By
from selenium.webdriver.chrome.options import Options
from selenium.webdriver.common.keys import Keys
import re
import chromedriver_autoinstaller

chromedriver_autoinstaller.install()


class Booking(webdriver.Chrome):

    def __init__(self, teardown=False):
        self.teardown = teardown
        chrome_options = Options()
        chrome_options.add_argument("--no-sandbox")  # Disable sandbox mode
        chrome_options.add_argument("--headless")  # Run in headless mode
        chrome_options.add_argument("--disable-dev-shm-usage")  # Disable /dev/shm usage
        chrome_options.add_argument("--disable-gpu")  # Disable GPU acceleration
        chrome_options.add_argument("--disable-extensions")  # Disable extensions
        chrome_options.page_load_strategy = 'eager'
        super(Booking, self).__init__(options=chrome_options)
        self.implicitly_wait(3)
        self.maximize_window()

    def __exit__(self, exc_type, exc_val, exc_tb):
        if self.teardown:
            self.quit()

    def land_first_page(self):
        self.get("https://algo.monster/problems/stats")
        print("Landed on the first page.")

    @staticmethod
    def remove_line_numbers(text):
        """
        Removes leading line numbers from each line of the input text.
        Only digits at the very beginning of a line are removed.
        
        Args:
            text (str): The original text with line numbers.
        
        Returns:
            str: The text with the leading line numbers removed.
        """
        cleaned_text = re.sub(r'^\d+', '', text, flags=re.MULTILINE)
        return cleaned_text
    
    def find_solution(self, problem):   
        try:
            search_input = WebDriverWait(self, 10).until(
                EC.presence_of_element_located((By.CSS_SELECTOR, 'input[type="search"]'))
            )
            search_input.clear()
            search_input.send_keys(f"{problem}.")
            time.sleep(10)
            search_input.send_keys(Keys.RETURN)
            print(f"Searching for {problem}...")
            time.sleep(3)

            cpp_tab = WebDriverWait(self, 10).until(
                EC.element_to_be_clickable((By.ID, "react-aria-2-tab-cpp"))
            )
            cpp_tab.click()
            div_element = self.find_element(By.ID, 'react-aria-2-tabpane-')
            print("Extracting C++ code...")

            soup = BeautifulSoup(div_element.get_attribute('outerHTML'), 'html.parser')
            code_tag = soup.find("code", class_="language-cpp")
            
            cpp_code = code_tag.get_text()
            cleaned_text = Booking.remove_line_numbers(cpp_code)
            
            print("Successfully extracted and cleaned C++ code.")
            # print(cleaned_text)
            print("Successfully extracted and cleaned C++ code.")
            return cleaned_text

        except Exception as e:
            error_message = str(e)
            print(f"Unhandled exception: {error_message}")
            traceback_details = traceback.format_exc()
            print(f"Traceback details: {traceback_details}")
            raise