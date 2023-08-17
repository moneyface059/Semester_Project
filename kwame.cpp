#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

class Course {
private:
    std::string courseName;
    double credits;
    double gradePoints;

public:
    Course(std::string name, double creds, double points) {
        courseName = name;
        credits = creds;
        gradePoints = points;
    }

    double getCredits() const {
        return credits;
    }

    double getGradePoints() const {
        return gradePoints;
    }

    std::string getCourseName() const {
        return courseName;
    }
};

class Student {
private:
    std::string name;
    int numCourses;
    std::vector<Course> courses;

public:
    Student(std::string studentName) {
        name = studentName;
        numCourses = 0;
    }

    void addCourse(std::string courseName, double credits, double gradePoints) {
        courses.push_back(Course(courseName, credits, gradePoints));
        numCourses++;
    }

    double calculateCGPA() {
        double totalCredits = 0.0;
        double totalGradePoints = 0.0;

        for (int i = 0; i < numCourses; ++i) {
            totalCredits += courses[i].getCredits();
            totalGradePoints += courses[i].getCredits() * courses[i].getGradePoints();
        }

        if (totalCredits > 0) {
            return totalGradePoints / totalCredits;
        } else {
            return 0.0; // Return 0.0 for invalid input
        }
    }

    void displayCourses() {
        std::cout << "Courses and Grades for " << name << std::endl;
        for (int i = 0; i < numCourses; ++i) {
            std::cout << courses[i].getCourseName() << " - " << courses[i].getGradePoints() << std::endl;
        }
    }
};

int main() {
    std::string studentName;
    std::cout << "Enter student's name: ";
    std::cin >> studentName;

    Student student(studentName);

    int numCourses;
    std::cout << "Enter the number of courses: ";
    std::cin >> numCourses;

    for (int i = 0; i < numCourses; ++i) {
        std::string courseName;
        double credits, gradePoints;

        std::cout << "Enter course name: ";
        std::cin >> courseName;

        std::cout << "Enter credits for " << courseName << ": ";
        std::cin >> credits;

        std::cout << "Enter grade points for " << courseName << ": ";
        std::cin >> gradePoints;

        student.addCourse(courseName, credits, gradePoints);
    }

    student.displayCourses();
    double cgpa = student.calculateCGPA();

    if (cgpa > 0) {
        std::cout << "Cumulative Grade Point Average (CGPA): " << std::fixed << std::setprecision(2) << cgpa << std::endl;
    } else {
        std::cout << "Invalid input. Total credits cannot be zero." << std::endl;
    }
return 0;
}
