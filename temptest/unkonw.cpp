/*
 * @Author: KendrickKan 
 * @Date: 2020-09-27 22:14:26 
 * @Last Modified by: KendrickKan
 * @Last Modified time: 2020-09-27 22:21:12
 */
#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define rep(i, a, b) for (int i = a; i < b; i++)
#define repp(i, a, b) for (int i = a; i <= b; i++)
#define rep1(i, a, b) for (int i = a; i >= b; i--)
#define mem(a) memset(a, 0, sizeof(a))
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define eps 1e-10
#define mod 1e9 + 7
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int main()
{
	FastIO;
	string str;
	cin >> str;
	int a[10];
	mem(a);
	rep(i, 0, str.length())
	{
		a[str[i] - '0']++;
	}
	rep(i, 0, 10)
	{
		if (a[i] != 0)
			cout << i << ':' << a[i] << endl;
	}
	return 0;
}