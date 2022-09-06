class Solution {
    public:
    
    
    int majorityElement(vector<int>& nums) {
       
        
        // Brute force technique will take o(n^2) time 
        
        
        
        // Sorting technique will take o(n logn) time ans o(1) space
        // sort(nums.begin(), nums.end());
        // return nums[nums.size()/2];
        
        
        // This solution will take o(n) time ans o(n) space 
        /*
        unordered_map<int, int> m;
        int ns = nums.size();
        
        for(int i=0; i<ns; i++)
        {
            m[nums[i]]++;
        }
        
        int cnt = 0;
        int ans = 0;
        for(auto & it : m)
        {
            if(it.second > cnt)
            {
                ans = it.first;
                cnt = it.second;
            }
        }
        
        return ans;
        
        */
        
        
        // Boyer-Moore voting algorithm
        // Tc = O(n) and Sc = O(1)
        /*
        
        int size = nums.size();
        int count = 0;
        int candidate = 0;
        
        for(int i=0; i<size; i++)
        {
            if(count == 0)
            {
                candidate = nums[i];
            }
            
            if(candidate == nums[i]) count++;
            else count--;
        }
        
        return candidate;
        
        */
        
        
        // using bit manupulation (bitmasking)
        
        
        int bits = sizeof(int) * 8;
        int ans = 0;
        
        for(int i=0; i<bits; i++)
        {
            int count = 0;
            for(int j=0; j<nums.size(); j++)
            {
                if(nums[j] & (1 << i))
                {
                    count++;
                }
            }
            
            if(count > nums.size() / 2)
            {
                ans += (1 << i);
            }
        }
        
        return ans;
        
        
        
        
        
    }
};
