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

		int n = s.size();

		map<char, vector<int>> m;

		for(int i=0; i<n; i++)
		{
			m[s[i]].push_back(i+1);
		}
			



		vector<int> path;
		if(s[0] < s[n-1])
		{	
			for(char ch = s[0]; ch <= s[n-1]; ch++)
			{
				if(m.find(ch) != m.end())
				{
					for(auto i : m[ch])
					{
						path.push_back(i);
					}
				}
			}
		}
		else 
		{
			for(char ch = s[0]; ch >= s[n-1]; ch--)
			{
				if(m.find(ch) != m.end())
				{
					for(auto i : m[ch])
					{
						path.push_back(i);
					}
				}
			}
		}

		cout << abs(int(s[0]) - int(s[n-1])) << " " << path.size() << endl;

		for(int i=0; i<path.size(); i++)
		{
			cout << path[i] << " ";
		}

		cout << endl;


	}

	return 0;
}

