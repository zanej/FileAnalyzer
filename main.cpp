#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <algorithm>
#include <cctype>

std::string clean_word(const std::string& word) {
    std::string result;
    for (char c : word) {
        if (std::isalnum(c)) result += std::tolower(c);
    }
    return result;
}

int main() {
    std::string filename;
    std::cout << "Enter the name of the text file to analyze: ";
    std::cin >> filename;

    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file.\n";
        return 1;
    }

    int line_count = 0, word_count = 0, char_count = 0;
    std::map<std::string, int> word_freq;
    std::string line;

    while (std::getline(file, line)) {
        line_count++;
        char_count += line.size();
        std::istringstream iss(line);
        std::string word;
        while (iss >> word) {
            std::string clean = clean_word(word);
            if (!clean.empty()) {
                word_count++;
                word_freq[clean]++;
            }
        }
    }

    std::pair<std::string, int> most_common = {"", 0};
    for (const auto& p : word_freq) {
        if (p.second > most_common.second) {
            most_common = p;
        }
    }

    std::cout << "\nAnalysis Report:\n";
    std::cout << "Total Lines: " << line_count << "\n";
    std::cout << "Total Words: " << word_count << "\n";
    std::cout << "Total Characters: " << char_count << "\n";
    std::cout << "Most Common Word: '" << most_common.first << "' (" << most_common.second << " times)\n";

    file.close();
    return 0;
}
