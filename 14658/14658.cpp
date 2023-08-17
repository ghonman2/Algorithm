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


int n,m,l,k;
queue<pair<int,int>> stars;
vector<int> nr_n;
vector<int> nr_m;
void init()
{
	cin >> n >> m >> l >> k;
	for(int i = 0 ; i < k; i ++){
		int x,y;
		cin >> x >> y;
		stars.push_back({x,y});
	}
	
}
int answer = 0 ;

void sol()
{
	for(int i = 0 ; i < k ; i ++){
		for(int  j = 0 ; j < k ; j++){
			for(int mk = 0 ; mk < k ; mk++){
				if(i*l <= stars[i].first && stars[i].first <= i*l+l &&
						i*l <= stars[i].)
			}
		}
	}
}


int main(){
	FAST;
	init();
	sol();
	return 0;
}

