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




vector<int> topView(Node * root) {

	vector<int> ans;

	// line, node value
	map<int, int> m;

	// node, line 
	queue<pair<Node*, int>> q;
	q.push({root, 0});

	while(!q.empty()) {

		auto it = q.front();
		q.pop();

		Node * node = it.first;
		int line = it.second;

		if(m.find(line) == m.end()) {
			m[line] = node->val;
		}

		if(node->left) {
			q.push({node->left, line - 1});
		}

		if(node->right) {
			q.push({node->right, line + 1});
		}


	}


	for(auto it : m) ans.push_back(it.second);


	return ans;

}





int main()
{	

	vector<int> arr;
	for(int i=1; i<=7; i++) arr.push_back(i);

	Node * root = createTree(arr, 0);
	vector<int> result = topView(root);
	for(int num : result) cout << num << " ";

		

	return 0;
}



