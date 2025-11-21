# Project Plan – GradeBook Manager  
CSC 138 – Step 3

## 3.1 Problem Definition and Goal
GradeBook Manager is a C++ console-based system designed to help an instructor manage students, courses, and numerical grades. The program supports adding students, creating courses, assigning grades, and viewing reports that summarize performance at both the student and course levels.

The goal of this project is to demonstrate foundational object-oriented programming principles by implementing three interacting classes. The system must clearly show inputs, outputs, relationships, and UML structure consistent with OOP design standards.

## 3.2 Inputs and Outputs

### Inputs
- Student name (string)  
- Student ID (int)  
- Course name (string)  
- Course ID (int)  
- Course credit hours (int)  
- Grade values (double, 0–100)

### Outputs
- **Student Transcript:** list of course IDs + grades and the student’s average  
- **Course Report:** list of student IDs + grades and the course average  
- **Validation Messages:** errors for invalid or missing IDs  

## 3.3 Classes and Relationships

### Classes

#### Student
- **Attributes:** `name`, `student_id`, `grades : map<int, double>`  
- **Methods:** constructor, `addGrade`, `getAverage`, `printTranscript`

#### Course
- **Attributes:** `course_id`, `course_name`, `credits`, `studentGrades : map<int, double>`  
- **Methods:** constructor, `addStudentGrade`, `getAverage`

#### GradeBook
- **Attributes:** `students : map<int, Student>`, `courses : map<int, Course>`  
- **Methods:** `addStudent`, `addCourse`, `assignGrade`,  
  `studentAverage`, `courseAverage`, `printStudentReport`, `printCourseReport`

### Relationships and Multiplicities

**GradeBook → Student**  
- One GradeBook contains **0..*** Students  
- UML: `GradeBook 1 ---- 0..* Student`

**GradeBook → Course**  
- One GradeBook contains **0..*** Courses  
- UML: `GradeBook 1 ---- 0..* Course`

**Student ↔ Course (Conceptual Many-to-Many)**  
- A student may have **0..*** courses  
- A course may have **0..*** students  
- UML: `Student 0..* ---- 0..* Course`

## 3.4 UML Class Diagram
The UML class diagram includes class names, attributes, methods, and multiplicities.  
Stored in the repository:

```
docs/Gradebook-manager.drawio.svg
```

## 3.5 Team Tasks and Roles

| Team Member     | Roles & Responsibilities                                                     |
|-----------------|------------------------------------------------------------------------------|
| **Comar Abrams** | UML diagram design, ProjectPlan.md creation, documentation, GitHub setup     |
| **Carlos Brown** | Lead programmer for C++ implementation, testing, video presenter             |

**Deliverables**  
- **Comar:** UML diagram, documentation, GitHub organization  
- **Carlos:** main program file, testing, demonstration video  

This document completes Steps **3.1–3.5** and will be placed in the `/docs` folder of the repository.
