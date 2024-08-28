

// https://www.geeksforgeeks.org/problems/tower-of-hanoi-1587115621/1

#include <iostream>
using namespace std;

long long toh(int n, int from, int to, int aux) {
        // Your code here
        if(n == 1)
        {
            cout<<"move disk "<< n << " from rod "<<from<<" to rod "<< to <<endl;
            return 1;
        }
        
        int j = toh(n-1, from, aux, to);
        cout<<"move disk "<< n << " from rod "<<from<<" to rod "<< to <<endl;
        toh(n-1, aux, to, from);
        
        return j*2 + 1;
    }