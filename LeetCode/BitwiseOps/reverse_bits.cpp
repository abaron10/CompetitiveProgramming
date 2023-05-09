#include <iostream>

using namespace std;

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

    uint32_t s = 0b00000010100101000001111010011100;

    cout << bitset<32>(reverseBits(s)) << endl;

    return 0;
}