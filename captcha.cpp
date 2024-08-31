#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <unistd.h>

using namespace std;



class Captcha {
private:
    string username;
    string originalCaptchaCode; 

    // Generate a random captcha code
    string generateCaptcha() {
        const string characters = "QWERTYUIOPASDFGHJKLZXCVBNMqwertyuioplkjhgfdsazxcvbnm0123456789";
        string captcha;
        srand(time(NULL));

        for (int i = 0; i < 6; ++i) {
            captcha = captcha+ characters[rand() % characters.length()];
        }
        return captcha;
    }

    // Store the captcha and username in a file
    void saveToTheFile() {
        ofstream File("captchas.txt", ios::app);
        if (File.is_open()) {
            File << username << " \t\t" << originalCaptchaCode << endl; // Save the original captcha and the username
            File.close();
        } else {
            cout << "Unable to open file." << endl;
        }
    }

    
            bool verifyCaptcha(const string& input) {       // Verifying  the user's input
                return input == originalCaptchaCode; // Compare the input with the original captcha
            }

public:
   
    Captcha( string  name)  {           // Constructor
        username=name;
        originalCaptchaCode = generateCaptcha(); 
    }

    // Main function to run the program
    void run() {
        while (true) {
            cout << "Welcome, " << username << "!" << endl;
            cout << "Please verify yourself by entering the following captcha: " << endl;
            cout << originalCaptchaCode << endl; // Displaying the captcha code
            cout << "Enter the captcha code: ";
            string userInput;
            cin >> userInput;

            if (verifyCaptcha(userInput)) {
                cout << "Captcha is correct! You have been verified." << endl;
                saveToTheFile();
                break;
            } else {
                
                cout << "Incorrect captcha code. Generating a new captcha..." << endl;
                sleep(2);
                system("clear");
                
                originalCaptchaCode = generateCaptcha(); // Updating the  originalCaptchaCode with new captcha
            }
        }
    }
};

int main() {
	system("clear");
    string name;
    cout << "Enter your username: ";
    getline(cin,name);
    system("clear"); //clear command for linux

    Captcha captcha(name);
    captcha.run();

    return 0;
}
