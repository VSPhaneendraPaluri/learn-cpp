#include "register.h"

Register::Register(const std::string name, uint32_t offset, uint32_t default_value, uint32_t read_mask, uint32_t write_mask)
    : m_name(name), m_offset(offset), m_default_value(default_value), m_read_mask(read_mask), m_write_mask(write_mask) {
        pre_write_callback = nullptr;
        pre_read_callback = nullptr;
        post_write_callback = nullptr;
        post_read_callback = nullptr;
}

Register::~Register() {
    // Destructor implementation (if needed)
    deregister_wr_callback(CallbackType::PRE_WRITE);
    deregister_wr_callback(CallbackType::POST_WRITE);
    deregister_rd_callback(CallbackType::PRE_READ);
    deregister_rd_callback(CallbackType::POST_READ);
}

void Register::register_wr_callback(CallbackType type, wr_callback cb) {
    switch (type) {
        case CallbackType::PRE_WRITE:
            pre_write_callback = cb;
            break;
        case CallbackType::POST_WRITE:
            post_write_callback = cb;
            break;
        default:
            std::cerr << "Invalid callback type!" << std::endl;
    }
}

void Register::register_rd_callback(CallbackType type, rd_callback cb) {
    switch (type) {
        case CallbackType::PRE_READ:
            pre_read_callback = cb;
            break;
        case CallbackType::POST_READ:
            post_read_callback = cb;
            break;
        default:
            std::cerr << "Invalid callback type!" << std::endl;
    }
}

void Register::deregister_wr_callback(CallbackType type) {
    switch (type) {
        case CallbackType::PRE_WRITE:
            pre_write_callback = nullptr;
            break;
        case CallbackType::POST_WRITE:
            post_write_callback = nullptr;
            break;
        default:
            std::cerr << "Invalid callback type!" << std::endl;
    }
}

void Register::deregister_rd_callback(CallbackType type) {
    switch (type) {
        case CallbackType::PRE_READ:
            pre_read_callback = nullptr;
            break;
        case CallbackType::POST_READ:
            post_read_callback = nullptr;
            break;
        default:
            std::cerr << "Invalid callback type!" << std::endl;
    }
}

void Register::write(uint32_t value) {
    if (pre_write_callback) {
        pre_write_callback(value);
    }
    reg_value =  (value & m_write_mask) | (reg_value & ~m_write_mask);
    if (post_write_callback) {
        post_write_callback(reg_value);
    }
}

uint32_t Register::read() {
    if (pre_read_callback) {
        return pre_read_callback();
    }
    return reg_value & m_read_mask;
    if (post_read_callback) {
        return post_read_callback();
    }
}
