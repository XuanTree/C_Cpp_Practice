#include <cctype>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
using namespace std;

// 无脑粘贴就行了

unsigned termFrequency(const string& content, map<string, unsigned>& msu) {
    istringstream iss(content);

    string word;
    string puncts = ".,!?\";:";

    while (iss >> word) {
        // 先去掉单词首尾的标点
        string clean;
        for (size_t i = 0; i < word.size(); ++i) {
            char c = word[i];
            if (puncts.find(c) == string::npos) {
                clean += tolower((unsigned char)c);
            }
        }

        // 判断是否全是数字（纯数字单词不算）
        bool isPureDigit = true;
        for (size_t i = 0; i < clean.size(); ++i) {
            if (!isdigit((unsigned char)clean[i])) {
                isPureDigit = false;
                break;
            }
        }

        if (!clean.empty() && !isPureDigit) {
            msu[clean]++;
        }
    }

    return msu.size();
}

void alphabetSortedFrequency(const map<string, unsigned>& msu) {
    // 把 map 的键值对拷到 vector 中
    vector<pair<string, unsigned> > vec(msu.begin(), msu.end());
    
    // 按首字母排序，首字母相同则按完整单词字典序
    sort(vec.begin(), vec.end(), [](const pair<string, unsigned>& a, const pair<string, unsigned>& b) {
        char ca = tolower((unsigned char)a.first[0]);
        char cb = tolower((unsigned char)b.first[0]);
        if (ca != cb) return ca < cb;
        return a.first < b.first;
    });
    
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i].first << ":" << vec[i].second << std::endl;
    }
}
