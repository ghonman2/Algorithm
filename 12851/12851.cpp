#include <bits/stdc++.h>
#define REP(i,a,b) for ( int i = a ; i < b ; i ++)
#define FAST cin.tie(NULL);cout.tie(NULL); ios::sync_with_stdio(false)
#define print(a) cout << a << "\n"
#define MAX 100001
using namespace std;

typedef long long ll;
typedef unsigned long long u64;
typedef unsigned int u32;
typedef vector<int> vi;


int n= 0,k = 0 ;
int way = 1;
int tick = INT_MAX;
int dx[2] = {1,-1};


void input(){
    cin >> n >> k;
}

int dfs()
{
	queue<pair<int,int>>q;
	q.push({n,0});
	char visited[MAX];
	memset(visited,0,sizeof(visited));

	while(!q.empty()){
		int p,cnt;
		tie(p,cnt) = q.front();q.pop();
		visited[p] = 1;
		if(p == k){
			if(tick > cnt){
				tick = cnt;
				way = 1;
			}
			else if(tick == cnt)
				way += 1;
		}
		
		REP(i,0,2){
			int np = dx[i] + p;
			if(np >= 0 && np < MAX && !visited[np])
				q.push({np,cnt+1});
		}
		if(p*2 >= 0 && p*2 < MAX && !visited[p*2])
			q.push({p*2,cnt+1});
	}
	return 0;
}



int main(){
    FAST;
    input();
    dfs();
	print(tick);
	print(way);
	return 0;
}

