#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		ll n;
		cin >> n;

		string s;
		cin >> s;

		ll mid = n / 2;

		ll sum = 0;
		for(int i=0; i<n; i++)
		{
			if(s[i] == 'L')
			{
				sum += (i);
			}
			else
			{
				sum += (n - i - 1);
			}
		}

		vector<ll> k;
		for(int i=0; i<mid; i++)
		{
			if(s[i] == 'L')
			{
				ll temp = n - i - 1;
				temp -= i;
				// sum -= i
				k.push_back(temp);
			}
		}

		if(n % 2 == 0)
		{
			for(int i=mid; i<n; i++)
			{
				if(s[i] == 'R')
				{
					ll temp = i;
					temp -= (n - i - 1);
					// sum -= (n - i - 1);
					k.push_back(temp);

				}
			}
		}
		else
		{
			for(int i=mid+1; i<n; i++)
			{
				if(s[i] == 'R')
				{
					ll temp = i;
					temp -= (n - i - 1);
					// sum -= (n - i - 1);
					k.push_back(temp);
				}
			}
		}

		sort(k.rbegin(), k.rend());

		vector<ll> ans;
		for(int i=0; i<k.size(); i++)
		{
			sum += k[i];
			ans.push_back(sum);
		}

		for(int i=k.size(); i<n; i++)
		{
			ans.push_back(sum);
		}

		for(int i=0; i<ans.size(); i++)
		{
			cout << ans[i] << " ";
		}


		cout << endl;


	}

	return 0;
}
