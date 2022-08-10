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



		sort(arr, arr + n);

		int minimax = INT_MIN;
		int sub = 0;

		for(int i=0; i<n; i++)
		{
			minimax = max(minimax, arr[i] - sub);
			sub = arr[i];
		}


		cout << minimax;
		cout << endl;


	}

	return 0;
}
