#include <bits/stdc++.h>

using namespace std;
int n, v[200001], ml[200001], maxL = 0, p;
int searchP(int i)
{
    int r = 0, k;
    for(int b=20; b>=0; b--)
    {
        k = (1<<b);
        if(r+k<=n && v[ml[r+k]]<v[i])
        {
            r = r + k;
        }
    }

    return r;
}
int main()
{
    cin>>n;
    v[0] = 1000000007;
    for(int i=1;i<=n;i++)
        cin>>v[i];

    for(int i=1;i<=n;i++)
    {
        p = searchP(i);
        ml[p+1] = i;
        maxL = max(maxL, p+1);
    }

    cout<<maxL;
    return 0;
}
