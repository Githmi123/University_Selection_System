# University Selection System: A Data Structures Project in C++

## A Data Structures Project that Efficiently Allocate Candidates to Engineering Degree Programs in Sri Lanka, Using Linked Lists and Queues

## Introduction

The University Selection System is one of our Semester 03 projects for the module Data Structures and Algorithms, of Faculty of Engineering, University of RUhuna, focusing on efficient candidate allocation to engineering programs. This system utilizes linked lists and queues to manage candidate data and allocate them to universities based on priority codes(unicodes) and available capacities(of the programs).

### Key Features

- **Data** : Details of the students including index number, NIC number, Z-score, district, and 6 unicodes of degree programs according to their preference order stored in the text file "StudentDataList.txt".
- **Preference Order of the programs** :  The unicodes in preference order are stored in a "Preference_Order_Queue".
- **Students** : All the details of the students are stored in a "Candidate_Doubly_Linked_List".
- **Capacities of programs** : Each University program is a "University_Queue", with a certain specified capacity as it's size.
- **Candidate Allocation** : Candidates are allocated based on the z-scores to the "University_Queue" of each degree program.
