// You are given an array and integer k
// You have to find the maximum sum among all subarrays of size k
// example input

/*  

array = 2 3 5 2 5 9 8
K = 3


Now, 

all the subarrays with size 3 are,
2 3 5 => sum = 10
3 5 2 => sum = 10
5 2 5 => sum = 12
2 5 9 => sum = 16
5 9 8 => sum = 22

you can see that maximum sum is 22 

ANSWER = 22

*/


// fixed size sliding window problem

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		int n, k;
		cin >> n >> k;

		int arr[n];
		for(int i=0; i<n; i++)
		{
			cin >> arr[i];
		}

		int i=0;
		int j=0;
		int ans = 0;
		long long sum = 0;
		while(j < n)
		{
			sum += arr[j];
			if(sum < k)
			{
				j++;
			}
			else if(sum == k)
			{
				int len = j - i + 1;
				ans = max(ans, len);
				j++;
			}
			else if(sum > k)
			{
				// cout << i << j << " : " << sum << endl;
				while(sum > k)
				{
					sum -= arr[i];
					i++;
					if(sum == k)
					{
						ans = max(ans, j-i+1);
						break;
					}
					
				}
				j++;
			}
		}

		cout << ans << endl;

	}

	return 0;
}
