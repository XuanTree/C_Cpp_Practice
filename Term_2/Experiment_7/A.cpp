#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cctype>
#include <unordered_set>

//! 不用提交Main函数
void readPapers(std::string content) {
    std::istringstream iss(content);

    std::string word;
    std::vector<std::string> words;
    std::unordered_set<char> puncts = {',', '.', '!', '?', '"', ';', ':'};

    char ch;
    int count = 0;
    while (iss.get(ch)) {
        if (puncts.count(ch)) {
            count++;
        }
    }

    iss.clear();
    iss.seekg(0);

    while (iss >> word) {
        words.push_back(word);
    }

    std::cout << words.size() << "," << count << std::endl;
}

int main() {
    std::string content;
    std::getline(std::cin, content, '\n');
    readPapers(content);
    return 0;
}
