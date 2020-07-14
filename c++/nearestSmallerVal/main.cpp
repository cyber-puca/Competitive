#include <bits/stdc++.h>

using namespace std;
int v[200001];
stack<int> maxP;
int n;

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>v[i];
    }
    for(int i=1;i<=n;i++)
    {
        while(!maxP.empty() && v[maxP.top()]>=v[i])
        {
            maxP.pop();
        }
        if(maxP.empty())
            cout<<"0 ";
        else
            cout<<maxP.top()<<" ";
        maxP.push(i);

    }
    return 0;
}
