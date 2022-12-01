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
	int n, s;
	cin >> n >> s;

	int sm = 0;
	int arr[n];
	for(int i=0; i<n; i++) cin >> arr[i], sm += arr[i];

	if(sm < s)
	{
		cout << "-1";
	}
	else if(sm == s)
	{
		cout << "0";
	}
	else
	{
		int res = 0;
		int i=0, j=0;
		int low = 0;
		int high = 0;

		int sum = 0;
		while(j < n)
		{
			sum += arr[j];

			if(sum < s) j++;
			else if(sum == s)
			{
				// res = max(res, j-i+1);
				if(j-i+1 > res)
				{
					res = j - i + 1;
					low = i;
					high = j;
				}
				j++;
			}
			else
			{
				while(sum > s)
				{
					sum -= arr[i];
					i++;
					if(sum == s)
					{
						if(j-i+1 > res)
						{
							res = j - i + 1;
							low = i;
							high = j;
						}
						break;
					}
				}
				j++;
			}


		}

		cout << low + n - high - 1;

	}

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
