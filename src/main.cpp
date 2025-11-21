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
 

class Student { 

public: 

    Student() : name(""), student_id(-1) {} 

    Student(const string& n, int id) : name(n), student_id(id) {} 

 

    string getName() const { return name; } 

    int getID() const { return student_id; } 
  
 

    void addGrade(int courseID, double grade) { grades[courseID] = grade; } 

 

    double getAverage() const { 

        if (grades.empty()) return -1.0; 

        double sum = 0; 

        for (auto &p : grades) sum += p.second; 

        return sum / grades.size(); 

    } 

 

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

        if (avg >= 0) cout << "  Average: " << fixed << setprecision(2) << avg << "\n"; 

    } 

 

    const map<int,double>& getGrades() const { return grades; } 

 

private: 

    string name; 

    int student_id; 

    map<int,double> grades; 

}; 

 

class Course { 

public: 

    Course() : course_id(-1), course_name(""), credits(0) {} 

    Course(const string& n, int id, int c) : course_name(n), course_id(id), credits(c) {} 

 

    int getID() const { return course_id; } 

    string getName() const { return course_name; } 

    int getCredits() const { return credits; } 

 

    void addStudentGrade(int studentID, double grade) { studentGrades[studentID] = grade; } 

 

    double getAverage() const { 

        if (studentGrades.empty()) return -1.0; 

        double sum = 0; 

        for (auto &p : studentGrades) sum += p.second; 

        return sum / studentGrades.size(); 

    } 

 

    const map<int,double>& getStudentGrades() const { return studentGrades; } 

 

private: 

    string course_name; 

    int course_id; 

    int credits; 

    map<int,double> studentGrades; 

}; 

 

class GradeBook { 

public: 

    bool addStudent(const Student& s) { 

        int id = s.getID(); 

        if (students.count(id)) return false; 

        students[id] = s; 

        return true; 

    } 

 

    bool addCourse(const Course& c) { 

        int id = c.getID(); 

        if (courses.count(id)) return false; 

        courses[id] = c; 

        return true; 

    } 

 

    bool assignGrade(int studentID, int courseID, double grade) { 

        if (!students.count(studentID) || !courses.count(courseID)) return false; 

        students[studentID].addGrade(courseID, grade); 

        courses[courseID].addStudentGrade(studentID, grade); 

        return true; 

    } 

 

    double studentAverage(int studentID) const { 

        auto it = students.find(studentID); 

        if (it == students.end()) return -1.0; 

        return it->second.getAverage(); 

    } 

 

    double courseAverage(int courseID) const { 

        auto it = courses.find(courseID); 

        if (it == courses.end()) return -1.0; 

        return it->second.getAverage(); 

    } 

 

    void printStudentReport(int studentID) const { 

        auto it = students.find(studentID); 

        if (it == students.end()) { 

            cout << "Student ID " << studentID << " not found.\n"; 

            return; 

        } 

        it->second.printTranscript(); 

    } 

 

    void printCourseReport(int courseID) const { 

        auto it = courses.find(courseID); 

        if (it == courses.end()) { 

            cout << "Course ID " << courseID << " not found.\n"; 

            return; 

        } 

        const Course &c = it->second; 

        cout << "Course " << c.getName() << " (ID " << c.getID() << ", credits " << c.getCredits() << ")\n"; 

        if (c.getStudentGrades().empty()) { 

            cout << "  No grades recorded.\n"; 

            return; 

        } 

        for (auto &p : c.getStudentGrades()) { 

            cout << "  Student " << p.first << " : " << p.second << "\n"; 

        } 

        double avg = c.getAverage(); 

        if (avg >= 0) cout << "  Average: " << fixed << setprecision(2) << avg << "\n"; 

    } 

 

    // Demo that shows several cases 

    static void demo() { 

        GradeBook gb; 

        // Add courses 

        gb.addCourse(Course("Intro to Security", 101, 3)); 

        gb.addCourse(Course("Data Structures", 102, 4)); 

        // Add students 

        gb.addStudent(Student("Alice", 201)); 

        gb.addStudent(Student("Bob", 202)); 

        gb.addStudent(Student("Carlos", 203)); 

 

        // Assign grades - case 1: multiple students multiple courses 

        gb.assignGrade(201, 101, 92.5); 

        gb.assignGrade(201, 102, 88.0); 

        gb.assignGrade(202, 101, 75.0); 

        gb.assignGrade(202, 102, 80.0); 

        gb.assignGrade(203, 101, 100.0); 

 

        cout << "=== Student Reports ===\n"; 

        gb.printStudentReport(201); 

        gb.printStudentReport(202); 

        gb.printStudentReport(203); 

 

        cout << "\n=== Course Reports ===\n"; 

        gb.printCourseReport(101); 

        gb.printCourseReport(102); 

 

        cout << "\n=== Averages ===\n"; 

        cout << "Alice average: " << gb.studentAverage(201) << "\n"; 

        cout << "Course 101 average: " << gb.courseAverage(101) << "\n"; 

 

        // Case 2: student with no grades 

        gb.addStudent(Student("Donna", 204)); 

        cout << "\n=== Donna (no grades) ===\n"; 

        gb.printStudentReport(204); 

 

        // Case 3: attempt invalid assignment 

        bool ok = gb.assignGrade(999, 101, 50.0); 

        cout << "\nAssign grade to non-existent student returned: " << (ok ? "true" : "false") << "\n"; 

    } 

 

private: 

    map<int, Student> students; 

    map<int, Course> courses; 

}; 

 

int main() { 
    cout << "GradeBook Manager demo running...\n\n";

    GradeBook gb;
    gb.addCourse(Course("Intro to Security", 101, 3));
    gb.addCourse(Course("Data Structures", 102, 4));

    string name;
    int studentID;
    int courseID;
    double grade;

    cout << "Enter student's name: ";
    getline(cin >> ws, name);

    cout << "Enter student ID: ";
    cin >> studentID;

    cout << "Enter course number (101 or 102): ";
    cin >> courseID;

    cout << "Enter grade (0-100): ";
    cin >> grade;

    gb.addStudent(Student(name, studentID));

    if (gb.assignGrade(studentID, courseID, grade)) {
        cout << "\nStudent Report After Input\n";
        gb.printStudentReport(studentID);
    } else {
        cout << "Invalid student or course ID. Grade not assigned.\n";
    }

    cout << "\nDemo Cases\n";
    GradeBook::demo();

    return 0;
}
