// Solution 1 :- Naive approach (Brute force)
/* 
         -> Traverse an array and for each element, we'll try to find sum - x by traversing an array
*/
// T.c = O(n^2) 
// S.c = O(1)



// Solution 2 :- Two pointers 
/* 

         first of all we have to sort an array 
         
         low = 0, high = size - 1
         
         if nums[low] + nums[high] == sum then return 
         else if nums[low] + nums[high] > sum then high--
         else if nums[low] + nums[high] < sum then low++;
         
         
         Tc = O(n lonn) because of sorting 
         Sc = O(1
         
*/

// solution 3 :- using map
/*

        -> traverse an array 
        -> if target - nums[i] is present in map then return 
        -> else insert nums[i] in map 
  
*/



/* LEETCODE SOLUTION */
// Problem link :- https://leetcode.com/problems/two-sum/


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        
        unordered_map<int, int> m;
        int size = nums.size();
        
        vector<int> ans;
        for(int i=0; i<size; i++)
        {
            if(m.count(target-nums[i]) > 0)
            {
                ans.push_back(m[target-nums[i]]);
                ans.push_back(i);
                break;
            }
            else
            {
                m[nums[i]] = i;
            }
        }
        
        return ans;
        
    }
    
};




/* GFG SOLUTION */
// Problem Link :- https://practice.geeksforgeeks.org/problems/find-all-pairs-whose-sum-is-x5808/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=find-all-pairs-whose-sum-is-x


class Solution{
    public:
    vector<pair<int,int>> allPairs(int A[], int B[], int N, int M, int x)
    {
        
        unordered_map<int, int> hash;
        for(int i=0; i<M; i++)
        {
            hash[B[i]]++;
        }
        
        vector<pair<int, int> > ans;
        for(int i=0; i<N; i++)
        {
            if(hash.count(x - A[i]) > 0)
            {
                ans.push_back({A[i], x - A[i]});
            }
        }
        
        sort(ans.begin(), ans.end());
        
        return ans;
    }
};

