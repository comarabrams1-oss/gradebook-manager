#include <iostream> 

#include <string> 

#include <map> 

#include <iomanip> 

 

class Student { 

public: 

    Student() : name(""), student_id(-1) {} 

    Student(const std::string& n, int id) : name(n), student_id(id) {} 

 

    std::string getName() const { return name; } 

    int getID() const { return student_id; } 

 

    void addGrade(int courseID, double grade) { grades[courseID] = grade; } 

 

    double getAverage() const { 

        if (grades.empty()) return -1.0; 

        double sum = 0; 

        for (auto &p : grades) sum += p.second; 

        return sum / grades.size(); 

    } 

 

    void printTranscript() const { 

        std::cout << "Transcript for " << name << " (ID " << student_id << "):\n"; 

        if (grades.empty()) { 

            std::cout << "  No grades recorded.\n"; 

            return; 

        } 

        for (auto &p : grades) { 

            std::cout << "  Course " << p.first << " : " << p.second << "\n"; 

        } 

        double avg = getAverage(); 

        if (avg >= 0) std::cout << "  Average: " << std::fixed << std::setprecision(2) << avg << "\n"; 

    } 

 

    const std::map<int,double>& getGrades() const { return grades; } 

 

private: 

    std::string name; 

    int student_id; 

    std::map<int,double> grades; 

}; 

 

class Course { 

public: 

    Course() : course_id(-1), course_name(""), credits(0) {} 

    Course(const std::string& n, int id, int c) : course_name(n), course_id(id), credits(c) {} 

 

    int getID() const { return course_id; } 

    std::string getName() const { return course_name; } 

    int getCredits() const { return credits; } 

 

    void addStudentGrade(int studentID, double grade) { studentGrades[studentID] = grade; } 

 

    double getAverage() const { 

        if (studentGrades.empty()) return -1.0; 

        double sum = 0; 

        for (auto &p : studentGrades) sum += p.second; 

        return sum / studentGrades.size(); 

    } 

 

    const std::map<int,double>& getStudentGrades() const { return studentGrades; } 

 

private: 

    std::string course_name; 

    int course_id; 

    int credits; 

    std::map<int,double> studentGrades; 

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

            std::cout << "Student ID " << studentID << " not found.\n"; 

            return; 

        } 

        it->second.printTranscript(); 

    } 

 

    void printCourseReport(int courseID) const { 

        auto it = courses.find(courseID); 

        if (it == courses.end()) { 

            std::cout << "Course ID " << courseID << " not found.\n"; 

            return; 

        } 

        const Course &c = it->second; 

        std::cout << "Course " << c.getName() << " (ID " << c.getID() << ", credits " << c.getCredits() << ")\n"; 

        if (c.getStudentGrades().empty()) { 

            std::cout << "  No grades recorded.\n"; 

            return; 

        } 

        for (auto &p : c.getStudentGrades()) { 

            std::cout << "  Student " << p.first << " : " << p.second << "\n"; 

        } 

        double avg = c.getAverage(); 

        if (avg >= 0) std::cout << "  Average: " << std::fixed << std::setprecision(2) << avg << "\n"; 

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

 

        std::cout << "=== Student Reports ===\n"; 

        gb.printStudentReport(201); 

        gb.printStudentReport(202); 

        gb.printStudentReport(203); 

 

        std::cout << "\n=== Course Reports ===\n"; 

        gb.printCourseReport(101); 

        gb.printCourseReport(102); 

 

        std::cout << "\n=== Averages ===\n"; 

        std::cout << "Alice average: " << gb.studentAverage(201) << "\n"; 

        std::cout << "Course 101 average: " << gb.courseAverage(101) << "\n"; 

 

        // Case 2: student with no grades 

        gb.addStudent(Student("Donna", 204)); 

        std::cout << "\n=== Donna (no grades) ===\n"; 

        gb.printStudentReport(204); 

 

        // Case 3: attempt invalid assignment 

        bool ok = gb.assignGrade(999, 101, 50.0); 

        std::cout << "\nAssign grade to non-existent student returned: " << (ok ? "true" : "false") << "\n"; 

    } 

 

private: 

    std::map<int, Student> students; 

    std::map<int, Course> courses; 

}; 

 

int main() { 

    std::cout << "GradeBook Manager demo running...\n\n"; 

    GradeBook::demo(); 

    return 0; 

} 
