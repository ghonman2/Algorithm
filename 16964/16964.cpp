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

vector<vi>graph;
vector<vi>tree;
int n = 0 ;
vi cNumber;
vector<bool>dcheck;
vector<char>check;
void dfs(int x,int depth) {
    if (dcheck[x] == true) {
        return;
    }
    dcheck[x] = true;
	tree[depth].push_back(x);
    for (int y : graph[x]) {
        if (dcheck[y] == false) {
            dfs(y,depth+1);
        }
    }
}

void init()
{
	cin >> n;
	graph = vector<vi>(n+1);
	REP(i,0,n-1){
		int in,out;
		cin >> in >> out ;
		graph[in].push_back(out);
		graph[out].push_back(in);
	}
	dcheck = vector<bool>(n+1,false);
	tree = vector<vi>(n+1);
	cNumber = vi(n,0);
	REP(i,0,n)cin >> cNumber[i];
	check = vector<char>(n+1,1);
}


void sol()
{
	dfs(1,0);
	int idx = 0;

	for(auto leafs : tree){
		int last = idx + leafs.size();
		for(auto node : leafs){
			if(find(cNumber.begin()+idx,cNumber.begin()+last,node) != cNumber.end()&& 
					check[node]) check[node] = 0;
			else {
				cout << "0" << "\n";
				return;
			}
		}
		idx = last;
	}
	cout << "1" << "\n";
	
}

int main(){
	FAST;
	init();
	sol();
	return 0;
}

