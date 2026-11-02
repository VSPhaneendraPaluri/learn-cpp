#include <iostream>
#include <string>

#include "test_scripts/test.h"

int main() {

    Test test;

    test.test_decode_0();
    test.test_decode_1();

    test.test_string_puzzles_0_0();
    test.test_string_puzzles_0_1();
    test.test_string_puzzles_0_2();

    test.test_sentence_word_reverse_0();

    test.test_palindrome_0();
    test.test_palindrome_1();

    test.test_cache_0();

    test.test_register_impl();
    
    return 0;
}