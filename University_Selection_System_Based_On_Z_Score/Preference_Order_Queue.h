#include<iostream>

using namespace std;

class Preference_Order_Queue
{
public:
	
	int size;
	int front;
	int rear;
	string* preferences;



	Preference_Order_Queue() {
		size = 0;
		preferences = new string[6];
		front = 0;
		rear = 0;
	}

	void enQueue(string val) {
		
		if (size == 6) {
			cout << "Queue is Full" << endl;
		}

		else {
			preferences[rear] = val;
			rear = (rear + 1) % 6;
			
			size++;
		}

	}

	void deQueue() {  
		if (size == 0) {
			cout << "Queue is Empty" << endl;
			
		}
		else {
			string temp = preferences[front];  
			front = (front + 1) % 6;
			size--;
			
		}
	}

	
	
};

