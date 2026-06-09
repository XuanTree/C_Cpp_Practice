#include "../include/Test.h"

// Child class

const int &Child::getAge() const { return this->age; }
void Child::setAge(int new_age) { age = new_age; }

// Test class

const int &Test::getVariable() const { return this->variable; }
const std::string &Test::getTestName() const { return this->TestName; }
const double &Test::getTime() const { return this->time; }

// Document class

std::string Document::getText() const { return this->text; }
