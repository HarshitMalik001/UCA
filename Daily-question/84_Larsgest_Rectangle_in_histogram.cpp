

// 84. Largest Rectangle in Histogram

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack <pair<int, int>> stk;
        int max_rect = -1;
        for(int i = 0; i < heights.size(); i++)
        {
            if(stk.empty() || heights[i] > stk.top().second) stk.push({i, heights[i]});
            else
            {
                int min_index = i;
                while(!stk.empty() && heights[i] < stk.top().second)
                {
                    pair <int , int> rect = stk.top();
                    stk.pop();
                    min_index = rect.first;
                    max_rect = max(max_rect, rect.second*(i - rect.first));
                }
                stk.push({min_index, heights[i]});
            }
        }

        while(!stk.empty())
        {
            pair <int , int> rect = stk.top();
            stk.pop();
            int j = rect.second*(heights.size() - rect.first);
            max_rect = max(max_rect, j);
        }

        return max_rect;
    }
};
