#include <cstddef>
#include <cstring>
#include <iostream>

class Str{
private:
    char* p;
public:
    Str(const char* s);
    ~Str();

    void operate(const char* s, int n);
    void show() const;
};

Str::Str(const char* _s) {
    p = new char[strlen(_s) + 1];
    strcpy(p, _s);
}

Str::~Str() {
    delete[] p;
}

void Str::operate(const char* _s, int _n) {
    // 步骤1: 反转字符串 _s
    size_t len_s = strlen(_s);
    char* reversedChar = new char[len_s + 1];

    size_t origin = strlen(p);

    for (size_t i = 0; i < len_s; i++) {
        reversedChar[i] = _s[len_s - 1 - i];
    }
    reversedChar[len_s] = '\0';

    // 步骤2: 从反转后的字符串中，从第 _n 个字符开始截取到末尾
    // 注意: 如果 _n 大于等于字符串长度，结果为空字符串
    size_t resultLen;
    if (_n >= static_cast<int>(len_s)) {
        resultLen = 0;
    } else {
        resultLen = len_s - _n;
    }

    p = new char[resultLen + 1]();

    for (size_t i = origin - 1; i < resultLen; i++) {
        p[i] = reversedChar[_n + i];
    }
    p[resultLen] = '\0';

    delete[] reversedChar;
}

void Str::show() const {
    for (size_t i = 0; i < strlen(p); i++) {
        std::cout << p[i] << " " ;
    }

    std::cout << "\n";
}

int main() {
    char string1[20] = "Hello World!";
    char string2[20] = "Test For Cpp!";

    int n = 4;

    Str str1(string1);

    str1.operate(string2, n);

    str1.show();

    return 0;
}
