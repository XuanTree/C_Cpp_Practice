#include <iostream>
#include "Student.hpp"

Student::Student(const std::string& _name, int _age, const std::string& _job)
	: Person(_name, _age, _job) {}

void Student::PrintMessages() const {
	std::cout << "The " << this->job << " is " << this->name << " and " << this->age
		<< " years old." << std::endl;
}

void Student::ChangeTheJob(std::string new_job) {
	this->job = std::move(new_job);
}

void Student::SayHi() const {
	std::cout << this->name << " says Hi~. " << std::endl;
}
