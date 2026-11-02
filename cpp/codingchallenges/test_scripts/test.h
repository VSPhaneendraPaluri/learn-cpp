#pragma once

#include <string>

class Test {
public:
    std::string input_0_0{"This is String Puzzle 0"};
    std::string input_0_1{"This is String Puzzle 1"};
    std::string input_0_2{"This is String Puzzle 2"};

    std::string input_1_0{"This is Sentence Puzzle 0"};

    uint64_t cache_data_16_bytes_0{0x0123456789abcdef}; // Example 16 bytes of data
    uint64_t cache_data_16_bytes_1{0xfedcba9876543210}; // Another example 16 bytes of data
    uint64_t cache_data_16_bytes_2{0x0f1e2d3c4b5a6978}; // Another example 16 bytes of data
    uint64_t cache_data_16_bytes_3{0x89abcdef01234567}; // Another example 16 bytes of data

    void test_result(std::string output, std::string golden);

    void test_decode_0();
    void test_decode_1();

    void test_zigzag_0();

    void test_string_puzzles_0_0();
    void test_string_puzzles_0_1();
    void test_string_puzzles_0_2();

    void test_sentence_word_reverse_0();

    void test_palindrome_0();
    void test_palindrome_1();

    void test_cache_0();

    void test_register_impl();
    void test_register_pre_write_callback(uint32_t value);
    void test_register_post_write_callback(uint32_t value);
    uint32_t test_register_pre_read_callback();
    uint32_t test_register_post_read_callback();
};
