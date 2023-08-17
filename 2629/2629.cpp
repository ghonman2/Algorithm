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


int n = 0 ;
vi chus;
int m = 0;
vi balls;

void init()
{
	cin >> n ;
	chus = vi(n,0);
	REP(i,0,n)cin >> chus[i];
	cin >> m;
	balls = vi(m,0);
	REP(i,0,m)cin >> balls[i];
}

void sol()
{
	int sums = accumulate(chus.begin(),chus.end(),0);
	vi dp(sums+1,0);
	dp[0] =1 ;
	for(auto chu : chus){
		for(int i = sums-chu; i >= 0 ; i --){
			dp[i+chu] |= dp[i];
		}
	}
	for(auto chu : chus){
		for(int i = chu; i <= sums; i++){
			if(dp[i] == 1) dp[i-chu] = 1;
		}
	}
	for(auto ball : balls){
		if( ball <= sums && dp[ball]) cout << "Y" << " ";
		else cout << "N" << " ";
	}
	cout << "\n";
}

int main(){
	FAST;
	init();
	sol();
	return 0;
}

