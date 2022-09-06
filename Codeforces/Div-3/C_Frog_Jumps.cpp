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

		
		// my solution 
		// TC O(n) and SC O(1)
		
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
		
		
		
		
		
		
		
		// another approach 
		// Tc -> O(n) but we will use array to store the indices of R


		vector<int> r;
		r.push_back(0);
		for(int i=0; i<size; i++)
		{
			if(s[i] == 'R')
			{
				r.push_back(i+1);
			}
		}
		r.push_back(size + 1);


		int maxDif = 0;
		for(int i=1; i<r.size(); i++)
		{
			maxDif = max(maxDif, r[i] - r[i-1]);
		}

		cout << maxDif;

		
		cout << endl;


	}

	return 0;
}
