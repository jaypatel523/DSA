// striver problem link : https://takeuforward.org/data-structure/boundary-traversal-of-a-binary-tree/


#include<bits/stdc++.h>
using namespace std;


struct Node {

	int val;
	struct Node * left;
	struct Node * right;

};

struct Node * newNode(int val) {

	struct Node * node = (struct Node*)malloc(sizeof(struct Node));

	node->val = val;
	node->left = NULL;
	node->right = NULL;

	return node;

}






bool isLeaf(Node * root) {
	return (!root->left && !root->right);
}


void leftBoundary(Node * root, vector<int> & ans) {

	Node * temp = root->left;

	while(temp) {
		if(!isLeaf(temp)) ans.push_back(temp->val);

		if(temp->left) temp = temp->left;
		else temp = temp->right;
	}
}



void addLeaves(Node * root, vector<int> & ans) {

	if(isLeaf(root)) {
		ans.push_back(root->val);
		return;
	}

	if(root->left) addLeaves(root->left, ans);
	if(root->right) addLeaves(root->right, ans);

}



void rightBoundary(Node * root, vector<int> & ans) {
	Node * temp = root->right;
	vector<int> rev;
	while(temp) {
		if(!isLeaf(temp)) rev.push_back(temp->val);
		if(temp->right) temp = temp->right;
		else temp = temp->left;
	}

	for(int i=rev.size()-1; i>=0; i--) {
		ans.push_back(rev[i]);
	}

}



// main function 
vector<int> printBoundary(Node * root) {

	vector<int> ans;
	if(!root) return ans;
	if(!isLeaf(root)) ans.push_back(root->val);

	leftBoundary(root, ans);
	addLeaves(root, ans);
	rightBoundary(root, ans);


	cout << ans.size();

	return ans;
}





int main() {


	struct Node * root = newNode(1);

	root->left = newNode(2);
	root->left->left = newNode(3);
	root->left->left->right = newNode(4);
	root->left->left->right->left = newNode(5);
	root->left->left->right->right = newNode(6);


	root->right = newNode(7);
	root->right->right = newNode(8);
	root->right->right->left = newNode(9);
	root->right->right->left->left = newNode(10);
	root->right->right->left->right = newNode(11);




	vector<int> result = printBoundary(root);
	cout << result.size() << endl;

	for(int num : result) {
		cout << num << " ";
	}
	cout << endl;







	return 0;
}
