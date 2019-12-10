/*
 ============================================================================
 Name        : contacts.c
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

#include <stdio.h>
//#include <string.h>
#include "contactHelpers.h"
#include "contacts.h"

void getName(struct Name *name) {

	int option = 0;

	//printf("\n");
	printf("Please enter the contact's first name: ");
	scanf(" %[^\n]", name->firstName);

	printf("Do you want to enter a middle initial(s)? (y or n): ");
	clearKeyboard();
	option = yes();


	if (option == 1) {

		printf("Please enter the contact's middle initial(s): ");
		scanf(" %[^\n]", name->middleInitial);
		clearKeyboard();

	}
	else
	{
		name->middleInitial[0] = '\0';
		//name->middleInitial[strlen(name->middleInitial) - 1] == '\0';
	}
	printf("Please enter the contact's last name: ");
	//clearKeyboard();
	scanf(" %[^\n]", name->lastName);

}

// getAddress:
void getAddress(struct Address *address) {

	int option = 0;
//	int option2;

	printf("Please enter the contact's street number: ");
	//clearKeyboard();
	address->streetNumber = getInt();
	if(address->streetNumber > 0){
	}
	else
	{
		printf("*** INVALID STREET NUMBER *** <must be a positive number>: ");
//		clearKeyboard();
		address->streetNumber = getInt();
	}	

	printf("Please enter the contact's street name: ");
	scanf(" %40[^\n]s", address->street);
	clearKeyboard();

	printf("Do you want to enter an apartment number? (y or n): ");
	//clearKeyboard();
	option = yes();

	if (option == 1) {

		printf("Please enter the contact's apartment number: ");
		address->apartmentNumber = getInt();
	//	clearKeyboard();
		
		if(address->apartmentNumber < 0)
		{
			printf("*** INVALID APARTMENT NUMBER *** <must be a positive number>: ");
			scanf("%d", &address->apartmentNumber);
		}	
	}

	printf("Please enter the contact's postal code: ");
//	clearKeyboard();
	scanf(" %7[^\n]s", address->postalCode);
	clearKeyboard();


	printf("Please enter the contact's city: ");
//	clearKeyboard();
	scanf(" %40[^\n]s", address->city);
	clearKeyboard();


}


// getNumbers:
void getNumbers(struct Numbers *numbers) {
	char option;

	printf("Please enter the contact's cell phone number: ");
	getTenDigitPhone(numbers->cell);
	clearKeyboard();


	printf("Do you want to enter a home phone number? (y or n): ");
	option = yes();
	if (option == 1) 
	{

		printf("Please enter the contact's home phone number: ");
		getTenDigitPhone(numbers->home);
		clearKeyboard();
	}
	else
	{
		numbers->home[0] = '\0';
	}

	printf("Do you want to enter a business phone number? (y or n): ");
	option = yes();
	if (option == 1) 
	{

		printf("Please enter the contact's business phone number: ");
		getTenDigitPhone(numbers->business);
	//	printf("\n");
		clearKeyboard();
	}
	else
	{
		numbers->business[0] = '\0';
	}
}
void getContact(struct Contact * contact)
{
	getName(&contact->name);
	getAddress(&contact->address);
	getNumbers(&contact->numbers);
}
