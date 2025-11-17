# GradeBook Manager – Project Report  
**Course:** CSC 138  
**Team Members:**  
- **Comar Abrams** – UML Designer, Documentation, GitHub Organizer  
- **Carlos Brown** – Lead Developer, Testing, Video Presenter  

---

## 1. Project Overview  
GradeBook Manager is a C++ console application designed to help instructors store students, courses, and numerical grades. The system allows the user to add students and courses, assign grades, compute averages, and display formatted reports. The project demonstrates the fundamentals of object-oriented programming, including encapsulation, mapping relationships between classes, and managing data with C++ structures such as `map<int, Student>` and `map<int, Course>`.

The design focuses on clarity, maintainability, and reusability of code. Each class has a well-defined role, and the relationships between them are represented clearly in the UML diagram.

---

## 2. Inputs and Outputs  

### **Inputs**
- Student name (string)  
- Student ID (int)  
- Course name (string)  
- Course ID (int)  
- Course credits (int)  
- Numeric grade values (double, 0–100)  

### **Outputs**
- **Student Transcript:**  
  - List of courses and grades  
  - Student's average grade  
- **Course Report:**  
  - List of students and grades  
  - Course average  
- **Validation messages** for invalid operations (nonexistent student/course IDs)

---

## 3. System Design and Classes

### **3.1 Student Class**
**Attributes:**  
- `name : string`  
- `student_id : int`  
- `grades : map<int, double>`  

**Responsibilities:**  
- Store grades per course  
- Compute a student’s overall average  
- Print transcript  

**Key Methods:**  
- `addGrade(courseID, grade)`  
- `getAverage()`  
- `printTranscript()`  

---

### **3.2 Course Class**
**Attributes:**  
- `course_id : int`  
- `course_name : string`  
- `credits : int`  
- `studentGrades : map<int, double>`  

**Responsibilities:**  
- Store grades for each student  
- Compute course average  
- Track credit hours  

**Key Methods:**  
- `addStudentGrade(studentID, grade)`  
- `getAverage()`  

---

### **3.3 GradeBook Class**
**Attributes:**  
- `students : map<int, Student>`  
- `courses : map<int, Course>`  

**Responsibilities:**  
- Add/manage students  
- Add/manage courses  
- Assign grades  
- Connect students ↔ courses  
- Generate reports  

**Key Methods:**  
- `addStudent(...)`  
- `addCourse(...)`  
- `assignGrade(studentID, courseID, grade)`  
- `studentAverage(studentID)`  
- `courseAverage(courseID)`  
- `printStudentReport(studentID)`  
- `printCourseReport(courseID)`  

---

## 4. UML Diagram  
The UML diagram visually represents:  
- All three classes  
- Attributes and methods  
- Relationships and multiplicities  
- Student ↔ Course many-to-many  
- GradeBook → Student and GradeBook → Course (1 → 0..*)

**Files included:**  
- `docs/Gradebook-manager.drawio.svg` – UML image  

---

## 5. Implementation Summary  
The entire program is contained in `main.cpp`.  
It includes:

### ** Correct Class Definitions**  
Each class is fully implemented with constructors, getters, setters, and behavior‐based functions.

### ** Demo Function**
`GradeBook::demo()` demonstrates real scenarios including:  
1. Multiple students across multiple courses  
2. Student with no grades  
3. Course averages  
4. Invalid grade assignment (nonexistent ID)  

### ** No syntax or runtime errors**
The code compiles cleanly using:

```bash
g++ -std=c++17 -O2 -Wall main.cpp -o gradebook
./gradebook
