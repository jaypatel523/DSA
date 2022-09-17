
#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> t, vector<int> m, string s)
{

	if(t.size() != m.size() * 2)
	{
		return false;
	}
	
	for(int i=0; i<m.size(); i++)
	{
		if(m[i] < t[i] || m[i] > t[i + m.size()])
		{
			return false;
		}
	}

	return true;

}



int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		int n;
		cin >> n;

		string s;
		cin >> s;

		vector<int> t, m;
		for(int i=0; i<s.size(); i++)
		{
			if(s[i] == 'T')
			{
				t.push_back(i);
			}
			else
			{
				m.push_back(i);
			}
		}


		if(check(t, m, s))
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
