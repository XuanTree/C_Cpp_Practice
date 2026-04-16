#include <iostream>
using namespace std; // 好讨厌啊

class Item_base { // 未打折的图书商品
protected:
  string ISBN;  // 图书序列号
  double price; // 单价

public:
  Item_base(const string &book_ISBN = "", double sales_price = 0.0);
  string get_ISBN() const;
  virtual double net_price(int) const; // 返回购买指定数量的图书的总价
  virtual ~Item_base() ;
};

double Item_base::net_price(int num) const{
    return this->price * num;
}

Item_base::~Item_base() {}

Item_base::Item_base(const string& _bookISBN, double _salesPrice) {
    this->ISBN = _bookISBN;
    this->price = _salesPrice;
}

string Item_base::get_ISBN() const {
    return this->ISBN;
}

class Bulk_Item : public Item_base { // 根据购买数量打折
public:
  Bulk_Item(const string &book_ISBN = "", double sales_price = 0.0,
            int min_qty = 0, double discount = 0.0);

  double net_price(int) const override; // 返回根据购买数量打折后的总价
private:
  int min_qty;     // 买够这个数量可以打相应的折扣
  double discount; // 折扣
};

Bulk_Item::Bulk_Item(const string& _bookISBN, double _salesPrice, int _minQty, double _discount) {
    this->ISBN = _bookISBN;
    this->price = _salesPrice;
    this->discount = _discount;
    this->min_qty = _minQty;
}

double Bulk_Item::net_price(int _qty) const {
    if (_qty >= this->min_qty) {
        return this->price * (1.-discount) * _qty;
    } else {
        return this->price * _qty;
    }
}

int main() {
  Item_base book("0-001-0001-1", 10.0);
  Bulk_Item bulk1("0-001-0001-1", 10.0, 5, 0.1);
  Bulk_Item bulk2("0-001-0001-1", 10.0, 10, 0.2);

  int num;

  while (cin >> num){
    cout << bulk1.get_ISBN() << "\t" << num << "\t";

    Item_base *p;

    if (num >= 10)
      p = &bulk2;
    else if (num >= 5)
      p = &bulk1;
    else
      p = &book;

    cout << p->net_price(num) << "\n";
  }
  return 0;
};
