#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		int m;
		cin >> m;
		cin.clear();
		char name[100][163];
		cin.get();//去掉输入m之后的回车
		for (int i = 0; i < m + 2; i++)
		{
			cin.getline(name[i], 163);
		}
		for (int k = 0; k < m; k++)
			cout << name[k] << endl;
	}

	return 0;
}