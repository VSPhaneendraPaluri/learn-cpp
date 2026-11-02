#include "decode.h"
#include <sstream>

std::string decode::decode_string(std::string input) {
    int count = 0;
    int num = 0;
    v1.clear();
    v2.clear();        

    for (char s : input) {
        if (std::isdigit(s)) {
            num = num * 10 + (s - '0');
            count++;
        } else if (s == '[') {
            if (count) {
                count = 0;
            }
            v1.emplace_back(num);
            num = 0;
            v2.emplace_back(subString);
            subString = std::string("");
        } else if (s == ']') {
            int times = v1.back();
            v1.pop_back();
            std::stringstream ss;
            for( auto i = 0; i < times; i++ ) {
                ss << subString;
            }
            std::string temp;
            if (!v2.empty()) {
                temp = v2.back();
                v2.pop_back();
            }
            num = 0;
            subString = temp + ss.str();
        } else {
            subString += s;
        }
    }
    return subString;
}


std::string decode::zigzag_conversion(std::string input) {
#if 0
    int str_size = input.length();
    std::cout << str_size << std::endl;
    auto regular_columns = str_size / 3;
    for (auto rows = 0; i < 3; i++) {
        for (auto j = 0; )
    }
#endif
    return subString;
}