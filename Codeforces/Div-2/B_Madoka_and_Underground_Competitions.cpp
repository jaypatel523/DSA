#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		int n, k, r, c;
		cin >> n >> k >> r >> c;

		char mat[n][n];
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<n; j++)
			{
				mat[i][j] = '.';
			}
		}

		
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<n; j++)
			{
				if( (i+j) % k == (r+c-2)%k )
				{
					mat[i][j] = 'X';
				}
			}
		}



		

		for(int i=0; i<n; i++)
		{
			for(int j=0; j<n; j++)
			{
				cout << mat[i][j];
			}
			cout << endl;
		}







	}

	return 0;
}
