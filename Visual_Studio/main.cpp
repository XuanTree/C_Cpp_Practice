#include "include/STL.h"
#include "include/templates.h"
#include "include/Operators.h"
#include <iostream>

static void SplitContext() {
  std::cout << "===================================================="
            << std::endl;
}

int main(int, char **) {

  int a = 20;
  int b = 10;

  // 函数模板交换地址设计
  Swap(a, b);
  std::cout << a << " " << b << std::endl;

  SplitContext();

  // 简单计算器设计
  SimpleCalculator<double, double> simplecalculator(12, 24);

  simplecalculator.Plus();
  simplecalculator.Minus();
  simplecalculator.Multiply();
  simplecalculator.Devide();

  SplitContext();

  // 学校类与学生类设计
  School school;
  Student _students[3];

  std::string name;
  int level;

  for (Student &stu : _students) {
    std::cin >> name >> level;
    stu.InitStudent(name, level);
  }

  for (int i = 0; i < 3; i++) {
    school.students.push_back(_students[i]);
  }

  SplitContext();

  school.showStudents();

  SplitContext();

  // 运算符重载复数的计算
  Complex complex1(1, 2);
  Complex complex2(2, -2);
  Complex complex3;

  std::cin >> complex3;

  std::cout << "The result is: " << complex1 + complex2;

  std::cout << "The result is: " << complex3 - complex2;

  return 0;
}
