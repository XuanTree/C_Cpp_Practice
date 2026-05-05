#pragma once
#include <string>

#include "Person.hpp"

class Student : public Person {
public:
	Student() = default;
	Student(const std::string& _name, int _age, const std::string& _job = "Student");
	void PrintMessages() const override;
	void ChangeTheJob(std::string new_job) override;
	void SayHi() const;
};