#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> generate(int numRows) {

    vector<vector<int>> response;    
    for(int i = 0; i < numRows; i++){
        vector<int> tmp(i+1, 1); 
        if(i > 1) {
            auto prev = response.back();
            int flag = 0, tmpCurr = 1;
            while(flag + 1 < prev.size()){
                tmp[tmpCurr] = prev[flag] + prev[flag+1];
                tmpCurr++;
                flag++;
            } 
        }

        response.push_back(tmp);
    }

    return response;
}

int main()
{
    int numRows(5);
    auto response = generate(numRows);
    cout << (response == vector<vector<int>>{{1}, {1,1}, {1,2,1}, {1,3,3,1}, {1,4,6,4,1}});
}