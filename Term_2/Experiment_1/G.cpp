// 本题不需要提交main函数
#include <iostream>
#include <string>

//! 本题想要通过需要加下面这句话 
using namespace std;

class TestConstClass {
    private:
        std::string text;
    public:
        std::string get() const;
        void set(const std::string& temp);
};

std::string TestConstClass::get() const{
    return text;
}

void TestConstClass::set(const std::string& temp){
    text = temp;
}

void print (const TestConstClass & tcs) {
    std::cout << tcs.get() << '\n';
}

// int main() {
//     std::string tmp;
//     TestConstClass tcs;

//     while(std::cin>>tmp){
//         tcs.set(tmp);
//         print(tcs);
//     }

//     return 0;
// }