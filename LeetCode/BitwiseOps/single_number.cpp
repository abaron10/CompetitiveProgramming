
#include <iostream>
#include <vector>
#include <bitset>

using std::cout; 
using std::vector;
using std::bitset;


int singleNumber(vector<int> nums)
{
    int ans = 0;
    for (auto x : nums)
    {
        ans ^= x;
        bitset<4> s(ans);
        cout << s.to_string() << '\n';
    }
    return ans;
}

int main()
{

    cout << singleNumber({2,1});
    
    return 0;
}
