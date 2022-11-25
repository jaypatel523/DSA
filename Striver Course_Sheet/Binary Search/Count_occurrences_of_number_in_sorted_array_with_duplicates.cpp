/*

Given a sorted array Arr of size N and a number X, you need to find the number of occurrences of X in Arr.


Example 1:

Input:
N = 7, X = 2
Arr[] = {1, 1, 2, 2, 2, 2, 3}
Output: 4
Explanation: 2 occurs 4 times in the
given array.



Example 2:

Input:
N = 7, X = 4
Arr[] = {1, 1, 2, 2, 2, 2, 3}
Output: 0
Explanation: 4 is not present in the
given array.
Your Task:
You don't need to read input or print anything. Your task is to complete the function count() which takes the array of integers arr, n and x as parameters and returns an integer denoting the answer.


Expected Time Complexity: O(logN)
Expected Auxiliary Space: O(1)


Constraints:
1 ≤ N ≤ 105
1 ≤ Arr[i] ≤ 106
1 ≤ X ≤ 106


*/



class Solution{
    
int firstOccurence(vector<int> & arr, int target)
{
	int low = 0;
	int high = arr.size() - 1;
	int ans = -1;

	while(low <= high)
	{
		int mid = low + (high - low) / 2;

		if(arr[mid] == target)
		{
			ans = mid;
			high = mid - 1;
		}
		else if(arr[mid] > target)
		{
			high = mid - 1;
		}
		else 
		{
			low = mid + 1;
		}
	}
	return ans;
}




int lastOccurence(vector<int> & arr, int target)
{
	int low = 0;
	int high = arr.size() - 1;
	int ans = -1;

	while(low <= high)
	{
		int mid = low + (high - low) / 2;

		if(arr[mid] == target)
		{
			ans = mid;
			low = mid + 1;
		}
		else if(arr[mid] < target)
		{
			low = mid + 1;
		}
		else 
		{
			high = mid - 1;
		}
	}
	return ans;
}


    
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int arr[], int n, int x) {
	    
	    vector<int> nums;
	    for(int i=0; i<n; i++)
	    {
	        nums.push_back(arr[i]);
	    }
	    
	    int ans1 = lastOccurence(nums, x);
	    int ans2 = firstOccurence(nums, x);
	    
	    if(ans1 == -1 && ans2 == -1)
	    {
	        return 0;
	    }
	    
	    return abs(ans1 - ans2) + 1;
	}
};



