#include<iostream>
#include<queue>
#include<cmath>
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
	cin >> value_at_node;

	//Base Case
	if (value_at_node == -1)
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
	if (root == NULL)
	{
		return;
	}

	cout << root -> data << " ";
	PreOrderTraversal(root -> left);
	PreOrderTraversal(root -> right);
}

void InOrderTraversal(Node* root)
{
	// PreOrder Traversal -->  (Left --> Root --> Right)
	if (root == NULL)
	{
		return;
	}

	InOrderTraversal(root -> left);
	cout << root -> data << " ";
	InOrderTraversal(root -> right);
}

void PostOrderTraversal(Node* root)
{
	// PreOrder Traversal -->  (Left --> Right --> Root)
	if (root == NULL)
	{
		return;
	}

	PostOrderTraversal(root -> left);
	PostOrderTraversal(root -> right);
	cout << root -> data << " ";
}

int Height(Node* root)
{
	// Base Case
	if (root == NULL)
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
	if (root == NULL)
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

	if (k == 1)
	{
		cout << root -> data << " ";
		return;
	}

	// Recursive Case
	PrintkthLevelOfTree(root -> left, k - 1);
	PrintkthLevelOfTree(root -> right, k - 1);
}

void PrintAllLevels(Node* root)
{
	// Worst Case Complexity : O(n^2) -> if we are given a Skew Tree
	if (root == NULL)
	{
		return;
	}

	int H = Height(root);
	for (int i = 1; i <= H; i++)
	{
		PrintkthLevelOfTree(root, i);
		cout << "\n";
	}
}

