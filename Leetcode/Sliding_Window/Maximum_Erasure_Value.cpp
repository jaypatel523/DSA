class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        
        int i=0;
        int j=0;
        
        int sum = 0;
        int ans = 0;
        
        int size = nums.size();
        unordered_map<int, int> m;
        
        while(j < size)
        {
            sum += nums[j];
            m[nums[j]]++;
            
            if(j - i + 1 == m.size())
            {
                ans = max(ans, sum);
                j++;
            }
            else if(j - i + 1 > m.size())
            {
                while(j - i + 1 > m.size())
                {
                    sum -= nums[i];
                    m[nums[i]]--;
                    
                    
                    if(m[nums[i]] == 0) 
                    {
                        m.erase(nums[i]);
                    }
                    
                    
                    
                    i++;
                    
                    if(j - i + 1 == m.size())
                    {
                        ans = max(ans, sum);
                        break;
                    }
                }
                j++;
            }
            
        }
        
        return ans;
        
    }
};
