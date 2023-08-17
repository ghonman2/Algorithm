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

int n ,m = 0;
vi nums;
vector<pair<int,int>> conds;
vector<vi> dp;
void init()
{
	cin >> n;
	nums = vi(n+1,0);
	REP(i,1,n+1) cin >> nums[i];
	cin >> m;
	REP(i,0,m){
		int frm,dst;
		cin >> frm >>dst;
		conds.push_back({frm,dst});
	}
	dp = vector<vi>(n+1,vi(n+1,-1));
	return;
}

int search(int i ,int j)
{
	if(i > j) return 1;
	if(dp[i][j] == -1){
		if(i == j) dp[i][j] = 1;
		else if (nums[i] == nums[j]) dp[i][j] = search(i+1,j-1);
		else dp[i][j] = 0;
	}
	return dp[i][j];
}
void sol()
{
	for(auto cond : conds){
		int frm = cond.first, dst = cond.second;
		cout << search(frm,dst) << "\n";
	}
}

int main(){
	FAST;
	init();
	sol();
	return 0;
}

