#include "STL.h"

std::ostream& operator<<(std::ostream& os, const Student& student) {
    for (const auto& pair : student.student_map) {
        os << pair.first << ": " << pair.second << std::endl;
    }
    return os;
}

std::istream& operator>>(std::istream& is, Student& student) {
    std::string name;
    int level;
    is >> name >> level;
    student.student_map[name] = level;
    return is;
}

void Student::InitStudent(std::string& name, int& i) {
    student_map[name] = i;
}

void Student::showMap() const {
    for (const auto& pair : student_map) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
}

void School::showStudents() const {
    // 输出所有学生的key和value
    for (const Student& stu : students) {
        stu.showMap();
        std::cout << "----------" << std::endl;
    }
}
