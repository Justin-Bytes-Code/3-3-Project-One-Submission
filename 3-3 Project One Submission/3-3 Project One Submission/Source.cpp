#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

/// Justin Perez
/// 3-3
/// Project One Submission

// Shows the Menu
void menu() {
    cout << "*********************" << endl;
    cout << "* 1 - Add One Hour" << endl;
    cout << "* 2 - Add One Minute" << endl;
    cout << "* 3 - Add One Second" << endl;
    cout << "* 4 - Exit Program" << endl;
    cout << "*********************" << endl;
}

// Displays time
void time(int hour, int minute, int second, string amOrpm) {
    cout << "********************" << endl;
    cout << "*  " << "12-Hour Clock" << "   * " << endl;
    cout << "*   " << setw(2) << setfill('0') << hour << ":" << setw(2) << setfill('0') << minute << ":" << setw(2) << setfill('0') << second << " " << amOrpm << "    *" << endl;
    cout << "********************" << endl;
}

// Displays time in 24 hours
void time24(int hour, int minute, int second, string amOrpm) {
    if (amOrpm == "pm" || amOrpm == "Pm" || amOrpm == "PM") {
        hour = (hour % 12) + 12;
    }

    cout << "********************" << endl;
    cout << "*  " << "24-Hour Clock" << "   * " << endl;
    cout << "*   " << setw(2) << setfill('0') << hour << ":" << setw(2) << setfill('0') << minute << ":" << setw(2) << setfill('0') << second << " " << amOrpm << "    *" << endl;
    cout << "********************" << endl;
}

// Adds 1 hour to the time and changes AM/PM if necessary
void addOneHour(int& hour, int& minute, int& second, string& amOrpm) {
    hour += 1;

    if (hour > 12) {
        hour -= 12;
        amOrpm = (amOrpm == "AM" || amOrpm == "am") ? "PM" : "AM";
    }
    else if (hour == 12) {
        amOrpm = (amOrpm == "AM" || amOrpm == "am") ? "PM" : "AM";
    }

    time(hour, minute, second, amOrpm);
    time24(hour, minute, second, amOrpm);
}

// Adds 1 minute and adjusts hours if necessary
void addOneMinute(int& hour, int& minute, int& second, string& amOrpm) {
    minute += 1;

    if (minute >= 60) {
        minute -= 60;
        addOneHour(hour, minute, second, amOrpm);  // Increment hour if minutes overflow
    }
    else {
        time(hour, minute, second, amOrpm);
        time24(hour, minute, second, amOrpm);
    }
}

// Adds 1 second and adjusts minutes if necessary
void addOneSecond(int& hour, int& minute, int& second, string& amOrpm) {
    second += 1;

    if (second >= 60) {
        second -= 60;
        addOneMinute(hour, minute, second, amOrpm);  // Increment minute if seconds overflow
    }
    else {
        time(hour, minute, second, amOrpm);
        time24(hour, minute, second, amOrpm);
    }
}

void newline() {
    cout << endl;
}

int main() {
    string userInput = "nothing";
    string amOrpm;
    int hour;
    int minute;
    int second;
    int menuNav;

    cout << "Welcome to time creator! Would you like to create a time?" << endl;
    cout << "Please type Y or N" << endl;
    cin >> userInput;
    newline();

    // Validate user input
    while (userInput != "y" && userInput != "Y" &&
        userInput != "Yes" && userInput != "yes" &&
        userInput != "n" && userInput != "N" &&
        userInput != "no" && userInput != "No") {
        cout << "Invalid response." << "Please type Y or N" << endl;
        cin >> userInput;
        newline();
    }

    // If the user types in Yes, start the time creation process.
    if (userInput == "y" || userInput == "Y" || userInput == "Yes" || userInput == "yes") {
        cout << "Alright! Let's get started! Please type in 12-hour time for setup!" << endl;

        // Get the hour
        cout << "What is the current hour?" << endl;
        while (true) {
            cin >> hour;
            newline();
            if (hour < 1 || hour > 12) {
                cout << "Please type a number between 1 and 12." << endl;
                newline();
            }
            else {
                break;
            }
        }

        // Get the minute
        cout << "What is the current minute?" << endl;
        while (true) {
            cin >> minute;
            newline();
            if (minute < 0 || minute > 59) {
                cout << "Please type a number between 0 and 59." << endl;
                newline();
            }
            else {
                break;
            }
        }

        // Get the second
        cout << "What is the current second?" << endl;
        while (true) {
            cin >> second;
            newline();
            if (second < 0 || second > 59) {
                cout << "Please type a number between 0 and 59." << endl;
                newline();
            }
            else {
                break;
            }
        }

        // Get AM/PM
        while (true) {
            cout << "Is it AM or PM right now?" << endl;
            cin >> amOrpm;
            if (amOrpm == "am" || amOrpm == "Am" || amOrpm == "AM" ||
                amOrpm == "pm" || amOrpm == "Pm" || amOrpm == "PM") {
                break;
            }
            else {
                cout << "Please type AM or PM." << endl;
            }
        }

        // Display the initial time
        newline();
        cout << "The current time is:" << endl;
        newline();
        time(hour, minute, second, amOrpm);
        time24(hour, minute, second, amOrpm);

        // Main Menu Navigation
        while (true) {
            menu();
            cin >> menuNav;

            switch (menuNav) {
            case 1:
                addOneHour(hour, minute, second, amOrpm);
                break;
            case 2:
                addOneMinute(hour, minute, second, amOrpm);
                break;
            case 3:
                addOneSecond(hour, minute, second, amOrpm);
                break;
            case 4:
                cout << "Goodbye!" << endl;
                return 0;
            default:
                newline();
                cout << "The menu only has 4 options!" << endl;
                newline();
                break;
            }
        }
    }

    // If the user selected No, exit the program
    cout << "Goodbye!" << endl;
    return 0;
}


