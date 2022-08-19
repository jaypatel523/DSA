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


		int ans = 0;
		int sum = 0;
		int i=0;
		int j=0;
		while(j < n)
		{
			sum += arr[j];
			if(j-i+1 < k)
			{
				j++;
			}
			else if(j-i+1 == k)
			{
				ans = max(ans, sum);
				sum -= arr[j];
				i++;
				j++;

				// cout << i << " " << j << endl;
			}

		}

		cout << ans << endl;





	}

	return 0;
}
