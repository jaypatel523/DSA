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



		long long fpn = 0; // firstPositiveNumber
		long long fpi = 0; // firstPositiveIndex

		for(int i=0; i<n; i++)
		{
			if(arr[i] > 0)
			{
				fpn = arr[i];
				fpi = i;
				break;
			}
		}

		for(int i=fpi+1; i<n; i++)
		{
			fpn += arr[i];
			if(fpn < 0) fpn = 0;
		}

		cout << fpn << endl;

	}

	return 0;
}
