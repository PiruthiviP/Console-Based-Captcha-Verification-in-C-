# Captcha Verification Program
This program is a simple console-based Captcha verification system written in C++. It generates a random Captcha code, asks the user to input it for verification, and stores the username along with the Captcha code in a file named captchas.txt.
## Features
* Random Captcha Generation: The program generates a random 6-character Captcha code using a mix of uppercase letters, lowercase letters, and digits.
* User Verification: Users are required to enter the Captcha code correctly to verify their identity.
* Captcha Regeneration: If the user enters the Captcha code incorrectly, the program generates a new Captcha until the user enters the correct one.
* File Logging: Once the user verifies the Captcha, their username and the Captcha code are saved to a file named captchas.txt.
## Prerequisites
* A Unix-based system (Linux, macOS) is required for the clear and sleep commands used in the program.
* A C++ compiler that supports C++11 or later.
 ## How to Compile and Run 
1. #### Compile the Program: g++ -std=c++11 -o captcha.cpp 
2. #### Run the Program: ./a.out  
3. #### Program Flow:
    * The program will prompt you to enter your username.
    * It will then generate and display a random Captcha code.
    * You must enter the correct Captcha code to be verified.
    * If the Captcha is entered incorrectly, a new Captcha will be generated.
    * Upon correct verification, your username and Captcha code will be saved in captchas.txt.
## Files Included
* main.cpp: The main program file that contains the Captcha class and the main function.
* captchas.txt: The file where usernames and Captcha codes are stored (created after the program runs).
## License
This project is open-source and available under the MIT License.




