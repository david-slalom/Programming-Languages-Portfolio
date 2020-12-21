#include <iostream>
#include <iomanip>
#include <string>
#include "Menu.h"

using namespace std;

void printMenu() {
	//Display form to user
	cout << "*************************\n";
	cout << "********Data Input*******\n";
	cout << "Initial Investment Amount: \n";
	cout << "Monthly Deposit: \n";
	cout << "Annual Interest: \n";
	cout << "Number of years: \n";
	//To get press any key to continue line
	"Press any Key to Continue \n";
	system("PAUSE");

	getUserInput();
}

void getUserInput() {

	//Declare variables to store input
	float initInvestment, monthlyDeposit, AnuInterest, years;
	float totalAmount = 0.0;
	//to store interest and year end interest
	float interest = 0.0;
	float yearInterest = 0.0;

	//Get data from user
	cout << "*************************\n";
	cout << "********Data Input*******\n";
	cout << "Initial Investment Amount: ";
	cin >> initInvestment;
	cout << "Monthly Deposit: ";
	cin >> monthlyDeposit;
	cout << "Annual Interest: ";
	cin >> AnuInterest;
	cout << "Number of years: ";
	cin >> years;
	system("PAUSE");

	showReports(totalAmount, initInvestment, AnuInterest, interest, monthlyDeposit, years, yearInterest);
}

void showReports(float totalAmount, float initInvestment,float  AnuInterest, float interest, float monthlyDeposit, float years, float yearInterest) {

	//Set totalAm = initInv
	totalAmount = initInvestment;
	//Display year data without monthly deposits
	cout << "\nBalance and Interest Without Additional Monthly Deposits\n";
	cout << "==============================================================\n";
	cout << "Year\t\tYear End Balance\tYear End Earned Interest\n";
	cout << "--------------------------------------------------------------\n";
	for (int i = 0; i < years; i++) {
		//Calculate yearly interest
		interest = (totalAmount) * ((AnuInterest / 100));
		//Calculate year end total
		totalAmount = totalAmount + interest;
		//We set fixed and set precision to show only 2 decimal points
		cout << (i + 1) << "\t\t" << fixed << setprecision(2) << totalAmount << "\t\t\t" << interest << "\n";

	}

	//For monthly
	totalAmount = initInvestment;
	//Display year data with monthly deposits
	cout << "\n\nBalance and Interest With Additional Monthly Deposits\n";
	cout << "==============================================================\n";
	cout << "Year\t\tYear End Balance\tYear End Earned Interest\n";
	cout << "--------------------------------------------------------------\n";
	for (int i = 0; i < years; i++) {
		//Set yearly interest to zero at the start of the year
		yearInterest = 0;
		for (int j = 0; j < 12; j++) {
			//Calculate monthly interest
			interest = (totalAmount + monthlyDeposit) * ((AnuInterest / 100) / 12);
			//Calculate month end interest
			yearInterest = yearInterest + interest;
			//Calculate month end total
			totalAmount = totalAmount + monthlyDeposit + interest;
		}
		cout << (i + 1) << "\t\t" << fixed << setprecision(2) << totalAmount << "\t\t\t" << yearInterest << "\n";


	}
}