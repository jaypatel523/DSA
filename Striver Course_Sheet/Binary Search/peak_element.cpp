class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 1)
        {
            return 0;
        }
        
        int low = 0;
        int high = n - 1;
        
        while(low <= high)
        {
            int mid = low + (high - low) / 2;
                
            if(mid == 0)
            {
                if(nums[0] > nums[1])
                {
                    return 0;
                }
                
                return 1;
            }
            else if(mid == n - 1)
            {
                if(nums[n-1] > nums[n-2])
                {
                    return n-1;
                }
                return n-2;
            }
            else 
            {
                if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1])
                {
                    return mid;
                }
                else if(nums[mid+1] > nums[mid])
                {   // because nums[mid+1] can be one of the candidates to be peak element 
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }
            
        }
        
        return -1;
        
        
    }
};
