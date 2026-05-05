#include <iostream> //AI Assisted.
#include <string>
#include <cctype>
#include <sstream>
using namespace std;
int main() {
    string word, article;
    getline(cin, word);
    getline(cin, article);
    for(char &c : word){
        c = tolower(c);
    }
    for(char &c : article){
        c = tolower(c);
    }
    int count = 0, firstPos = -1;
    stringstream ss(article);
    string currentWord;
    int position = 0;
    while(ss >> currentWord) {
        if(currentWord == word) {
            count++;
            if(firstPos == -1) {
                firstPos = position;
            }
        }
        position += currentWord.length() + 1;
    }
    if(count > 0) {
        cout << count << " " << firstPos;
    } else {
        cout << -1;
    }
    return 0;
}