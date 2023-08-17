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

int n,m;
vector<vector<char>>board;
pair<int,int> Rball;
pair<int,int> Bball;
pair<int,int> dest;
int answer = INT_MAX;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
unsigned char visited[10][10][10][10];

void init()
{
	cin >> n >> m;
	board = vector<vector<char>>(n,vector<char>(m,0));
	REP(i,0,n){
		REP(j,0,m){
			cin >> board[i][j];
			if(board[i][j] == 'B')
				Bball = make_pair(i,j);
			if(board[i][j] == 'R')
				Rball = make_pair(i,j);
			if(board[i][j] == '0')
				dest = make_pair(i,j);
		}
	}
	memset(visited,0,sizeof(visited));
}

void bfs()
{
	queue<vi>q;


	while(q.empty()){
		int rx = q[0], ry = q[1], bx = q[2], by = q[3], cnt = q[4];
		if(rx == dst.first && ry == dst.second)
		{
			answer = min(answer,cnt);
			break;
		}
		for(int i = 0 ; i < 4 ; i ++)
		{
			move(&rx,&ry,&rc,i);
			move();
		}
	}
}


void sol()
{

}

int main(){
	FAST;
	init();
	return 0;
}

