#include <bits/stdc++.h>
using namespace std;


long long bsRoom(long long arr[], long long n, long long target)
{

	long long low = 0;
	long long high = n - 1;
	long long ans = -1;

	vector<long long> res;


	while(low <= high)
	{
		long long mid = low + (high - low) / 2;

		if(arr[mid] == target)
		{
			high = mid - 1;
			ans = mid - 1;
		}
		else if(arr[mid] < target)
		{
			ans = mid;
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}
	}


	return ans;
}



void solve(long long arr[], long long query[], long long n, long long m)
{
	for(int i=1; i<n; i++)
	{
		arr[i] = arr[i-1] + arr[i];
	}	


	// cout << binarySearch(arr, n, 37);

	// int j=0;
	for(int i=0; i<m; i++)
	{

		// j part is solution without binarysearch


		// while(query[i] > arr[j])
		// {
		// 	j++;
		// }

		// if(j == 0)
		// {
		// 	cout << j + 1 << " " << query[i] << endl; 
		// }
		// else
		// {
		// 	cout << j + 1 << " " << query[i] - arr[j-1] << endl;
		// }	


		long long bs = bsRoom(arr, n, query[i]);

		// why bs + 2
		// +1 because 0 based indexing but we have to take answer by considering 1 base indexing 
		// +1 because we will return the floor index of target and our dormitory number will be floor index + 1

		long long room = (bs == -1) ? 0 : arr[bs];
		cout << bs + 2 << " " << query[i] - room << endl;

	}
}




int main()
{

		long long n, m;
		cin >> n >> m;

		long long arr[n];
		for(int i=0; i<n; i++)
		{
			cin >> arr[i];
		}

		long long query[m];
		for(int i=0; i<m; i++)
		{
			cin >> query[i];
		}

		solve(arr, query, n, m);




	return 0;
}
