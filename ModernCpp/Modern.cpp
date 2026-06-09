#include <iostream>
#include <print>
#include <sstream>
#include <string>
#include <map>

// ============================================================
// Word count using istringstream
// ============================================================

struct WordStats {
    size_t words = 0;                       // total word count
    size_t chars = 0;                       // non-whitespace chars
    size_t lines = 0;                       // line count
    std::map<std::string, size_t> freq;     // word frequency table
};

// Analyze text with istringstream
static WordStats count_words(const std::string& text) {
    WordStats stats;

    // 1. Count words and frequency via >> (whitespace-delimited)
    {
        std::istringstream iss(text);
        std::string word;
        while (iss >> word) {
            stats.words++;
            stats.chars += word.size();
            stats.freq[word]++;
        }
    }

    // 2. Count lines via getline (newline-delimited)
    {
        std::istringstream iss(text);
        std::string line;
        while (std::getline(iss, line)) {
            stats.lines++;
        }
    }

    return stats;
}

static std::string ReverseString(const std::string& input) {
    std::string temp, res;

    std::stringstream ss(input);
    while (ss >> temp) {
        res = temp + " " + res;
    }
    if (!res.empty()) {
        res.pop_back();
    }
    return res;
}

int main() {
    //// ---- Demo: stringstream + getline with different delimiters ----
    //std::print("=== stringstream delimiter demo ===\n");

    //std::string a, b, c, d;
    //std::string lines = "adfa;asdfasd;fasdf;ccc";
    //std::stringstream ss(lines);            // init with string

    //getline(ss, a, 'f');                    // read until first 'f' -> "ad"
    //getline(ss, b, ';');                    // then until ';'       -> "a"
    //getline(ss, c, ';');                    // then until next ';'  -> "asdfasd"
    //getline(ss, d);                         // rest, default '\n'  -> "fasdf;ccc"

    //std::cout << "a = " << a << std::endl;
    //std::cout << "b = " << b << std::endl;
    //std::cout << "c = " << c << std::endl;
    //std::cout << "d = " << d << std::endl;

    //// ---- New: word count demo ----
    //std::print("\n=== Word count demo ===\n");

    //const std::string sample = R"(Modern C++ is powerful
    //        stringstream makes text processing easy
    //        C++23 brings std::print and more
    //        Use istringstream for parsing strings
    //        C++ and Modern C++ are the same language)";

    //std::print("Text:\n{}\n\n", sample);

    //auto stats = count_words(sample);

    //std::print("Results:\n");
    //std::print("  Total words:     {}\n", stats.words);
    //std::print("  Non-space chars: {}\n", stats.chars);
    //std::print("  Lines:           {}\n", stats.lines);
    //std::print("  Unique words:    {}\n", stats.freq.size());
    //std::print("\nWord frequency:\n");
    //for (const auto& [word, count] : stats.freq) {
    //    std::print("  {:>12} : {}\n", word, count);
    //}

    std::string input = "Hello World From C++     !!!";

    std::string reversed = ReverseString(input);

    std::cout << reversed << std::endl;

    return 0;
}
