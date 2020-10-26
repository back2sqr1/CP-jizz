/*
	ID: theredh1
	LANG: C++
	PROG: diamond
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
#define all(x) (x).begin(), (x).end()
void setIO(string name = "") { 
    ios_base::sync_with_stdio(0); cin.tie(0); 
   
    if (sz(name)) {
        freopen((name+".in").c_str(), "r", stdin); 
        freopen((name+".out").c_str(), "w", stdout);
    }
} 
void show(vector<ll> v)
{
    for(ll i=0; i<v.size(); i++)
        cout<<v[i]<<" ";
    cout<<"\n";
}
void showrev(vector<ll> v)
{
    for(ll i=0; i<v.size(); i++)
        cout<<v[v.size()-i-1]<<" ";
    cout<<"\n";
}
void showarr(ll arr[],ll n)
{
    for(ll i=0; i<n; i++)
        cout<<arr[i]<<" ";
    cout<<"\n";
}
struct Rect{
	int x1,y1,x2,y2;
	int area()
	{
		return (x2-x1)*(y2-y1);
	}
};
const int mxN=2e5;
int main() {
	ios_base::sync_with_stdio(false);
	//setIO("homework");
	ll n, q;
	cin>>n>>q;
	vector<int> v;
	int pre[n+1];
	pre[0]=0;
	for(int i=1; i<=n; i++)
	{
		int num;
		cin>>num;
		pre[i]=pre[i-1]^num;
	}
	for(int i=0; i<q; i++){
		int l, r;
		cin>>l>>r;
		cout<<(pre[l-1]^pre[r])<<endl;
	}
}
