# GradeBook Manager – CSC 138 Team Project

## Team Members
- Comar Abrams  
- Carlos Brown  

## Overview
GradeBook Manager is a C++ console application that allows users to add students, assign grades, and generate reports. It demonstrates basic object-oriented programming using three main classes: `Student`, `Course`, and `GradeBook`.

The program supports an interactive menu for user input as well as an automated demo function that showcases multiple test scenarios.

## Features
- Add students  
- Assign grades to students  
- Print student transcripts  
- Print course reports  
- Compute student and course averages  
- Handle invalid IDs  
- Run automated demo cases  

## Classes
### Student
- Stores student name, ID, and a map of grades  
- Methods: `addGrade`, `getAverage`, `printTranscript`

### Course
- Stores course ID, name, credits, and student grade entries  
- Methods: `addStudentGrade`, `getAverage`

### GradeBook
- Stores all students and courses  
- Methods:  
  `addStudent`, `addCourse`, `assignGrade`,  
  `studentAverage`, `courseAverage`,  
  `printStudentReport`, `printCourseReport`, `demo`

## UML Diagram
The UML diagram is stored at:

```
docs/Gradebook-manager.drawio.svg
```

If the file exists in GitHub, it will display automatically when clicked.

## How to Compile and Run

### Compile
```bash
g++ -std=c++17 -O2 -Wall main.cpp -o gradebook
```

### Run
```bash
./gradebook
```

### Online Compiler
You may also run the program here:  
https://onlinegdb.com/online_c++_compiler

## Example Menu Interaction
```
=== MENU ===
1. Add a new student
2. Assign a grade to a student
3. Print a student report
4. Print a course report
5. Exit and run demo
```

## Demo Mode
After exiting the menu, the program automatically runs a series of test cases:
- Multiple students with multiple courses  
- Students with no grades  
- Invalid grade assignment  
- Course and student averages  
- Full student and course reports  

## Conclusion
GradeBook Manager demonstrates essential OOP concepts in C++. It provides a functional grade-management system with both interactive input and automated test cases, making it suitable for coursework and introductory programming projects.
