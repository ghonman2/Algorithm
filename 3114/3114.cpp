#include <bits/stdc++.h>
#define REP(i,a,b) for ( int i = a ; i < b ; i ++)
#define FAST cin.tie(NULL);cout.tie(NULL); ios::sync_with_stdio(false)
#define print(a) cout << a << "\n";
#define vprint(a) REP(i,0,a.size()) cout << a[i] << " "; cout << "\n";
#define v2print(a) REP(i,0,a.size()) vprint(a[i]);
using namespace std;

typedef long long ll;
typedef unsigned long long u64;
typedef unsigned int u32;
typedef vector<int> vi;

int r,c;
vector<vector<string>>field;
vector<vi> banna;
vector<vi> apple;
int sum = 0;
void init()
{
	cin  >> r >> c;
	apple = vector<vi>(r);
	banna = vector<vi>(r);
	for(int i = 0 ; i < r ; i++){
		for(int j = 0 ; j < c ; j++ ){
			string word;
			cin >> word;
			char type = word[0];
			int num = atoi(word.c_str()+1);
			if(type == 'A')
			{
				apple[i].push_back(num);
				banna[i].push_back(0);
			}
			else{	
				apple[i].push_back(0);
				banna[i].push_back(num);
			}
		}
	}

	for(int i = 0 ; i < r ; i++){
		for(int j = 0 ; j < c ; j++ ){
			apple[i][j] += apple[i][j-1];
			banna[i][j] += banna[i][j-1];
		}
	}

	for(int i = 1 ; i < r ; i++){
		for(int j = 1 ; j < c ; j++ ){
			apple[i][j] += apple[i-1][j];
			banna[i][j] += banna[i=1][j]; 
		}
	}

}

void sol()
{
	vector<vi> dp(r,vector<int>(c,0));
	for(int i = 0 ; i < c ; i++ ) dp[0][i] = banna[0][c-1] - banna[0][i];
	for(int i = 0 ; i < r; i ++) dp[i][0] = apple
	for(int i = 0 ; i < r ; i ++){
		for(int j = 0 ; j < c; j ++){

		}
	}
}

int main(){
	FAST;
	init();
	sol();
	return 0;
}

