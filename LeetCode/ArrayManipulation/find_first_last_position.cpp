#include <iostream>
#include <vector>
using namespace std;

int binSearch(vector<int> &nums, int &target, bool leftBiased)
{
    int left = 0;
    int right = nums.size() - 1;
    int pos = -1;

    while (left <= right)
    {
        int middle = (left + right) / 2;

        if (nums[middle] > target)
        {
            right = middle - 1;
        }
        else if (nums[middle] < target)
        {
            left = middle + 1;
        }
        else
        {
            pos = middle;

            if (leftBiased)
            {
                right = middle - 1;
            }
            else
            {
                left = middle + 1;
            }
        }
    }

    return pos;
}

vector<int> searchRange(vector<int> &nums, int target)
{
    return vector<int>{binSearch(nums, target, true), binSearch(nums, target, false)};
}

int main()
{

    std::vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;

    cout << (vector<int>{3,4} == searchRange(nums, target));
}