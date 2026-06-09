#pragma once

#include <iostream>
#include <vector>
#include <ostream>
#include <istream>
#include <unordered_map>

class Student {
private:
	std::unordered_map<std::string, int> student_map;
public:
	Student() {}
	Student(std::string& name, int& level) {
		student_map[name] = level;
	}

	friend class School;

	friend std::ostream& operator<< (std::ostream& os, const Student& student);
	friend std::istream& operator>> (std::istream& is, Student& student);

	void InitStudent(std::string& name, int& i);
	void showMap() const;
};


class School {
public:
	std::vector<Student> students;

	School() {}
	School(Student& student) {
		students.push_back(student);
	}

	void showStudents() const;
};