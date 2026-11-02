#pragma once

#include <iostream>
#include <vector>

class decode {
public:
    std::string decode_string(std::string input);
    std::string zigzag_conversion(std::string input);
        
public:
    std::vector<int> v1;
    std::vector<std::string> v2;
    std::string subString{""};
};
