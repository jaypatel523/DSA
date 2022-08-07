int slidingWindow(vector<int> & nums, int firstLen, int secondLen)
{
        int n = nums.size();
        
        int iOuter = 0;
        int jOuter = 0;
        int ans = 0;
        
        int sum = 0;
        while(jOuter < n)
        {
            sum += nums[jOuter];
            
            int sumInner = 0;
            
            
            if(jOuter - iOuter + 1 < firstLen)
            {
                jOuter++;
            }
            else if(jOuter - iOuter + 1 == firstLen)
            {
                int iInner = jOuter + 1;
                int jInner = jOuter + 1;
                
                while(jInner < n)
                {
                    
                    
                    sumInner += nums[jInner];
                    
                    if(jInner - iInner + 1 < secondLen)
                    {
                        jInner++;
                    }
                    else if(jInner - iInner + 1 == secondLen)
                    {   
                        // cout << sum << " " << sumInner << " ";
                        // cout << endl;
                        ans = max(ans, sum + sumInner);
                        
                        
                        
                        sumInner -= nums[iInner];
                        iInner++;
                        jInner++;
                        
                    }
                }
                
                // cout << endl;
                

                sum -= nums[iOuter];
                iOuter++;
                jOuter++;
                
                
            }
            
        }
    
        return ans;
            
            
}
    
    


class Solution {
public:
    
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        
        
            

        // int ans = max(slidingWindow(nums, firstLen, secondLen), slidingWindow(nums, secondLen, firstLen));
        
        
        // cout << slidingWindow(nums, firstLen, secondLen) << endl;
        // cout << slidingWindow(nums, secondLen, firstLen) << endl;
        
        // cout << ans;
        
        int ans = max(slidingWindow(nums, firstLen, secondLen), slidingWindow(nums, secondLen, firstLen));
        
        // cout << ans;
        
        return ans;
        
        
        
    }
};
