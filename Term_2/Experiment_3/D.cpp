#include <iostream>
using namespace std; // eeee....

class Vehicle {
protected:
    string name;
    string color;
public:
    virtual void display() const = 0;
};

class Car : public Vehicle {
public:
    Car(string name, string color, int passengers);
    void display() const override;
private:
    int passengers;
};

Car::Car(string _name, string _color, int _passengers) {
    this->name = _name;
    this->color = _color;
    this->passengers = _passengers;
}

void Car::display() const {
    std::cout << "Car name:" << this->name << " Car color:" << this->color << " Car passenger:" << this->passengers << endl;
}

class Truck : public Vehicle {
public:
    Truck(string name, string color, double capacity);
    void display() const override;
private:
    double capacity;
};

Truck::Truck(string _name, string _color, double _capacity) {
    this->name = _name;
    this->color = _color;
    this->capacity = _capacity;
}

void Truck::display() const {
    std::cout << "Truck name:" << this->name << " Truck color:" << this->color << " Truck capacity:" << this->capacity << endl;
}

int main(){
  Vehicle *p;
  char type;
  char name[110], color[110];
  int pas;
  double cap;

  while (cin >> type){
    cin >> name >> color;

    if (type == 'C') {
      cin >> pas;

      Car car(name, color, pas);
      p = &car;
      p->display();
    } else if (type == 'T') {
      cin >> cap;

      Truck truck(name, color, cap);
      p = &truck;
      p->display();
    }
  }
  return 0;
}