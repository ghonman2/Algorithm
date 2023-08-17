#include <bits/stdc++.h>
#define REP(i,a,b) for ( int i = a ; i < b ; i ++)
#define FAST cin.tie(NULL);cout.tie(NULL); ios::sync_with_stdio(false)

using namespace std;

typedef long long ll;
typedef unsigned long long u64;
typedef unsigned int u32;
typedef vector<int> vi;


int n = 0, k = 0, m = 0 ;

void changLight(int **lamps,int idx){

	REP(i,0,n){
		lamps[i][idx] = lamps[i][idx] ? 0 :1;
	}
}
int countLight(int **lamps)
{

}
int main(){
	FAST;
	cin >> n >> m ;
	int number[n][m];
	REP(i,0,n){
		REP(j,0,m)
			cin >> number[i][j];
	}
	cin >> k ;
	return 0;
}
