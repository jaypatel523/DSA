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

	vector<int> arr;
	for(int i=0; i<n; i++)
	{
		int x;
		cin >> x;
		arr.push_back(x);
	}

	vector<int> ans;
	if(n % 2 == 1)
	{
		ans.push_back(arr[0]);
		arr.erase(arr.begin());
	}

	for(int i=0; i<arr.size(); i+=2)
	{
		ans.push_back(min(arr[i], arr[i+1]));
		ans.push_back(max(arr[i], arr[i+1]));
	}

	if(isSorted(ans)) cout << "YES";
	else cout << "NO";



	cout << endl;
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
