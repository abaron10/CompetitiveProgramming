#include <iostream>
#include <string>

int myAtoi(std::string s)
{
    // 1. ignore whitespaces (leading)
    s.erase(0, s.find_first_not_of(" "));

    int sign = 1;
    int value = 0;

    char curr = s[0];

    if (curr == '-' || curr == '+')
    {
        s.erase(0, 1);
        if (curr == '-')
        {
            sign = -1;
        }
    }

    for (int i = 0; i < s.size(); i++)
    {

        curr = s[i];

        if (!isdigit(curr))
        {
            return value;
        }

        int digit = (curr - '0') * sign;

        if (value > INT_MAX / 10 || value == INT_MAX / 10 && digit > INT_MAX % 10)
        {
            return INT_MAX;
        }

        if (value < INT_MIN / 10 || value == INT_MIN / 10 && digit < INT_MIN % 10)
        {
            return INT_MIN;
        }

        value = value * 10 + digit;
    }

    return value;
}

int main()
{

    std::string s = "-42";

    std::cout << myAtoi(s);

    return 0;
}
