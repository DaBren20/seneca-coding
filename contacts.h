/*
 ============================================================================
 Name        : contacts.h
 Author      : Brendan Polius Prosper
 Email       : bkpoliusprosper@myseneca.ca
 Student #   : 022541114
 Course Code : IPC 144
 Section     : NWW
 Date        : November 18, 2019
 Workshop    : Milestone 2 - home
 ============================================================================
*/
/*
 ============================================================================
 Description: This Workshop was about creating an Employee database and the
	      easy way that they are created is by using structs to help store
	      the data entered. I first declared three structs in a seperate called 
		  Name, Address and Numbers and initialize my variables within the 
		  approprate structs with those structs made I was then able to make members
		  within this file called name, address, and numbers. This file used functions
		  that were declared in contacthelpers.c. With those functions I called them
		  in this file whenever I needed them. 
 ============================================================================
 */
#ifndef CONTACTS_H_
#define CONTACTS_H_
//#include "contactHelpers.h"

struct Name
{
	char firstName[31];
	char middleInitial[7];
	char lastName[36];
};

struct Address
{
	int streetNumber;
	char street[41];
	int apartmentNumber;
	char postalCode[8];
	char city[41];
};

struct Numbers
{
	char cell[11];
	char home[11];
	char business[11];

};

struct Contact
{
	struct Name name;
	struct Address address;
	struct Numbers numbers;
};

//Call functions

//Names
void getName(struct Name *name);


//Addresses
void getAddress(struct Address *address);


//Phone Numbers
void getNumbers(struct Numbers *numbers);


//Contacts
void getContact(struct Contact *);

#endif // !CONTACTS_H_
