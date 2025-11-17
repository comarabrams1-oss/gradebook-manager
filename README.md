# GradeBook Manager – CSC 138 Team Project

## Team Members
- Comar Abrams – UML Design, GitHub Repo, Report Coordinator  
- Carlos Brown – Lead Developer, Testing, Video Presenter  

## Project Description

GradeBook Manager is a C++ console application that lets a user create students and courses, assign grades, and compute averages. The program demonstrates basic object-oriented design in C++ using three main classes: `Student`, `Course`, and `GradeBook`. Users can see per-student transcripts and per-course grade reports.

## Features

- Add students and courses
- Assign grades for a student in a course
- Compute per-student and per-course averages
- Print formatted transcripts and course reports
- Demonstration cases in `main.cpp::demo()` (multiple students/courses, student with no grades, invalid operations)

## Classes Overview

- **Student**
  - Attributes: `name`, `student_id`, `grades (map<int,double>)`
  - Key methods: `addGrade`, `getAverage`, `printTranscript`

- **Course**
  - Attributes: `course_id`, `course_name`, `credits`, `studentGrades (map<int,double>)`
  - Key methods: `addStudentGrade`, `getAverage`

- **GradeBook**
  - Attributes: `students (map<int,Student>)`, `courses (map<int,Course>)`
  - Key methods: `addStudent`, `addCourse`, `assignGrade`, `studentAverage`, `courseAverage`, `printStudentReport`, `printCourseReport`, `demo`

## UML Diagram

The UML class diagram for `Student`, `Course`, and `GradeBook` with relationships and multiplicities is saved as:

- `docs/Gradebook-manager.drawio.svg` (exported from draw.io)
- `docs/Gradebook-manager.drawio` (source file)
## UML Diagram

![UML Diagram](docs/Gradebook-manager.drawio.svg)
## How to Compile and Run

You can use this link `http://onlinegdb.com/online_c++_compiler` and copy the code from the `src` folder or use the a terminal to execute the code.

From the `src` folder (or repo root if you prefer):

```bash
g++ -std=c++17 -O2 -Wall main.cpp -o gradebook
./gradebook

