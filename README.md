# University Selection System: A Data Structures Project in C++

**A Data Structures Project that Efficiently Allocate Candidates to Engineering Degree Programs in Sri Lanka, Using Linked Lists and Queues.**

## Introduction

The University Selection System is one of our Semester 03 projects for the module Data Structures and Algorithms, of Faculty of Engineering, University of RUhuna, focusing on efficient candidate allocation to engineering programs. This system utilizes linked lists and queues to manage candidate data and allocate them to universities based on priority codes(unicodes) and available capacities(of the programs).

### Key Features

- **Data** : Details of the students including index number, NIC number, Z-score, district, and 6 unicodes of degree programs according to their preference order stored in the text file "StudentDataList.txt".
- **Preference Order of the programs** :  The unicodes in preference order are stored in a "Preference_Order_Queue".
- **Students** : All the details of the students are stored in a "Candidate_Doubly_Linked_List".
- **Capacities of programs** : Each University program is a "University_Queue", with a certain specified capacity as it's size.
- **Candidate Allocation** : Candidates are allocated based on the z-scores to the "University_Queue" of each degree program. Allocated using switch cases.
- **Output** : Index No. and the z-score of the allocated candidates for each degree program are printed on the console and saved in a text file "FinalLists.txt".

### Technologies Used

- **Language** : C++
- **Data Structures** : Linked Lists, Queues

## Installation

To install and run this project, follow these steps:

1. Clone the repository to your local machine.
2. Navigate to the project directory.
3. Start the application in Visual Studio by double-clicking on "University_Selection_System_Based_On_Z_Score.sln".
4. Build the program.


### Contributing

We welcome contributions to our project. Whether it's a bug fix, new feature, or improvement, we appreciate your efforts to make this project better for everyone. Here is how you can contribute:

## Getting Started
- Fork the repository and clone it to your local machine.
- Create a new branch for your changes.

## Submitting Changes
- Push your changes to your fork.
- Submit a pull request to the main branch of this original repository.
- Please provide a clear description of your changes and why they are necessary.

### Conclusion

Thank you for checking out our project! We hope you found it useful. If you have any questions or feedback, please don't hesitate to contact us.
