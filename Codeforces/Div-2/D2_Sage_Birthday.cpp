#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;

	int arr[n];
	for(int i=0; i<n; i++)
	{
		cin >> arr[i];
	}

	sort(arr, arr + n);



	vector<int> ans(n);
	int l=0;
	int h=n/2;

	for(int i=0; i<n; i+=2)
	{
		ans[i] = arr[h++];
		ans[i+1] = arr[l++];
	}

	int totalbuy = 0;
	for(int i=1; i<n-1; i++)
	{
		if(ans[i] < ans[i-1] && ans[i] < ans[i+1])
		{
			totalbuy++;
		}
	}



	cout << totalbuy << endl;

	for(int i=0; i<n; i++)
	{
		cout << ans[i] << " ";
	}



	return 0;
}
