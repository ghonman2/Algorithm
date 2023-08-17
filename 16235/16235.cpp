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

int n,m,k;
int x,y,z;

vector<vi>trees;
void init()
{
	cin >> n >> m >> k;
	trees = vector<vi>(m);
	REP(i,0,m){
		int x,y,z;
		cin >> x >> y >> z;
		trees.push_back({x,y,z});
	}
}



int main(){
	FAST;
	init();
	return 0;
}

