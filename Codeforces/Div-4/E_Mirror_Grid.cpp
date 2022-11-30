#include <bits/stdc++.h>
using namespace std;
#define ll long long


int __gcd(int a, int b) 
{ 
    if (b == 0)  return a; 
    return __gcd(b, a % b); 
}


int __lcm(int a, int b)
{
	int ans = (a * b) / __gcd(a, b);
	return ans;
}


bool isPrime(int num)
{
	if(num == 0 || num == 1) return false;
	
	for(int i=2; i*i <= num; i++)
	{
		if(num % i == 0) return false;
	}

	return true;
}




void solve()
{
	int n;
	cin >> n;

	vector<vector<char>> arr(n, vector<char>(n));

	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++) cin >> arr[i][j];
	}

		

	int ans = 0;
	for(int i=0; i<n-1; i++)
	{
		for(int j=i; j<n-i-1; j++)
		{
			int one = 0;
			int zero= 0;

			if(arr[i][j] == '0') zero++;
			else one++;

			if(arr[n-i-1][n-j-1] == '0') zero++;
			else one++;

			if(arr[j][n-i-1] == '0') zero++;
			else one++;

			if(arr[n-j-1][i] == '0') zero++;
			else one++;
				
			// cout << i << j << " " << n-i-1 << n-j-1<< endl;
			// cout << j << n-i-1 << " " << n-j-1 << i << endl;

			ans += min(zero, one);


		}
		// cout << endl;
	}
			
	cout << ans << endl;


}






int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		solve();
	}

	return 0;
}
