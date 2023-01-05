//// Labs.cpp : This file contains the 'main' function. Program execution begins and ends there.
////
///*
//#include <iostream>
//using namespace std;
//
//void analyze_pointer(int* ptr)
//{
//    // Add your code here!
//    cout << "Pointer's memory location: " << ptr << endl;
//    cout << "Pointer's pointed value: " << *ptr << endl;
//}
//
//int main()
//{
//    // int* salary = new int[20];
//    // for (int i = 0; i < 20; ++i) {
//    //     cout << "Enter Salary: ";
//    //     cin >> salary[i];
//    // }
//    // for (int i = 0; i < 20; ++i) {
//    //     salary[i] = salary[i] + salary[i] / (i + 1);
//    // }
//    // delete [] salary;
//    int a;
//    int* pointer = &a;
//    analyze_pointer(pointer);
//
//    return 0;
//}
//*/
//
///*
//* Kindly fill this information.
//* Name: Huzaifa Jawad
//* Student : 367779
//* Date: 27/09/22
//*/
//
//#include <iostream>
//
//using namespace std;
//
///*
//* PROBLEM #2: Analyze pointers
//*/
//
///*
//* PART #1: Write a function that does two things:
//* >> Write the memory location pointed by the pointer to the console.
//* >> Write the value of the integer (which the pointer points to) to the console.
//*/
//void analyze_pointer(int* ptr)
//{
//	// Add your code here!
//	cout << "Pointer's memory location: " << ptr << endl;
//	cout << "Pointer's pointed value: " << *ptr << endl;
//
//}
//
//
///*
//* PROBLEM #3: Add a couple more functions to the mix
//* >> call them int_pointer1 and int_pointer2
//* >> both will return int pointers.
//*/
//
///*
//* Follow the steps:
//* >> the function will allocate an int on the heap (via new int)
//* >> assign a value to it
//* >> and return that value (an int pointer type).
//*/
//int* int_pointer1()
//{
//	// Add your code here!
//	int* integer1 = new int;
//	*integer1 = 10;
//	return integer1;
//}
//
///*
//* Follow the steps:
//* >> the function will allocate an int on the stack (via "int iValue;" or something similar)
//* >> assign a value to it
//* >> and return its memory location (an int pointer type).
//*/
//int* int_pointer2()
//{
//	// Add your code here!
//	int num = 7;
//	return &num;
//}
//
//
//int main()
//{
//	/*
//	* PART #2: Use the analyze_pointer function to complete two TASKS
//	*/
//
//	/*
//	* TASK #1
//	* >> allocate an int on the stack (e.g.,  "int iValue;")
//	* >> assign a value to it
//	* >> get its memory location (with the reference operator---&)
//	* >> and pass this value to analyze_pointer.
//	*/
//	cout << "Part #2: Memory on stack..." << endl;
//
//	// Add your code here!
//	int iValue = 19;
//	analyze_pointer(&iValue);
//
//	/*
//	* TASK #2
//	* >> allocate an int on the heap (with the new operator)
//	* >> assign a value to it
//	* >> and pass it to analyze_pointer.
//	*/
//	cout << "Memory on heap..." << endl;
//
//	// Add your code here!
//	int* num1 = new int;
//	analyze_pointer(num1);
//	delete num1;
//
//	/*
//	* PROBLEM #3: Call analyze_pointer on the return of functions int_pointer1() and int_pointer2()
//	*/
//	cout << "Memory on heap versus on stack..." << endl;
//
//	// Add your code here!
//	int* arg1 = int_pointer1();
//	analyze_pointer(arg1);
//
//	int* arg2 = int_pointer2();
//	analyze_pointer(arg1);
//
//	/*
//	* Remember that int was allocated on the heap for function "int_pointer1()"
//	* Delete it
//	* and call analyze_pointer on it after deleting it.
//	*/
//	cout << "Memory on heap after delete..." << endl;
//
//	// Add your code here!
//	delete arg1;
//	analyze_pointer(arg1);
//
//	/*
//	* Call: analyze_pointer(new int);
//	*/
//
//	// Add your code here!
//	analyze_pointer(new int);
//
//	return 0;
//}

/*
* Kindly fill this information.
* Name: Huzaifa Jawad
* Student #: 367779
* Date: 27/09/22
*/

#include <iostream>
#include <string>

using namespace std;

/*
* Define a struct Area that has two private variable members;
* units of type string and area_value of type float.
*/
struct Area
{
	string getUnits() { return units; }
	float getAreaVal() { return area_value; }
	void setUnits(string unit) { units = unit; }
	void setAreaVal(float area) { area_value = area; }

	// Add your code here!
private:
	string units;
	float area_value;
};

int main()
{
	/*
	* Modify program to create a dynamic variable of type Area.
	*/

	// Add your code here!
	Area* obj = new Area;
	float a;
	string u;

	/*
	* Input from the keyboard the area_value and its units.
	*/

	// Add your code here!
	cout << "Enter the area_value: ";
	cin >> a;
	cout << "Enter the units: ";
	cin >> u;
	obj->setAreaVal(a);
	obj->setUnits(u);
	/*
	* Compute one-half and one-quarter of the area
	* and display the results
	*/

	// Add your code here!
	cout << "one-half: " << obj->getAreaVal() / 2 << obj->getUnits() << endl;
	cout << "one-quater: " << obj->getAreaVal() / 4 << obj->getUnits() << endl;
	/*
	* Destroy the dynamic variable at the end
	*/

	// Add your code here!
	delete obj;

	return 0;
}
