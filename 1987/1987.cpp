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
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int r,c;
vector<vector<char>>board;
map<char,int> check;
void init()
{
	cin >> r >> c;
	board = vector<vector<char>>(r,vector<char>(c,0));
	REP(i,0,r) REP(j,0,c) {cin >> board[i][j];
		check[board[i][j]] = 1;
	}
}

int answer = 0;
void search(int x, int y,int cnt)
{

	answer = max(answer,cnt);

	for(int i = 0 ; i < 4; i ++ ){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(nx >=0 && ny >= 0 && nx < r && ny < c && check[board[nx][ny]] == 1){
			check[board[nx][ny]] = 0;
			search(nx,ny,cnt+1);
			check[board[nx][ny]] = 1;
		}
	}

}

int main(){
	FAST;
	init();
	check[board[0][0]] = 0 ;
	search(0,0,1);
	cout << answer << "\n";
	return 0;
}

