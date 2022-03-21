#ifndef REGISTRATIONLIST_H_INCLUDED
#define REGISTRATIONLIST_H_INCLUDED

// RegistrationList.h

#include <iostream>
#include <map>
#include <string>

#include "RegistrationEntry.h"

class RegistrationList
{
public:
    RegistrationList() : itr_current_entry(m_entries.end()) {}

    void add(const std::string & name, const unsigned & year_of_birth, std::string & category, bool & reg_status);
    void display_current_entry() const;
    void edit_current(const std::string & name, const unsigned & year_of_birth, std::string & new_category, bool & reg_status);
    void find(const std::string & name);
    bool empty() const { return m_entries.empty(); }
    void read_file( const std::string & file_name );
    void write_file( const std::string & file_name ) const;
    void write_file_backup(const std::string & file_name) const;
    void write_file_list_cat(const std::string & file_name) const;
    void clear();
    friend bool operator==(const RegistrationEntry & e1, const RegistrationEntry & e2);

    int num_entries = 0;

private:
    std::map<std::string, RegistrationEntry> m_entries;
    std::map<std::string, RegistrationEntry>::iterator itr_current_entry;
};

inline void RegistrationList::clear(){ m_entries.clear(); }

inline void RegistrationList::add(const std::string & name, const unsigned & year_of_birth, std::string & category, bool & reg_status) {
    auto result = m_entries.insert(std::pair<std::string, RegistrationEntry>(name, RegistrationEntry(name, year_of_birth,
                                                                                                     category, reg_status)));
        itr_current_entry = result.first;
}


inline void RegistrationList::display_current_entry() const {
    if (m_entries.empty()) return;
    std::cout << itr_current_entry->second;
}

// Edit a player's information
// entry
inline void RegistrationList::edit_current(const std::string & new_name, const unsigned & new_year_of_birth,
                                           std::string & new_category, bool & new_reg_status) {
    itr_current_entry->second.name = new_name;
    itr_current_entry->second.year_of_birth = new_year_of_birth;
    itr_current_entry->second.category = new_category;
    itr_current_entry->second.reg_status = new_reg_status;
}

// Look up a player
inline void RegistrationList::find(const std::string & name) {
    auto itr = m_entries.find(name);
    if (itr != m_entries.end()) itr_current_entry = itr;
}

#endif // REGISTRATIONLIST_H_INCLUDED
