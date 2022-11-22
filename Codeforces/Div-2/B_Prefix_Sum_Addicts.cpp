#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool isSorted(vector<ll> & arr, int k)
{
	for(int i=0; i<k-1; i++)
	{
		if(arr[i] > arr[i+1])
		{
			return false;
		} 
	}
	return true;
}


void solve()
{
	ll n, k;
	cin >> n >> k;

	ll arr[k];
	for(int i=0; i<k; i++)
	{
		cin >> arr[i];
	}


	if(n == 1 || k == 1)
	{
		cout << "YES";
	}
	else 
	{	
		ll rem = n - k + 1;
		ll num1;
		if(arr[0] < 0)
		{
			num1 = arr[0] / rem;
		}
		else 
		{
			num1 = arr[0] / rem;
			if(arr[0] % rem) num1++;
		}


		vector<ll> temp;
		temp.push_back(num1);
		for(int i=1; i<k; i++)
		{
			temp.push_back(arr[i] - arr[i-1]);
		}

		if(isSorted(temp, temp.size()))
		{
			cout << "YES";
		}
		else
		{
			cout << "NO";
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
