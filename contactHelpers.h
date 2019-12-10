/*
 ============================================================================
 Name        : contactHelpers.h
 Author      : Brendan Polius Prosper
 Email       : bkpoliusprosper@myseneca.ca
 Student #   : 022541114
 Course Code : IPC 144
 Section     : NWW
 Date        : November 18, 2019
 Workshop    : Milestone 2 - home
 ============================================================================
*/

/*--------------------------------------------------------------------
Description: This header file modularizes general helper functions to
             help reduce redundant coding for common repetitive tasks. 
---------------------------------------------------------------------*/

// HINT: 
// You will most likely want to include this header file
// in other files of the project since it provides general 
// helper functions that can be used throughout.


//--------------------------------
// Function Prototypes
//--------------------------------

// +-------------------------------------------+
// | ====== Assignment 2 | Milestone 4 ======= |
// +-------------------------------------------+
//typedef struct Contact contacts;

//#define MAXCONTACTS 5
//#ifndef CONTACTS_H_
//#define CONTACTS_H_
#include "contacts.h"

// Clear the standard input buffer
void clearKeyboard();

// pause:
// Put function prototype below:
void pause(void);

// getInt:
// Put function prototype below:
int getInt(void);

// getIntInRange:
// Put function prototype below:
int getIntInRange(int min, int max);

// yes:
// Put function prototype below:
int yes(void);

// menu:
// Put function prototype below:
int menu(void);

// contactManagerSystem:
// Put function prototype below:
void contactManagerSystem(void);

//getTenDigitPhone
int getTenDigitPhone(char phoneNum[11]);

//findContactIndex
int findContactIndex(const struct Contact contact[], int size, const char cellNum[11]);

//displayContactHeader
void displayContactHeader(void);

//displayContactFooter
void displayContactFooter(int count);

//displayContact
void displayContact(const struct Contact *contact);

//displayContacts
void displayContacts(const struct Contact contact[], int size);

//searchContacts
void searchContacts(const struct Contact contact[], int size);

//addContact
void addContact(struct Contact contact[], int size);

//updateContact
void updateContact(struct Contact contact[], int size);

//deleteContact
void deleteContact(struct Contact contact[], int size);

//#endif // !CONTACTS_H_
