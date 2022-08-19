// You are given two strings string s and string p
// you have to count all anagrams of p in s

// example 

/*
  
 string s = aabaabaa
 string p = aaba
 
 anagrams of p in string s are -> aaba at 0, abaa at 1, aaba at 3 and abaa at 4
 
 total anagrams are 4 therefore answer = 4
 
 // if you are given that return starting indices of anagrams then also solution is same
 
 

*/


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

		string p;
		cin >> p;
			

		int ss = s.size();
		int ps = p.size();

		unordered_map<char, int> m;
		for(int i=0; i<p.size(); i++)
		{
			m[p[i]]++;
		}

		int count = m.size();

		int i=0;
		int j=0;
		vector<int> ans;
        int ans = 0;

		while(j < ss)
		{
			if(m.find(s[j]) != m.end())
			{
				m[s[j]]--;
				if(m[s[j]] == 0)
				{
					count--;
				}
			}


			if(j - i + 1 < ps)
			{
				j++;
			}
			else if(j - i + 1 == ps)
			{
				if(count == 0)
				{
                    ans++;
// 					ans.push_back(i);
				}

				if(m.find(s[i]) != m.end())
				{
					m[s[i]]++;
					if(m[s[i]] == 1)
					{
						count++;
					}
				}

				i++;
				j++;
			}
		}
  
    cout << ans; // count of anagrams
		
    // This is array of starting indices of all anagrams of string p
// 		for(int i=0; i<ans.size(); i++)
// 		{
// 			cout << ans[i] << " ";
// 		}

		cout << endl;


	}

	return 0;
}

