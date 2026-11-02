#include "cache.h"

Cache::Cache() {
    // Initialize cache parameters
    if ((Cache::CACHE_LINES % 8) == 0) {
        sets = 8; // Ensure sets is a multiple of 8
    }
    ways = Cache::CACHE_LINES / sets;
    std::cout << "Cache initialized with " << std::hex << sets << " sets and "
                                           << std::hex << ways << " ways." << std::endl;

    // Initialize cache lines
    cache_lines.resize(sets, std::vector<CacheLine>(ways));
}

Cache::~Cache() {
    // Destructor logic if needed
}

void Cache::decode(uint32_t address) {
    uint32_t address_mask = (1U << Cache::TAG_BITS) - 1;
    // Decode the address into tag, index, and block offset
    m_block_offset = address & Cache::BLOCK_MASK;
    m_index = (address >> Cache::BLOCK_OFFSET_BITS) & Cache::INDEX_MASK;
    m_tag = (address >> (Cache::BLOCK_OFFSET_BITS + Cache::INDEX_BITS)) & address_mask;

    std::cout << "Address: " << address
              << ", Tag: " << m_tag
              << ", Index: " << m_index
              << ", Block Offset: " << m_block_offset
              << std::endl;
}

void Cache::set_cache(uint32_t address, uint8_t * data_ptr, uint32_t length) {
    if (length > Cache::BLOCK_SIZE) {
        std::cerr << "Error: Length exceeds block size." << std::endl;
        return;
    }
    decode(address);
    
    int way_found = -1;
    int way_index = -1;

    for (uint32_t way = 0; way < ways; way++) {
        if (cache_lines[m_index][way].valid && cache_lines[m_index][way].tag == m_tag) {
            way_found = way;
            way_index = way;
            break;
        }
        if (!cache_lines[m_index][way].valid && (way_index == -1)) {
            way_index = way; // First invalid way found
        }
    }

    if (way_found) {
        if (way_index != -1) {
            way_found = way_index; // Use the found way index
            std::cout << "Cache hit at index: " << m_index << ", way: " << way_index << std::endl;
        } else {
            std::cout << "Error: Cache hit but no valid way found." << std::endl;
            // eviction policy can be implemented here if needed (e.g., LRU, FIFO, etc.)
            way_found = 0; // For simplicity, we can choose the first way for eviction
        }
    
        cache_lines[m_index][way_found].valid = true;
        cache_lines[m_index][way_found].tag = m_tag;
        std::copy(data_ptr, data_ptr + Cache::BLOCK_SIZE, cache_lines[m_index][way_found].data);    
        cache_lines[m_index][way_found].dirty = true;
    }
}

void Cache::get_cache(uint32_t address, uint8_t * data_ptr, uint32_t length) {
    if (length > Cache::BLOCK_SIZE) {
        std::cerr << "Error: Length exceeds block size." << std::endl;
        return;
    }
    decode(address);
    // Logic to get data from cache (not implemented)
}