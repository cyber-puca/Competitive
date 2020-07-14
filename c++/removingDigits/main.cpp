#include <bits/stdc++.h>

using namespace std;
const int N = 1000001;
int steps[N], n, ci;

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        ci = i;
        vector<int> d;
        while(ci>0)
        {
            d.push_back(ci%10);
            ci=ci/10;
        }
        int s = d.size();
        steps[i]=N;
        for(int j=0;j<s;j++)
        {
            steps[i]=min(steps[i-d[j]]+1,steps[i]);
        }
    }
    cout<<steps[n];
    return 0;
}
