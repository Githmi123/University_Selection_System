#pragma once
#include <iostream>
#include <cstddef>
#include "Preference_Order_Queue.h"

using namespace std;

class Node  
{
public:
	string indexNo; 
	string nicNo;
	double zScore;
	string district;
    Preference_Order_Queue preferenceQueue;
	Node* next;
	Node* prev;


	Node() {   
		indexNo = "Not stated"; 
		nicNo = "Not stated";
		zScore = 0;
		preferenceQueue;
		district = "Not stated";
		next = NULL;
		prev = NULL;
	}

	Node(string index_No, string nic_No, double z_Score, string _district, Preference_Order_Queue poq) {
		indexNo = index_No;
		nicNo = nic_No;
		zScore = z_Score;
		district = _district;
		preferenceQueue = poq;
		next = NULL;
		prev = NULL;
	}
};

class Candidate_Doubly_Linked_List {
public:
	Node* head;
	Node* tail;
	int size;

	Candidate_Doubly_Linked_List() {
		head = NULL;
		tail = NULL;
		size = 0;
	}

	void insertFirst(string index_No, string nic_No, double z_Score, string _district, Preference_Order_Queue poq) {
		Node* temp = new Node( index_No,  nic_No,  z_Score,  _district, poq);
		if (head == NULL) {

			head = temp;
			tail = temp;
			size++;


		}

		else {  
			temp->next = head;  
			head->prev = temp;  
			head = temp; 
			size++;
		}
	}

	void insertLast(string index_No, string nic_No, double z_Score, string _district, Preference_Order_Queue poq) {
		Node* temp2 = new Node( index_No,  nic_No,  z_Score,  _district, poq);  
		if (tail == NULL) { 
			head = temp2;  
			tail = temp2; 
			size++;


		}

		else { 
			tail->next = temp2;  
			temp2->prev = tail;
			tail = temp2; 
			size++;
		}
	}

	void insertAt(int pos, string index_No, string nic_No, double z_Score, string _district, Preference_Order_Queue poq) {  // Build a function for position
		if (pos<0 || pos>size) {
			cout << "Invalid position" << endl;
		}
		else if (pos == 0) {
			insertFirst( index_No,  nic_No,  z_Score,  _district, poq);
		}
		else if (pos == size) {
			insertLast( index_No,  nic_No,  z_Score,  _district, poq);
		}
		else {
			Node* temp = new Node(index_No, nic_No, z_Score, _district, poq);
			Node* current = head;

			for (int i = 0; i < pos - 1; i++) {
				current = current->next;
			}

			temp->next = current->next;
			temp->prev = current;
			current->next = temp;
			(temp->next)->prev = temp;
			size++;
		}

	}

	void print() {  // This uses traversing
		Node* current = head;  // A pointer named 'current' of type Node class is created and is assigned the address in the head

		while (current != NULL) {  // The next of current is NULL only when 'current' points to the last element
			cout << current->indexNo << " ";  // Prints the element(data value) in the current Node
			current = current->next;  // Current Node is pointed to the next Node
		}
		cout << endl;
	}

	void deleteFirst() {
		if (head == NULL)  // or tail == NULL or size == 0
			cout << "List is empty" << endl;

		else {
			Node* temp = head;  // We copy the values in the head to this. SO that we can delete what is imside the temporary pointer. Otherewise, if we give delete head, then it will delete what is inside head. So, we can't make the next element as the head. That is why we take a temporary variable
			if (size == 1) {
				delete temp;
				head = NULL;
				tail = NULL;
				size = 0;
			}
			else {
				head = head->next;
				head->prev = NULL;
				delete temp;
				size--;
			}
		}
	}

	void deleteLast() {
		if (head == NULL)  // or tail == NULL or size == 0
			cout << "List is empty" << endl;

		else {
			Node* temp = tail;
			if (size == 1) {
				delete temp;
				head = NULL;
				tail = NULL;
				size = 0;
			}
			else {
				Node* current = head;
				tail = tail->prev;
				tail->next = NULL;
				delete temp;

			}
			size--;
		}
	}

	void deleteAt(int pos) {
		if (pos < 0 || pos >= size) {
			cout << "Invalid podition" << endl;
		}
		else if (pos == 0) {
			deleteFirst();
		}
		else if (pos = size - 1) {
			deleteLast();

		}
		else {
			Node* current = head;
			for (int i = 0; i < pos; i++) {
				current = current->next;
			}
			Node* temp = current;
			(current->prev)->next = temp->next;
			(current->next)->prev = temp->prev;
			delete temp;
			size--;
		}
	}

	
	int search(double elem) {
		Node* current = head;
		int count = 0;
		while (current != NULL) {
			if (current->zScore >= elem) {
				//cout << count << " ";
				return count;
			}
			count++;
			current = current->next;
		}

	}

};
