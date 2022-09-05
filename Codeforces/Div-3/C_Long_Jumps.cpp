// what i have done here is .
/*


    suppose my array is ,
    index -> 1 2 3 4 5 6 7 8 9 10
    array -> 1 1 2 3 2 3 1 1 1 2 
    
    // traverse from last and sum of element and index
    
    10 + 2 = 12 out of bount then nothing
    9 + 1 = 10 which is not out of bound so arr[9] = 1 + arr[1 + 9] = 1 + 2 = 3
    8 + 1 = 9 not outof bound then arr[8] = 1 + arr[1 + 8] = 1 + arr[9] = 1 + 3 = 5
    
    and so on.....
    
    
    




*/




#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		ll n;
		cin >> n;

		ll arr[n];
		for(int i=1; i<=n; i++)
		{
			cin >> arr[i];
		}

		for(int i=n; i>0; i--)
		{
			if(i + arr[i] <= n)
			{
				arr[i] = arr[i] + arr[i + arr[i]];
			}
		}


		ll ans = arr[n];
		for(int i=n; i>0; i--)
		{
			ans = max(ans, arr[i]);
		}

    
        
		cout << ans;
		cout << endl;


	}

	return 0;
}
