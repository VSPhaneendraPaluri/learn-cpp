#include "test.h"
#include "encode_decode_puzzles/decode.h"
#include "string_puzzles/string_puzzles.h"
#include "cache_impl/cache.h"
#include "register_impl/register.h"

#include <iostream>

void Test::test_result(std::string output, std::string golden) {
    if (output != golden) {
        std::cerr << "TEST FAILED! Input and output do not match!" << std::endl;
        std::exit(1); // Force the program to exit with an error code
    } else {
        std::cout << "TEST PASSED! Output : " << output << std::endl << std::endl;
    }
}

void Test::test_decode_0() {
    std::cout << __FUNCSIG__ << std::endl;
    std::string input{"10[ab]3[c]"};
    decode decode_inst;
    auto result = decode_inst.decode_string(input);
    test_result(result, "ababababababababababccc");
}

void Test::test_decode_1() {
    std::cout << __FUNCSIG__ << std::endl;
    std::string input{"10[3[c]d]"};
    decode decode_inst;
    auto result = decode_inst.decode_string(input);
    test_result(result, "cccdcccdcccdcccdcccdcccdcccdcccdcccdcccd");
}

void Test::test_zigzag_0() {
    std::cout << __FUNCSIG__ << std::endl;
    std::string input{"PAYPALISHIRING"};
    decode decode_inst;
    auto result = decode_inst.zigzag_conversion(input);
    //test_result(result, );
}

void Test::test_string_puzzles_0_0() {
    std::cout << __FUNCSIG__ << std::endl;
    std::cout << "Input String : " << input_0_0 << std::endl;
    string_puzzles string_puzzles_inst;
    std::string output = string_puzzles_inst.string_char_reverse_0(input_0_0);
    test_result(output, "0 elzzuP gnirtS si sihT");
}

void Test::test_string_puzzles_0_1() {
    std::cout << __FUNCSIG__ << std::endl;
    std::cout << "Input String : " << input_0_1 << std::endl;
    string_puzzles string_puzzles_inst;
    std::string output = string_puzzles_inst.string_char_reverse_1(input_0_1);
    test_result(output, "1 elzzuP gnirtS si sihT");
}

void Test::test_string_puzzles_0_2() {
    std::cout << __FUNCSIG__ << std::endl;
    std::cout << "Input String : " << input_0_2 << std::endl;
    string_puzzles string_puzzles_inst;
    std::string output = string_puzzles_inst.string_char_reverse_2(input_0_2);
    test_result(output, "2 elzzuP gnirtS si sihT");
}

void Test::test_sentence_word_reverse_0() {
    std::cout << __FUNCSIG__ << std::endl;
    std::cout << "Input String : " << input_1_0 << std::endl;
    string_puzzles string_puzzles_inst;
    std::string output = string_puzzles_inst.sentence_word_reverse_0(input_1_0);
    test_result(output, "0 Puzzle Sentence is This");
}

void Test::test_palindrome_0() {
    std::string palindrome_str{"malayalam"};
    std::cout << "Input 0: " << palindrome_str << std::endl;
    string_puzzles string_puzzles_inst;
    bool output = string_puzzles_inst.is_palindrome(palindrome_str);
    std::cout << "Is Palindrome : " << std::boolalpha << output << std::endl;
}

void Test::test_palindrome_1() {
    std::string palindrome_str{"otto"};
    std::cout << "Input 0: " << palindrome_str << std::endl;
    string_puzzles string_puzzles_inst;
    bool output = string_puzzles_inst.is_palindrome(palindrome_str);
    std::cout << "Is Palindrome : " << std::boolalpha << output << std::endl;
}

void Test::test_cache_0() {
    std::cout << std::endl;
    std::cout << __FUNCSIG__ << std::endl;
    Cache cache_inst;
    uint32_t address = 0x8234; // Example address
    cache_inst.set_cache(address, reinterpret_cast<uint8_t*>(&cache_data_16_bytes_0), 16);
}

void Test::test_register_pre_write_callback(uint32_t value) {
    std::cout << "Pre-write callback: Value to write = " << value << std::endl;
}

void Test::test_register_post_write_callback(uint32_t value) {
    std::cout << "Post-write callback: Value written = " << value << std::endl;
}

uint32_t Test::test_register_pre_read_callback() {
    std::cout << "Pre-read callback: called " << std::endl;
    return 0x98765432; // Example value to return
}

uint32_t Test::test_register_post_read_callback() {
    std::cout << "Post-read callback: called " << std::endl;
    return 0x99887766; // Example value to return
}

void Test::test_register_impl() {
    std::cout << std::endl;
    std::cout << __FUNCSIG__ << std::endl;
    // Implement your register test logic here
    Register reg_inst("TestRegister", 0x00, 0x00000000, 0xFFFFFFFF, 0xFFFFFFFF);
    reg_inst.register_wr_callback(CallbackType::PRE_WRITE, 
        [this](uint32_t val) { this->test_register_pre_write_callback(val); });
    reg_inst.register_rd_callback(CallbackType::PRE_READ,
        [this]() { return this->test_register_pre_read_callback(); });
    reg_inst.register_wr_callback(CallbackType::POST_WRITE,
        [this](uint32_t val) { this->test_register_post_write_callback(val); });
    reg_inst.register_rd_callback(CallbackType::POST_READ,
        [this]() { return this->test_register_post_read_callback(); });

    // callbacks testing
    reg_inst.write(0x12345678);
    auto read_value = reg_inst.read();
    
    reg_inst.deregister_wr_callback(CallbackType::PRE_WRITE);
    reg_inst.deregister_rd_callback(CallbackType::PRE_READ);
    reg_inst.deregister_wr_callback(CallbackType::POST_WRITE);
    reg_inst.deregister_rd_callback(CallbackType::POST_READ);
    reg_inst.write(0x87654321);
    read_value = reg_inst.read();
}