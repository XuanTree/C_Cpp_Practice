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

template<typename T, int N>
class Queue {
private:
    T data[N];
    size_t head = 0;
	size_t tail = 0;
    int count = 0;
public:
    Queue() = default;
    Queue(const Queue&) = default;

    int GetSize() const { return N; }
    void PushBack(const T& value) {
        if (count < N) {
            data[tail] = value;
            tail = (tail + 1) % N;
            count++;
        }
    }
    void PopOut() {
        if (IsEmpty()) return;
        data[head].~T();
        head = (head + 1) % N;
        count--;
    }
	void Clear() { 
		while (!IsEmpty()) {
            PopOut();
		}
        head = 0; tail = 0; count = 0; 
    }
	const T& Front() const { return data[head]; }
	bool IsEmpty() const { return count == 0; }
	bool IsFull() const { return count == N; }

};

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

    Queue<std::string, 5> my_queue;
	my_queue.PushBack("Hello");
	my_queue.PushBack("World");
	my_queue.PushBack("From");
	my_queue.PushBack("C++");

	std::cout << my_queue.GetSize() << std::endl;
    std::cout << my_queue.IsEmpty() << std::endl;
	std::cout << my_queue.IsFull() << std::endl;

	my_queue.PushBack("!!!");
	std::cout << my_queue.IsFull() << std::endl;
    
	my_queue.PopOut();
	std::cout << my_queue.IsFull() << std::endl;
    my_queue.PushBack("Hello");

	my_queue.Clear();
	std::cout << my_queue.IsEmpty() << std::endl;

    return 0;
}
