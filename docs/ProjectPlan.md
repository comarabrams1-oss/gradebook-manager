# ProjectPlan – GradeBook Manager (CSC 138 – Step 3)

## 3.1 Problem Definition and Goal
GradeBook Manager is a C++ console application that allows an instructor to manage students, courses, and numerical grades. The program lets users add students, add courses, assign grades, and view averages for both students and courses. The goal of the project is to demonstrate object-oriented design using three interacting classes while producing clear inputs, outputs, relationships, and UML structure.

---

## 3.2 Inputs and Outputs

### **Inputs**
- Student name (string)
- Student ID (int)
- Course name (string)
- Course ID (int)
- Course credits (int)
- Grade values (double 0–100)

### **Outputs**
- **Student Transcript:** list of course IDs + grades and the student’s average  
- **Course Report:** list of student IDs + grades and the course average  
- **Validation Messages:** errors for invalid operations (invalid ID, missing student/course)

---

## 3.3 Classes and Relationships

### **Classes**
**Student**
- Attributes: `name`, `student_id`, `grades : map<int, double>`
- Methods: constructor, `addGrade`, `getAverage`, `printTranscript`

**Course**
- Attributes: `course_id`, `course_name`, `credits`, `studentGrades : map<int, double>`
- Methods: constructor, `addStudentGrade`, `getAverage`

**GradeBook**
- Attributes: `students : map<int, Student>`, `courses : map<int, Course>`
- Methods: `addStudent`, `addCourse`, `assignGrade`, `studentAverage`, `courseAverage`,  
  `printStudentReport`, `printCourseReport`

### **Relationships + Multiplicities**
- **GradeBook → Student:**  
  - One GradeBook contains **0..*** Students  
  - UML: `GradeBook 1 ---- 0..* Student`

- **GradeBook → Course:**  
  - One GradeBook contains **0..*** Courses  
  - UML: `GradeBook 1 ---- 0..* Course`

- **Student ↔ Course:** (conceptual many-to-many)  
  - A Student may have **0..*** Courses  
  - A Course may have **0..*** Students  
  - UML: `Student 0..* ---- 0..* Course`

---

## 3.4 UML Class Diagram
Our UML class diagram includes:
- Class names  
- Attributes with visibility (`+`/`-`)  
- Methods  
- Three associations with multiplicities (1 → 0..*, 0..* ↔ 0..*)  

**Files:**
- `docs/UML.png` – Image for the report and GitHub preview  
- `docs/UML.drawio` – Editable version  

(The diagram is not embedded here but stored in the `/docs` folder.)

---

## 3.5 Team Tasks and Roles

| Team Member   | Roles & Responsibilities |
|---------------|--------------------------|
| **Comar Abrams** | UML diagram design, ProjectPlan.md creation, documentation, GitHub setup |
| **Carlos Brown** | Lead programmer for C++ code, testing, video presenter, class design implementation |

Each team member owns one or more deliverables:

- **Comar:** UML, documentation, GitHub structure  
- **Carlos:** main.cpp, testing, demo in the video  

This document completes Steps 3.1–3.5 and will be pushed to the `/docs` folder of our GitHub repository.
