#include <iostream>
#include <string>
using namespace std;
string numberToWord(int num) {
    string words[] = {
        "zero", "one", "two", "three", "four", "five", 
        "six", "seven", "eight", "nine", "ten",
        "eleven", "twelve", "thirteen", "fourteen", "fifteen",
        "sixteen", "seventeen", "eighteen", "nineteen", "twenty"
    };
    if (num <= 20) {
        return words[num];
    } else if (num < 30) {
        return "twenty " + words[num - 20];
    } else if (num == 30) {
        return "thirty";
    } else if (num < 40) {
        return "thirty " + words[num - 30];
    } else if (num == 40) {
        return "forty";
    } else if (num < 50) {
        return "forty " + words[num - 40];
    } else if (num == 50) {
        return "fifty";
    } else {
        return "fifty " + words[num - 50];
    }
}
int main() {
    int h, m;
    cin >> h >> m;
    string result;
    result += numberToWord(h);
    if (m == 0) {
        result += " o'clock";
    } else {
        result += " " + numberToWord(m);
    }
    cout << result;
    return 0;
}