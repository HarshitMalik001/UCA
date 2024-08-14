class Solution {
public:

    int quickSelectionRecursion(vector<int>& nums, int k, int first ,int last)
    {
        int i = first + 1;
        int j = i;
        int l = i;
        while(i <= last)
        {
            if(nums[i] == nums[first])
            {
                nums[i] = nums[l];
                nums[l] = nums[first];
                l++;
            }

            else if(nums[i] < nums[first])
            {
                int temp = nums[i];
                nums[i] = nums[l];
                nums[l] = nums[j];
                nums[j] = temp;
                j++;
                l++;
            }
            i++;
        }

        j--;
        int temp = nums[j];
        nums[j] = nums[first];
        nums[first] = temp;

        if(k>=j && k<l )
        {
            return nums[j];
        }
        else if (j > k)
        {
            return quickSelectionRecursion(nums, k, first, j-1);
        }
        else
        {
            return quickSelectionRecursion(nums, k, l , last);
        }
    }

    int findKthLargest(vector<int>& nums, int k) {
        
        return quickSelectionRecursion(nums, nums.size() - k , 0, nums.size()- 1 );
    }
};


