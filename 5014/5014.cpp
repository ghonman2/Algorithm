#include <bits/stdc++.h>
#define REP(i,a,b) for ( int i = a ; i < b ; i ++)
#define FAST cin.tie(NULL);cout.tie(NULL); ios::sync_with_stdio(false)
#define print(a) cout << a << "\n"
using namespace std;

typedef long long ll;
typedef unsigned long long u64;
typedef unsigned int u32;
typedef vector<int> vi;

#define MAX 1000000
int F,S,G,U,D;
int dp[MAX];
void init()
{
	memset(dp,0,sizeof(dp));
	cin >> F >> S >> G >> U >> D;
}

int dfs()
{
	queue<pair<int,int>> q;
	q.push({S,0});
	dp[S] = 1;
	while (!q.empty()){
		auto node = q.front();q.pop();
		int floor = node.first, cnt = node.second;

		if (floor == G)
			return cnt;

		int ufloor = floor + U;
		int dfloor = floor - D;

		if ( 0 < ufloor && ufloor <= F && !dp[ufloor]){
			dp[ufloor] = 1;
			q.push({ufloor,cnt+1});
		}
		if ( 0 < dfloor && dfloor <=F   && !dp[dfloor]){
			dp[dfloor] = 1;
			q.push({dfloor,cnt+1});
		}
	}

	return -1;
}


int main(){
	FAST;
	init();
	int answer = dfs();

	if (answer == -1)
		print("use the stairs");
	else 
		print(answer);

	return 0;
}
