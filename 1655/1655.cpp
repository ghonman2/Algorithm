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


struct node_t{
	struct node_t *prv;
	struct node_t *nxt;
	int num;
};

struct node_t *init_node(int num)
{
	struct node_t *node = (struct node_t*)malloc(sizeof(*node));
	*node = (struct node_t){
		.prv = node,
		.nxt = node,
		.num = num,
	};
	return node;
}

void __insert_node(struct node_t **_root, struct node_t *node)
{
	struct node_t *root = *_root;
	char check = 0;
	while(root->nxt != *_root){
		if(root->num > node->num){
			node->prv = root->prv;
			node->prv->nxt = node;
			node->nxt= root;
			root->prv = node;
			check = 1;
			break;
		}
		else root = root->nxt;
	}
	if(!check){
		root->nxt = root;
		node->nxt = *_root;
		node->prv = root;
		(*_root)->prv = node;

	}

}

void insert_node(struct node_t **root, int num)
{
	__insert_node(root,init_node(num));
}


void print_node(struct node_t *root)
{
	struct node_t *iter = root;
	do{
		cout << iter->num << " ";
		iter = iter->nxt;
	}while(root != iter);
	cout << "\n";
}

int main(){
	FAST;
	int n = 0 ;
	cin >> n ;
	int t = n;
	struct node_t * root = NULL;
	while(t--){
		int num;
		cin >> num;
		if(!root) root = init_node(num);
		else insert_node(&root,num);
		print_node(root);
	}

	return 0;
}

