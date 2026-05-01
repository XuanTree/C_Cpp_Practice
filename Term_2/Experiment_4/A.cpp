#include <iostream>
#include <ostream>

using namespace std;

class Singer {
private:
  string name;
  char gender;
  int age;
public:
  double score;
  Singer() {};
  
  friend istream& operator>>(istream &is, Singer &s);
  friend ostream& operator<<(ostream &os, const Singer &s); 
  bool operator>(Singer &s) { return this->score > s.score; }
  bool operator==(Singer &s) { return this->score == s.score; }

  string getName() const;
};

string Singer::getName() const { return this->name; }

istream& operator>>(istream &is, Singer &s) {
    cin >> s.name >> s.gender >> s.age >> s.score;
    return is;
}

ostream& operator<<(ostream &os, const Singer &s) {
    os << s.name << " " << s.gender << " " << s.age << " " << s.score;
    return os;
}

int main() {
  Singer s1, s2;

  cin >> s1 >> s2;

  cout << s1 << "\n" << s2 << endl;

  if (s1 > s2)

    cout << s1.getName() << "'s score is higher than " << s2.getName()
         << "'s.\n";

  else if (s1 == s2)

    cout << s1.getName() << "'s score is equal to " << s2.getName() << "'s.\n";

  else

    cout << s1.getName() << "'s score is lower than " << s2.getName()
         << "'s.\n";
}