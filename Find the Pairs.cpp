#include<iostream>
using namespace std;

struct Node {
	int data;
	struct Node *left;
	struct Node *right;
	struct Node *prev;
	struct Node *next;
};

	class BST{
		private:
			struct Node *start = NULL;
        public:
			Node* insert(int x, Node* root);	//Insert a new node at the beginning
			void preorder(Node* root);			//pre-order traversal
			void insertBeg(int x);				// Insert values to the linked list
			void checkPairs(int sum);
    };

Node* BST::insert(int x, Node* root)
	{
		if (root == NULL)
		{
			root = new Node;
			root->data = x;
			root->left = root->right = NULL;
		}
		else if (x < root->data)
			root->left = insert(x, root->left);
		else if (x > root->data)
			root->right = insert(x, root->right);
		return root;
	}

void BST::preorder(Node* root) {
	Node* temp = root;
	if (root != NULL)
	{
		insertBeg(temp->data);
		//cout << temp->data << " ";
		preorder(temp->left);
		preorder(temp->right);
	}
}

void BST::insertBeg(int x)
{
	struct Node* newNode;
	newNode = new Node;
	if (start == NULL)
	{
		start = newNode;
		newNode->data = x;
		newNode->next = NULL;
		newNode->prev = NULL;
	}
	else
	{
		newNode->data = x;
		newNode->prev = NULL;
		start->prev = newNode;
		newNode->next = start;
		start = newNode;
	}
}

void BST::checkPairs(int sum)
{
	struct Node* temp1 = start;
	struct Node* temp2;
	bool flag = 0;
	while (temp1 != NULL)
	{
		temp2 = temp1->next;
		while (temp2 != NULL)
		{
			if (temp1->data + temp2->data==sum)
			{
				cout << " (" << temp1->data << "," << temp2->data << ")";
				flag = 1;
			}
			temp2 = temp2->next;
		}
		temp1 = temp1->next;
	}
	if (flag == 0)
		cout << " There are no sum of pairs which equal to the given value !!!";
}


int main() {

	BST tree;
	Node* root = NULL;
	int n,val,x;
	cout << "Enter the Number of nodes in the Tree : ";
	cin >> n;


	cout << "Enter Elements : ";

	for (int i = 0; i <n; i++)
	{
		cin >> x;		//getting user input values
		root = tree.insert(x, root);	//add those values to the tree
	}


	tree.preorder(root);

	cout << "Enter a value : ";
	cin >> val;

	cout << "\nPairs :";
	tree.checkPairs(val);
	cout << endl<<endl;
	system("pause");
}