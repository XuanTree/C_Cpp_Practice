#include <iostream>

using namespace std;

class Sales_data {
  // 依次输入书号、销量和收入

  friend istream &operator>>(istream &, Sales_data &);

  // 依次输出书号、销量、收入和均价

  friend ostream &operator<<(ostream &, const Sales_data &);

  friend bool operator==(const Sales_data &, const Sales_data &);

  friend bool operator!=(const Sales_data &, const Sales_data &);

  // for "+", assume that both objects refer to the same book

  friend Sales_data operator+(const Sales_data &, const Sales_data &);

public:
  Sales_data() : units_sold(0), revenue(0.0) {}

  Sales_data(const string &s, unsigned n, double r)
      : bookNo(s), units_sold(n), revenue(r) {}

  string get_bookNo() const;

  // for "+=", assume that both objects refer to the same book

  Sales_data &operator+=(const Sales_data &);

private:
  double avg_price() const; // 均价，等于收入除以销量

  string bookNo; // 书号

  unsigned units_sold; // 销量

  double revenue; // 收入
};

istream &operator>>(istream &is, Sales_data &item) {
    cin >> item.bookNo >> item.units_sold >> item.revenue;
    return is;
}

double Sales_data::avg_price() const { return this->revenue / this->units_sold; }

string Sales_data::get_bookNo() const { return this->bookNo; }

ostream &operator<<(ostream &os, const Sales_data &item) {
    os << item.bookNo << " " << item.units_sold << " " << item.revenue
       << " " << item.avg_price();
    return os;
}

bool operator==(const Sales_data &lhs, const Sales_data &rhs) {
    return lhs.bookNo == rhs.bookNo && lhs.units_sold == rhs.units_sold &&
           lhs.revenue == rhs.revenue;
}

bool operator!=(const Sales_data &lhs, const Sales_data &rhs) {
    return !(lhs == rhs);
}

Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs) {
    Sales_data sum = lhs;
    sum.units_sold += rhs.units_sold;
    sum.revenue += rhs.revenue;
    return sum;
}

Sales_data &Sales_data::operator+=(const Sales_data &rhs) {
    this->units_sold += rhs.units_sold;
    this->revenue += rhs.revenue;
    return *this;
}

int main() {

  Sales_data item1, item2;

  while (cin >> item1 >> item2) {

    cout << item1 << "\n" << item2 << "\n";

    if (item1 == item2)

      cout << item1.get_bookNo() << " equals " << item2.get_bookNo() << "\n";

    if (item1 != item2)

      cout << item1.get_bookNo() << " doesn't equal " << item2.get_bookNo()
           << "\n";

    cout << (item1 + item2) << "\n";

    item1 += item2;

    cout << item1 << "\n";
  }

  return 0;
}