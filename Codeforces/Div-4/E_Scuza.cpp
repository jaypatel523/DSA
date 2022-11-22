#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
	ll n, q;
	cin >> n >> q;

	vector<ll> arr;
	for(int i=0; i<n; i++)
	{
		ll x;
		cin >> x;
		arr.push_back(x);
	}

	// prefix sum of an array arr
	vector<ll> prefixSum(n, 0);
	prefixSum[0]=arr[0];
	for(int i=1; i<n; i++)
	{
		prefixSum[i] = arr[i] + prefixSum[i-1];
	}


	// created array in increasing order to use binary search 
	// example 
	// given array -> 1 2 1 5
	// answer -> 1 2 2 5 
	// reason -> because we can climb height 2 than we can also climb height with 1 so if there is smaller height after an element than i will make it equal to prevois maximum 
	for(int i=1; i<n; i++)
	{
		if(arr[i] < arr[i-1])
		{
			arr[i] = arr[i-1];
		}
	}



	for(int i=0; i<q; i++)
	{
		ll k;
		cin >> k;

		ll temp = upper_bound(arr.begin(), arr.end(), k) - arr.begin() - 1;


		if(temp == -1)
		{
			cout << "0 ";
		}
		else
		{
			cout << prefixSum[temp] << " ";
		}

	}

	cout << endl;

}


int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		solve();
	}

	return 0;
}
