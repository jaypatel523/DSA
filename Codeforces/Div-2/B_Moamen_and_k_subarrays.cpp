
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

		map<int, int> m;
		for(int i=0; i<n; i++)
		{
			m[arr[i]] = i;
		}

		vector<int> locations;
		for(auto element : m)
		{
			locations.push_back(element.second);
		}

		int ans = 1;
		for(int i=1; i<locations.size(); i++)
		{
			if(locations[i] - locations[i-1] != 1 )
			{
				ans++;
			}
		}

		if(ans <= k)
		{
			cout << "YES";
		}
		else
		{
			cout << "NO";
		}

		cout << endl;


	}

	return 0;
}

