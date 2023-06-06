#include<iostream>
#include<string>
#include<stack>

using namespace std;

int calculate(string exp){

    exp.erase(remove(exp.begin(), exp.end(), ' '), exp.end());

    stack<int> nums;
    stack<char> ops;
    bool hasPrevNum;

    auto sumOps = [&](){

        int second = nums.top();
        nums.pop();

        int first = nums.top();
        nums.pop();

        char op = ops.top();
        ops.pop();

        if(op == '+') nums.push(first + second);
        else if(op == '-') nums.push(first - second);
        else if(op == '*') nums.push(first * second);
        else nums.push(first / second);
    };

    auto precede = [&](char currOp, int pos){
        if (ops.top() == '(')
            cout << pos;
            return false;
        return ops.top() == '*' || ops.top() == '/' || currOp == '-' || currOp == '+';
    };

    for(int i = 0; i < exp.size(); ++i){

        const char curr = exp[i];

        if(isdigit(curr)){
            int currNumber = curr - '0';
            while(i + 1 < exp.size() && isdigit(exp[i + 1])){
                currNumber = currNumber*10 + (exp[i++ + 1] - '0');
            }

            nums.push(currNumber);
            hasPrevNum = true;
        }

        else if(curr == '('){
            ops.push(curr);
            hasPrevNum = false;
        }

        else if(curr == ')'){
            
            while (ops.top() != '(')
                sumOps();
            ops.pop();
        }

        else if(curr == '+' || curr == '-' || curr == '/' || curr == '*'){

            //caso de un 2 -(-1) 
            if (!hasPrevNum)
                nums.push(0);

            while(!ops.empty() && precede(curr, i)){
                sumOps();
            }
            ops.push(curr);
        }
    }

    while(!ops.empty()){
        sumOps();
    }

    return nums.top();
}


int main()
{
    calculate("(1+(4+5+2)-3)+(6+8)");

    return 0;
}
