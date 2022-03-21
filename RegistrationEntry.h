//Schuyler Meyer

#ifndef REGISTRATIONENTRY_H_INCLUDED
#define REGISTRATIONENTRY_H_INCLUDED

#include <fstream>
#include <string>
#include <iostream>
using std::endl;

class RegistrationEntry
{
public:
    RegistrationEntry() : name("No Name"), year_of_birth(9999), category("U0"), reg_status(1) {}
    RegistrationEntry(const std::string & name0, const unsigned & year_of_birth0,
                      const std::string & category0, bool & reg_status0) :
                      name(name0), year_of_birth(year_of_birth0),
                      category(category0), reg_status(reg_status0) {}
    std::string name;
    unsigned year_of_birth;
    std::string category;
    bool reg_status;
};

// ** Update ** //
inline std::istream & operator>>(std::istream & in, RegistrationEntry & e) {
    getline(in, e.name);
    in >> e.year_of_birth;
    in.get();
    getline(in, e.category);
    in >> e.reg_status;
    in.get();
    return in;
}

// ** Update ** //
inline std::ostream & operator<<(std::ostream & out, const RegistrationEntry & e) {
    out << e.name << endl << e.year_of_birth << endl << e.category << endl;
    if (e.reg_status == 0) {
        out << "Paid" << endl;
    } else if (e.reg_status == 1) {
        out << "Not Paid" << endl;
    } else {
        out << "Error: Registration Status - Unknown." << endl;
    }
    return out;
}

inline bool operator==(const RegistrationEntry & e, const std::string s)
{
return e.category == s;
}


/*
// foo.operator+=(1);
//MyClass & MyClass::operator+=(const MyClass &rhs) {
//    ...
//    return *this;
//  }
void operator+=(int num_days);
void Date::operator+=(int num_day)
{
... // same as Date::add
}

Num& operator+=(const Num& rhs){

      this->m_iNumber += rhs.m_iNumber;
      return *this;
}

*/

#endif // REGISTRATIONENTRY_H_INCLUDED
