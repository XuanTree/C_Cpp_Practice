#include <iostream>
#include <list>

struct Student {
    int no;
    std::string name;
};

//! 仅提交下面的Input函数和Show函数即可！！！

void Input(std::list<Student>& li) {
    int number;
    std::cin >> number;

    for (int i = 0; i < number; i++) {
        Student s;
        std::cin >> s.no >> s.name;
        li.push_back(s);
    }
}

void Show(std::list<Student>& li) {
    for (std::list<Student>::iterator it = li.begin(); it != li.end(); it++) {
        std::cout << it->no << ", " << it->name << std::endl;
    }
}

int main() {
    std::list<Student> li;

    Input(li);

    Show(li);

    return 0;
}