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





// root, left, right
void recursive_preorder(Node * node) {
	if(node == NULL) return;

	cout << node->val << " ";
	recursive_preorder(node->left);
	recursive_preorder(node->right);
} 


// left, root, right
void recursive_inorder(Node * node) {
	if(node == NULL) return;

	recursive_inorder(node->left);
	cout << node->val << " ";
	recursive_inorder(node->right);
}


// left, right, root
void recursive_postorder(Node * node) {
	if(node == NULL) return;

	recursive_postorder(node->left);
	recursive_postorder(node->right);
	cout << node->val << " ";
}



// level order traversal 
/*
	EXPLAINATION (ALGORITHM)
	
	-> 	take one queue to store node of tree 
	->	take one vector<vector<int>> to store answer
	-> 	repeat
		-> 	take front node from queue 
		-> 	check if node has left child then push it into the queue
		-> 	check if node has right child then push it into the queue
		->  push value of front node into a vector
		-> 	do above 4 steps for each level
		-> 	after complete one level, push level vector inside answer vector
		-> 	repeat the process untill queue will not become empty 
	->	print the vector of vector 
	
*/
void print2Dvector(vector<vector<int>> arr);
void leverorder(Node * node) {

	vector<vector<int>> ans;
	if(node == NULL) return;

	queue<Node*> q;
	q.push(node);


	while(!q.empty()) {

		int levelSize = q.size();
		vector<int> level;
		for(int i=0; i<levelSize; i++) {
			Node * n = q.front();
			q.pop();
			if(n->left) q.push(n->left);
			if(n->right) q.push(n->right);
			level.push_back(n->val);
		}
		ans.push_back(level);
	}
	print2Dvector(ans);

}







void print2Dvector(vector<vector<int>> arr) {
	for(auto row : arr) {
		for(auto col : row) {
			cout << col << " ";
		}
		cout << endl;
	}
	cout << endl;
}




int main()
{	

	vector<int> arr;
	for(int i=1; i<=7; i++) arr.push_back(i);

	Node * root = createTree(arr, 0);

	recursive_preorder(root); cout << endl;
	recursive_inorder(root); cout << endl;
	recursive_postorder(root); cout << endl;
	leverorder(root);


	return 0;
}



