#include <bits/stdc++.h>
#define REP(i,a,b) for ( int i = a ; i < b ; i ++)
#define FAST cin.tie(NULL);cout.tie(NULL); ios::sync_with_stdio(false)
#define print(a) cout << a << "\n";
using namespace std;

typedef long long ll;
typedef unsigned long long u64;
typedef unsigned int u32;
typedef vector<int> vi;

struct node_t
{
	int key;
	struct node_t *left;
	struct node_t *right;
};

struct node_t* __init_node(int key,struct node_t * left, struct node_t *right)
{
	struct node_t *node = (struct node_t *)malloc(sizeof(*node));
	*node = (struct node_t){
		.key = key,
		.left = left,
		.right = right,
	};
	return node;
}


struct node_t *init_node(int key)
{
	return __init_node(key,NULL,NULL);
}

void add_node(struct node_t *node, struct node_t *add)
{
	if(node->key < add->key){
		if(!node->right)
			node->right = add;
		else
			add_node(node->right,add);
	}
	else if (node->key > add->key){
		if(!node->left)
			node->left = add;
		else 
			add_node(node->left,add);
	}
	return ;
}

void pre_order(struct node_t *node)
{
	if(node->left){
		pre_order(node->left);
	}
	if(node->right){
		pre_order(node->right);
	}
	print(node->key);
}

void init()
{
	int x = 0;
	int check = 0;
	struct node_t *root;
	while(cin >> x){
		if(!check){
			root = init_node(x);
			check = 1;
		}
		else {
			add_node(root,init_node(x));
		}
	}
	pre_order(root);
}


int main(){
	FAST;
	init();
	return 0;
}
