#include <bits/stdc++.h>

using namespace std;
const int M = 1000000007;
long long n, sum, sol[250000];

int main()
{
    cin>>n;
    sum = n*(n+1)/2;
    if(sum%2!=0)
    {
        cout<<0;
        return 0;
    }
    else
        sum = sum/2;

    sol[0] = 1;
    for(int j=1;j<=n;j++)
        for(int i=sum;i>=0;i--)
        {
            if(sol[i]!=0)
            {
                sol[i+j] = sol[i+j] + sol[i];
                if(sol[i+j]>2*M)
                    sol[i+j] %= M;
            }
        }

    cout<<sol[sum]/2;
    return 0;
}
