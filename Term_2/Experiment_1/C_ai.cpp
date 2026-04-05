#include <iostream> // AI Assisted.
#include <cstring>
using namespace std;

class Book {
private:
    char* name;    // 书名
    char* author;  // 作者
    int sale;      // 销售量
    
public:
    // 无参构造函数
    Book() {
        name = new char[strlen("No name") + 1];
        strcpy(name, "No name");
        author = new char[strlen("No author") + 1];
        strcpy(author, "No author");
        sale = 0;
    }
    
    // 有参构造函数
    Book(const char* n, const char* a, int s) {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
        author = new char[strlen(a) + 1];
        strcpy(author, a);
        sale = s;
    }
    
    // 拷贝构造函数
    Book(const Book& other) {
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
        author = new char[strlen(other.author) + 1];
        strcpy(author, other.author);
        sale = other.sale;
    }
    
    // 打印函数
    void print() const {
        cout << "Name: " << name << "\tAuthor: " << author << "\tSale: " << sale << endl;
    }
    
    // 析构函数
    ~Book() {
        delete[] name;
        delete[] author;
    }
};

int main() {
    char name[101], author[101];
    int sale;
    
    // 读取输入
    cin.getline(name, 101);
    cin.getline(author, 101);
    cin >> sale;
    
    // 根据输入值选择构造函数
    if (strcmp(name, "-1") == 0 && strcmp(author, "-1") == 0 && sale == -1) {
        // 无参构造函数
        Book book;
        book.print();
    } 
    else if (strcmp(name, "0") == 0 && strcmp(author, "0") == 0 && sale == 0) {
        // 拷贝构造函数
        Book book1;  // 先创建一个默认对象
        Book book2(book1);  // 用拷贝构造函数创建book2
        book2.print();
    } 
    else {
        // 有参构造函数
        Book book(name, author, sale);
        book.print();
    }
    
    return 0;
}