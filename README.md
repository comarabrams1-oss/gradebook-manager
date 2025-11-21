GradeBook Manager – CSC 138 Team Project
Team Members

Comar Abrams

Carlos Brown

Overview

GradeBook Manager is a C++ console application that allows users to add students and courses, assign grades, and view student or course reports. The project demonstrates basic object-oriented programming using three classes: Student, Course, and GradeBook.

The program also includes:

An interactive menu for user input

A demo function that runs several automated test cases

Features

Add students

Assign grades to students

View student transcripts

View course reports

Compute student and course averages

Handle invalid IDs

Run automated demo scenarios

Classes

Student – stores student name, ID, and grades

Course – stores course ID, name, credits, and student grades

GradeBook – manages all students and courses, assigns grades, and prints reports

UML Diagram
docs/Gradebook-manager.drawio.svg


(Include the image in your repo for GitHub to display)

Running the Program
Compile
g++ -std=c++17 -O2 -Wall main.cpp -o gradebook

Run
./gradebook

Online Compiler

You may also run the program here:
https://onlinegdb.com/online_c++_compiler

Menu Example
=== MENU ===
1. Add a new student
2. Assign a grade to a student
3. Print a student report
4. Print a course report
5. Exit and run demo

Demo Mode

After exiting the menu, the built-in demo runs automatically.
It includes:

Multiple students and courses

Students with multiple grades

A student with no grades

Handling invalid grade assignments

Printing averages
