#include <bits/stdc++.h>
using namespace std;



void transpose(vector<vector<int> > & mat)
{
	int n = mat.size();

	for(int i=0; i<n; i++)
	{
		for(int j=0; j<=i; j++)
		{
			swap(mat[i][j], mat[j][i]);
		}
	}

}
	

void print(vector<vector<int> > & mat)
{
	int n = mat.size();
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}



vector<vector<int> > rotate90_brute(vector<vector<int> > & mat)
{
	int n = mat.size();

	vector<vector<int> > rotated(n, vector<int>(n));
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			rotated[j][n-i-1] = mat[i][j];
		}
	}

	return rotated;

}


void rotate90_optimal(vector<vector<int> > & mat)
{
	int n = mat.size();

	transpose(mat);
	for(int i=0; i<n; i++)
	{
		reverse(mat[i].begin(), mat[i].end());
	}
}








// matrix must be square matrix

int main()
{
	int n;
	cin >> n;

	vector<vector<int> > mat(n, vector<int>(n));
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			cin >> mat[i][j];
		}
	}



	// vector<vector<int> > ans = rotate90_brute(mat);
	// print(ans);



	// rotate90_optimal(mat);
	// print(mat);

	return 0;
}
