#include "string_puzzles.h"

#include <vector>
#include <algorithm>
#include <numeric>
#include <sstream>

std::string string_puzzles::string_char_reverse_0(std::string & input) {
    std::string result;
    std::vector<char> vec;
    for (char ch : input) {
        vec.emplace_back(ch);
    }
    while (!vec.empty()) {
        result += vec.back();
        vec.pop_back();
    }
    return result;
}

std::string string_puzzles::string_char_reverse_1(std::string & input) {
    std::string result;
    std::vector<char> vec;
    for (char ch : input) {
        vec.emplace_back(ch);
    }
    for (auto it = vec.rbegin(); it != vec.rend(); ++it) {
        result += *it;
    }
    return result;
}

std::string string_puzzles::string_char_reverse_2(std::string & input) {
    std::reverse(input.begin(), input.end());
    return input;
}

std::string string_puzzles::sentence_word_reverse_0(std::string & input) {
    std::stringstream ss;
    while(!input.empty()) {
        size_t pos = input.rfind(" ");
        if (pos != std::string::npos) {
            ss << input.substr(pos+1, input.size() - pos) << " ";
            input = input.substr(0, pos);
        } else {
            ss << input;
            input.clear();
        }
    }
    return ss.str();
}

bool string_puzzles::is_palindrome(std::string & input) {
    bool result = true;
    size_t size = input.size();
    if (size % 2) { // odd
        auto center = (size / 2);
        for (auto i = center; i > 0; i--) {
            if (input[center - i - 1] != input[center + i + 1]) {
                result = false;
                break;
            }
        }
    } else { // even
        auto center = (size / 2) - 1;
        for (auto i = 0; i < center; i++) {
            if (input[center - i] != input[center + i + 1]) {
                result = false;
                break;
            }
        }
    }
    return result;
}
