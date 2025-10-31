import time
import sys
from utils.submit_solution import start_program
import os
import random

def main():
    try:
        run_count = 1  # Change this to your desired number
        
        print(f"Starting program to run {run_count} times...")
        for i in range(run_count):
            print(f"Run #{i+1} of {run_count}")
            # Get the list of files in the "C++" folder
            cpp_folder_path = "C++"
            cpp_files = [f for f in os.listdir(cpp_folder_path) if os.path.isfile(os.path.join(cpp_folder_path, f))]

            # Randomly select a file
            if cpp_files:
                selected_file = random.choice(cpp_files)
                print(f"Selected file: {selected_file}")
            else:
                raise FileNotFoundError("No files found in the C++ folder")

            # Pass the selected file name to start_program
            start_program(selected_file)

            # # Delete the selected file
            # os.remove(os.path.join(cpp_folder_path, selected_file))
            # print(f"Deleted file: {selected_file}")

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
