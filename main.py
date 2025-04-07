import time
import sys
from utils.submit_solution import start_program

def main():
    try:
        run_count = 1  # Change this to your desired number
        
        print(f"Starting program to run {run_count} times...")
        for i in range(run_count):
            print(f"Run #{i+1} of {run_count}")
            start_program()
            if i < run_count - 1:
                time.sleep(20)
        print("All runs completed")
        
    except Exception as e:
        error_message = str(e)
        print(f"An error occurred: {error_message}")
        time.sleep(2)
        sys.exit(1)  # ❗️Signal failure to the OS/workflow

if __name__ == "__main__":
    main()
