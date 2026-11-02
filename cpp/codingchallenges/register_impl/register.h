#pragma once

#include <iostream>
#include <string.h>
#include <functional>

enum class CallbackType : uint8_t {
    PRE_WRITE,
    PRE_READ,
    POST_WRITE,
    POST_READ
};

class Register {
    using wr_callback = std::function<void(uint32_t)>;
    using rd_callback = std::function<uint32_t()>;
    public:
        explicit Register(const std::string name, uint32_t offset, uint32_t default_value, uint32_t read_mask, uint32_t write_mask);
        ~Register();

        void register_wr_callback(CallbackType type, wr_callback cb);
        void register_rd_callback(CallbackType type, rd_callback cb);
        void deregister_wr_callback(CallbackType type);
        void deregister_rd_callback(CallbackType type);

        void write(uint32_t value);
        uint32_t read();

    private:
        std::string m_name;
        uint32_t m_offset;
        uint32_t m_default_value;
        uint32_t m_read_mask;
        uint32_t m_write_mask;
        uint32_t reg_value;

        wr_callback pre_write_callback;
        rd_callback pre_read_callback;
        wr_callback post_write_callback;
        rd_callback post_read_callback;
};

