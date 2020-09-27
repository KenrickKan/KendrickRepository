//ctrl alt i new-head
#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define mem(a) memset(a, 0, sizeof(a))
typedef long long ll;
struct knumber
{
    int num;
    int worb;
    int loc;
};
bool cmp(knumber a, knumber b)
{
    return a.num < b.num;
}
bool cmp1(knumber a, knumber b)
{
    return a.loc < b.loc;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        //knumber a[10005];
        //mem(a);
        vector<knumber> a;
        int n, k;
        cin >> n >> k;
        rep(i, 0, n)
        {
            knumber x;
            cin >> x.num;
            x.worb = 0;
            x.loc = i;
            a.push_back(x);
        }
        sort(a.begin(), a.end(), cmp);
        int leftloc = 0, rightloc = n - 1;
        int cnt = a[leftloc].num + 1;
        int ifworb = 0;
        while (leftloc < rightloc)
        {
            if ((a[leftloc].num + a[rightloc].num) != k)
            {
                a[rightloc].worb = a[leftloc].worb;
                if ((a[leftloc].num + a[rightloc].num) < k)
                    leftloc++;
                else
                    rightloc--;
            }
            else
            {
                if ((a[rightloc].num + cnt) == k)
                {
                    if (ifworb == 1)
                        a[rightloc].worb = 0;
                    else
                        a[rightloc].worb = 1;
                    ifworb = a[rightloc].worb;
                }
                else
                {
                    if (a[leftloc].worb == 0)
                        a[rightloc].worb = 1;
                    else
                        a[rightloc].worb = 0;
                    cnt = a[rightloc].num;
                    ifworb = a[rightloc].worb;
                }
                rightloc--;
            }
        }
        sort(a.begin(), a.end(), cmp1);
        rep(i, 0, n)
        {
            cout << a[i].worb << ' ';
        }
        cout << endl;
    }
    return 0;
}