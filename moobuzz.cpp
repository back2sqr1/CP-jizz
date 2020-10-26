/*
	ID: theredh1
	LANG: C++
	PROG: moobuzz
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
ll N;
bool check(ll x)
{
	
	ll y=x-(x/3+x/5-x/15);
	return N<=y;
} 
int main() {
    setIO("moobuzz");
	cin>>N;
	ll big=INT_MAX, small =0;
	while(small!=big)
	{
		ll mid=(small+big)/2;
		if(check(mid))
		{
			big=mid;
		}
		else
		{
			small=mid+1;
		}
	}
	cout<<small<<endl;
}


