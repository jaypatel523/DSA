class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        // brute force 
        // Tc = O(n^3) && Sc = O(1)
        
        /*
        int size = nums.size();
        
        int maxi = INT_MIN;
        for(int i=0; i<size; i++)
        {
            for(int j=i; j<size; j++)
            {
                int sum = 0;
                for(int k=i; k<=j; k++)
                {
                    sum += nums[k];
                }
                maxi = max(sum, maxi);
            }
        }
        
        return maxi;
        
        */
        
        // Better brute force
        // Quadratic time O(n^2) and Sc = O(1)
        
        /*
        int size = nums.size();
        int maxi = INT_MIN;
        
        for(int i=0; i<size; i++)
        {
            int sum = 0;
            for(int j=i; j<size; j++)
            {
                sum += nums[j];
                if(sum > maxi)
                {
                    maxi = sum;
                }
            }
            maxi = max(sum, maxi);
        }
        
        return maxi;
        
        */
        
        
        
        
        // Kadane's Algorithm
        // Tc = O(n) and Sc = O(1)
        
        int size = nums.size();
        int maxi = INT_MIN;
        
        int sum = 0;
        for(int i=0; i<size; i++)
        {
            sum += nums[i];
            
            if(sum > maxi)
            {
                maxi = sum;
            }
            
            if(sum < 0)
            {
                sum = 0;
            }
            

        }
        
        return maxi;
        
    }
};
