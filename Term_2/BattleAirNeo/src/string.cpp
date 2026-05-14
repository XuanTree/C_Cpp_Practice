#include "string.hpp"
#include <cstring>
#include <iostream>

string::string() : str(nullptr), len(0) {}

string::string(const char* s) {
    if (s == nullptr) {
        str = nullptr;
        len = 0;
        return;
    }
    len = std::strlen(s);
    str = new char[len + 1];
    std::strcpy(str, s);
}

string::string(const string& other) {
    if (other.str == nullptr) {
        str = nullptr;
        len = 0;
        return;
    }
    len = other.len;
    str = new char[len + 1];
    std::strcpy(str, other.str);
}

string::~string() {
    delete[] str;
}

string& string::operator=(const string& other) {
    if (this == &other) {
        return *this;
    }
    delete[] str;
    if (other.str == nullptr) {
        str = nullptr;
        len = 0;
        return *this;
    }
    len = other.len;
    str = new char[len + 1];
    std::strcpy(str, other.str);
    return *this;
}

void string::set(const char* s) {
    delete[] str;
    if (s == nullptr) {
        str = nullptr;
        len = 0;
        return;
    }
    len = std::strlen(s);
    str = new char[len + 1];
    std::strcpy(str, s);
}

const char* string::getContent() const {
    return str;
}

std::size_t string::length() const {
    return len;
}

std::istream& operator>>(std::istream& is, string& s) {
    char buffer[4096];
    is >> buffer;
    s.set(buffer);
    return is;
}

std::ostream& operator<<(std::ostream& os, const string& s) {
    if (s.str != nullptr) {
        os << s.str;
    }
    return os;
}

bool operator==(const string& str1, const string& str2) {
    if (str1.str == nullptr && str2.str == nullptr) return true;
    if (str1.str == nullptr || str2.str == nullptr) return false;
    return std::strcmp(str1.str, str2.str) == 0;
}

bool operator!=(const string& str1, const string& str2) {
    return !(str1 == str2);
}

string operator+(const string& lhs, const string& rhs) {
    string result;
    if (lhs.str == nullptr && rhs.str == nullptr) {
        return result;
    }
    if (lhs.str == nullptr) {
        result.set(rhs.str);
        return result;
    }
    if (rhs.str == nullptr) {
        result.set(lhs.str);
        return result;
    }
    result.len = lhs.len + rhs.len;
    result.str = new char[result.len + 1];
    std::strcpy(result.str, lhs.str);
    std::strcat(result.str, rhs.str);
    return result;
}

string& operator+=(string& lhs, const string& rhs) {
    lhs = lhs + rhs;
    return lhs;
}
