#include <bits/stdc++.h>
using namespace std;

	
struct Node {
	int val;
	Node * left;
	Node * right;

};


Node * newNode(int val) {
	Node * node = new Node;
	node->val = val;
	node->left = NULL;
	node->right = NULL;

	return node;
}


void pre(Node * root) {
	if(!root) return;

	cout << root->val << " ";
	pre(root->left);
	pre(root->right);

}

	
bool isPath(Node * root, vector<int> & v, int nodeVal) {

	if(!root) return false;

	v.push_back(root->val);
	if(root->val == nodeVal) {
		return true;
	}

	if(isPath(root->left, v, nodeVal) || isPath(root->right, v, nodeVal)) return true;

	v.pop_back();
	return false;


}



vector<int> rootToNodePath(Node * root, int nodeVal) {


	vector<int> ans;
	isPath(root, ans, nodeVal);
	return ans;

}



int main() {

	Node * root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->right->right = newNode(7);

	vector<int> path = rootToNodePath(root, 6);

	for(int num : path) cout << num << " ";	


	return 0;

}
