
#include <iostream>
#include <vector>

using namespace std;

vector<int> missingNumbers(int* arr, int size){

    int diff = (*arr);
    vector<int> response;
    int currPos =  0;

    for(int i = 0; i < size; i++){
        if(arr[i] - diff != currPos){
            int missingNums = arr[i] - diff - currPos; 
            while(missingNums > 0) {
                response.push_back(currPos + diff);
                currPos++;
                missingNums--;
            }
        }
        
        currPos++;
    }
    
    return response;
}


int main()
{   
    int arr[5] = {1,2,4};
    auto response = missingNumbers(arr, 3);


    for(auto num: response){
        cout << num << '\n';
    }

  
    return 0;
}