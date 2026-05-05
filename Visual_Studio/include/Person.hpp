#pragma once
#include <string>

class Person {
protected:
	std::string name;
	int age = -1;
	std::string job;
public:
	virtual ~Person() = default;

	Person() = default;
	inline Person(const std::string &_name, int age, const std::string &job)
		: name(_name), age(age), job(job) {}
	virtual void PrintMessages() const = 0;
	virtual void ChangeTheJob(std::string new_job) = 0;
};
