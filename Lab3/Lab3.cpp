/** \file bugExample.cpp
 *  \brief     A little with logical bugs in it
 *  \details   This program is littered with logical bugs. Your task is the
 *              following:
 *                1) Compile and run the program.
 *                2) For each bug you find you must fix the bug then Check In
 *                   the code with a comment on the fix you did
 *                3) There are a three functions that are not completed, you need to
 *                   complete them and also update the menu and the main function
 *  \author    Dmitrii Frolov
 *  \version   0.1
 *  \date      2022
 *  \bug       Many logical bugs
 *  \copyright University of Nicosia.
 */
#include <iostream>
#include<iomanip>
#include <cassert>
using namespace std;

// Function prototypes
int printMenu();
void fillInArray(int[], const int);
void multArrays(const int[], const int[], int[], const int);
void displayArray(const int[], const int);
int sumOddArray(const int[], const int);
bool isAllPositive(const int[], const int);
void avgOddArray(const int[], const int, double&);

/**
 * <code>main</code> is the main function of this program.
 * <BR>
 * @return Returns 0 if success, any other value otherwise.
 */
int main() {
	int a = 0;
	int choice;
	double average;
	const int SIZE = 10;
	int price[SIZE] = { 12, 4, 8, 1, 17, 2, 4, 2, 9, 1 };
	int quantity[SIZE], total[SIZE];
	do {
		choice = printMenu();

		switch (choice) {
		// Enter quantity
		case 1:
			fillInArray(quantity, SIZE);
			cout << a;
			system("pause");
			break;
		// Calculate total
		case 2:
			multArrays(quantity, total, price, SIZE);
			break;
		// Print total
		case 3:
			displayArray(total, SIZE);
			system("pause");
			break;
		// Exit
		case 4:
			cout << "\nSum of odd numbers is: " << sumOddArray(quantity, SIZE) << endl;
			system("pause");
			break;
		case 5:
			if (isAllPositive(quantity, SIZE)) cout << "\nAll entries are positive\n";
			else cout << "\nThere are negative entries\n";
			system("pause");
			break;
		case 6:
			avgOddArray(quantity, SIZE, average);
			system("pause");
			break;
		case 7:
		// No code needed
			break;
		default:
			assert(true);
		}
		system("CLS");
	} while (choice != 7);

	cout << "\nHave a nice day:)" << endl;
	return 0;
}

/**
 * <code>printMenu</code> shows a menu and accepts the choice
 * from the user which is returned.
 * <BR>
 * @return Returns the menu choice
 */
int printMenu() {
	int choice;

	do {
		cout << "\n == MENU ==";
		cout << "\n1) Enter quantity";
		cout << "\n2) Calculate total";
		cout << "\n3) Print total";
		cout << "\n4) Sum of odd quantities";
		cout << "\n5) Check for negative quantities";
		cout << "\n6) Print average of the off numbers";
		cout << "\n7) Exit";

		cout << "\nEnter the choice: ";
		cin >> choice;

		if (choice < 1 || choice > 7) {
			cout << "\nWrong choice, try again.";
		}
	} while (choice < 1 || choice > 7);
	return choice;
}

/**
 * <code>fillInArray</code> is a function that will
 * fill in the elements of an array.
 * <BR>
 * @param arr The array to be filled in.
 * @param size The size of the array.
 */
void fillInArray(int arr[], const int size) {
	assert(size > 0);
	system("CLS");
	for (int i = 0; i < size; i++) {
		cout << "\nEnter an element for the array at " << i << ": ";
		cin >> arr[i];
		system("CLS");
	}
}

/**
 * <code>multArrays</code> multiplies the value of elements of the source array
 * to the corresponding value at the destination array. NOTE: precondition
 * is that the arrays have the same size.
 * <BR>
 * @param arrSource The array containing the destination elements.
 * @param arrDest The array containing the source elements.
 * @param size The size of the arrays.
 */
void multArrays(const int arrQuantity[], const int arrPrice[], int arrTotal[], const int size) {
	assert(size > 0);

	for (int i = 0; i < size; i++) {
		arrTotal[i] = arrQuantity[i] + arrPrice[i + 1];
	}
}

/**
 * <code>displayArray</code> prints the value of each of the elements of the
 * array. In addition the function sums up the value of all the elements and
 * print the total.
 * <BR>
 * @param ar The array with values
 * @param size The size of array.
 */
void displayArray(const int arr[], const int size) {
	int sum = 0;

	for (int i = 0; i < size; i++) {
		cout << "\nValue at " << i << ": " << arr[i];
		sum += arr[i];
	}

	cout << "\nThe total is: " << sum<<"\n";
}

/**
 * <code>sumOddArray</code> sums the odd numbers in the array and returns the result
 * <BR>
 * @param arr The array with values
 * @param size The size of array
 * @return Returns the sum of odd numbers
 */
int sumOddArray(const int arr[], const int size) {
	int sum = 0;
	for (int i = 0; i < size; i++)
		if (arr[i] % 2 != 0) sum += arr[i];
	return sum;
}

/**
 * <code>isAllPositive</code> returns true if all the values in the array are positive
 * <BR>
 * @param arr The array with values
 * @param size The size of array
 * @return Returns <code>true</code> if all the values in the array are positive and
 * <code>false</code> if there are negative values
 */
bool isAllPositive(const int arr[], const int size) {
	int neg = 0;
	for (int i = 0; i < size; i++)
		if (arr[i] < 0) neg++;
	if (neg == 0) return true;
	else return false;
}

/**
 * <code>avgOddArray</code> finds the average of all the odd numbers in the array
 * and stores this in the last argument
 * <BR>
 * @param arr The array with values
 * @param size The size of array
 * @param avgOdd The average of the odd numbers
 */
void avgOddArray(const int arr[], const int size, double& avgOdd) {
	avgOdd = double(sumOddArray(arr, size)) / size;
	cout << "The average of the odd numbers is: " << avgOdd<<"\n";
	cout << "\nThe average of the odd numbers is: " << avgOdd<<"\n";
}