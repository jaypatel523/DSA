
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

		string s;
		cin >> s;

		int i=0;
		int j=0;


		while(i < n && j < n && s[i] != '*')
		{
			i++;
			j++;
		}

		int lastStar = n - 1;
		for(int i=n-1; i>=0; i--)
		{
			if(s[i] == '*')
			{
				lastStar = i;
				break;
			}
		}

		int ans = 1;
		if(i == lastStar)
		{
			ans = 1;
		}
		else
		{
			int idx = 0;

			while(i < n)
			{
				int j=i;

				while(j <= (i + k))
				{
					if(s[j] == '*')
					{
						idx = j;
					}
					j++;
				}

				ans++;
				if(idx >= lastStar)
				{
					break;
				}
				i = idx;
			}
		}


		cout << ans << endl;






	}

	return 0;
}

