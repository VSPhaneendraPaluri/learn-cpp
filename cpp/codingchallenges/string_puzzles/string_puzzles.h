#pragma once

#include <iostream>
#include <string.h>

class string_puzzles {
public:
    string_puzzles() = default;
    ~string_puzzles() = default;

    std::string string_char_reverse_0(std::string & input);
    std::string string_char_reverse_1(std::string & input);
    std::string string_char_reverse_2(std::string & input);

    std::string sentence_word_reverse_0(std::string & input);

    bool is_palindrome(std::string & input);
};
