
#include <iostream>
using namespace std;

// A binary tree node has data, pointer to left child
// and a pointer to right child
struct Node {
	int data;
	struct Node *left, *right;
};

// Utility function to create a new tree node
Node* newNode(int data)
{
	Node* temp = new Node;
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

// Given a binary tree, print its nodes in inorder
void printInorder(struct Node* node)
{
	if (node == NULL)
		return;

	// First recur on left child
	printInorder(node->left);

	// Then print the data of node
	cout << node->data << " ";

	// Now recur on right child
	printInorder(node->right);
}

// Given a binary tree, print its nodes in preorder
void printPreorder(struct Node* node)
{
    if (node == NULL)
        return;
 
    // First print data of node
    cout << node->data << " ";
 
    // Then recur on left subtree
    printPreorder(node->left);
 
    // Now recur on right subtree
    printPreorder(node->right);
}

// Given a binary tree, print its nodes according to the
// "bottom-up" postorder traversal.
void printPostorder(struct Node* node)
{
    if (node == NULL)
        return;
 
    // First recur on left subtree
    printPostorder(node->left);
 
    // Then recur on right subtree
    printPostorder(node->right);
 
    // Now deal with the node
    cout << node->data << " ";
}

// Driver code
int main()
{
	struct Node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->right->right = newNode(7);

	// Function call
	cout << "Inorder traversal of binary tree is \n";
	printInorder(root);
	cout<<endl;
	cout << "Preorder traversal of binary tree is \n";
	printPreorder(root);
	cout<<endl;
	cout << "Postorder traversal of binary tree is \n";
	printPostorder(root);
	cout<<endl;

	return 0;
}
