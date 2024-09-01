

// https://leetcode.com/problems/n-queens/description/


class Solution {
public:
    bool possible( vector <string> ans, int n, int row, int col)
    {
       
        //up
        for(int i = 0; i < row; i++)
        {
            if(ans[i][col] == 'Q') return 0;
        }

        //left-up
        for(int i = row - 1, j = col - 1 ; i >= 0 && j >= 0; i--, j--)
        {
            if(ans[i][j] == 'Q') return 0;
        }

        //right-up
        for(int i = row - 1, j = col + 1 ; i >= 0 && j < n; i--, j++)
        {
            if(ans[i][j] == 'Q') return 0;
        }
        return 1;
    }

    void checkN(vector <vector <string>> &final_res, vector <string> ans, int n, int row)
    {
        if(row == n)
        {
            final_res.push_back(ans);
            return;
        }

        for(int i = 0; i < n; i++)
        {
            if(possible(ans, n, row, i))
            {
                ans[row][i] = 'Q';
                checkN(final_res, ans, n, row + 1);
                ans[row][i] = '.';
            }
        }

    }


    vector<vector<string>> solveNQueens(int n) {
        string gg = "";
        for(int i = 0; i < n; i++)
        {
            gg += '.';
        }
        vector <vector <string>> final_res;
        vector <string> ans(n, gg);

        checkN(final_res, ans, n, 0);

        return final_res;
    }
};