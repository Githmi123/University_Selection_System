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
	string unicodes_array[7];
	fin >> no_of_rows;
	for (int i = 0; i < no_of_rows; i++)
	{
		fin >> index >> nic >> z_score >> unicodes_array[0] >> unicodes_array[1] >> unicodes_array[2] >> unicodes_array[3] >> unicodes_array[4] >> unicodes_array[5] >> unicodes_array[6];
		//cout << index << nic << z_score << unicodes_array[0] << unicodes_array[1] << unicodes_array[2] << unicodes_array[3] << unicodes_array[4] << unicodes_array[5] << unicodes_array[6];


		Preference_Order_Queue poq;
		for (int i = 0; i < 6; i++)
		{
			poq.enQueue(unicodes_array[i]);
		}

		students.insertAt(students.search(z_score), index, nic, z_score, district, poq);

	}

	University_Queue University_Of_Moratuwa__Faculty_Of_Engineering(8);
	University_Queue University_Of_Peradeniya__Faculty_Of_Engineering(6);;
	University_Queue University_Of_Ruhuna__Faculty_Of_Engineering(5);
	University_Queue University_Of_Jayawardhanapura__Faculty_Of_Engineering(3);
	University_Queue University_Of_Jaffna__Faculty_Of_Engineering(3);
	University_Queue University_Of_South_Eastern__Faculty_Of_Engineering(3);

	for (int i = 0; i < no_of_rows; i++) {
		int switch_NO;
		for (int k = 0; k < 6; k++) {
			if (students.tail->preferenceQueue.preferences[k] != "None") {
				string selection = students.tail->preferenceQueue.preferences[k];
				if (selection == "100M") { switch_NO = 1; }
				else if (selection == "200M") { switch_NO = 2; }
				else if (selection == "300M") { switch_NO = 3; }
				else if (selection == "400M") { switch_NO = 4; }
				else if (selection == "500M") { switch_NO = 5; }
				else if (selection == "600M") { switch_NO = 6; }
			}
			switch (switch_NO) {
				bool isFilled;
			case 1:
				isFilled = University_Of_Moratuwa__Faculty_Of_Engineering.enQueue(students.tail->indexNo, students.tail->zScore);
				if (isFilled == false)
				{
					break;
				}

			case 2:
				isFilled = University_Of_Peradeniya__Faculty_Of_Engineering.enQueue(students.tail->indexNo, students.tail->zScore);
				if (isFilled == false)
				{
					break;
				}
			case 3:
				isFilled = University_Of_Ruhuna__Faculty_Of_Engineering.enQueue(students.tail->indexNo, students.tail->zScore);
				if (isFilled == false)
				{
					break;
				}
			case 4:
				isFilled = University_Of_Jayawardhanapura__Faculty_Of_Engineering.enQueue(students.tail->indexNo, students.tail->zScore);
				if (isFilled == false)
				{
					break;
				}
			case 5:
				isFilled = University_Of_Jaffna__Faculty_Of_Engineering.enQueue(students.tail->indexNo, students.tail->zScore);
				if (isFilled == false)
				{
					break;
				}
			case 6:
				isFilled = University_Of_South_Eastern__Faculty_Of_Engineering.enQueue(students.tail->indexNo, students.tail->zScore);
				if (isFilled == false)
				{
					break;
				}

			default:
				cout << "Not eligible for University Entrance" << endl;
			}




			students.deleteLast();
		}



		University_Of_Moratuwa__Faculty_Of_Engineering.print_array();
		University_Of_Peradeniya__Faculty_Of_Engineering.print_array();
		University_Of_Ruhuna__Faculty_Of_Engineering.print_array();
		University_Of_Jayawardhanapura__Faculty_Of_Engineering.print_array();
		University_Of_Jaffna__Faculty_Of_Engineering.print_array();
		University_Of_South_Eastern__Faculty_Of_Engineering.print_array();


	}
}