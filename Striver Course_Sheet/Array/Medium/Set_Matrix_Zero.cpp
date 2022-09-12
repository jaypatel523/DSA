#include <bits/stdc++.h>
using namespace std;



void setZeros1(vector<vector<int>> & mat)
{
	int m = mat.size();
	int n = mat[0].size();

	for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(mat[i][j] == 0)
			{
				int idx = i-1;
				while(idx >= 0)
				{
					mat[idx][j] = -1;
					idx--;
				}

				idx = i + 1;
				while(idx < m)
				{
					mat[idx][j] = -1;
					idx++;
				}

				idx = j - 1;
				while(idx >= 0)
				{
					mat[i][idx] = -1;
					idx--;
				}

				idx = j + 1;
				while(idx < n)
				{
					mat[i][idx] = -1;
					idx++;
				}

			}
		}
	}

	for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(mat[i][j] < 0)
			{
				mat[i][j] = 0;
			}
		}
	}


}



void setZeros2(vector<vector<int> > & mat)
{
	int m = mat.size();
	int n = mat[0].size();

	vector<int> d1(m, -1);
	vector<int> d2(n, -1);

	for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(mat[i][j] == 0)
			{
				d1[i] = 0;
				d2[j] = 0;
			}
		}
	}

	for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(d1[i] == 0 || d2[j] == 0)
			{
				mat[i][j] = 0;
			}
		}
	}
}



void setZeros3(vector<vector<int> > & matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
	
    // for first element of first row
    bool firstRow = false;
	
    // for first element of first column
    bool firstCol = false;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(matrix[i][j] == 0)
            {
                if(i == 0)
                {
                    firstRow = true;
                }
                
                if(j == 0)
                {
                    firstCol = true;
                }
                
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }
    
    for(int i=1; i<n; i++)
    {
        for(int j=1; j<m; j++)
        {
            if(matrix[i][0] == 0 || matrix[0][j] == 0)
            {
                matrix[i][j] = 0;
            }
        }
    }
    
    if(firstRow)
    {
        for(int i=0; i<m; i++)
        {
            matrix[0][i] = 0;
        }
        
    }
    
    if(firstCol)
    {
        for(int i=0; i<n; i++)
        {
            matrix[i][0] = 0;
        }
    }
        
}


int main()
{
	int m, n;
	cin >> m >> n;


	vector<vector<int> > mat(m, vector<int>(n));

	for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++)
		{
			cin >> mat[i][j];
		}
	}



	// brute force
	// setZeros1(mat);



	// better brute force
	// setZeros2(mat);



	// optimal approach
	// setZeros3(mat);



	for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++)
		{
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}



	return 0;
}
