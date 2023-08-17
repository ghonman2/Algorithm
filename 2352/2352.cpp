#include <bits/stdc++.h>

using namespace std;


#define REP(i,a,b) for(int i = a ; i < b ; i ++)

typedef long long ll ;
typedef vector<int> vi;


int main(){
	int n ;
	cin >> n ;
	vi ports(n);
	vi set;
	REP(i,0,n){
		cin >> ports[i];
	}
	for(int i = 0 ; i < n ; i ++){
		if (set.size() == 0 || set[set.size()-1] < ports[i] ){
			set.push_back(ports[i]);
		}
		else{
			set[lower_bound(set.begin(),set.end(),ports[i]) - set.begin()] = ports[i];
		}
	}
	cout << set.size() << "\n";

	return 0; 
}
