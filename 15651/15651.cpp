
#include <bits/stdc++.h>
#define REP(i,a,b) for ( int i = a ; i < b ; i ++)

using namespace std;

typedef long long ll;
typedef unsigned long long u64;
typedef unsigned int u32;
typedef vector<int> vi;

vi choosen;
void search(vi subset,int n,int m){
	if (subset.size() == m){
		REP(i,0,subset.size()){
			cout << subset[i] << " ";
		}
		cout << "\n";
	}else {
		REP(i,1,n+1){
			choosen[i] = 1;
			subset.push_back(i);
			search(subset,n,m);
			subset.pop_back();
		}
	}
}

int main(){
	int n = 0 , m = 0 ;
	vi subset;
	cin  >> n >> m ;
	choosen = vi(n,0);
	search(subset,n,m);
	return 0;
}
