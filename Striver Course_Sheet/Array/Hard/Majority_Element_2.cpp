// Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

// LEETCODE SOLUTION 

class Solution {

    public:
    vector<int> majorityElement(vector<int>& nums) {
        
        
        // using hashMap
        /*
        int n = nums.size();
        int minF = n / 3;
        
        unordered_map<int, int> m;
        for(int element : nums)
        {
            m[element]++;
        }
        
        vector<int> ans;
        for(auto & it : m)
        {
            if(it.second > minF)
            {
                ans.push_back(it.first);
            }
        }
        
        
        return ans;
        
        */
        
        
        
        
        // using moore's voting algorithm
        int cnt1 = 0;
        int cnt2 = 0;
        int num1 = 0;
        int num2 = 0;
        
        int n = nums.size();
        
        for(int i=0; i<n; i++)
        {
            if(nums[i] == num1)
            {
                cnt1++;
            }
            else if(nums[i] == num2)
            {
                cnt2++;
            }
            else if(cnt1 == 0)
            {
                num1 = nums[i];
                cnt1 = 1;
            }
            else if(cnt2 == 0)
            {
                num2 = nums[i];
                cnt2 = 1;
            }
            else
            {
                cnt1--;
                cnt2--;
            }
        }
           
        vector<int> ans;
        
        cnt1 = 0;
        cnt2 = 0;
        for(int i=0; i<n; i++)
        {
            if(nums[i] == num1)
            {
                cnt1++;
            }
            else if(nums[i] == num2)
            {
                cnt2++;
            }
        }
        
        if(cnt1 > n/3)
        {
            ans.push_back(num1);
        }
        
        if(cnt2 > n/3)
        {
            ans.push_back(num2);
        }
        
        return ans;
    }
};
