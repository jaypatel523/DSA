/*

Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
Example 3:

Input: nums = [], target = 0
Output: [-1,-1]
 

Constraints:

0 <= nums.length <= 105
-109 <= nums[i] <= 109
nums is a non-decreasing array.
-109 <= target <= 109
    
*/


class Solution {
public:
    
    
    int binarySearchForFirstOccurence(vector<int>& nums, int target)
    {
        int i=0;
        int j=nums.size()-1;
        
        int mid;
        int ans = -1;
        while(i <= j)
        {
            mid = i + (j-i)/2;
            
            if(nums[mid] == target)
            {
                ans = mid;
            }
            
            if(nums[mid] >= target)
            {
                j = mid - 1;
            }
            else
            {
                i = mid + 1;
            }
        }
        
        return ans;
    }
    
    
    int binarySearchForLastOccurence(vector<int>& nums, int target)
    {
        int i=0;
        int j=nums.size()-1;
        
        int mid;
        int ans = -1;
        while(i <= j)
        {
            mid = i + (j-i)/2;
            
            if(nums[mid] == target)
            {
                ans = mid;
            }
            
            if(nums[mid] <= target)
            {
                i = mid + 1;
            }
            else
            {
                j = mid - 1;
            }
        }
        
        return ans;
    }
    
    
    
    vector<int> searchRange(vector<int>& nums, int target) {
        
        vector<int> v;
        
        
        v.push_back(binarySearchForFirstOccurence(nums, target));
        v.push_back(binarySearchForLastOccurence(nums, target));
        
        
        return v;
    }
};
