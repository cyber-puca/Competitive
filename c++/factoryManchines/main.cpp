#include <bits/stdc++.h>

using namespace std;

const int N=200001;
long long n, prod, t[N];

bool pos(long long tm)
{
    long long p = 0;
    for(int i=0;i<n;i++)
    {
        if(p>(1LL<<30))
            return true;
        p += tm/t[i];
    }
    if(p>=prod)
        return true;
    else
        return false;
}

long long searchT()
{
    long long r=0,k;
    for(int i=60;i>=0;i--)
    {
       k=(1LL<<i);
       if(!pos(r+k))
       {
           r += k;
       }
    }
    return r+1;
}
int main()
{
    cin>>n>>prod;

    for(int i=0;i<n;i++)
        cin>>t[i];

    cout<<searchT();
    return 0;
}
