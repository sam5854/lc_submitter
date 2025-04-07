import time
from utils.submit_solution import start_program
import sys

def main():
    try:
        # Number of times to run the program
        run_count = 1 # Change this to your desired number
        
        print(f"Starting program to run {run_count} times...")
        for i in range(run_count):
            print(f"Run #{i+1} of {run_count}")
            start_program()
            # Optional: Add a small delay between runs
            if i < run_count - 1:
                time.sleep(20)
        print("All runs completed")
        
    except Exception as e:
        error_message = str(e)
        print(f"An error occurred: {error_message}")
        time.sleep(2)
        # Exit with a non-zero status code to indicate failure
        sys.exit(1)

if __name__ == "__main__":
    main()