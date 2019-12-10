/*
 ============================================================================
 Name        : contactHelpers.c
 Author      : Brendan Polius Prosper
 Email       : bkpoliusprosper@myseneca.ca
 Student #   : 022541114
 Course Code : IPC 144
 Section     : NWW
 Date        : November 24, 2019
 Workshop    : Milestone 4 - home
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

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "contactHelpers.h"
#include "contacts.h"

#define MAXCONTACTS 5

/*struct Contact contact
{
	struct Name name;
	struct Address address;
	struct Numbers numbers;
};*/
// This source file needs to "know about" the functions you prototyped
//       in the contact helper header file.
// HINT: Put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
//       #include your contactHelpers header file on the next line:



//--------------------------------
// Function Definitions
//--------------------------------

// +-------------------------------------------------+
// | ====== Assignment 2 | Milestone 4 =======       |
// +-------------------------------------------------+
// | Put empty function definitions below...         |
// |                                                 |
// | - The clearKeyboard function is done for you    |
// +-------------------------------------------------+

// clearKeyboard:  Empty function definition 
void clearKeyboard(void)
{
	while (getchar() != '\n')  ;
}

// pause: Empty function definition goes here:
void pause(void)
{
	printf("(Press Enter to Continue)");  //Empty spaces are left intentionally to pause program
	clearKeyboard();
}
// getInt: Empty function definition goes here:
int getInt(void)
{
	char NL = 'x';
	int value;
	scanf("%d%c", &value, &NL);

	while (NL != '\n') {
		scanf("%d%c", &value, &NL);
		if (NL != '\n')
		{
			printf("*** INVALID INTEGER *** <Please enter an integer>: ");
			clearKeyboard();
		}
	};
	return value;
}
// getIntInRange: Empty function definition goes here:
int getIntInRange(int min, int max)
{
	int range;
	do {
		range = getInt();
		if (range > max || range < min)
		{
			printf("*** OUT OF RANGE *** <Enter a number between 100 and 500>: ");
		}
	}while (range > max || range < min);
	return range;
}
// yes: Empty function definition goes here:
int yes(void) 
{

	char newLine = 'x';
	char confirm = 'x';
	//int yes;

	while (newLine != '\n') {

		scanf("%c%c", &confirm, &newLine);
		if (newLine != '\n') {
			clearKeyboard();
			printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
			//clearKeyboard();
		}
		else if (confirm == 'y' || confirm == 'Y') {
			//yes = 1;
			return 1;
		}
		else if (confirm == 'n' || confirm == 'N') {
			//yes = 0;
			return 0;
		}
		else {
			newLine = 'x';
		}

	}
	return confirm;
}	
// menu: Empty function definition goes here:
int menu(void)
{
	int menu;

	printf("Contact Management System\n");
	printf("-------------------------\n");
	printf("1. Display contacts\n");
	printf("2. Add a contact\n");
	printf("3. Update a contact\n");
	printf("4. Delete a contact\n");
	printf("5. Search contacts by cell phone number\n");
	printf("6. Sort contacts by cell phone number\n");
	printf("0. Exit");
	printf("\n");
	printf("\nSelect an option:> ");
	
	do {
	menu = getInt();
	if (menu > 6 || menu < 0) {
		printf("*** OUT OF RANGE *** <Enter a number between 0 and 6>: ");
	}

	}while (menu > 6 || menu < 0);
	return menu;
}
// contactManagerSystem: Empty function definition goes here:
void contactManagerSystem(void)
{
	struct Contact contact[MAXCONTACTS] =
	{ { { "Rick", { '\0' }, "Grimes" },
	    { 11, "Trailer Park", 0, "A7A 2J2", "King City" },
	    { "4161112222", "4162223333", "4163334444" } },
	  {
	    { "Maggie", "R.", "Greene" },
	    { 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
	    { "9051112222", "9052223333", "9053334444" } },
	  { 
	    { "Morgan", "A.", "Jones" },
	    { 77, "Cottage Lane", 0, "C7C 9Q9", "Peterborough" },
	    { "7051112222", "7052223333", "7053334444" } },
	  {
	    { "Sasha", { '\0' }, "Williams" }, 
	    { 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
	    { "9052223333", "9052223333", "9054445555" } },
	};
	int select;
	int yn = 0;
	while (yn == 0) {
		select = menu();
			switch (select)
			{
			case 1:
				displayContacts(contact, MAXCONTACTS);
				//printf("\n");
				pause();
				printf("\n");
				break;
			case 2:
				addContact(contact, MAXCONTACTS);
				printf("\n");
				pause();
				printf("\n");
				break;
			case 3:
				updateContact(contact, MAXCONTACTS);
				pause();
				printf("\n");
				break;
			case 4:
				deleteContact(contact, MAXCONTACTS);
				printf("\n");
				pause();
				printf("\n");
				break;
			case 5:
				searchContacts(contact, MAXCONTACTS);
				pause();
				printf("\n");
				break;
			case 6:
				printf("\n");
				printf("<<< Feature to sort is unavailable >>>\n\n");
				pause();
				printf("\n");
				break;
			case 0:
				printf("\nExit the program? (Y)es/(N)o: ");
				yn = yes();
				printf("\n");
				if(yn)printf("Contact Management System: terminated\n");
				break;
			default:
				break;
		}	
	}
}	

//getTenDigitPhone
int getTenDigitPhone(char phoneNum[11])
{
	int i;
	int truedigit;
	int error = 0;
	int found = 1;

do{
	found = 1;
	if(error == 0)
	{
		scanf("%11[^\n]", phoneNum);
	}
	else if (error == 1)
	{
		truedigit = 0;
		while(getchar() != '\n');
		printf("Enter a 10-digit phone number: ");
		scanf("%11[^\n]", phoneNum);
	}
	for(i = 0; phoneNum[i] != '\0'; i++)
	{
		if(isdigit(phoneNum[i]) != 0)
		{
			truedigit = 1;
			error = 1;
		}
		else if(isdigit(phoneNum[i]) == 0)
		{
			error = 1;
			found = 0;
		}
	
	}
truedigit = found;

if(truedigit != 0 && strlen(phoneNum) != 10)
{
	truedigit = 0;
}
}while(truedigit == 0);
return phoneNum[11];
}


//findContactIndex
int findContactIndex(const struct Contact contact[], int size, const char cellNum[])
{
	int i = 0;
	int output;
	for (i = 0; i < size; i++)
	{
		output = strcmp(contact[i].numbers.cell, cellNum);
		
		if(output == 0)
		{
			return i;
		}
	}
	return -1;
}

//displayContactHeader
void displayContactHeader(void)
{
	printf("\n");
	printf("+-----------------------------------------------------------------------------+\n");
	printf("|                              Contacts Listing                               |\n");
	printf("+-----------------------------------------------------------------------------+\n");
}

//displayContactFooter
void displayContactFooter(int count)
{
	printf("+-----------------------------------------------------------------------------+\n");
	printf("Total contacts: %d\n\n", count);
}

//displayContact
void displayContact(const struct Contact *contact)
{
	printf(" %s ", contact->name.firstName);
	if(contact->name.middleInitial[0] != '\0') 
	{
		printf("%s ", contact->name.middleInitial);
	}
	printf("%s\n", contact->name.lastName);
	printf("    C: %-10s   H: %-10s   B: %-10s\n", contact->numbers.cell, contact->numbers.home, contact->numbers.business);
	printf("       %d %s, ", contact->address.streetNumber, contact->address.street);
	if(contact->address.apartmentNumber > 0) 
	{
		printf("Apt# %d, ", contact->address.apartmentNumber);
	}
	printf("%s, %s\n", contact->address.city, contact->address.postalCode);
}

//displayContacts
void displayContacts(const struct Contact contact[], int size)
{
	int count = 0;
	int i;

	displayContactHeader();
	for (i = 0; i < size; i++)
	{
		if(strlen(contact[i].numbers.cell) != 0)
		{
			displayContact(&contact[i]);
			count++;
		}
	}
	displayContactFooter(count);
}

//searchContacts
void searchContacts(const struct Contact contact[], int size)
{
	char cellNum[11];
	int found = 0;

	printf("\nEnter the cell number for the contact: ");
	//clearKeyboard();
	getTenDigitPhone(cellNum);
	found = findContactIndex(contact, size, cellNum);
	if (found == -1)
	{
		printf("*** Contact NOT FOUND ***\n");
		clearKeyboard();
		printf("\n");
	}
	else
	{
		printf("\n");
		displayContact(&contact[found]);
		printf("\n");
		clearKeyboard();
	}

}

//addContact
void addContact(struct Contact contact[], int size)
{
	int i = 0; 
//	int freecontact = -1;

//	getContact(&contact[i]);	
	for (i = 0; i < size; i++)
	{
		if(strlen(contact[i].numbers.cell) == 0)
		{
		//	freecontact = i;
			break;
		}
	}

	if(i == size)
	{
		printf("\n*** ERROR: The contact list is full! ***\n");
	}
	else
	{
		//clearKeyboard();
		printf("\n");
		getContact(&contact[i]);
		printf("--- New contact added! ---\n");
	}

}

//updateContact
void updateContact(struct Contact contact[], int size)
{
	char phoneNum[11];
	int found;
	int yn;

	printf("\nEnter the cell number for the contact: ");
	getTenDigitPhone(phoneNum);
	found = findContactIndex(contact, size, phoneNum);
	
	if (found == -1)
	{
		printf("*** Contact NOT FOUND ***\n");
		printf("\n");
		clearKeyboard();
	}
	else
	{
		printf("\nContact found:\n");
		displayContact(&contact[found]);
		printf("\n");
		printf("Do you want to update the name? (y or n): ");
		clearKeyboard();
		yn = yes();
		if(yn == 1) 
		{		
			getName(&contact[found].name);
		}
		printf("Do you want to update the address? (y or n): ");
		clearKeyboard();
		yn = yes();
		//clearKeyboard();
		if(yn == 1)
		{	
			getAddress(&contact[found].address);
		}
		printf("Do you want to update the numbers? (y or n): ");
		//clearKeyboard();
		yn = yes();
		if(yn == 1)
		{ 
			getNumbers(&contact[found].numbers);
		}

		printf("--- Contact Updated! ---\n");
	//	clearKeyboard();
		printf("\n");
	}
}

//deleteContact
void deleteContact(struct Contact contact[], int size)
{
	char phoneNum[11];
	int found;
	int yn;

	printf("\nEnter the cell number for the contact: ");
	getTenDigitPhone(phoneNum);
	found = findContactIndex(contact, size, phoneNum);
	if (found == -1)
	{
		printf("*** Contact NOT FOUND ***\n");
	}
	else
	{
		printf("\nContact found:\n");
		displayContact(&contact[found]);
		printf("\n");
		clearKeyboard();
		printf("CONFIRM: Delete this contact? (y or n): ");
		//clearKeyboard();
		yn = yes();
		if (yn == 1)
		{
			contact[found].numbers.business[0] = '\0';
			contact[found].numbers.cell[0] = '\0';
			contact[found].numbers.home[0] = '\0';
			printf("--- Contact deleted! ---\n");
		//	clearKeyboard();
		}
	}
}
