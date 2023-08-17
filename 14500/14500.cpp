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

int n,m ;
vector<vi>board;
int answer;
void init()
{
	cin >> n >> m;
	board = vector<vi>(n,vector<int>(m,0));
	for(int i = 0 ; i < n ; i ++ )
		for(int  j = 0; j < m; j ++)
			cin >> board[i][j];

}

int sumType(int type,int x, int y)
{
	int ret = 0 ;
	switch(type){
		case 1 :
			if(x + 3 < n) {
				int tmp = 0 ;
				REP(i,x,x+4){tmp += board[i][y];}
				ret = max(ret,tmp);
			}
			if(y + 3 < n){
				int tmp = 0 ;
				REP(i,y,y+4){tmp  += board[x][i];}
				ret = max(ret,tmp);
			}
			break;
		case 2 : 
			if(x+1 < n && y + 1 < n){
				for (int i = 0 ; i < 2; i ++ ){
					for(int j = 0 ; j < 2; j++){
						ret += board[x+i][y+j];	
					}
				}
			}
			break;
		case 3 :
			if(y+1 < n && x + 2 < n){
				ret = max(ret,board[x][y]+board[x+1][y]+board[x+2][y]+board[x+2][y+1]);
			}

			if(y +2 < n && x -1 >= 0 ){
				ret = max(ret,board[x][y]+board[x][y+1]
						+board[x][y+2]+board[x-1][y+2]);
			
			}

			if(y -1 >= 0  && x -2  >= 0 ){
				ret = max(ret,board[x][y]+board[x-1][y]
						+board[x-2][y]+board[x-2][y-1]);
			}

			if(y -1 >= 0  && x -2  >= 0 ){
				ret = max(ret,board[x][y]+board[x-1][y]
						+board[x-2][y]+board[x-2][y-1]);
			}
			break;
		case 4 :
			break;
		case 5 :
			break;

	}
	return ret;
}

void search()
{
	for(int i = 0 ; i < n ;i ++){
		for(int  j = 0; j < m ; j ++){
			for(int type = 0 ; type < 4 ; type ++){
				answer = max(answer,sumType(i,j,type));
			}
		}
	}
}

void sol()
{

}

int main(){
	FAST;

	return 0;
}

