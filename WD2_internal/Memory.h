#pragma once
#include <Windows.h>
#include <vector>
#include <stdexcept>
#include <iostream>


namespace Memory
{
    uintptr_t getAddress(const uintptr_t address, const std::vector<uintptr_t> offsets = {});

    void patch(BYTE* dst, BYTE* src, size_t size);

    void nop(BYTE* dst, size_t size);

    template <typename T>
    T read(const uintptr_t address)
    {
        if (address != NULL)
        {
            return *reinterpret_cast<T*>(address);
        }
        else
        {
            throw std::invalid_argument("Invalid address provided.");
        }
    }

    template <typename T>
    bool write(const uintptr_t address, const T value)
    {
        try {
            *reinterpret_cast<T*>(address) = value;
            return true;
        }
        catch (...)
        {
            return false;
        }
    }
};
