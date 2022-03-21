// RegistrationList.cpp

#include "RegistrationList.h"
#include "RegistrationEntry.h"

#include <fstream>
using std::ifstream;
using std::ofstream;
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <map>
using std::pair;
#include <string>
using std::string;

void RegistrationList::read_file(const string & file_name) {
    ifstream ifs(file_name);
    if (!ifs) return; // no file; one will be created when
        // write_file is called

        ifs >> num_entries;
        ifs.get(); // \n
        for (int i = 0; i < num_entries; i++) {
            RegistrationEntry new_entry;
            ifs >> new_entry;
            m_entries.insert(m_entries.end(),{new_entry.name, new_entry});
        }
        itr_current_entry = m_entries.begin();
}

void RegistrationList::write_file(const string & file_name) const {
    string update_file_name = "registration_list.txt";
    ofstream ofs_output(update_file_name);
    ofs_output << m_entries.size() << endl;
    //ofs_output << current_year << endl;
	for (auto itr_current_entry = m_entries.begin(); itr_current_entry != m_entries.end(); itr_current_entry++) {
		ofs_output << itr_current_entry->second;
	}
}

//**** Backup ****//
void RegistrationList::write_file_backup(const string & file_name) const {
    string backup_file_name = "registration_backup.txt";
    ofstream ofs_output_backup(backup_file_name);
    ofs_output_backup << m_entries.size() << endl;
    //ofs_output_backup << current_year << endl;
	for (auto itr_current_entry = m_entries.begin(); itr_current_entry != m_entries.end(); itr_current_entry++) {
		ofs_output_backup << itr_current_entry->second;
	}
    cout << "\nThe Registration List has been backed up and saved as '" << backup_file_name << "'.\n";
}

//**** List for Category ****//
void RegistrationList::write_file_list_cat(const string & filename) const {
    cout << "Please enter a filename (ex. 'U14List.txt'): ";
    string cat_file_name;
    getline(cin, cat_file_name);
    cout << "Please enter the category (ex. 'U14'): ";
    string category;
    cin >> category;
    ofstream ofs_output_cat(cat_file_name);
    for (auto itr_current_entry = m_entries.begin(); itr_current_entry != m_entries.end(); itr_current_entry++){
            if (itr_current_entry->second == category){
                ofs_output_cat << itr_current_entry->second;
            }
    }
}


