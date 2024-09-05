// https://leetcode.com/problems/count-of-smaller-numbers-after-self

class Solution {
public:

    void merge(vector<vector<int>> &nums_copy, vector<vector<int>> &aux, int first, int mid, int last)
    {
        for(int i = first; i <= last; i++)
        {
            aux[i] = nums_copy[i];
        }

        int inv_count = 0;
        int i = first;
        int j = mid + 1;

        for(int k = first; k <= last; k++)
        {
            if(i > mid)
            {
                nums_copy[k] = aux[j];
                j++;
            }
            else if(j > last)
            {
                nums_copy[k] = aux[i];
                nums_copy[k][2] += inv_count;
                i++;
            }
            else if(aux[i][0] > aux[j][0])
            {
                nums_copy[k] = aux[j];
                inv_count++;
                j++;
            }
            else
            {
                nums_copy[k] = aux[i];
                nums_copy[k][2] += inv_count;
                i++;
            }
        }
    }

    void merge_sort(vector<vector<int>> &nums_copy, vector<vector<int>> &aux, int first, int last)
    {
        if(first >= last) return;

        int mid = (first + last) / 2;

        merge_sort(nums_copy, aux, first, mid);
        merge_sort(nums_copy, aux, mid + 1, last);

        merge(nums_copy, aux, first, mid, last);
    }

    vector<int> countSmaller(vector<int>& nums) {
        vector <vector<int> > nums_copy;
        vector <vector<int> > aux;

        for(int i = 0; i < nums.size(); i++ )
        {
            nums_copy.push_back({nums[i], i, 0});
            aux.push_back({nums[i], i, 0});
        }

        merge_sort(nums_copy, aux, 0, nums.size() - 1);

        vector<int> nums1 (nums.size() , 0);

        for(int i = 0; i < nums.size(); i++)
        {
            nums1[nums_copy[i][1]] = nums_copy[i][2];
        }

        return nums1;
    }
};
