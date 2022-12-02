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
    ll n, q;
    cin >> n >> q;

    vector<ll> arr(n+1, 0);
    ll sum = 0;
    map<ll, ll> m;
    for(int i=1; i<=n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
        m[i-1] = arr[i];
    }



    
    ll last = 0;
    for(int i=0; i<q; i++) 
    {
        ll t;
        cin >> t;

        ll a, b;
        if(t == 1)
        {
            cin >> a >> b;
            if(m[a-1] == 0)  m[a-1] = last;
            sum -= m[a-1];
            sum += b;
            m[a-1] = b;
        }
        else
        {
            cin >> a;
            sum = a * n;
            last = a;
            m.clear();
        }

        cout << sum << endl;

    }


}


int main()
{
    // int t;
    // cin >> t;

    // while(t--)
    // {
      solve();
    // }

    return 0;
}
