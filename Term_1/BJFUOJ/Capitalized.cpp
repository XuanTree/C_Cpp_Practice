#include <iostream>
#include <string>
#include <cctype>
void capitalizeFirstLetter(std::string& sentence) {
    bool isNewWord = true;
    for (size_t i = 0; i < sentence.size(); ++i) {
        if (isspace(static_cast<unsigned char>(sentence[i]))) {
            isNewWord = true;
        } else {
            if (isNewWord) {
                sentence[i] = static_cast<char>(toupper(static_cast<unsigned char>(sentence[i])));
                isNewWord = false;
            }
            else {
                sentence[i] = static_cast<char>(tolower(static_cast<unsigned char>(sentence[i])));
            }
        }
    }
}
int main() {
    std::string inputSentence;
    while(std::getline(std::cin, inputSentence)) {
        capitalizeFirstLetter(inputSentence);
        std::cout << inputSentence << std::endl;
    }
    return 0;
}