#include <iostream>
using namespace std; // 真讨人厌的

class TableTennisPlayer {
private:
  string firstname;
  string lastname;
  bool hasTable;

public:
  TableTennisPlayer(const string &, const string &, bool);
  virtual string FirstName() const;
  virtual string LastName() const;
  virtual bool HasTable() const;
};

TableTennisPlayer::TableTennisPlayer(const string& _firstName, const string& _lastName, bool _hasTable) {
    this->firstname = _firstName;
    this->lastname = _lastName;
    this->hasTable = _hasTable;
}

string TableTennisPlayer::FirstName() const {
    return this->firstname;
};

string TableTennisPlayer::LastName() const {
    return this->lastname;
}

bool TableTennisPlayer::HasTable() const {
    return this->hasTable;
}

class RatedPlayer : public TableTennisPlayer{
private:
    double rating;
public: 
    RatedPlayer(const double&, const string&, const string&, bool);
    string FirstName() const override;
    string LastName() const override;
    bool HasTable() const override;
    double Rating() const;
};

RatedPlayer::RatedPlayer(const double& _rating, const string& _firstName, const string& _lastName, bool _hasTable) :
    TableTennisPlayer(_firstName, _lastName, _hasTable) {
        this->rating = _rating;
}

string RatedPlayer::FirstName() const {
    return TableTennisPlayer::FirstName();
}

string RatedPlayer::LastName() const {
    return TableTennisPlayer::LastName();
}

bool RatedPlayer::HasTable() const {
    return TableTennisPlayer::HasTable();
}

double RatedPlayer::Rating() const {
    return this->rating;
}

int main() {

  string firstname, lastname;
  bool hasTable;
  int rating;
  char flag;

  while (cin >> flag) {

    if (flag == 'T') {

      cin >> firstname >> lastname >> hasTable;
      TableTennisPlayer tp(firstname, lastname, hasTable);

      if (tp.HasTable())
        cout << tp.FirstName() << " " << tp.LastName() << " has a table.\n";
      else
        cout << tp.FirstName() << " " << tp.LastName() << " hasn't a table.\n";

    } else if (flag == 'R') {
      cin >> firstname >> lastname >> hasTable >> rating;
      RatedPlayer rp(rating, firstname, lastname, hasTable);

      if (rp.HasTable())
        cout << rp.FirstName() << " " << rp.LastName()
             << " has a table. The rating is " << rp.Rating() << ".\n";
      else
        cout << rp.FirstName() << " " << rp.LastName()
             << " hasn't a table. The rating is " << rp.Rating() << ".\n";
    }
  }

  return 0;
}