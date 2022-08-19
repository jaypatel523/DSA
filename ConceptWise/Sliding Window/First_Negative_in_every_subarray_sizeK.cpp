// you are given an array and interger k
// you gave to find first negative integer in every subarray with size k


// example

/*

array = 12 -1 -7 8 -15 30 16 2
K = 3



12 -1 -7 -> first negative number is -1
-1 -7 8 -> -1
-7 8 -15 -> -7
8 -15 30 -> -15
-15 30 16 -> -15
30 16 -2 -> 0


answer array = -1 -1 -7 -15 -15 0

// Note 
-> if there is no negative number in subarray then you can return 0 or you have to return as per given in question 




*/



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

		int i=0;
		int j=0;
		vector<int> ans;
		queue<int> q;


		while(j < n)
		{
			if(arr[j] < 0)
			{
				q.push(arr[j]);
			}


			// queue<int> temp = q;
			// while(!temp.empty())
			// {
			// 	cout << temp.front() << " ";
			// 	temp.pop();
			// }
			// cout << endl;


			if(j - i + 1 < k)
			{
				j++;
			}
			else if(j - i + 1 == k)
			{
				if(q.size()== 0)
				{
					ans.push_back(0);
				}
				else 
				{
					ans.push_back(q.front());
					if(q.front() == arr[i])
					{
						q.pop();
					}
				}



				// if(arr[i] >= 0)
				// {
				// 	ans.push_back(q.front());
				// 	q.pop();
				// }
				// else if(arr[i] <= 0)
				// {
				// 	ans.push_back(arr[i]);
				// 	if(arr[i] == q.front())
				// 	{
				// 		q.pop();
				// 	}
				// }
				// else if(q.empty())
				// {
				// 	ans.push_back(0);
				// }


				i++;
				j++;
			}
		}

		for(int i=0; i<ans.size(); i++)
		{
			cout << ans[i] << " ";
		}

		cout << endl;


	}

	return 0;
}
