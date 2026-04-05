#include <iostream>
#include <string>

class Hotel {
private:
    std::string name;
    int id;
    static int total;
public:
    Hotel() : id(0) {}
    void add(std::string n) {
        name = n;
        total++;
        id = total;
    }
    std::string getName() const {
        return name;
    }
    void print() const {
        std::cout << id << " " << name << " " << total << std::endl;
    }
    static int getTotal() {
        return total;
    }
};

int Hotel::total = 0;

int main() {
    Hotel h[100];
    h[0].add("Susan");
    h[1].add("Peter");
    h[2].add("John");
    h[3].add("Mary");
    h[4].add("Alice");

    std::string name;
    std::cin >> name;

    for (int i = 0; i < Hotel::getTotal(); i++) {
        if (h[i].getName() == name) {
            h[i].print();
            break;
        }
    }

    return 0;
}