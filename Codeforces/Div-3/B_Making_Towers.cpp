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

		int arr[n+1];
		for(int i=1; i<=n; i++)
		{
			cin >> arr[i];
		}

		vector<int> temp(n+1, 0);
		vector<int> parity(n+1, -1);

		// odd = 1
		// even = 0


		for(int i=1; i<=n; i++)
		{
			if(parity[arr[i]] == -1)
			{
				temp[arr[i]]++;
				parity[arr[i]] = i % 2;
			}
			else if(parity[arr[i]] == 1)
			{
				if(i % 2 == 0)
				{
					temp[arr[i]]++;
					parity[arr[i]] = 0;
				}	
			}
			else if(parity[arr[i]] == 0)
			{
				if(i % 2 == 1)
				{
					temp[arr[i]]++;
					parity[arr[i]] = 1;
				}
			}
		}

		for(int i=1; i<=n; i++)
		{
			cout << temp[i] << " ";
		}




		cout << endl;
	}

	return 0;
}
