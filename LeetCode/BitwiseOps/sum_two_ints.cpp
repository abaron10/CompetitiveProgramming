
#include<iostream>

uint sum(uint num_1, uint num_2){

    while(num_2){
        int carry = (num_1 & num_2); // AND to handle the carry
        num_1 = num_1 ^ num_2; // XOR to compute the raw operation
        num_2 = carry >> 1; // shift the carry one
    }

    return num_1;
}


int main()
{
    
    std::cout << sum(33,4);
    
    return 0;
}