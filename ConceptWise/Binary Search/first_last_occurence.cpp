#include <bits/stdc++.h>
using namespace std;
#define ll long long


ll firstOccurence(vector<ll> & arr, ll target)
{
	ll low = 0;
	ll high = arr.size() - 1;
	ll ans = -1;

	while(low <= high)
	{
		ll mid = low + (high - low) / 2;

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




ll lastOccurence(vector<ll> & arr, ll target)
{
	ll low = 0;
	ll high = arr.size() - 1;
	ll ans = -1;

	while(low <= high)
	{
		ll mid = low + (high - low) / 2;

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



void solve(vector<ll> & arr, ll target)
{
	ll n = arr.size();

	ll first = firstOccurence(arr, target);
	ll last = lastOccurence(arr, target);

	cout << "First : " << first << endl;
	cout << "Last : " << last << endl;
}



int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		ll n;
		cin >> n;


		vector<ll> arr;
		for(int i=0; i<n; i++)
		{
			ll x;
			cin >> x;
			arr.push_back(x);
		}	

		ll target;
		cin >> target;

		solve(arr, target);


	}

	return 0;
}
