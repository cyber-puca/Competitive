#include <bits/stdc++.h>

using namespace std;
int n, c[101], sum, counter;
bool s[100001];
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>c[i];
        sum += c[i];
    }
    s[0] = true;
    for(int j=1;j<=n;j++)
    {
        for(int i=sum;i>=0;i--)
        {
            if(s[i]==true)
            {
                s[i+c[j]] = true;
            }
        }
    }
    for(int j=1;j<=sum;j++)
    {
        if(s[j]==true)
        {
            counter++;
        }
    }
    cout<<counter<<"\n";
    for(int j=1;j<=sum;j++)
    {
        if(s[j]==true)
        {
            cout<<j<<" ";
        }
    }
    return 0;
}
