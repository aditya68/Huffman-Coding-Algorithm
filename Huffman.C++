#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ll long long
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pii>
#define all(a) (a).begin(),(a).end()
#define X first
#define Y second
#define setpr(x) cout<<fixed<<setprecision(x)
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define pi pair<int,pii>
#define pr pair<int,node*>
#define endl '\n'
const int inf=2e9;
const int mod=1e9+7;
const int N=1e5+5;
struct node {
    char ch; int freq;
    node *left,*right;
    node(){ch='#'; freq=0; left=right=NULL;}
};
map <char,string> ans;
void dfs(node *t,string code)
{
    if(!t->left)
    {
        ans[t->ch]=code;
        return;
    }
    dfs(t->left,code+"0");
    dfs(t->right,code+"1");
    return;
}
void solve()
{
    string s; getline(cin,s);
    map <char, int> f;
    vector <char> v;
    for(int i=0;i<s.size();i++)
    {
        if(!f[s[i]])v.pb(s[i]);
        f[s[i]]++;
    }
    priority_queue <pr, vector<pr>, greater<pr> >  pq;
    for(int i=0;i<v.size();i++)
    {
        node* ptr=new node();
        ptr->ch=v[i];
        ptr->freq=f[v[i]];
        pq.push({ptr->freq,ptr});
    }
    while(pq.size()>1)
    {
        pr p1=pq.top(); pq.pop();
        pr p2=pq.top(); pq.pop();
        node *ptr=new node();
        ptr->freq=p1.X+p2.X;
        ptr->left=p1.Y;
        ptr->right=p2.Y;
        pq.push({ptr->freq,ptr});
    }
    pr p=pq.top(); pq.pop();
    node *root=p.Y;
    dfs(root,"");
    for(int i=0;i<v.size();i++)cout<<ans[v[i]]<<" ";
    cout<<endl; string output,res;
    for(int i=0;i<s.size();i++)output+=ans[s[i]];
    for(int i=0;i<output.size();i+=8)
    {
        int cnt=0;
        for(int j=0;(j<8)&&(i+j<output.size());j++)cnt+=(output[i+j]-'0')*pow(2,(7-j));
        char t=cnt;
        res+=t;
    }
    cout<<res;
    return;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    while(t--)solve();
    return 0;
}
