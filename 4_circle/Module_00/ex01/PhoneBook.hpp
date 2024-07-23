#ifndef PHONEBOOK_APP
# define PHONEBOOK_APP

# include "Contact.hpp"

class Phonebook{
	private:
		Contact list[8];
		int _readInput(void) const;

	public:
		Phonebook();
		~PhoneBook();
		void addContact(void);
		

};
