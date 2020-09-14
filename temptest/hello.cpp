#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		int a[3];
		for (int i = 0; i < m; i++)
			cin >> a[i];
		if (m == 3)
			cout << a[1] << endl;
		else if (m == 1)
		{
			cout << a[0] << endl;
		}
		else
		{
			if (n == 2)
				cout << -1 << endl;
			else
			{
				if (a[0] == 1)
					cout << 1 << endl;
				if (a[1] == n)
					cout << n << endl;
			}
		}
	}

	return 0;
}