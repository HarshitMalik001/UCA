// https://leetcode.com/problems/maximal-rectangle/description/

#include <iostream>
using namespace std;
#include <vector>
#include <stack>


class Solution {
public:
    int findmax(vector<int> cur, int m)
    {

        stack < pair <int,int> > stk;

        int max_rect = 0;

        for(int i = 0; i < m; i++)
        {
            if(stk.empty())
            {
                stk.push({cur[i], i});
            }
            else
            {
                int prev = i;
                while(!stk.empty() && stk.top().first > cur[i])
                {
                    pair <int, int> gg = stk.top();
                    stk.pop();

                    prev = gg.second;

                    max_rect = max(max_rect, (gg.first)*(i - gg.second));
                }
                stk.push({cur[i], prev});
            }
        }


        while(!stk.empty())
        {
            pair <int, int> gg = stk.top();
            stk.pop();

            max_rect = max(max_rect, (gg.first)*(m - gg.second));
        }
 
        return max_rect;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {

        int n = matrix.size();
        int m = matrix[0].size();

        vector <int> cur(m, 0);

        int max_rect = 0;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(matrix[i][j] == '0')
                {
                    cur[j] = 0;
                }
                else
                {
                    cur[j]++;
                }
            }
            max_rect = max(max_rect, findmax(cur, m));
        }

        return max_rect;
    }

};