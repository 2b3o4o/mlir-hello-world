#include <iostream>
#include <string>
#include <unordered_map>
#include <functional>

// Function Prototype
std::string getNextWord();
void parse_hello();

// Define a type for the function that will be called based on the word
using WordHandler = std::function<void()>;

std::string getNextWord() {
    std::string word;
    char ch;

    while (std::cin.get(ch)) {
        if (isspace(ch)) {
            if (!word.empty()) {
                break; // End of a word
            }
        } else {
            word.push_back(ch);
        }
    }

    return word;
}

void parse_hello() {
    std::string name = getNextWord();
    std::cout << "Hello " << name << "!\n";
}

int main() {
    // Map of words to their corresponding functions
    std::unordered_map<std::string, WordHandler> wordHandlers = {
        {"hello", []() { parse_hello(); }},
    };

    while (true) {
        std::string word = getNextWord();
        if (word.empty()) {
            break; // EOF reached
        }

        // Trigger corresponding logic for the word
        auto it = wordHandlers.find(word);
        if (it != wordHandlers.end()) {
            it->second();
        } else {
            std::cout << "Word unrecognized: " << word << std::endl;
        }
    }

    return 0;
}