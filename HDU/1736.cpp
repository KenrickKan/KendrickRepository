#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    //cout.tie(NULL);
    string a;
    while (cin >> a)
    {
        int judge = 1;
        for (int i = 0; i < a.length(); i++)
        {
            if (a[i] == ',')
                cout << "，";
            else if (a[i] == '.')
                cout << "。";
            else if (a[i] == '!')
                cout << "！";
            else if (a[i] == '<' && a[i + 1] == '<')
            {
                cout << "《";
                i++;
            }
            else if (a[i] == '>' && a[i + 1] == '>')
            {
                cout << "》";
                i++;
            }
            else if (a[i] == '?')
                cout << "？";
            else if (a[i] == '"')
            {
                if (judge == 1)
                {
                    cout << "“";
                    judge = 0;
                }
                else
                {
                    cout << "”";
                    judge = 1;
                }
            }
            else
                cout << a[i];
            if (a[i] < 0 && a[i + 1] == -80)
            {
                judge = 0;
            }
            if (a[i] < 0 && a[i + 1] == -79)
            {
                judge = 1;
            }
        }
        cout << endl;
    }

    return 0;
}