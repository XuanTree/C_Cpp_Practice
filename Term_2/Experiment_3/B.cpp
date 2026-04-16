#include <iostream>

class Person {
protected:
    std::string name;
    std::string id;
public:
    virtual void input();
    virtual void display() const;
};

void Person::input() {
    std::cin >> this->name;
}

void Person::display() const{
    std::cout << this->name << std::endl;
}

class Student : public Person{
public:
    void input() override;
    void display() const override;
};

void Student::input() {
    std::cin >> this->id >> this->name;
};

void Student::display() const {
    std::cout << this->id << " " << this->name << std::endl;
}

int main(){
    Person * p;
    p = new Person;
    p->input();
    p->display();
    delete p;

    p = new Student;
    p->input();
    p->display();
    delete p;

    return 0;
}
