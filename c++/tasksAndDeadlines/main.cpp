#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int> > t;
long long n,task,d,r;

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>task>>d;
        t.push_back(make_pair(task,d));
    }
    sort(t.begin(),t.end());
    long long cT=0;
    for(int i=0;i<n;i++)
    {
        cT += t[i].first;
        r += t[i].second-cT;
    }

    cout<<r;
    return 0;
}
