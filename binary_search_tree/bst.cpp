/*
 author: Alessandro Ferrante
 * bst.cpp
*/

/*
 | The file introduces binary search trees with the use of struct.

 ? The bst_insert function 
    - Scroll the bst based on the value to be inserted, 
    - Following a path, searches for the correct position for the new node. 
    - When it finds an empty location, it creates a new node with the specified value 
    - and links it to the parent node on the left or right (or makes it root if the tree is empty).
 ? The bst_delete function
    - The bst_delete function is designed to remove a specific node from a binary search tree (BST).
    - It starts traversing the tree by looking for the node to delete and handles three main cases:
    - the node to be eliminated is a leaf,
    - has only one child (left or right),
    - or has both children.
    - In the case of only one child, it replaces the node to be deleted with its only child.
    - In the case of both children, find the successor in order
    - (the smallest node in the right subtree) to maintain the search property of the BST.
    - The function manages the detachment of the node to be deleted and the reconfiguration of the pointers in the BST.
 ? The bst_find function
    -
 ? The in_order function
    -
 ? The 
*/

#include <iostream>

using namespace std;


typedef struct node{
    // ? node value
    int value; // key
    // ? pointer to the left child
    node * left; // tree left
    // ? pointer to the right child
    node * right; // tree right
} node;

// ? for the root
// typedef node * tree_ptr;
using tree = node * ; // tree_ptr

void bst_insert(tree & root, int value) {
    tree current = root; // ? Initialize current node = root
    tree parent = nullptr; // ? 'parent' pointer to the parent node

    // | SCROOLS the tree to the empty position
    while(current != nullptr) {
        // ? if the value is 'greater' than the current node value, move right
        if (value > current->value) {
            parent = current;
            current = current->right;
        }
        // ? if the value is 'smaller' than the current node value, move left
        else {
            parent = current;
            current = current->left;
        }
    }

    // ? Create and initialize the new node
    tree new_node = new node;
    new_node->value  = value;
    new_node->left = nullptr;
    new_node->right = nullptr;

    // | INSERTION of the new node, in the correct position
    if (root == nullptr) {
        // ? if the tree is empty, it becomes the root
        root = new_node; 
    }
    else {
        // ? otherwise, it becomes right child or left child
        if(value > parent->value)
            parent->right = new_node;
        else
            parent->left = new_node;
    }
}

void bst_delete (tree root, int value) {
    tree current = root; // ?  Initialize current node = root
    tree parent = nullptr; // ? 'parent' pointer to the parent node
    
    // _ Scroll through the tree to the node to delete
    while (current != nullptr) {
        
        // | if the value is the one to be deleted
        if (value == current->value) {
            
            // - checks if the node to be deleted is a leaf -----------
            if (current->right == nullptr && current->left == nullptr) {
                // ? Detaches the node from its parent and deallocates it
                if (value > parent->value) {
                    // ? if the node is to the right of the parent
                    parent->right = nullptr; 
                }
                else {
                    // ? if the node is to the left of the parent
                    parent->left = nullptr;
                }
                delete current;
                return;
            }

            // - if it is not a leaf and has a right child -----------------
            tree successor = current->right; // ? right child of the node to be deleted
            tree successor_parent = current; // ? node to delete
            
            // ? searches for the successor i.e. the smallest element in the right subtree
            // ? iterate to the last child on the left
            while(successor->left != nullptr) {
                successor_parent = successor;
                successor = successor->left; // 
            }

            // ? detaches the successor from the tree
            // * successor_parent->left is the left pointer to the successor's parent
            // * successor_right is the right child of the successor
            // ? modifies the left pointer of the successor's parent by connecting it to the right subtree of the successor
            successor_parent->left = successor->right; 
            
            // - replace the value of the node to be deleted with that of the successor
            current->value = successor->value;

            // - check which child was to be deleted -------------------
            // ? if it's the left one
            if(current->left == successor)
                current->left = nullptr;
            // ? if it's the right
            if(current->right == successor)
                current->right = nullptr;
            
            // ? deallocates the memory occupied by the successor
            delete successor;

            return;
        }
        
        // | if the node to be deleted is greater than the current node we move to the right
        if (value > current->value){
            parent = current;
            current = current->right;
        }
        // | if the node to be deleted is smaller than the current node we move to the left
        else{
            parent = current;
            current =  current->left;
        }
    }
}

void visit_in_order(tree root)
{
	if (root != nullptr) {
		visit_in_order(root->left);
		cout << root->value << " ";
		visit_in_order(root->right);
	}
}

int main(int agc, char ** argv){
    tree mybst = nullptr;
	
	bst_insert(mybst, 10);
	bst_insert(mybst, 5);
	bst_insert(mybst, 2);
	bst_insert(mybst, 30);
	bst_insert(mybst, 20);
	bst_insert(mybst, 15);
	bst_insert(mybst, 18);
	bst_insert(mybst, 40);
	bst_insert(mybst, 35);
	bst_insert(mybst, 1);
	bst_insert(mybst, 3);
	bst_insert(mybst, 37);
	bst_insert(mybst, 11);
	bst_insert(mybst, 22);

    visit_in_order(mybst); cout << endl;

    bst_delete(mybst, 35);

    visit_in_order(mybst); cout << endl;

    return 0;
}