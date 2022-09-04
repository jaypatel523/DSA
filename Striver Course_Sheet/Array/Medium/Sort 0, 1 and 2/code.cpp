// LEETCODE 

class Solution {
public:
    void sortColors(vector<int>& nums) {


        // solution - 1

        // Tc = O(n) 
        // Sc = O(1)

        int size = nums.size();
        int ca = 0, cb = 0, cc = 0;

        for(int i=0; i<size; i++)
        {
            if(nums[i] == 0) ca++;

            if(nums[i] == 1) cb++;

            if(nums[i] == 2) cc++;
        }
        // cout << ca << cb << cc << endl;
        for(int i=0; i<size; i++)
        {
            if(ca > 0)
            {
                nums[i] = 0;
                ca--;
            }
            else if(cb > 0)
            {
                nums[i] = 1;
                cb--;
            }
            else if(cc > 0)
            {
                nums[i] = 2;
                cc--;
            }
        }







        // dutch national flag algorithm

        //  Three pointer approach 

        // Tc = O(n)
        // Sc = O(n)

        int size = nums.size();
        int low = 0;
        int mid = 0;
        int high = size - 1;

        while(mid <= high)
        {
            if(nums[mid] == 0)
            {
                swap(nums[low++], nums[mid++]);
            }
            else if(nums[mid] == 1)
            {
                mid++;
            }
            else if(nums[mid] == 2)
            {
                swap(nums[mid], nums[high--]);
            }
        }




    }
};
