class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        int size = nums.size();
        
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
