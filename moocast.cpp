/*
	ID: theredh1
	LANG: C++
	PROG: angry
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define f first
#define s second
#define mp make_pair
void setIO(string name = "") { 
    ios_base::sync_with_stdio(0); cin.tie(0); 
   
    if (sz(name)) {
        freopen((name+".in").c_str(), "r", stdin); 
        freopen((name+".out").c_str(), "w", stdout);
    }
}
vector<int> adj[201];
bool visited[201];
ll n, m;
ll dfs(int node) {
//	if(visited[node])
//	return 0;
	
	ll count=1;
	visited[node]=true;
	for(auto x: adj[node])
	{
		if(!visited[x])
		{
			count+=dfs(x);
		}
	}
	return count;
}
int main() {
	setIO("moocast");
	cin>>n;
	vector<pair<pair<int,int>, int>> v;
	for(int i=0; i<n; i++)
	{
		ll n1, n2, n3;
		cin>>n1>>n2>>n3;
		v.pb(mp(mp(n1, n2), n3));
	}
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(i==j)
			{
				continue;
			}
			double a=sqrt(pow(abs(v[i].f.f-v[j].f.f),2)+pow(abs(v[i].f.s-v[j].f.s), 2));
			if(a<=v[i].s)
			{
				adj[i].pb(j);
			}
			if(a<=v[j].s)
			{
				adj[j].pb(i);
			}
		}
	}
	ll max=0;
	for(int i=0; i<n; i++)
	{
		max=fmax(dfs(i), max);
		memset(visited, false, n+1);
	}
	cout<<max<<endl;
}

