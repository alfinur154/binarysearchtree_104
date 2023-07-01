#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
	string info;
	Node* leftchild;
	Node* rightchild;

	//Constructor for the node class
	Node(string i, Node* I, Node* r)
	{
		info = i;
		leftchild = I;
		rightchild = r;
	}
};

class BinaryTree
{
public:
	Node* ROOT;

	BinaryTree()
	{
		ROOT = NULL; // Initializing ROOT to null
	}

	void insert(string element) // insert a node in the binar search tree
	{
		Node* newNode = new Node(element, NULL, NULL); // Allocate memory for the new node
		newNode->info = element; // Assign value to the data field of the new node
		newNode->leftchild = NULL; // Make the left child of the new node point to NULL
		newNode->rightchild = NULL; // Make the right child of the new node point to NULL

		Node* parent = NULL;
		Node* currentNode = NULL;
		search(element, parent, currentNode); // locate the node which will be the parents of the node to be inserted

		if (parent == NULL) // if the parent is NULL (Tree is empty)
		{
			ROOT = newNode; // Mark the new node as ROOT
			return; // Exit
		}

		if (element < parent->info) // if the value in the data field of the new node is greater than that of the parent
		{
			parent->leftchild = newNode; // Make the left child of the parent point to the new node
		}
		else if (element > parent->info) // if the value in the data field of the new node is greater than of the parent
		{
			parent->rightchild = newNode; // Make the right child of the parent point  to the new node
		}
	}

	void search(string element, Node*& parent, Node*& currentNode)
	{
		// this funcition searcher the currentNode of the specified Node as well as the current Node of its parent
		currentNode = ROOT;
		parent = NULL;
		while ((currentNode != NULL) && (currentNode->info != element))
		{
			parent - currentNode;
			if (element < currentNode->info)
				currentNode = currentNode->leftchild; 
			else 
				currentNode = currentNode->rightchild;

		}
	}

	void inorder(Node* ptr)
	{
		if (ROOT == NULL)
		{
			cout << "Tree is empty" << endl;
			return;
		}
		if (ptr != NULL)
		{
			inorder(ptr->leftchild);
			cout << ptr->info << " ";
			inorder(ptr->rightchild);
		}
	}
	void preorder(Node* ptr)
	{
		if (ROOT == NULL)
		{
			cout << "Tree is empty" << endl;
			return;
		}
		if (ptr != NULL)
		{
			cout << ptr->info << " ";
			preorder(ptr->leftchild);
			preorder(ptr->rightchild);

		}
	}

	void postorder(Node* ptr)
	{
		// Performs the postorder traversal of the tree 
		if (ROOT == NULL)
		{
			cout <<	"Tree is empty"	<< endl; 
			return;
		}
		if (ptr != NULL)
		{
			postorder(ptr->leftchild); 
			postorder(ptr->rightchild);
			cout << ptr->info << " ";
		}
	}
};