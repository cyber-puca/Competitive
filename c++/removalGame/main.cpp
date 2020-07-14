#include <bits/stdc++.h>

using namespace std;
const int N = 5001;
long long sol[N][N], v[N], sum[N], n;
bool d[N][N];

long long optim (int l, int r)
{
    if(d[l][r]==true)
        return sol[l][r];
    long long s = sum[r] - sum[l-1];
    sol[l][r] = s - min(optim(l+1, r), optim(l, r-1));
    d[l][r] = true;
    return sol[l][r];

}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>v[i];
        sum[i] = sum[i-1] + v[i];
    }

    for(int i=1;i<=n;i++)
    {
        sol[i][i] = v[i];
        d[i][i] = true;
    }

    cout<<optim(1,n);
    return 0;
}
