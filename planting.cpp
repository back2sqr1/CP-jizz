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
int main()
{
	setIO("planting");
	int n;
	cin>>n;
	int a[n];
	fill(a, a+n, 0);
	for(int i=0; i<n-1; i++)
	{
		int n1,n2;
		cin>>n1>>n2;
		a[n1-1]++;
		a[n2-1]++;	
	}
	int max=0;
	for(int i=0; i<n; i++)
	{
		max=fmax(a[i], max);
	}
	cout<<max+1<<endl;
}
