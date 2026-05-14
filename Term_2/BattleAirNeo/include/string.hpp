#ifndef BATTLEAIRNEO_STRING_HPP
#define BATTLEAIRNEO_STRING_HPP

#pragma once
#include <ostream>
#include <istream>
#include <cstddef>

class string {
    private:
        char* str;
        std::size_t len;
    public:
        string();
        string(const char*);
        string(const string&);
        ~string();
        string& operator=(const string&);
        void set(const char*);
        [[nodiscard]] const char* getContent() const;
        [[nodiscard]] std::size_t length() const;

    friend std::ostream& operator<<(std::ostream&, const string&);
    friend std::istream& operator>>(std::istream&, string&);
    friend bool operator==(const string&, const string&);
    friend bool operator!=(const string&, const string&);
    friend string operator+(const string&, const string&);
    friend string& operator+=(string&, const string&);
};

#endif //BATTLEAIRNEO_STRING_HPP
