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

vector<pair<ll,ll>>cows;
int n = 0 ;
vector<ll>arrx;
vector<ll>arry;
bool result = false;
void init()
{
	cin >> n;
	arrx = vector<ll>(n,0);
	arry = vector<ll>(n,0);

	REP(i,0,n){
		cin >> arrx[i] >> arry[i];
	}
}

void dfs(int cnt, vector<pair<ll,ll>> l)
{
	if(result) return ;
	if(l.size() > 3) return;
	if(cnt == n) {result = true; return;}

	if(cnt == 0){
		l.push_back({arrx[0],-1});
		dfs(cnt+1,l);
		l.pop_back();
		l.push_back({-1,arry[0]});
		dfs(cnt+1,l);
	}
	else {
		int flag = 0 ;
		for(int i = 0 ; i < l.size(); i++){
			if(arrx[cnt] == l[i].first){
				flag = 1;
				dfs(cnt+1,l);
				break;
			}
			if(arry[cnt] == l[i].second){
				flag = 1;
				dfs(cnt+1,l);
				break;
			}
		}
		if(!flag){
			l.push_back({arrx[cnt],-1});
			dfs(cnt+1,l);
			l.pop_back();

			l.push_back({-1,arry[cnt]});
			dfs(cnt+1,l);
		}
	}
}

void sol()
{
	if(n<=3 ){ 
		cout << "1\n"; return;
	}
	vector<pair<ll,ll>>l;
	dfs(0,l);
	if(result) cout << "1\n";
	else cout << "0\n";
}
int main(){
	FAST;
	init();
	sol();
	return 0;
}

