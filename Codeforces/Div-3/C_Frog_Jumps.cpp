#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		string s;
		cin >> s;

		int size = s.size();

		
		int i=-1;
		int j=0;

		int ans = 0; 
		while(j < size)
		{
			if(s[j] == 'R')
			{
				ans = max(ans, j - i);
				i = j;
				j = i + 1;
			}
			else
			{
				j++;
			}
		}

		ans = max(ans, j - i);
		cout << ans << endl;


	}

	return 0;
}
