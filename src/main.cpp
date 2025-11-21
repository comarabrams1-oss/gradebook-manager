/* 
Gradebook Manager
Nov 25, 2025
Comar Abrams & Carlos Brown
*/

#include <iostream>
#include <string>
#include <map>
#include <iomanip>

using namespace std;

/*
  Student Class
  - Represents a single student.
  - Stores student name, ID, and a map of course grades.
*/
class Student {

public:
    // Default constructor: creates an empty student
    Student() : name(""), student_id(-1) {}

    // Parameterized constructor: creates a student with name and ID
    Student(const string& n, int id) : name(n), student_id(id) {}

    // Returns the student's name
    string getName() const { return name; }

    // Returns the student's ID
    int getID() const { return student_id; }

    /*
      addGrade
      - Adds or updates a grade for a course.
      - courseID is the key, grade is the value.
    */
    void addGrade(int courseID, double grade) { 
        grades[courseID] = grade; 
    }

    /*
      getAverage
      - Computes the average grade for this student.
      - Returns -1.0 if the student has no grades.
    */
    double getAverage() const {
        if (grades.empty()) return -1.0;

        double sum = 0;
        for (auto &p : grades) sum += p.second;

        return sum / grades.size();
    }

    /*
      printTranscript
      - Prints all course grades for this student.
      - Also prints the student's average.
      - If there are no grades, prints a message.
    */
    void printTranscript() const {
        cout << "Transcript for " << name << " (ID " << student_id << "):\n";

        if (grades.empty()) {
            cout << "  No grades recorded.\n";
            return;
        }

        for (auto &p : grades) {
            cout << "  Course " << p.first << " : " << p.second << "\n";
        }

        double avg = getAverage();
        if (avg >= 0) 
            cout << "  Average: " << fixed << setprecision(2) << avg << "\n";
    }

    // Returns the entire grades map (used by GradeBook if needed)
    const map<int,double>& getGrades() const { return grades; }

private:
    string name;                  // Student's name
    int student_id;               // Unique student ID
    map<int,double> grades;       // Map of courseID -> grade
};


/*
  Course Class
  - Represents one course.
  - Stores course details and grades for students enrolled.
*/
class Course {

public:
    // Default constructor: empty course
    Course() : course_id(-1), course_name(""), credits(0) {}

    // Parameterized constructor: sets course name, ID, and credit hours
    Course(const string& n, int id, int c) 
        : course_name(n), course_id(id), credits(c) {}

    // Returns course ID
    int getID() const { return course_id; }

    // Returns course name
    string getName() const { return course_name; }

    // Returns credit hours
    int getCredits() const { return credits; }

    /*
      addStudentGrade
      - Adds or updates a student's grade in this course.
      - studentID is key, grade is value.
    */
    void addStudentGrade(int studentID, double grade) { 
        studentGrades[studentID] = grade; 
    }

    /*
      getAverage
      - Computes average grade of all students in this course.
      - Returns -1.0 if no grades exist.
    */
    double getAverage() const {
        if (studentGrades.empty()) return -1.0;

        double sum = 0;
        for (auto &p : studentGrades) sum += p.second;

        return sum / studentGrades.size();
    }

    // Returns full map of student grades (used in course report)
    const map<int,double>& getStudentGrades() const { return studentGrades; }

private:
    string course_name;                 // Course title
    int course_id;                      // Unique course ID
    int credits;                        // Credit hours
    map<int,double> studentGrades;      // Map of studentID -> grade
};


/*
  GradeBook Class
  - Central controller class.
  - Stores all students and courses.
  - Assigns grades and prints reports.
*/
class GradeBook {

public:
    /*
      addStudent
      - Adds a student to the system.
      - Returns false if the ID already exists.
    */
    bool addStudent(const Student& s) {
        int id = s.getID();
        if (students.count(id)) return false;

        students[id] = s;
        return true;
    }

    /*
      addCourse
      - Adds a course to the system.
      - Returns false if course ID already exists.
    */
    bool addCourse(const Course& c) {
        int id = c.getID();
        if (courses.count(id)) return false;

        courses[id] = c;
        return true;
    }

    /*
      assignGrade
      - Assigns a grade to a student in a course.
      - Updates BOTH Student and Course objects.
      - Returns false if either ID doesn't exist.
    */
    bool assignGrade(int studentID, int courseID, double grade) {
        if (!students.count(studentID) || !courses.count(courseID)) return false;

        students[studentID].addGrade(courseID, grade);
        courses[courseID].addStudentGrade(studentID, grade);

        return true;
    }

    /*
      studentAverage
      - Returns the average grade for a student.
      - Returns -1.0 if student ID doesn't exist.
    */
    double studentAverage(int studentID) const {
        auto it = students.find(studentID);
        if (it == students.end()) return -1.0;

        return it->second.getAverage();
    }

    /*
      courseAverage
      - Returns the average grade for a course.
      - Returns -1.0 if course ID doesn't exist.
    */
    double courseAverage(int courseID) const {
        auto it = courses.find(courseID);
        if (it == courses.end()) return -1.0;

        return it->second.getAverage();
    }

