#ifndef REGISTRATION_H_INCLUDED
#define REGISTRATION_H_INCLUDED

#include <iostream>
#include <string>
#include <map>

//----For current year----//
#include <chrono>
using namespace std::chrono;
#include <ctime>
//------------------------//

#include "RegistrationList.h"

const char FileName[] = "registration.txt";

class Registration
{
public:
    void run();
    RegistrationList entry_list;

private:
    void display_entry_and_menu() const;
    void execute(char command, bool & done);
};

inline void Registration::display_entry_and_menu() const {
    using std::cout;
    using std::endl;
    using std::string;

    string long_separator(67, '-');
    string short_separator(20, '-');

    entry_list.display_current_entry();

    cout << long_separator << endl
         << "|     Full List (f)     |    Add Player (a)   |   New Season (n)  |\n"
         << long_separator << endl
         << "|   Search Player (s)   |   Edit Player (e)   |      Quit (q)     |\n"
         << long_separator << endl;

    // For current year
    /*
    system_clock::time_point now = system_clock::now();
    time_t tt = system_clock::to_time_t(now);
    tm utc_tm = *gmtime(&tt);
    tm local_tm = *localtime(&tt);
    cout << utc_tm.tm_year + 1900 << endl;
    */
}


#endif // REGISTRATION_H_INCLUDED
