#include <bits/stdc++.h>
using namespace std;




struct Node {
	int val;

	struct Node * left;
	struct Node * right;

	Node(int val) {
		this->val = val;
		left = right = NULL;
	}
};




// function to creat tree from array 
// level order traversal 
Node * createTree(vector<int> arr, int i) {

	Node * root = NULL;

	if(i < arr.size()) {

		root = new Node(arr[i]);

		root->left = createTree(arr, 2 * i + 1);
		root->right = createTree(arr, 2 * i + 2);

	}

	return root;
 
}

 


vector<int> rightView(Node * root) {
	vector<int> ans;


	queue<Node *> q;
	int level = 0;
	q.push(root);
	// level, last element at every level
	map<int, int> m;

	while(!q.empty()) {

		int levelsize = q.size();
		while(levelsize--) {
			Node * node = q.front();
			q.pop();
			m[level] = node->val;

			if(node->left) q.push(node->left);
			if(node->right) q.push(node->right);
		}
		level++;
	}

	for(auto it : m) {
		ans.push_back(it.second);
	}

	return ans;
}






int main()
{	

	vector<int> arr;
	for(int i=1; i<=15; i++) arr.push_back(i);

	Node * root = createTree(arr, 0);
	vector<int> result = rightView(root);
	for(int num : result) cout << num << " ";

		

	return 0;
}



