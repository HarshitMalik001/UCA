// Write a program to return the sum of all even numbers in the Fibonacci series till a given number n. 
// Ex: for n = 100, fib series till 100 is [1,1,2,3,5,8,21,34,55,89]. 
// Return sum of even numbers in it : 2+8+34 = 44

#include <iostream>
using namespace std;
#include <stack>

int main() {
    
    int n;
    cin>>n;
    
    stack <int> stk;
    
    stk.push(1);
    stk.push(1);
    
    int sum = 0;
    
    while(stk.top() <= n)
    {
        int last = stk.top();
        stk.pop();
        int new_last = last + stk.top();
        stk.push(last);
        stk.push(new_last);
        
        if(new_last % 2 == 0 && new_last <= n) {
            sum += new_last;
        }
       
    }
    
    cout <<sum;
    
    return 0;
}