#pragma once
#include<string>
#include<iostream>
#include<fstream>

using namespace std;

class University_Queue
{
public:

	int size;
	int front;
	int rear;
	int capacity;
	string* student_list;
	double* z_score_list;



	University_Queue(int cap) {
		size = 0;
		capacity = cap;
		student_list = new string[capacity];
		z_score_list = new double[capacity];
		front = 0;
		rear = 0;
	}

	bool enQueue(string indexNO, double zScore, int capacity) {

		if (size == capacity) {
			return true;
		}

		else {
			student_list[rear] = indexNO;
			z_score_list[rear] = zScore;

			rear = (rear + 1) % capacity;

			size++;
			return false;
		}

	}

	void print_array() {

		for (int i = 0; i < size; i++) {
			cout << student_list[i] << "	";
			cout << "\t";
			cout << z_score_list[i] << "	";
			cout << endl;
		}
		cout << endl;
	}


	void print_array_to_file(string path) {
		string filename(path);
		fstream file;
		for (int i = 0; i < size; i++) {
			file.open(filename, std::ios_base::app | std::ios_base::in);
			if (file.is_open()) {
				file << student_list[i] << "\t\t" << z_score_list[i] << "	" << endl;
				file.close();
			}

		}

	}

};

