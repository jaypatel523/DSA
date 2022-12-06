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


bool isSorted(vector<int> & ans)
{
	int n = ans.size();
	for(int i=0; i<n-1; i++)
	{
		if(ans[i] > ans[i+1]) return false;
	}

	return true;
}


void solve()
{
	int n;
	cin >> n;

	string s;
	cin >> s;

	// concept (we will count number of substrings which are paranoid and end with ith index)

	/*
	
		11, 00 are not paranoid
		any string which ends with 01 or 10 is always paranoid 
	
	
	*/


	ll ans = 0;
	for(int i=n-1; i>=0; i--)
	{
		if(i == 0) ans++;
		else if(s[i] == s[i-1]) ans++;
		else ans += (i+1);
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
