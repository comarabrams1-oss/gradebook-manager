# GradeBook Manager – Final Project Report  
**Course:** CSC 138  
**Team Members:**  
- **Comar Abrams** – UML Designer, Documentation, GitHub Organizer  
- **Carlos Brown** – Lead Developer, Testing, Video Presenter  

---

## 1. Project Overview  
GradeBook Manager is a C++ console application designed to help instructors manage students, courses, and numerical grades. The system allows the user to add students, assign grades, compute averages, and display formatted reports for both students and courses.  

The purpose of this project is to demonstrate core object-oriented programming (OOP) principles using three interacting classes: `Student`, `Course`, and `GradeBook`. These classes work together to model a simplified grade management system that includes data storage, report generation, and error handling.  

The design emphasizes code clarity, modularity, and proper class responsibilities. The application showcases encapsulation, use of maps for data association, and the relationship structure captured in the UML diagram.

---

## 2. Inputs and Outputs  

### **Inputs**
- Student name (string)  
- Student ID (int)  
- Course name (string)  
- Course ID (int)  
- Course credit hours (int)  
- Grade values (double, 0–100)

### **Outputs**
- **Student Transcript:**  
  Displays course IDs, grades, and the student’s average  
- **Course Report:**  
  Displays student IDs, grades, and the course average  
- **Validation Messages:**  
  Shown when attempting to assign grades to invalid or nonexistent IDs

---

## 3. System Design and Classes  

### **3.1 Student Class**  
**Attributes:**  
- `name : string`  
- `student_id : int`  
- `grades : map<int, double>`  

**Responsibilities:**  
- Store individual course grades  
- Compute a student’s average  
- Produce formatted transcripts  

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
- Store grades assigned to each student in the course  
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
- Add and manage student objects  
- Add and manage course objects  
- Assign grades while linking students and courses  
- Generate both student and course reports  
- Serve as the central controller of the system  

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
The UML diagram illustrates the structure of the application, including:
- Class names  
- Attributes and methods  
- One-to-many relationships between `GradeBook → Student` and `GradeBook → Course`  
- Conceptual many-to-many relationship between students and courses  

**File included:**  
```
docs/Gradebook-manager.drawio.svg
```

---

## 5. Implementation Summary  

### **5.1 Class Definitions**  
All classes are fully implemented with constructors and behavior-based methods. Maps are used to store grade associations, ensuring quick lookup and avoiding duplication.

### **5.2 Interactive Menu**  
The `main()` function provides a simple interface that allows the user to:
- Add students  
- Assign grades  
- Print student reports  
- Print course reports  
- Exit and run the demo  

### **5.3 Demo Function**  
`GradeBook::demo()` runs automatically after the interactive menu and demonstrates:
1. Multiple students assigned to multiple courses  
2. Calculation of student and course averages  
3. A student with no grades  
4. Invalid grade assignment using a nonexistent student ID  
5. Proper reporting of transcripts and course summaries  

### **5.4 Compilation and Execution**  
The program compiles with no errors or warnings using:

```bash
g++ -std=c++17 -O2 -Wall main.cpp -o gradebook
./gradebook
```

The program can also be executed using an online compiler such as OnlineGDB.

---

## 6. Results and Output Summary  
The system successfully produced all expected outputs:

### **Student Reports**
- Displayed all enrolled courses and grades  
- Correctly computed and displayed averages  
- Properly handled cases where a student had no grades  

### **Course Reports**
- Listed all students enrolled in the course  
- Calculated course averages accurately  
- Included appropriate formatting  

### **Error Handling**
- Invalid IDs were rejected  
- The system provided clear error messages  

### **Demo Verification**
All demonstration cases behaved exactly as designed, showing that the system is robust, functional, and aligned with the project specifications.

---

## 7. Team Contributions  
| Team Member     | Responsibilities |
|-----------------|-----------------|
| **Comar Abrams** | UML diagram, documentation, GitHub setup, project planning |
| **Carlos Brown** | C++ implementation, testing, demo creation, debugging |

Both team members collaborated on design discussions and final review of the project.

---

## 8. Conclusion  
GradeBook Manager successfully demonstrates object-oriented programming techniques in C++. Through its three interacting classes, the application models real-world relationships between students, courses, and grades. The system includes interactive input, automated demonstrations, structured reports, and clean class design.

This project fulfills all requirements of CSC 138 by presenting:
- A functioning C++ application  
- Clear OOP structure  
- A complete UML diagram  
- Proper documentation  
- Test cases that validate correctness  

The program could be expanded in the future with additional features such as saving data to files, supporting letter grades, or adding menu options for editing or deleting records.

---