void NormalBFS(Node* root)
{
	queue<Node*> q;
	q.push(root);

	while (!q.empty())
	{
		Node* f = q.front();
		cout << f -> data << " ";
		q.pop();

		if (f -> left)
		{
			q.push(f -> left);
		}
		if (f -> right)
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

	while (!q.empty())
	{
		Node* f = q.front();

		if (f == NULL)
		{
			cout << "\n";
			q.pop();

			if (!q.empty())
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
			cout << f -> data << " ";
			q.pop();

			if (f -> left)
			{
				q.push(f -> left);
			}
			if (f -> right)
			{
				q.push(f -> right);
			}
		}
	}
	return;
}

int CountNodes(Node* root)
{
	//Base Case
	if (root == NULL)
	{
		return 0;
	}

	// Recursive Case
	int left_subtree_nodes = CountNodes(root -> left);
	int right_subtree_nodes = CountNodes(root -> right);

	return 1 + left_subtree_nodes + right_subtree_nodes;
}

int SumOfAllNodes(Node* root)
{
	// Base Case
	if (root == NULL)
	{
		return 0;
	}

	// Recursive Case
	int sum_left_subtree = SumOfAllNodes(root -> left);
	int sum_right_subtree = SumOfAllNodes(root -> right);

	return root -> data + sum_left_subtree + sum_right_subtree;
}

int Diameter(Node* root)
{

	// Here, we used a Top- Down Approach (Pre-order Traverse)
	// for finding the Diamater of the Binary Tree...
	// Takes a time of Order = O(n^2)
	// As, First for finding height --> O(n) time
	// Then, Recursively calling for on the left and right subtrees. --> O(n) time
	// So, Overall Takes O(n^2) time
	//                   -----------

	//Base Case
	if (root == NULL)
	{
		return 0;
	}

	// Recursive Case
	int height_left_subtree = Height(root -> left);
	int height_right_subtree = Height(root -> right);

	int option1 = height_left_subtree + height_right_subtree;
	int option2 = Diameter(root -> left);
	int option3 = Diameter(root -> right);

	return max(option1, max(option2, option3));
}



// For this we can use Class as well as Structure ..
class HeightDiameterPair
{
public:
	int height;
	int diameter;
};

HeightDiameterPair FastDiameter(Node* root)
{
	// Here, we will be following the "Bottom - Up approach" using the Post Order Traversal
	// this will be much faster as compared to the above method

	HeightDiameterPair p;

	//Base Case
	if (root == NULL)
	{
		// As the height and the Diamater of an Empty tree is always 0.....
		p.height = p.diameter = 0;
		return p;
	}

	//Recirsive Case
	HeightDiameterPair left_tree = FastDiameter(root -> left);

	HeightDiameterPair right_tree = FastDiameter(root -> right);

	p.height = max( left_tree.height , right_tree.height) + 1;

	p.diameter = max(left_tree.height + right_tree.height , max(left_tree.diameter , right_tree.diameter));

	return p;
}


int replaceSumOfNodeWithItsChildren( Node* root)
{
	// The idea/trick is that we need to store the data in the root
	// ie. int temp = root -> data
	// in a temp variable and after the computation of the sum we got
	// on a particular nodes from its right and left children part
	// root -> data = leftsum + rightsum;
	// we will return the value (temp + root -> data)....

	// Base Case
	if (root == NULL)
	{
		// if empty tree return 0
		return 0;
	}

	if (root -> left == NULL && root -> right == NULL)
	{
		// Means we are on the leaf node
		// so, only return the root ->data
		return root -> data;
	}

	// Recursive case
	// Here we, follow bottom up approact(post order traversal)
	int left_sum = replaceSumOfNodeWithItsChildren(root -> left);
	int right_sum = replaceSumOfNodeWithItsChildren(root -> right);

	int temp = root -> data;
	root -> data = left_sum + right_sum;

	return temp + root -> data;
}

bool CheckHeightBalanced(Node* root)
{

	// this is a top down approach and takes O(n ^ 2) time


	// Base Case
	if (root == NULL)
	{
		return true;  // --> as empty tree is always height balanced
	}

	// recursive case
	int left_subtree_height = Height(root -> left);
	int right_subtree_height = Height(root -> right);

	if ((abs(left_subtree_height - right_subtree_height) <= 1) && (CheckHeightBalanced(root -> left)) && (CheckHeightBalanced(root -> right)))
	{
		return true;
	}
	return false;
}


class HeightBalancedPair
{
public:
	int height;
	bool balanced;
};

HeightBalancedPair CheckHeightBalancedFaster(Node* root)
{
	// In this approach , we do bottom up traversal and this algorithm
	// will take O(n) time......

	HeightBalancedPair p;

	// Base Case
	if (root == NULL)
	{
		// As an empty tree is always balanced...
		p.height = 0;
		p.balanced = true;
		return p;
	}

	// Recursive Case
	HeightBalancedPair left_tree = CheckHeightBalancedFaster(root -> left);
	HeightBalancedPair right_tree = CheckHeightBalancedFaster(root -> right);

	p.height = max(left_tree.height, right_tree.height) + 1;

	if ((abs(left_tree.height - right_tree.height) <= 1) && left_tree.balanced && right_tree.balanced)
	{
		p.balanced = true;
	}
	else
	{
		p.balanced = false;
	}
	return p;
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
	//--------------------------------------------

	// Node* root = buildTree();
	//NormalBFS(root);   // Level Order Traversal without newline
	//cout<<"\n";

	// BFS(root);   // Level Order With Newline
	// cout<<"\n";




	// 5. Count No. of Nodes of Tree And Sum of All nodes in Tree
	// ------------------------------------------------------------

	// Node* root = buildTree();
	// cout<<"No. of Nodes : "<<CountNodes(root)<<"\n";
	// cout<<"Sum of all Nodes : "<<SumOfAllNodes(root)<<"\n";






	// 6. Diameter of a Binary tree
	//---------------------------------------------

	// Node* root = buildTree();
	// // cout<<"Diameter : "<<Diameter(root)<<"\n";

	// HeightDiameterPair p = FastDiameter(root);
	// cout << "Height :" << p.height << "\n";
	// cout << "Diameter : " << p.diameter << "\n";





	// 7. Sum Replacement Question
	// -------------------------------------------------------
	// Keeping the leaf nodes as it is and replace the other nodes by the sum
	// of their children nodes.

	//				8                                      63
	//			   / \	                                  /  \
	//			  10  3							         23   27
	//			 /  \  \        ------------->          /  \   \
	//			1    6  14                             1   16   13
	//		    	/ \  \                                /  \   \
	//		       9   7  13 	                         9    7   13


	// Node* root = buildTree();
	// cout << "Tree Before Replacement :" << "\n";
	// BFS(root);

	// replaceSumOfNodeWithItsChildren(root);
	// cout << "Tree After Replacement : " << "\n";
	// BFS(root);





	// 8. Height Balanced Tree
	//----------------------------------------------------------
	// A height balanced tree (Binary tree) is that tree which satisfy the
	// condition that the difference between the heights of the left and the
	// right subtree must be <= 1 at each and every node of the tree..
	// Node* root = buildTree();
	// if (CheckHeightBalanced(root))
	// {
	// 	cout << "Balanced" << "\n";
	// }
	// else
	// {
	// 	cout << "Not Balanced" << "\n";
	// }

	Node* root = buildTree();
	HeightBalancedPair p = CheckHeightBalancedFaster(root);
	if (p.balanced)
	{
		cout << "Balanced" << "\n";
	}
	else
	{
		cout << "Not Balanced" << "\n";
	}


	return;
}

int main(int argc, char const *argv[])
{
	fastIO();
	fileIO();
	int t = 1;
	//cin>>t;
	while (t--) solve();
	return 0;
}

