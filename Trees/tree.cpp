#include<iostream>
#include<queue>
using namespace std;
void fastIO()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}

void fileIO()
{
	#ifndef ONLINE_JUDGE
		freopen( "input.txt" , "r" , stdin);
		freopen( "output.txt" , "w" , stdout);
	#endif
}

/* #############################################################################

	Binary Tree Guide for Complete Revision of the important points and the
	functions regarding the Binary Trees:-

	INTRODUCTION
	------------
	1) The maximum number of nodes at level ‘l’ of a binary tree is 2l. 
	
	2) The Maximum number of nodes in a binary tree of height ‘h’ is 2h – 1. 
	
	3) In a Binary Tree with N nodes, minimum possible height or 
	   the minimum no. of levels is --> Log2(N+1).
	
	4) A Binary Tree with L leaves has at least ( | Log2L |+ 1 )levels. 
		L   <=  2l-1  [From Point 1]
		l =   | Log2L | + 1 
		where l is the minimum number of levels.
	
	5) In Binary tree where every node has 0 or 2 children,
	   the number of leaf nodes is always one more than nodes with two children.

		L = T + 1
		Where L = Number of leaf nodes
		T = Number of internal nodes with two children

	############################################################################

*/ 




struct Node
{
	int data;
	Node* left;
	Node* right;

	Node(int d)
	{
		data = d;
		left = NULL;
		right = NULL;
	}
};


// Recursive Function to Build the Binary tree
Node* buildTree()
{
	int value_at_node;
	cin>> value_at_node;

	//Base Case
	if(value_at_node == -1)
	{
		return NULL;;
	}

	Node* root = new Node(value_at_node);

	root -> left = buildTree();
	root -> right = buildTree();

	return root;
}

void PreOrderTraversal(Node* root)
{
	// PreOrder Traversal -->  (Root --> Left --> Right)
	if(root == NULL)
	{
		return;
	}

	cout<<root -> data<<" ";
	PreOrderTraversal(root -> left);
	PreOrderTraversal(root -> right);
}

void InOrderTraversal(Node* root)
{
	// PreOrder Traversal -->  (Left --> Root --> Right)
	if(root == NULL)
	{
		return;
	}

	InOrderTraversal(root -> left);
	cout<<root -> data<<" ";
	InOrderTraversal(root -> right);
}

void PostOrderTraversal(Node* root)
{
	// PreOrder Traversal -->  (Left --> Right --> Root)
	if(root == NULL)
	{
		return;
	}

	PostOrderTraversal(root -> left);
	PostOrderTraversal(root -> right);
	cout<<root -> data<<" ";
}

int Height(Node* root)
{
	// Base Case
	if(root == NULL)
	{
		return 0;
	}

	// Recursive Case
	int height_left_subtree = Height(root -> left);
	int height_right_subtree = Height(root -> right);

	return max(height_left_subtree, height_right_subtree) + 1;
}

void PrintkthLevelOfTree(Node *root, int k)
{
	// Base Case
	if(root == NULL)
	{
		return;
	}

	//  Comment this out when doing alllevelPrint
	// -------------------------------------------
	// if(Height(root) < k)
	// {
	// 	cout<<"Level No. Cannot be greater than Height of Tree.....Enter Valid Value"<<"\n";
	// 	return;
	// }

	if(k == 1)
	{
		cout<<root -> data<<" ";
		return;
	}

	// Recursive Case
	PrintkthLevelOfTree(root -> left, k - 1);
	PrintkthLevelOfTree(root -> right, k - 1);
}

void PrintAllLevels(Node* root)
{
	// Worst Case Complexity : O(n^2) -> if we are given a Skew Tree
	if(root == NULL)
	{
		return;
	}

	int H = Height(root);
	for(int i = 1; i <= H; i++)
	{
		PrintkthLevelOfTree(root,i);
		cout<<"\n";
	}
}

void NormalBFS(Node* root)
{
	queue<Node*> q;
	q.push(root);

	while(!q.empty())
	{
		Node* f = q.front();
		cout<<f -> data<<" ";
		q.pop();

		if(f -> left)
		{
			q.push(f -> left);
		}
		if(f -> right)
		{
			q.push(f -> right);
		}
	}
	return;
}


void BFS(Node* root)
{
	queue<Node*> q;
	q.push(root);
	q.push(NULL);

	while(!q.empty())
	{
		Node* f = q.front();

		if(f == NULL)
		{
			cout<<"\n";
			q.pop();

			if(!q.empty())
			{
				// if after poping NULL the Queue is still Not empty
				// then push one more NULL, so that we can know that 
				// all the chilfren of the prev. node are pushed into the 
				// queue.....
				q.push(NULL);
			}
		}
		else
		{
			cout<<f -> data<<" ";
			q.pop();

			if(f -> left)
			{
				q.push(f -> left);
			}
			if(f -> right)
			{
				q.push(f -> right);
			}
		}
	}
	return;
}

void solve()
{
	// 1. Building Part Of the Tree --(First Execute)
	// -----------------------------------------------------------------------
	// Node *root = buildTree();
	// PreOrderTraversal(root);
	// return;



	// 2. Different traversals (post, pre, in)

	// INPUT TREE
	// ----------

	//       8
	//      / \
	//     10  3
	//    /  \  \
	//   1    6  14
	//       / \  \
	//      9   7  13

	// Input :- 8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
	// Output: 
	//			Pre Order : 8 10 1 6 9 7 3 14 13 
	//			In Order : 1 10 9 6 7 8 3 13 14 
	//			Post Order : 1 9 7 6 10 13 14 3 8 

	// Node* root = buildTree();

	// cout<<"Pre Order : ";
	// PreOrderTraversal(root);
	// cout<<"\n";

	// cout<<"In Order : ";
	// InOrderTraversal(root);
	// cout<<"\n";

	// cout<<"Post Order : ";
	// PostOrderTraversal(root);
	// cout<<"\n";




	//3. LEVEL ORDER TRAVERSALS (HEIGHT AND PRINTING A PARTICULAR LEVEL)
	// ---------------------------------------------------------------------
	//   (i) Finding Height of the tree   ---|  Both Will combine to give
	//   (ii) printing each level  ----------|_ level order Traversal  
	// Node* root = buildTree();
	
	// cout<<"Height of Tree : "<<Height(root)<<"\n";   
	
	// //PrintkthLevelOfTree(root, 7);  // PrintkthLevelOfTree(root, k - value) 
	// //cout<<"\n";

	// PrintAllLevels(root);
	// cout<<"\n";




	// 4. BFS (Breadth First Search)
	Node* root = buildTree();
	//NormalBFS(root);   // Level Order Traversal without newline
	//cout<<"\n";

	BFS(root);   // Level Order With Newline
	cout<<"\n";

	return;
}

int main(int argc, char const *argv[])
{
	fastIO();
	fileIO();
	int t = 1;
	//cin>>t;
	while(t--) solve();
	return 0;
}

