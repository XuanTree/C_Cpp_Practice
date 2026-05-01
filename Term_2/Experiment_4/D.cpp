#include <iostream>
#include <string.h>

using namespace std;

class String {
private:
  char *s;
public:
  String();
  String(const char *);
  String(const String &);
  ~String();
  String &operator=(const char *);
  String &operator=(const String &);
  String operator+(const char *);
  String operator+(const String &);
  String &operator+=(const char *);
  String &operator+=(const String &);
  friend istream &operator>>(istream &, String &);
  friend ostream &operator<<(ostream &, const String &);
  friend bool operator==(const String &, const char *);
  friend bool operator==(const String &, const String &);
  friend bool operator!=(const String &, const char *);
  friend bool operator!=(const String &, const String &);
};

String::String() {
  s = new char[1];
  s[0] = '\0';
}

String::String(const char *str) {
  int len = strlen(str);
  s = new char[len + 1];
  strcpy(s, str);
}

String::String(const String &str) {
  int len = strlen(str.s);
  s = new char[len + 1];
  strcpy(s, str.s);
}

String::~String() {
    delete[] s;
}

String &String::operator=(const char *str) {
    if (s!= NULL) {
    delete[] s;
  }
  int len = strlen(str);
  s = new char[len + 1];
  strcpy(s, str);
  return *this;
}

String &String::operator=(const String &str) {
  if (s!= NULL) {
    delete[] s;
  }
  int len = strlen(str.s);
  s = new char[len + 1];
  strcpy(s, str.s);
  return *this;
}

String String::operator+(const char *str) {
  int len1 = strlen(s);
  int len2 = strlen(str);
  char *new_s = new char[len1 + len2 + 1];
  strcpy(new_s, s);
  strcat(new_s, str);
  String result(new_s);
  delete[] new_s;
  return result;
}

String String::operator+(const String &str) {
  int len1 = strlen(s);
  int len2 = strlen(str.s);
  char *new_s = new char[len1 + len2 + 1];
  strcpy(new_s, s);
  strcat(new_s, str.s);
  String result(new_s);
  delete[] new_s;
  return result;
}

String &String::operator+=(const char *str) {
  int len1 = strlen(s);
  int len2 = strlen(str);
  char *new_s = new char[len1 + len2 + 1];
  strcpy(new_s, s);
  strcat(new_s, str);
  delete[] s;
  s = new_s;
  return *this;
}

String &String::operator+=(const String &str) {
  int len1 = strlen(s);
  int len2 = strlen(str.s);
  char *new_s = new char[len1 + len2 + 1];
  strcpy(new_s, s);
  strcat(new_s, str.s);
  delete[] s;
  s = new_s;
  return *this;
}

istream &operator>>(istream &is, String &str) {
  char c;
  int len = 0;
  while (is.get(c)) {
    if (c == '\n') {
      break;
    }
    len++;
  }
  char *new_s = new char[len + 1];
  is.clear();
  is.seekg(0, ios::beg);
  is.get(new_s, len + 1);
  str = String(new_s);
  delete[] new_s;
  return is;
}

ostream &operator<<(ostream &os, const String &str) {
  os << str.s;
  return os;
}

bool operator==(const String &str1, const char *str2) {
  return strcmp(str1.s, str2) == 0;
}

bool operator==(const String &str1, const String &str2) {
  return strcmp(str1.s, str2.s) == 0;
}

bool operator!=(const String &str1, const char *str2) {
  return strcmp(str1.s, str2)!= 0;
}

bool operator!=(const String &str1, const String &str2) {
  return strcmp(str1.s, str2.s)!= 0;
}

int main() {
  String s;
  s += "hello";
  cout << s << endl;
  String s1("String1");
  String s2("copy of ");
  s2 += "String1";
  cout << s1 << "\n" << s2 << endl;
  String s3;
  cin >> s3;
  cout << s3 << endl;
  String s4("String4"), s5(s4);
  cout << (s5 == s4) << endl;
  cout << (s5 != s4) << endl;
  String s6("End of "), s7("my string.");
  s6 += s7;
  cout << s6 << endl;
  return 0;
}