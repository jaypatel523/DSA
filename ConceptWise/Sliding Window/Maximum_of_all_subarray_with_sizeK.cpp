// you are given an array and integer k
// you have to find the maximum element from all the subarrays 

// example

/*


array = 1 3 -1 -3 5 3 6 7
k = 3


1 3 -1 -> max = 3
3 -1 -3 -> max = 3
-1 -3 5 -> max = 5
-3 5 3 -> max = 5
5 3 6 -> max = 6
3 6 7 -> max = 7

answer array is -> 3 3 5 5 6 7



*/


#include <bits/stdc++.h>
using namespace std;



vector<int> maxOfSubarr(vector<int> & v, int k)
{
	vector<int> ans;
	if(k > v.size())
	{
		ans.push_back(1);
	}
	else
	{
		int i=0;
		int j=0;

		queue<int> q;
		while(j < v.size())
		{
			while(q.size() > 0 && q.back() < v[j])
			{
				q.pop();
			}
			q.push(v[j]);


			if(j - i + 1 < k)
			{
				j++;
			}
			else if(j - i + 1 == k)
			{
				ans.push_back(q.front());

				if(v[i] == q.front())
				{
					q.pop();
				}
				i++;
				j++;
			}
		}


	}

	return ans;
}



int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		int n, k;
		cin >> n >> k;

		vector<int> v(n);
		for(int i=0; i<n; i++)
		{
			cin >> v[i];
		}


		vector<int> ans = maxOfSubarr(v, k);


		for(int i=0; i<ans.size(); i++)
		{
			cout << ans[i] << " ";
		}

		cout << endl;


	}

	return 0;
}
