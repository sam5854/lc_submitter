import time
from utils.submit_solution import start_program
import sys

def main():
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

if __name__ == "__main__":
    main()