    /*
      printStudentReport
      - Prints transcript for a specific student.
      - If student doesn't exist, prints error.
    */
    void printStudentReport(int studentID) const {
        auto it = students.find(studentID);
        if (it == students.end()) {
            cout << "Student ID " << studentID << " not found.\n";
            return;
        }

        it->second.printTranscript();
    }

    /*
      printCourseReport
      - Prints all student grades for a course.
      - Also prints course average.
      - If course doesn't exist, prints error.
    */
    void printCourseReport(int courseID) const {
        auto it = courses.find(courseID);
        if (it == courses.end()) {
            cout << "Course ID " << courseID << " not found.\n";
            return;
        }

        const Course &c = it->second;
        cout << "Course " << c.getName() 
             << " (ID " << c.getID() 
             << ", credits " << c.getCredits() << ")\n";

        if (c.getStudentGrades().empty()) {
            cout << "  No grades recorded.\n";
            return;
        }

        for (auto &p : c.getStudentGrades()) {
            cout << "  Student " << p.first << " : " << p.second << "\n";
        }

        double avg = c.getAverage();
        if (avg >= 0) 
            cout << "  Average: " << fixed << setprecision(2) << avg << "\n";
    }

    /*
      demo
      - Runs all required test cases automatically.
      - Shows normal operation, empty student, and invalid operations.
    */
    static void demo() {
        GradeBook gb;

        // Add default courses
        gb.addCourse(Course("Intro to Security", 101, 3));
        gb.addCourse(Course("Data Structures", 102, 4));

        // Add sample students
        gb.addStudent(Student("Alice", 201));
        gb.addStudent(Student("Bob", 202));
        gb.addStudent(Student("Carlos", 203));

        // Assign sample grades
        gb.assignGrade(201, 101, 92.5);
        gb.assignGrade(201, 102, 88.0);
        gb.assignGrade(202, 101, 75.0);
        gb.assignGrade(202, 102, 80.0);
        gb.assignGrade(203, 101, 100.0);

        // Print reports
        cout << "=== Student Reports ===\n";
        gb.printStudentReport(201);
        gb.printStudentReport(202);
        gb.printStudentReport(203);

        cout << "\n=== Course Reports ===\n";
        gb.printCourseReport(101);
        gb.printCourseReport(102);

        // Print averages
        cout << "\n=== Averages ===\n";
        cout << "Alice average: " << gb.studentAverage(201) << "\n";
        cout << "Course 101 average: " << gb.courseAverage(101) << "\n";

        // Test: student with no grades
        gb.addStudent(Student("Donna", 204));
        cout << "\n=== Donna (no grades) ===\n";
        gb.printStudentReport(204);

        // Test: invalid assignment
        bool ok = gb.assignGrade(999, 101, 50.0);
        cout << "\nAssign grade to non-existent student returned: " 
             << (ok ? "true" : "false") << "\n";
    }

private:
    map<int, Student> students;   // Stores all students by ID
    map<int, Course> courses;     // Stores all courses by ID
};


/*
  main
  - Provides a simple menu for user interaction.
  - Lets user add students and assign grades.
  - Runs automated demo after menu ends.
*/
int main() {
    cout << "GradeBook Manager running...\n\n";

    GradeBook gb;

    // Preloaded courses so user can assign grades immediately
    gb.addCourse(Course("Intro to Security", 101, 3));
    gb.addCourse(Course("Data Structures", 102, 4));

    int choice = 0;

    while (true) {
        cout << "\n=== MENU ===\n";
        cout << "1. Add a new student\n";
        cout << "2. Assign a grade to a student\n";
        cout << "3. Print a student report\n";
        cout << "4. Print a course report\n";
        cout << "5. Exit input section and run demo\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            string name;
            int id;

            cout << "Enter student name: ";
            getline(cin >> ws, name);

            cout << "Enter student ID: ";
            cin >> id;

            if (gb.addStudent(Student(name, id)))
                cout << "Student added.\n";
            else
                cout << "Student ID already exists.\n";
        }

        else if (choice == 2) {
            int sid, cid;
            double grade;

            cout << "Enter student ID: ";
            cin >> sid;

            cout << "Enter course ID: ";
            cin >> cid;

            cout << "Enter grade (0–100): ";
            cin >> grade;

            if (gb.assignGrade(sid, cid, grade))
                cout << "Grade assigned.\n";
            else
                cout << "Invalid student or course ID.\n";
        }

        else if (choice == 3) {
            int sid;
            cout << "Enter student ID: ";
            cin >> sid;
            gb.printStudentReport(sid);
        }

        else if (choice == 4) {
            int cid;
            cout << "Enter course ID: ";
            cin >> cid;
            gb.printCourseReport(cid);
        }

        else if (choice == 5) {
            cout << "\nExiting input section...\n";
            break;
        }

        else {
            cout << "Invalid choice. Try again.\n";
        }
    }

    cout << "\n=== Demo Cases ===\n";
    GradeBook::demo();

    return 0;
}
