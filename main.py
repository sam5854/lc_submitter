import time
from utils.submit_solution import start_program

def main():
    try:
        start_program()
        
    except Exception as e:
        error_message = str(e)
        print(f"An error occurred: {error_message}")    
        time.sleep(2)

if __name__ == "__main__":
    main()