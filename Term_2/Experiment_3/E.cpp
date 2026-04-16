#include <cmath>
#include <iostream>
using namespace std;

class Shape {
public:
  Shape() {}

  virtual double area() = 0;

  virtual void input() = 0;

  virtual double volume() = 0;

  virtual ~Shape() {}
};

class Cylinder : public Shape {
public:
    Cylinder() {};
    void input() override;
    double area() override;
    double volume() override;
private:
    const double pi = acos(-1);
    double r;
    double h;
};

void Cylinder::input() {
    cin >> this->r >> this->h;
}

double Cylinder::area() {
    return (this->pi * this->r * this->r) * 2 + (2 * this->pi * this->r * h);
}

double Cylinder::volume() {
    return (this->pi * this->r * this->r) * this->h;
}

class Cuboid : public Shape {
public:
    Cuboid() {};
    void input() override;
    double area() override;
    double volume() override;
private:
    double l;
    double w;
    double h;
};

void Cuboid::input() {
    cin >> this->l >> this->w >> this->h;
}

double Cuboid::area() {
    return (this->l * this->w * 2) + (this->l * this->h * 2) + (this->w * this->h * 2);
}

double Cuboid::volume() {
    return (this->l * this->w * this->h);
}

class Ball : public Shape {
public:
    Ball() {};
    void input() override;
    double area() override;
    double volume() override;
private:
    const double pi = acos(-1);
    double r;
};

void Ball::input() {
    cin >> this->r;
}

double Ball::area() {
    return (4 * this->pi * r * r);
}

double Ball::volume() {
    return (4./3. * this->pi * this->r * this->r * this->r);
}

void work(Shape *s) {
  s->input();

  cout << s->area() << " " << s->volume() << endl;

  delete s;
}

int main() {
  char c;

  while (cin >> c) {
    switch (c) {
    case 'y':
      work(new Cylinder());
      break;
    case 'c':
      work(new Cuboid());
      break;
    case 'q':
      work(new Ball());
      break;
    default:
      break;
    }
  }
  return 0;
}
