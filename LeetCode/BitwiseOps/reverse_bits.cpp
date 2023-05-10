#include <iostream>

uint32_t reverseBits(uint32_t n)
{
    uint32_t output = 0;
    for (int i = 0; i < 32; i++)
    {
        output <<= 1;
        if (n & 1)
        {
            output += 1;
        }
        n >>= 1;
    }
    return output;
}

int main()
{

    uint s = 1001;

    std::cout << std::bitset<32>(reverseBits(s)) << std::endl;

    return 0;
}