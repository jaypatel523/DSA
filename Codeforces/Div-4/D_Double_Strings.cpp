#include <bits/stdc++.h>
using namespace std;


int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		int n;
		cin >> n;

		vector<string> arr;
		for(int i=0; i<n; i++)
		{
			string s;
			cin >> s;

			arr.push_back(s);
		}			


		unordered_map<string, bool> m;
		for(int i=0; i<n; i++)
		{
			m[arr[i]] = true;
		}



		for(int i=0; i<arr.size(); i++)
		{
			bool flag = false;
			for(int j=1; j<arr[i].size(); j++)
			{
				string pref = arr[i].substr(0, j);
				string suff = arr[i].substr(j, arr[i].size()-j);

				if(m[pref] && m[suff])
				{
					flag = true;
				}
			}	
			cout << flag;
		}
		cout << endl;



	}

	return 0;
}
