/*
 author: Alessandro Ferrante
 * bst_recursive.cpp
*/

/*
 | Introduces the implementation of a binary search tree (BST) recursively.
 *
 ? 
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

// - recursive insertion
void bst_insert(tree root, int value){
    // ? se l'albero è vuoto o appena trova il nodo vuoto
    if(root == nullptr) {
        root = new node;
        root->value = value;
        root->left = nullptr;
        root->right = nullptr;
    }
    else{ 
        // ? inserts the value into the correct subtree recursively
        if (value < root->value)
            bst_insert(root->left, value);
        else
            bst_insert(root->right, value);
    }
}

tree successor(tree& root){
    // todo
}

// - recursive delete function
void bst_delete(tree& root, int value){
    if (root == nullptr)
        return;
    if(root->value == value){
        
        // - checks if the node is a leaf
        if(root->right == nullptr && root->left == nullptr) {
            // * is a leaf, in fact is delete directly
            delete root;
            root = nullptr;
            return;  
        }
        // - checks if it has a child
        // ? node with only left subtree
        if(root->right == nullptr) {
            tree current = root->left;
            delete root;
            root = current;
            return;
        }
        // ? node with only right subtree
        if(root->left == nullptr) {
            tree current = root->right;
            delete root;
            root = current;
            return;
        }
        
        // ? successor search
        tree successor = sucessor(root->right); // todo successor function
        
        // - replace the value to be deleted with that of the successor
        root->value = successor->value;
        
        // ? deallocate the successor
        delete successor;
        return;
    }
    else {
        // ? recursive calls to search in the correct subtree  
        if (value > root->value)
            bst_delete(root->right, value);
        else
            bst_delete(root->left, value);
    }
}

// - recursive value search
bool bst_find(tree current, int value){
    // ? if the tree is empty or the value was not found
    if (current == nullptr)
        return false;
    else{
        if (value = current->value)
            return true;
        // ? recursive calls until it finds the node
        // ? the current node will become the main root to "check"
        if (value > current->value)
            return bst_find(current->right, value); 
        else
            return bst_find(current->left, value);
    }
}

// - left-node-right
void visit_in_order(tree root) {
	if (root != nullptr) {
        // ? scrolls through the entire left subtree and then over the left children of the right subtree
		visit_in_order(root->left);
        // ? prints the current value, subtree first
		cout << root->value << " ";
        // ? scrolls to the right children of the left subtree and then to the right subtree
		visit_in_order(root->right);
	}
}

// - node-left-right
void visit_in_pre_order(tree root){
    if (root != nullptr) {
        // ? prints the current value, node first
        cout << root->value << " ";
        // ? scrolls through the entire left subtree and then over the left children of the right subtree
        visit_in_pre_order(root->left);
        // ? scrolls to the right children of the left subtree and then to the right subtree
        visit_in_pre_order(root->right);
    }
}

// - right-left-node
void visit_in_post_order(tree root) {
    if (root != nullptr) {
        // ? scrolls through the entire left subtree and then over the left children of the right subtree
        visit_in_post_order(root->left);
        // ? scrolls to the right children of the left subtree and then to the right subtree
        visit_in_post_order(root->right);
        // ? prints the current value, child right of subtree first
        cout << root->value << " ";
    }
}

int main(int argc, char ** argv){
  // todo

 return 0;
}