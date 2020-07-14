#include <bits/stdc++.h>

using namespace std;
int n, v[200001], sum, currSum, noOfSub;
int main()
{
    cin>>n>>sum;
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    int l=0,r=0;
    while(l<=r && r<n)
    {
        currSum += v[r];
        while(currSum>sum)
        {
            currSum -= v[l];
            l++;
        }

        if(currSum == sum)
        {
            noOfSub++;
        }
        r++;
    }
    cout<<noOfSub;
    return 0;
}
