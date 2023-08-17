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
int n,m;
vector<ll>nums;
vector<pair<int,ll>> checks;
map<ll,int>dictP;
map<ll,int>dictM;

void init(void)
{
	cin >> n >>m;
	nums = vector<ll>(n,0);
	REP(i,0,n) cin >> nums[i];
	REP(i,0,m) {
		int frm;
		ll dst;
		cin >> frm >>dst ;
		checks.push_back({frm,dst});
	}
	REP(i,1,n){
		if(nums[i] - nums[i-1] >= 0){
			if(dictP.find(nums[i]-nums[i]) == dictP.end())
				dictP[nums[i]-nums[i-1]] += 1;
			else dictP[nums[i]-nums[i-1]] = 1;
		}
		if(nums[i] % nums[i-1]){
			if(dictM.find(nums[i]/nums[i-1]) == dictM.end())
				dictM[nums[i]/nums[i-1]] += 1;
			else dictM[nums[i]/nums[i-1]] = 1;
		}
	}
}

void update(int idx, ll num)
{
	ll dx = 0 ;
	for(int i = idx; i < idx +2; i++){
		if(i == 0 || i == n) continue;
		dx = nums[i] - nums[i-1];
		dictP[dx] -= 1;
		if(dictP[dx] == 0 ) dictP.erase(dx);
	}
	for(int i = idx; i < idx +2; i++){
		if(i == 0 || i == n) continue;
		if(nums[i] % nums[i-1])continue;
		dx = nums[i] / nums[i-1];
		dictM[dx] -= 1;
		if(dictM[dx] == 0) dictM.erase(dx);
	}

	nums[idx] = num;
	
	for(int i = idx; i < idx+2; i ++){
		if(i == 0 || i == n)continue;
		dx = nums[i] - nums[i-1];
		if(dictP.find(dx) != dictP.end())
			dictP[dx] += 1;
		else dictP[dx] = 1;
	}
	for(int i = idx; i < idx+2; i ++){
		if(i == 0 || i == n)continue;
		if(nums[i] % nums[i-1])continue;
		dx = nums[i] / nums[i-1];
		if(dictM.find(dx) != dictM.end())
			dictM[dx] += 1;
		else dictM[dx] = 1;
	}
}

int isRight(map<ll,int>&dict)
{
	if(dict.size() != 1) return 0;
	if(dict.begin()->first && dict.begin()->second != n-1)return 0;
	return 1;
}

void sol()
{
	for(auto check : checks){
		int idx = check.first-1;
		ll dst = check.second;
		
		update(idx,dst);
		
		if(isRight(dictP)) cout<< "+\n";
		else if (isRight(dictM)) cout << "*\n";
		else cout << "?\n";
	}

}

int main(){
	FAST;
	init();
	sol();
	return 0;
}

