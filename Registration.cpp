// Registration.cpp

#include "Registration.h"

#include <fstream>
using std::ifstream;
using std::ofstream;

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <map>
using std::map;
using std::pair;

#include <string>
using std::string;

#include <chrono>
#include <thread>

unsigned current_year = 9999;

void Registration::run()
{
    cout << "Please Input the Current Year: ";
    cin >> current_year;
    while(cin.fail()) {
                cout << "Error: Please Input the Current Year: ";
                cin.clear();
                cin.ignore(256,'\n');
                cin >> current_year; // does not work with "2a", but does work with "a2"
            }
    cout << endl;
    entry_list.read_file(FileName);
    if (entry_list.empty()){
            std::cout << "Error: File '" << FileName << "' could not open and / or does not exist." << endl;
            return;
    }
    bool done = false;
    do {
        display_entry_and_menu();
        cout << "Please Select a Choice: ";
        char command;
        cin >> command;
        cin.get(); // new line char
        execute(command, done);
        cout << endl;
    } while (!done);
}

void Registration::execute(char command, bool & done)
{
    switch (command) {
        case 'f': { // Prints Full List for given Category
            string file_name;
            entry_list.write_file_list_cat(file_name);
            break;
        }
        case 'n': { // Backs up and Deletes List (empty)
            cout << "Please provide the current year: ";
            cin >> current_year;
            cout << "\nAre you sure you want to delete all players"
            << " ('y' for Yes, 'n' for No)? " << endl;
            char yon;
            cin >> yon;
            if (yon == 'y' || yon == 'Y'){
                // backup
                entry_list.write_file_backup(FileName);
                entry_list.write_file(FileName);

                cout << "\nDeleting now";
                std::chrono::seconds dura(1);
                cout << ".";
                std::this_thread::sleep_for(dura);
                cout << ".";
                std::this_thread::sleep_for(dura);
                cout << ".";
                std::this_thread::sleep_for(dura);
                cout << endl;

                // delete
                entry_list.clear();
                cout << "The Registration List has been deleted. " << endl;
            } else {
                break;
            }
            break;
        }

        // Edit //
        case 'e': { // Edits specific entry
            if (entry_list.empty()) return;
            cout << "Please Enter the Name (ex. Asuna Yuuki): ";
            string name;
            getline(cin, name);
            entry_list.find(name);

            cout << "Please Enter the New Name (ex. Asuna Yuuki): ";
            string new_name;
            getline(cin, new_name);
            cout << "Please Enter the New Year of Birth (ex. 2007): ";
            unsigned new_year_of_birth;
            cin >> new_year_of_birth;
            while(cin.fail()) {
                cout << "Error: Please Input the New Year of Birth: ";
                cin.clear();
                cin.ignore(256,'\n');
                cin >> new_year_of_birth;
            }
            string new_category;
            unsigned yr_diff = current_year - new_year_of_birth;
            if (yr_diff < 6 && yr_diff >= 4)
            {
                new_category = "U6";
                cout << "Your Division is: U6" << endl;
            } else if (yr_diff < 8 && yr_diff >= 6)
            {
                new_category = "U8";
                cout << "Your Division is: U8" << endl;
            } else if (yr_diff < 10 && yr_diff >= 8)
            {
                new_category = "U10";
                cout << "Your Division is: U10" << endl;
            } else if (yr_diff < 12 && yr_diff >= 10)
            {
                new_category = "U12";
                cout << "Your Division is: U12" << endl;
            } else if (yr_diff < 14 && yr_diff >= 12)
            {
                new_category = "U14";
                cout << "Your Division is: U14" << endl;
            } else if (yr_diff < 17 && yr_diff >= 14)
            {
                new_category = "U17";
                cout << "Your Division is: U17" << endl;
            } else
            {
                new_category = "U0 - Invalid";
                cout << "\nError: " << new_name << " is not of the right " <<
                "age to play in this league." << endl;
                break;
            }
            cout << "Please State the New Registration Status (0 = Paid, 1 = Not Paid): ";
            bool new_registration_status;
            cin >> new_registration_status;
            cout << endl;
            entry_list.edit_current(new_name, new_year_of_birth, new_category, new_registration_status);
            break;
        }

        case 's': { // Searches for a player
            cout << "Please Enter the Name (ex. Asuna Yuuki): ";
            string name;
            getline(cin, name);
            entry_list.find(name);
            break;
        }
        // Edit //

        case 'a': {
            cout << "Please Enter a New Name (ex. Asuna Yuuki): ";
            string new_name;
            getline(cin, new_name);
            cout << "Please Enter the Year of Birth (ex. 2007): ";
            unsigned new_year_of_birth;
            cin >> new_year_of_birth;
            while(cin.fail()) {
                cout << "Error: Please Input the Year of Birth: ";
                cin.clear();
                cin.ignore(256,'\n');
                cin >> new_year_of_birth;
            }
            string new_category;
            unsigned yr_diff = current_year - new_year_of_birth;
            if (yr_diff < 6 && yr_diff >= 4)
            {
                new_category = "U6";
                cout << "Your Division is: U6" << endl;
            } else if (yr_diff < 8 && yr_diff >= 6)
            {
                new_category = "U8";
                cout << "Your Division is: U8" << endl;
            } else if (yr_diff < 10 && yr_diff >= 8)
            {
                new_category = "U10";
                cout << "Your Division is: U10" << endl;
            } else if (yr_diff < 12 && yr_diff >= 10)
            {
                new_category = "U12";
                cout << "Your Division is: U12" << endl;
            } else if (yr_diff < 14 && yr_diff >= 12)
            {
                new_category = "U14";
                cout << "Your Division is: U14" << endl;
            } else if (yr_diff < 17 && yr_diff >= 14)
            {
                new_category = "U17";
                cout << "Your Division is: U17" << endl;
            } else
            {
                new_category = "U0 - Invalid";
                cout << "\nError: " << new_name << " is not of the right " <<
                "age to play in this league." << endl;
                break;
            }
            cout << "Please State the Registration Status (0 = Paid, 1 = Not Paid): ";
            bool new_registration_status;
            cin >> new_registration_status;
            cout << endl;
            entry_list.add(new_name, new_year_of_birth, new_category, new_registration_status);
            //RegistrationList.num_entries += 1;
            break;
        }

        case 'q': {
            entry_list.write_file(FileName);
            done = true;
            break;
        }

        default: {
            cout << "Error: You selected something that is not on the menu. ";
            done = true;
            break;
        }
    };
}


