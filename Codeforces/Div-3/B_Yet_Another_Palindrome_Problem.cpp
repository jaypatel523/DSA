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

		int arr[n];
		for(int i=0; i<n; i++)
		{
			cin >> arr[i];
		}



		// brute force 
		// Quadratic time -> O(n^2)

		// bool flag = false;
		// for(int i=0; i<n; i++)
		// {
		// 	for(int j=i+1; j<n; j++)
		// 	{
		// 		if(arr[i] == arr[j])
		// 		{
		// 			if(j - i > 1)
		// 			{
		// 				flag = true;
		// 				break;
		// 			}
		// 		}
		// 	}
		// }

		// if(flag)
		// {
		// 	cout << "YES";
		// }
		// else
		// {
		// 	cout << "NO";
		// }




		// optimal solution 
		// linear time -> O(n)

		unordered_map<int, int> m;

		bool flag = false;
		for(int i=0; i<n; i++)
		{
			if(m.count(arr[i]) == 0)
			{
				m.insert({arr[i], i});
			}
			else if(m.count(arr[i]) == 1)
			{
				int currentIdx = i;
				int prevIdx = m[arr[i]];

				if(currentIdx - prevIdx > 1)
				{
					flag = true;
					break;
				}
			}
		}

		if(flag)
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
