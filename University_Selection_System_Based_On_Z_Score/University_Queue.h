#pragma once
#include<string>
#include<iostream>
using namespace std;
 
class University_Queue
{
public:

	int size;
	int front;
	int rear;
	int capacity;
	string* student_list;
	float* z_score_list;



	University_Queue(int cap){
		size = 0;
		cap = capacity;
		student_list = new string[capacity];
		z_score_list = new float[capacity];
		front = 0;
		rear = 0;
	}

	bool enQueue(string indexNO,float zScore) {
		
		if (size == 6) {
			return true;
		}

		else {
			student_list[rear] = indexNO;
			z_score_list[rear] = zScore;

			rear = (rear + 1) % 6;

			size++;
			return false;
		}

	}

	void print_array() {  // Here, we print the value as they are.

		for (int i = 0; i < capacity; i++) {
			cout << student_list[i] << " ";
			cout << z_score_list[i] << " ";
		}
		cout << endl;
	}

};

