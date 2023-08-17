#include <bits/stdc++.h>
#define REP(i,a,b) for ( int i = a ; i < b ; i ++)
#define FAST cin.tie(NULL);cout.tie(NULL); ios::sync_with_stdio(false)
#define print(a) cout << a << "\n";
#define vprint(a) REP(i,0,a.size()) cout << a[i] << " "; cout << "\n";

using namespace std;

typedef long long ll;
typedef unsigned long long u64;
typedef unsigned int u32;
typedef vector<int> vi;

int n =0;
vector<pair<int,int>> sizes;
vi dp;


int mp(pair<int,int>a){
	return a.first*a.second;
}

void init()
{
	cin >> n;
	sizes = vector<pair<int,int>>(n);
	dp = vi(n+1,0);
	REP(i,0,n){
		int x,y;
		cin >> x >> y;
		sizes[i] = {x,y};
	};
	dp[1] = mp(sizes[0]);
}

void sol()
{

}

int main(){
	FAST;
	init();
	sol();
	return 0;
}

