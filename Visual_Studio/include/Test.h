#pragma once

#include <iostream>
class Child {
private:
	int age;
public:
	Child() {}
	Child(int age) : age(age) {}

	const int& getAge() const;
	void setAge(int new_age);
};
class Test {
private:
	int variable;
	std::string TestName;
	double time;
	Child child;
public:
	Test() {}
	Test(int var, std::string name, double testTime) : variable(var), TestName(name), time(testTime) {}
	
	const int& getVariable() const;
	const std::string& getTestName() const;
	const double& getTime() const;
};