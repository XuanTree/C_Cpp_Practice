#include <iostream>
#include <string.h>
using namespace std; // 真讨人厌的

class Date {
    public:
        Date(int d = 0, int m = 0, int y = 0); //构造函数
        int get_day() const; // 返回day
        int get_month() const; //返回month
        int get_year() const; // 返回year
        static void set_default(int, int, int); //设置default_date
        static int get_default_day(); //返回缺省day
        static int get_default_month(); //返回缺省month
        static int get_default_year(); //返回缺省year
        Date & add_year(int n); //加n年
        Date & add_month(int n); //加n月，考虑超过12月
        Date & add_day(int n); //加n天，考虑进位月和年，考虑闰年
    private:
        int day, month, year;
        static Date default_date; //初始化为 1901年1月1日
};

Date::Date(int _d, int _m, int _y) : day(_d), month(_m), year(_y) { }

Date Date::default_date(1, 1, 1901);

void Date::set_default(int d, int m, int y) {
    default_date.day = d;
    default_date.month = m;
    default_date.year = y;
}

int Date::get_day() const {
    return this->day;
}

int Date::get_default_day() {
    return default_date.day;
}

int Date::get_default_month() {
    return default_date.month;
}

int Date::get_default_year() {
    return default_date.year;
}

int Date::get_month() const {
    return this->month;
}

int Date::get_year() const {
    return this->year;
}

Date& Date::add_day(int n) {
    day += n;
    while (true) {
        int days_in_month;
        if (month == 2) {
            bool is_leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
            days_in_month = is_leap ? 29 : 28;
        } else if (month == 4 || month == 6 || month == 9 || month == 11) {
            days_in_month = 30;
        } else {
            days_in_month = 31;
        }

        if (day <= days_in_month) break;
        day -= days_in_month;
        month++;
        if (month > 12) {
            month = 1;
            year++;
        }
    }
    return *this;
}

Date& Date::add_month(int n) {
    month += n;
    while (month > 12) {
        month -= 12;
        year++;
    }

    int max_day;
    if (month == 2) {
        bool is_leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        max_day = is_leap ? 29 : 28;
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        max_day = 30;
    } else {
        max_day = 31;
    }
    if (day > max_day) {
        day = max_day;
    }
    return *this;
}

Date& Date::add_year(int n) {
    year += n;

    if (month == 2 && day == 29) {
        bool is_leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        if (!is_leap) {
            day = 28;
        }
    }
    return *this;
}

int main() {
    char type[110];
    int day,mon,year;
    int addday,addmon,addyear;
    while(cin>>type) {
        if(strcmp(type,"Date") == 0){
            cin>>day>>mon>>year;
            Date mydate(day,mon,year);
            cin>>addday>>addmon>>addyear;
            mydate.add_day(addday).add_month(addmon).add_year(addyear);
            cout << mydate.get_day() << " " << mydate.get_month() << " " << mydate.get_year() << endl;
        } else if(strcmp(type,"defaultDate") == 0) {
            cout << Date::get_default_day() << " " << Date::get_default_month() << " " << Date::get_default_year() << endl;
        } else if(strcmp(type,"setdefaultDate") == 0) {
            cin>>day>>mon>>year;
            Date::set_default(day,mon,year);
            cout << Date::get_default_day() << " " << Date::get_default_month() << " " << Date::get_default_year() << endl;
        }
    }
    return 0;
}