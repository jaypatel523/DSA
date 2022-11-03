#include <bits/stdc++.h>
using namespace std;



string mtoh(int m)
{
	
	int minute = m % 60;
	int hour = m / 60;

	string temp1 = to_string(hour);
	string temp2 = to_string(minute);



	string left = "";
	if(temp1.size() == 1)
	{
		left += '0';
	}
	left += temp1;


	string right = "";
	if(temp2.size() == 1)
	{
		right += '0';
	}
	right += temp2;




	return (left + ":" + right);
}



int htom(string s)
{
	string left = "";
	left += s[0];
	left += s[1];
	int hour = stoi(left);


	string right = "";
	right += s[3];
	right += s[4];
	int minute = stoi(right);

	int ans = (hour * 60) + minute;

	return ans;
}


bool checkPalindrome(string s)
{
	int i=0;
	int j=s.size()-1;

	while(i <= j)
	{
		if(s[i] != s[j])
		{
			return false;
		}
		else
		{
			i++;
			j--;
		}
	}

	return true;
}



int countPalindrome(int m, int x)
{

	int ans = 0;
	ans += checkPalindrome( mtoh(m) );
	int num = (m + x) % 1440;
	while(num != m)
	{
		ans += checkPalindrome( mtoh(num) );
		num = (num + x) % 1440;
	}

	return ans;
}



int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		string s;
		cin >> s;

		int x;
		cin >> x;

		x = x % 1440;

		int m = htom(s);

		cout << countPalindrome(m, x);


		cout << endl;

	}

	return 0;
}
