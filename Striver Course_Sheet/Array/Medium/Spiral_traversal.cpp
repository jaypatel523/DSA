#include <bits/stdc++.h>
using namespace std;

void spiral(vector<vector<int> > & mat)
{
	int m = mat.size();
	int n = mat[0].size();


	int top = 0;
	int left = 0;
	int bottom = m - 1;
	int right = n - 1;


	while(top <= bottom && left <= right)
	{
		for(int i=left; i<=right; i++)
		{
			cout << mat[top][i] << " ";
		}
		top++;


		for(int i=top; i<=bottom; i++)
		{
			cout << mat[i][right] << " ";
		}
		right--;


		if(top <= bottom)
		{
			for(int i=right; i>=left; i--)
			{
				cout << mat[bottom][i] << " ";
			}
		}
		bottom--;


		if(left <= right)
		{
			for(int i=bottom; i>=top; i--)
			{
				cout << mat[i][left] << " ";
			}
		}

		left++;


	}

}






int main()
{
	int m, n;
	cin >> m >> n;

	// m x n matrix
	vector<vector<int> > mat(m, vector<int>(n));

	for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++)
		{
			cin >> mat[i][j];
		}
	}

	spiral(mat);




	return 0;
}



