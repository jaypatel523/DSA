#include <bits/stdc++.h>
using namespace std;
#define ll long long


// print pascal triangle 
vector<vector<int>> pascal1(int n)
{
	vector<vector<int>> ans(n);

	for(int i=0; i<n; i++)
	{
		ans[i].resize(i+1);
		ans[i][0] = ans[i][i] = 1;

		for(int j=1; j<i; j++)
		{
			ans[i][j] = ans[i-1][j-1] + ans[i-1][j];
		}
	}

	return ans;

}




// print nth row of triangle 
vector<int> pascal2(int n)
{
	vector<vector<int>> ans(n);

	for(int i=0; i<n; i++)
	{
		ans[i].resize(i+1);
		ans[i][0] = ans[i][i] = 1;

		for(int j=1; j<i; j++)
		{
			ans[i][j] = ans[i-1][j-1] + ans[i-1][j];
		}
	}

	return ans[n-1];

}


	
// return element at rth row and cth column
ll elementAtPosition(ll r, ll c)
{
	r--;
	c--;

	ll upperPart = 1;
	for(ll i=r; i>(r-c); i--)
	{
		upperPart *= i;
	}

	ll lowerPart = 1;
	for(ll i=1; i<=c; i++)
	{
		lowerPart *= i;
	}



	return upperPart / lowerPart;
}



int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		int n;
		cin >> n;


		// print pascal triangle 
		// vector<vector<int>> tr = pascal1(n);
		// for(int i=0; i<tr.size(); i++)
		// {
		// 	for(int j=0; j<tr[i].size(); j++)
		// 	{
		// 		cout << tr[i][j] << " ";
		// 	}
		// 	cout << endl;
		// }
		// cout << endl;





		// print nth row 
		// vector<int> tr = pascal2(n);
		// for(int i=0; i<n; i++)
		// {
		// 	cout << tr[i] << " ";
		// }
		// cout << endl;





		// element at 5th row and 3rd column
		// cout << elementAtPosition(5, 3) << endl;




		// cout << endl;


	}

	return 0;
}
