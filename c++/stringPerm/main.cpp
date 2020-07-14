#include <bits/stdc++.h>
using namespace std;

int len, n,x;
multiset<int> diff;
set<int> l;

int main()
{
    cin>>len>>n;
    l.insert(0);
    l.insert(len);
    diff.insert(len);

    for(int i=0;i<n;i++)
    {
        cin>>x;
        auto p = l.upper_bound(x);
        int val = *p;
        p--;
        int val2 = *p;
        diff.erase(diff.find(val-val2));
        diff.insert(x-val2);
        diff.insert(val-x);
        l.insert(x);
        p=diff.end();
        p--;
        cout<<*p<<" ";
    }
    return 0;
}
