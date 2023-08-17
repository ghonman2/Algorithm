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
typedef pair<int,int> pii;

vector<pii>dots;
int m = 0 ;

int cmp(pii a, pii b)
{
	if(a.first == b.first) return a.second < b.second;
	return a.first < b.first;
}

void init()
{
	cin >> m;
	while(1){
		int l,r;
		cin >> l >> r;
		if(l == 0 && r == 0)break;
		if(r <= 0 ) continue;
		dots.push_back({l,r});
	}
	sort(dots.begin(),dots.end(),cmp);
}

void sol()
{
	int answer = 0 ;
	int line = 0;
	for(int i = 0 ; i < dots.size(); i++){
		pii dot = dots[i];
		int tmp = line;
		if(dot.second <= line)continue;
		if(line >= dot.first && dot.second > line)tmp = dot.second;
		for(int j = i+1; j < dots.size(); j++){
			if(line >= dots[j].first && dots[j].second > tmp) 
				tmp = dots[j].second;
			else break;
		}
		line = tmp;
		answer += 1;
		if(line >=m) break;
	}

	if(line >= m) cout << answer << "\n";
	else cout << 0 << "\n";

}

int main(){
	FAST;	
	init();
	sol();
	
	return 0;
}

