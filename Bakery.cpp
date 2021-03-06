#include<iostream>
#include<bits/stdc++.h>
typedef long long int ll;
#define pp pair<ll,ll>
#define dbg printf("in");
#define NL printf("\n");
#define inf 1000000000000
#define max2(a,b) ((a<b)?b:a)
#define max3(a,b,c) max2(max2(a,b),c)
#define min2(a,b) ((a>b)?b:a)
#define min3(a,b,c) min2(min2(a,b),c)
using namespace std;
struct edge
{
    ll to,cost;
    edge(ll a,ll b)
    {
        to=a;cost=b;
    }
};
vector<edge>a[100010];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    ll i,j;
    ll n,m,k;
    ll u,v,w;
    cin>>n>>m>>k;
    for(i=0;i<m;i++)
    {
        cin>>u>>v>>w;
        a[u].push_back(edge(v,w));
        a[v].push_back(edge(u,w));
    }
    if(k==0)
    {
        printf("-1");
        return 0;
    }
    map<ll,bool> mp;
    for(i=0;i<k;i++)
    {
        cin>>j;
        mp[j]=1;
    }
    ll res=inf;
    for(i=1;i<=n;i++)
    {
        if(mp[i]==1 and a[i].size()>0)
        {
            for(j=0;j<a[i].size();j++)
            {
                if(mp[a[i][j].to]==0 and a[i][j].cost<res)
                {
                    res=a[i][j].cost;
                }
            }
        }
    }
    if(res!=inf)
    {
        printf("%I64d",res);
    }
    else
    {
        printf("-1");
    }
    cin.clear();
    cin.ignore();
    cin.get();
    return 0;
}
