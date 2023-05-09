#include <iostream>

int hammingWeight(uint32_t n)
{   
    int counter = 0;
    while(n){
        n = n &(n-1);
        counter++;
    }

    return counter;
}

int main()
{   
    uint32_t n = 0b1101;
    
    std::cout<< hammingWeight(n);
}