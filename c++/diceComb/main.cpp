#include <bits/stdc++.h>

using namespace std;
const int m = 1000000007;
int n, solve[1000001];

int main()
{
    cin>>n;
    solve[0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=6;j++)
        {
            if(i-j>=0)
            {
                solve[i] = (solve[i]+ solve[i-j])%m;
            }
        }
    }
    cout<<solve[n];
    return 0;
}
