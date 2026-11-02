#pragma once

#include <iostream>
#include <vector>

constexpr uint32_t log2_constexpr(uint32_t n) {
    uint32_t result = 0;
    while (n >>= 1) {
        ++result;
    }
    return result;
}

class Cache {
public:
    Cache();
    ~Cache();

    static constexpr uint32_t MEMORY_SIZE{16384}; // 16 KB
    static constexpr uint32_t BLOCK_SIZE{16}; // 16 bytes
    static constexpr uint32_t CACHE_SIZE{1024}; // 1 KB
    static constexpr uint32_t CACHE_LINES{CACHE_SIZE / BLOCK_SIZE}; // Number of cache lines

    static constexpr uint32_t ADDRESS_BITS{32};
    static constexpr uint32_t BLOCK_OFFSET_BITS{log2_constexpr(BLOCK_SIZE)};
    static constexpr uint32_t INDEX_BITS{log2_constexpr(CACHE_LINES / 8)}; // Assuming 8 sets
    static constexpr uint32_t TAG_BITS{log2_constexpr(MEMORY_SIZE) - INDEX_BITS - BLOCK_OFFSET_BITS};
    static constexpr uint32_t BLOCK_MASK{BLOCK_SIZE - 1};
    static constexpr uint32_t INDEX_MASK{(1U << INDEX_BITS) - 1};
    static constexpr uint32_t TAG_MASK{(1U << TAG_BITS) - 1};

    void set_cache(uint32_t address, uint8_t * data_ptr, uint32_t length);
    void get_cache(uint32_t address, uint8_t * data_ptr, uint32_t length);

private:
    uint8_t memory[MEMORY_SIZE];
    uint32_t sets{8};
    uint32_t ways{0};
    uint32_t m_block_offset{0};
    uint32_t m_index{0};
    uint32_t m_tag{0};

    void decode(uint32_t address);

    struct CacheLine {
        bool valid{false};
        bool dirty{false};
        uint32_t tag{0};
        uint8_t data[BLOCK_SIZE]{0};
    };
    std::vector<std::vector<CacheLine>> cache_lines;
};
