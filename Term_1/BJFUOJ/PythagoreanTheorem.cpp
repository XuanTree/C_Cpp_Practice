#include <iostream>
#include <cmath>
#include <iomanip>
int main() {
    double a,b,c;
    std:: cin >> a >> b;
    c = sqrt(a*a + b*b);
    std:: cout << std:: fixed << std:: setprecision(2) << c;
    return 0;
}