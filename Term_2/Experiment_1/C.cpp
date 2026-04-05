#include <iostream>
#include <string>

class Book {
    private: 
        std::string name;
        std::string author;
        int sale;
    public:
        Book();
        Book(std::string, std::string, int);
        Book(const Book&);
        void print() const;
        ~Book();
};

Book::Book() {
    this->name = "No name";
    this->author = "No author";
    this->sale = 0;
}

Book::Book(std::string _name, std::string _author, int _sale) 
    : name(_name), 
     author(_author), 
     sale(_sale) {}

Book::Book(const Book&) {}

void Book::print() const {
    std::cout << "Name: " << this->name << "\t" << 
        "Author: " << this->author << "\t" << "Sale: " 
        << this->sale << "\n";
}

Book::~Book() {
    
}

int main () {
    std::string name;
    std::string author;
    int sale;

    std::getline(std::cin,name);
    std::getline(std::cin,author);
    std::cin >> sale;

    if (name == "-1" && author == "-1" && sale == -1) {
        Book b1 = Book();
        b1.print();
    } else if (name == "0" && author == "0" && sale == 0) {
        Book b1 = Book();
        Book b2 = Book(b1);
        b2.print();
    } else {
        Book b1 = Book(name, author, sale);
        b1.print();
    }
    return 0;
}