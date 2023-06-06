
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> topKFrequent(vector<int> &nums, int k)
{
    unordered_map<int, int> freq;
    int maxSeen = 0;

    // Count the frequency of each number
    for (const auto &num : nums)
    {
        freq[num]++;
        maxSeen = max(maxSeen, freq[num]);
    }

    // Create a vector to store numbers with frequencies
    vector<vector<int>> bucket(maxSeen + 1);
    for (const auto &pair : freq)
    {
        bucket[pair.second].push_back(pair.first);
    }

    vector<vector<int>>::reverse_iterator it = bucket.rbegin();
    vector<int> response;
    for (; it != bucket.rend() && response.size() < k; it++)
    {
        for (const auto &num : (*it))
        {
            response.push_back(num);
            if (response.size() == k)
            {
                break;
            }
        }
    }

    return response;
}


int main(){

    vector<int> a = {1,1};
    topKFrequent(a,2);

    return 0;
}