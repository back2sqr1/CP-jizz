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
vector<int> adj[3001];
bool closed[3001], visited[3001];
ll n, m;
ll dfs(int node) {
	if(node==0 || closed[node])
	return 0;
	ll visCount=1;
	
	visited[node]=true;
    for (auto neighbour: adj[node]) {
        if (!closed[neighbour] && !visited[neighbour]) {
            visCount+=dfs(neighbour);
        }
    }
    return visCount;
}
bool check(ll d)
{
	ll a=0, first=0;
	for(int i=1; i<=n; i++)
	{
		if(!closed[i])
		{
			a++;
		}
	}
	memset(visited, false, n+1);
	ll b=dfs(d);
//	cout<<a<<' '<<b<<endl;
	return a==b;
}
int main() {
//	setIO("closing");
	cin>>n>>m;
	for(int i=0; i<m; i++)
	{
		ll n1, n2;
		cin>>n1>>n2;
		adj[n1].pb(n2);
		adj[n2].pb(n1);
	}
	for(int i=0; i<n; i++)
	{
		ll N;
		cin>>N;
		
		if(check(N))
		cout<<"YES"<<endl;
		else
		cout<<"NO"<<endl;
		
		closed[N]=true;
	//	cout<<N;
		for(auto x: adj[N])
		{
		//	cout<<' '<<x;
			closed[x]=true;
		}
	//	cout<<endl;
	}
}

