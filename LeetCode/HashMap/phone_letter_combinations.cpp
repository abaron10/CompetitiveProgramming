#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>

using namespace std;

vector<string> letterCombinations(string digits)
{

    if (digits == "")
    {
        return {};
    }

    unordered_map<char, string> m = {{'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};

    vector<string> combos = {""};

    for (const auto &digit : digits)
    {

        vector<string> tmp;

        for (const auto &combo : combos)
        {

            for (const auto &letter : m.at(digit))
            {

                tmp.push_back(combo + letter);
            }
        }

        combos = move(tmp);
    }

    return combos;
}


// The code uses nested loops to generate all possible combinations of letters for the given digits. The time complexity analysis focuses on the number of iterations these loops perform.

// Let's consider the variables N and M:

// N represents the number of digits in the input string that maps to 3 letters ('2', '3', '4', '5', '6', '8').
// M represents the number of digits in the input string that maps to 4 letters ('7', '9').
// The outer loop iterates N times, as it processes each digit mapped to 3 letters. Inside this loop, the middle loop iterates over the current set of combinations, which initially contains only one empty string. The number of iterations of the middle loop depends on the size of the combinations vector.

// During each iteration of the middle loop, the innermost loop iterates over the letters mapped to the current digit. The number of iterations in this loop is constant, either 3 or 4, as determined by the mapping.

// Here's a step-by-step breakdown of the iterations:

// The outer loop iterates N times, where N is the count of digits mapped to 3 letters.
// For each outer loop iteration, the middle loop iterates over the current set of combinations. Initially, there is only one combination, so the middle loop iterates once.
// Inside the middle loop, the innermost loop iterates over the letters mapped to the current digit. This loop iterates a constant number of times, either 3 or 4, depending on the digit.
// To determine the total number of iterations, we need to multiply the number of iterations of each loop:

// Iterations = N * iterations of middle loop * iterations of innermost loop.

// Since the number of iterations of the middle loop depends on the size of the combinations vector, and the number of iterations of the innermost loop is constant (3 or 4), we can simplify the expression as:

// Iterations = N * O(combos) * O(1) = N * O(combos) = O(N * combos).

// Now, let's analyze the value of combos, the size of the combinations vector. Initially, combos contains a single empty string. However, in each iteration of the outer loop, the combinations are updated and grow exponentially.

// In the worst case scenario, if all the digits in the input string map to 4 letters ('7', '9'), the size of combos will be 4^M. This is because, in each iteration of the outer loop, the number of combinations can multiply by 4 due to the additional letters.

// Hence, the final time complexity is given by:

// Iterations = O(N * combos) = O(N * 4^M).

// Since N represents the count of digits mapped to 3 letters and M represents the count of digits mapped to 4 letters, we express the time complexity as:

// Iterations = O(3^N * 4^M).

// Therefore, the time complexity of the code is O(3^N * 4^M), where N is the count of digits mapped to 3 letters and M is the count of digits mapped to 4 letters.