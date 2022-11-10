#include <bits/stdc++.h>
using namespace std;

void solve(int arr[], int n)
{	
	int last = arr[n-1];
	int size = 0;

	int i=n-1;
	int ans = 0;

	while(i >= 0)
	{
		while(arr[i] == last && i >= 0)
		{
			size++;
			i--;
		}

		if(i < 0) break;
		ans++;
		i -= size;
		size *= 2;
	}

	

	// cout << i << endl;

	cout << ans;


}


int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		int n;
		cin >> n;

		int arr[n];
		for(int i=0; i<n; i++)
		{
			cin >> arr[i];
		}

		solve(arr, n);


		cout << endl;
	}

	return 0;
}
