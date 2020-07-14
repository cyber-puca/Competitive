#include <bits/stdc++.h>

using namespace std;

long long n, sum;
int maxV, x;
pair<int,int> v[1001],s;
pair<int,pair<int,int> > p[1000001];

pair<int,int> searchX(int v)
{
    long long r=0,k;
    for(int b=20;b>=0;b--)
    {
        k=(1LL<<b);
        if(r+k<n*(n-1)/2 && p[r+k].first<=v)
        {
            r += k;
        }
    }
    if(p[r].first==v)
        return make_pair(p[r].second.first,p[r].second.second);
    else
        return make_pair(-1,-1);
}

int main()
{
    cin>>n>>sum;
    for(int i=0;i<n;i++)
    {
        cin>>v[i].first;
        v[i].second = i+1;
    }
    int k=0;
    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
        {
            p[k].first = v[i].first+v[j].first;
            p[k].second.first = v[i].second;
            p[k].second.second = v[j].second;
            k++;
        }
    sort(p,p+k);

    for(int i=0;i<k;i++)
    {
        x = sum - p[i].first;
        if(x>=0)
        {
            s = searchX(x);
            if(s.first != -1 && !(s.first==p[i].second.first || s.first==p[i].second.second || s.second==p[i].second.first || s.second==p[i].second.second))
            {
                cout<<p[i].second.first<<" "<<p[i].second.second<<" "<<s.first<<" "<<s.second;
                return 0;
            }
        }
    }

    cout<<"IMPOSSIBLE";
    return 0;
}
