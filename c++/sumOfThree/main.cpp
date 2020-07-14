#include <bits/stdc++.h>

using namespace std;

long long n, sum, temp,x,s;
pair<int,int> v[5001];

int searchX(int x)
{
    long long r=0,k;
    for(int b=20;b>=0;b--)
    {
        k=(1LL<<b);
        if(r+k<n && v[r+k].first<=x)
        {
            r += k;
        }
    }
    if(v[r].first==x)
        return v[r].second;
    else
        return -1;
}

int main()
{
    cin>>n>>sum;
    for(int i=0;i<n;i++)
    {
        cin>>v[i].first;
        v[i].second = i+1;
    }
    sort(v,v+n);
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            temp = v[i].first+v[j].first;
            x = sum - temp;
            s = searchX(x);
            if(s!=-1 && s!=v[i].second && s!=v[j].second)
            {
               cout<<v[i].second<<" "<<v[j].second<<" "<<s;
               return 0;
            }
        }
    }
    cout<<"IMPOSSIBLE";
    return 0;
}
