#include "Memory.h"

uintptr_t Memory::getAddress(const uintptr_t address, const std::vector<uintptr_t> offsets)
{
    if (address != NULL)
    {
        uintptr_t address_ = address;

        if (!offsets.empty())
        {
            for (uintptr_t offset : offsets)
            {
                if (address_ == NULL)
                {
                    throw std::runtime_error("Invalid pointer encountered during offset calculation.");
                }

                address_ = *reinterpret_cast<uintptr_t*>(address_);
                address_ += offset;
            }
        }

        return address_;
    }
    else
    {
        throw std::invalid_argument("Invalid address provided.");
    }
}

void Memory::patch(BYTE* dst, BYTE* src, size_t size)
{
    DWORD oldProtect;
    VirtualProtect(dst, size, PAGE_EXECUTE_READWRITE, &oldProtect);

    memcpy(dst, src, size);

    VirtualProtect(dst, size, oldProtect, &oldProtect);
}

void Memory::nop(BYTE* dst, size_t size)
{
    DWORD oldProtect;
    VirtualProtect(dst, size, PAGE_EXECUTE_READWRITE, &oldProtect);

    memset(dst, 0x90, size);

    VirtualProtect(dst, size, oldProtect, &oldProtect);
}
