// If we will make every even number 0 and every odd number 1 in array then this problem will convert into Number of subarrays with sum equals to k


class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        
        int size = nums.size();
        
        for(int i=0; i<size; i++)
        {
            if(nums[i] % 2 == 0)
            {
                nums[i] = 0;
            }
            else
            {
                nums[i] = 1;
            }
        }
        
        unordered_map<int, int> m;
        m[0] = 1; 
        int ans = 0;
        int sum = 0;
        for(int i=0; i<size; i++)
        {
            sum += nums[i];
            
            if(m.count(sum - k))
            {
                ans += m[sum - k];
            }
            m[sum]++;
        }
        
        
        
        
        
        return ans;
        
    }
};
