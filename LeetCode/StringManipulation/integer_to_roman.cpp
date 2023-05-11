

#include <iostream>
#include <vector>

std::string integerToRoman(int number)
{

    std::vector<std::pair<std::string, int>> values = {
        {"I", 1},
        {"IV", 4},
        {"V", 5},
        {"IX", 9},
        {"X", 10},
        {"XL", 40},
        {"L", 50},
        {"XC", 90},
        {"C", 100},
        {"CD", 400},
        {"D", 500},
        {"CM", 900},
        {"M", 1000}};

    std::reverse(values.begin(), values.end());

    std::string response = "";

    for (const auto &[k, v] : values)
    {
        if (number / v)
        {
            int amount = number / v;
            for(int i = 0; i < amount; i ++){
                response += k;
            }
            // 3240 si le hacemos el chop por 1000 3240 % 1000 = 240
            number = number % v;
        }
    }

    return response;
}

int main()
{
    std::cout << integerToRoman(58);
    return 0;
}