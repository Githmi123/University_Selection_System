#include<string>
#include<fstream>
#include<iostream>
#include "Candidate_Linked_List.h"
#include"University_Queue.h"

using namespace std;

void Read_Student_Data_and_Check(string path)
{
	Candidate_Doubly_Linked_List students;
	ifstream fin(path);

	string index, nic, district;
	int  no_of_rows = 0;
	float z_score;
	string unicodes_array[6];
	fin >> no_of_rows;
	for (int i = 0; i < no_of_rows; i++)
	{
		fin >> index >> nic >> z_score >> district >> unicodes_array[0] >> unicodes_array[1] >> unicodes_array[2] >> unicodes_array[3] >> unicodes_array[4] >> unicodes_array[5];
		//cout << index << " " << nic << " " << z_score << " " << district << " " << unicodes_array[0] << " " << unicodes_array[1] << " " << unicodes_array[2] << " " << unicodes_array[3] << " " << unicodes_array[4] << " " << unicodes_array[5];
		//cout << endl;

		Preference_Order_Queue poq;
		for (int i = 0; i < 6; i++)
		{
			poq.enQueue(unicodes_array[i]);
		}

		students.insertAt(students.search(z_score), index, nic, z_score, district, poq);

	}
	//students.print();
	University_Queue University_Of_Moratuwa__Faculty_Of_Engineering(8);
	University_Queue University_Of_Peradeniya__Faculty_Of_Engineering(6);
	University_Queue University_Of_Ruhuna__Faculty_Of_Engineering(5);
	University_Queue University_Of_Jayawardhanapura__Faculty_Of_Engineering(3);
	University_Queue University_Of_Jaffna__Faculty_Of_Engineering(3);
	University_Queue University_Of_South_Eastern__Faculty_Of_Engineering(3);
	University_Queue Not_Eligible(no_of_rows);


	for (int i = 0; i < no_of_rows; i++) {
		int switch_NO = 0;
		for (int k = 0; k < 6; k++) {
			if (students.tail->preferenceQueue.preferences[k] != "None") {
				string selection = students.tail->preferenceQueue.preferences[k];
				if (selection == "008G") { switch_NO = 1; }
				else if (selection == "008B") { switch_NO = 2; }
				else if (selection == "008F") { switch_NO = 3; }
				else if (selection == "008C") { switch_NO = 4; }
				else if (selection == "008E") { switch_NO = 5; }
				else if (selection == "008J") { switch_NO = 6; }

			}
			else {
				Not_Eligible.enQueue(students.tail->indexNo, students.tail->zScore, no_of_rows);
				students.deleteLast();
				break;
			}
			bool isFilled = false, isDone = false;
			switch (switch_NO) {

			case 1:
				isFilled = University_Of_Moratuwa__Faculty_Of_Engineering.enQueue(students.tail->indexNo, students.tail->zScore, 8);
				if (isFilled == false)
				{
					isDone = true;
					break;
				}
				else if (k != 5) continue;
				else students.deleteLast();

			case 2:
				isFilled = University_Of_Peradeniya__Faculty_Of_Engineering.enQueue(students.tail->indexNo, students.tail->zScore, 6);
				if (isFilled == false)
				{
					isDone = true;
					break;
				}
				else if (k != 5) continue;
				else students.deleteLast();
			case 3:
				isFilled = University_Of_Ruhuna__Faculty_Of_Engineering.enQueue(students.tail->indexNo, students.tail->zScore, 5);
				if (isFilled == false)
				{
					isDone = true;
					break;
				}
				else if (k != 5) continue;
				else students.deleteLast();
			case 4:
				isFilled = University_Of_Jayawardhanapura__Faculty_Of_Engineering.enQueue(students.tail->indexNo, students.tail->zScore, 3);
				if (isFilled == false)
				{
					isDone = true;
					break;
				}
				else if (k != 5) continue;
				else students.deleteLast();
			case 5:
				isFilled = University_Of_Jaffna__Faculty_Of_Engineering.enQueue(students.tail->indexNo, students.tail->zScore, 3);
				if (isFilled == false)
				{
					isDone = true;
					break;
				}
				else if (k != 5) continue;
				else students.deleteLast();
			case 6:
				isFilled = University_Of_South_Eastern__Faculty_Of_Engineering.enQueue(students.tail->indexNo, students.tail->zScore, 3);
				if (isFilled == false)
				{
					isDone = true;
					break;
				}
				else if (k != 5) continue;
				else students.deleteLast();


			default:
				break;

			}

			if (isDone) {
				students.deleteLast();
				break;
			}




		}



	}

	ofstream endFile("FinalLists.txt");
	endFile << endl;
	endFile << endl;
	cout << "University of Moratuwa" << endl;
	endFile << "University of Moratuwa" << endl;
	cout << "------------------------------------------------------------------------------------------" << endl;
	endFile << "------------------------------------------------------------------------------------------" << endl;
	cout << "INDEX_No\tZ_SCORE" << endl;
	endFile << "INDEX_No\tZ_SCORE" << endl;
	endFile.open("FinalLists.txt", std::ios_base::app | std::ios_base::in);
	University_Of_Moratuwa__Faculty_Of_Engineering.print_array();
	University_Of_Moratuwa__Faculty_Of_Engineering.print_array_to_file("FinalLists.txt");
	endFile.close();
	endFile.open("FinalLists.txt", std::ios_base::app | std::ios_base::in);
	endFile << endl;
	cout << "University of Peradeniya" << endl;
	endFile << "University of Peradeniya" << endl;
	cout << "------------------------------------------------------------------------------------------" << endl;
	endFile << "------------------------------------------------------------------------------------------" << endl;
	cout << "INDEX_No\tZ_SCORE" << endl;
	endFile << "INDEX_No\tZ_SCORE" << endl;
	University_Of_Peradeniya__Faculty_Of_Engineering.print_array();
	University_Of_Peradeniya__Faculty_Of_Engineering.print_array_to_file("FinalLists.txt");
	endFile << endl;
	cout << "University of Ruhuna" << endl;
	endFile << "University of Ruhuna" << endl;
	cout << "------------------------------------------------------------------------------------------" << endl;
	endFile << "------------------------------------------------------------------------------------------" << endl;
	cout << "INDEX_No\tZ_SCORE" << endl;
	endFile << "INDEX_No\tZ_SCORE" << endl;
	University_Of_Ruhuna__Faculty_Of_Engineering.print_array();
	University_Of_Ruhuna__Faculty_Of_Engineering.print_array_to_file("FinalLists.txt");
	endFile << endl;
	cout << "University of Sri Jayawardenapura" << endl;
	endFile << "University of Sri Jayawardenapura" << endl;
	cout << "------------------------------------------------------------------------------------------" << endl;
	endFile << "------------------------------------------------------------------------------------------" << endl;
	cout << "INDEX_No\tZ_SCORE" << endl;
	endFile << "INDEX_No\tZ_SCORE" << endl;
	University_Of_Jayawardhanapura__Faculty_Of_Engineering.print_array();
	University_Of_Jayawardhanapura__Faculty_Of_Engineering.print_array_to_file("FinalLists.txt");
	endFile << endl;
	cout << "University of Jaffna" << endl;
	endFile << "University of Jaffna" << endl;
	cout << "------------------------------------------------------------------------------------------" << endl;
	endFile << "------------------------------------------------------------------------------------------" << endl;
	cout << "INDEX_No\tZ_SCORE" << endl;
	endFile << "INDEX_No\tZ_SCORE" << endl;
	University_Of_Jaffna__Faculty_Of_Engineering.print_array();
	University_Of_Jaffna__Faculty_Of_Engineering.print_array_to_file("FinalLists.txt");
	endFile << endl;
	cout << "University of South Eastern" << endl;
	endFile << "University of South Eastern" << endl;
	cout << "------------------------------------------------------------------------------------------" << endl;
	endFile << "------------------------------------------------------------------------------------------" << endl;
	cout << "INDEX_No\tZ_SCORE" << endl;
	endFile << "INDEX_No\tZ_SCORE" << endl;
	University_Of_South_Eastern__Faculty_Of_Engineering.print_array();
	University_Of_South_Eastern__Faculty_Of_Engineering.print_array_to_file("FinalLists.txt");
	cout << endl;
	endFile << endl;
	cout << endl;
	endFile << endl;
	cout << endl;
	endFile << endl;
	cout << "Not Eligible" << endl;
	endFile << "Not Eligible" << endl;
	cout << "------------------------------------------------------------------------------------------" << endl;
	endFile << "------------------------------------------------------------------------------------------" << endl;
	Not_Eligible.print_array();
	Not_Eligible.print_array_to_file("FinalLists.txt");
	endFile.close();
}


