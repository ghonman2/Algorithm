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

int n,k;
int sizes;
vi dp;

void init()
{
	cin >> n >> k ;
	sizes = 100000 + 1;
	dp = vi (sizes,INT_MAX);
}

void add_queue(queue<pair<int,int>>&q, int now, int cnt)
{
	if (0 <= now * 2  && now * 2 < sizes && dp[now*2] > cnt)
	{
		dp[now*2] = cnt;
		q.push({now*2,cnt});
	}
	if (0 <= now + 1 && now < sizes && dp[now + 1] > (cnt + 1))
	{
		dp[now + 1] =cnt + 1;
		q.push({now + 1, cnt + 1});
	}
	if (0 <= now - 1 && now < sizes && dp[now - 1] > (cnt + 1))
	{
		dp[now - 1] = cnt + 1;
		q.push({now - 1, cnt + 1});
	}
}

void sol()
{
	queue<pair<int,int>>q;
	dp[n] = 0;
	q.push({n,0});
	while(!q.empty())
	{
		int now,cnt;
		tie(now,cnt) = q.front(); q.pop();
		if (now == k){
			cout << dp[k] << "\n";
			break;
		}
		add_queue(q,now,cnt);
	}
}


int main(){
	FAST;
	init();
	sol();
	return 0;
}

