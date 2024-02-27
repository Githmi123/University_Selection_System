#pragma once
#include<iostream>
#include "Student_Data_Entry_Functions.h"
using namespace std;

void Welcome() {
	cout << endl;
	cout << endl;
	cout << "*********************************************** WELCOME ************************************************" << endl;
	cout << endl;
	cout << "************************ UNIVERSITY SELECTION SYSTEM BASED ON Z-SCORE ************************" << endl;
	cout << endl;
	cout << "To proceed, make sure you have entered IndexNO--IDNo--ZScore--District--Unicodes_Of_prefernces respectively to the *StudentDataList.txt* file" << endl;
	cout << endl;
	cout << endl;
	cout << "In entering the above information please adhere to the following guidelines" << endl;
	cout << endl;
	cout << "(1) Enter data in the above mentioned order." << endl;
	cout << "(2) The data must be space-seperated." << endl;
	cout << "(3) The maximum number of courses one candidate can apply is six." << endl;
	cout << "(4) If the number of applying courses is below six mention the rest as 'NONE'." << endl;
	cout << "(5) Consider the following Unicodes:" << endl;
	cout << "\t*008G for University of Moratuwa" << endl;
	cout << "\t*008B for University of Peradeniya" << endl;
	cout << "\t*008F for University of Ruhuna" << endl;
	cout << "\t*008C for University of Sri Jayawardhanapura" << endl;
	cout << "\t*008E for University of Jaffna" << endl;
	cout << "\t*008J for University of South Eastern" << endl;
	cout << "" << endl;
	cout << endl;
	auto var = 0;
	cout << "To proceed further, press any key and press Enter...  ";
	cin >> var;

	cout << "\033[2J\033[1;1H";
	cout << "" << endl;
	Read_Student_Data_and_Check("StudentDataList.txt");
};
