#include <iostream>
#include <string>

class Date {
    private:
        int Date_year;
        int Date_month;
        int Date_day;
    public:
        Date(int year = 2000,int month = 1,int day = 1);
        void show() const;
};

class Croster {
    private:
        std::string name;
        Date birthday;
    public: 
        Croster();
        Croster(std::string name, int year, int month, int day);
        Croster(std::string name, Date date);
        void show() const;

};

Date::Date(int _year,int _month,int _day) {
    this->Date_month = _month;
    this->Date_year = _year;
    this->Date_day = _day;
}

Croster::Croster() {
    this->name = "NULL";
    this->birthday = Date(0,0,0);
}

Croster::Croster(std::string _name, int _year, int _month, int _day) {
    this->name = _name;
    this->birthday = Date(_year, _month, _day);
}

Croster::Croster(std::string _name, Date date) {
    this->name = _name;
    this->birthday = date;
}

void Date::show() const {
    std::cout << this->Date_year << "-" << this->Date_month << "-" << this->Date_day 
        << std::endl;
}

void Croster::show() const {
    std::cout << "Name: " << this->name << ", " << "Birthday: ";
    this->birthday.show();
    std::cout << std::endl;
}
int main () {
    int choice;
    while (std::cin >> choice) {
        if (choice == 0) {
            Croster cro = Croster();
            cro.show();
        } else if (choice == 1) {
            std::string name;std::cin >> name;
            int year, month, day;
            std::cin >> year >> month >> day;
            Croster cro = Croster(name,year,month,day);
            cro.show();
        } else if (choice == 2) {
            std::string name;std::cin >> name;
            int year, month, day;
            std::cin >> year >> month >> day;
            Date date = Date(year, month, day);
            Croster cro = Croster(name,date);
            cro.show();
        } else {
            break;
        }
    }
    return 0;
}