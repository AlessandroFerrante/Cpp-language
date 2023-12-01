/*
 author: Alessandro Ferrante
 * bst_recursive.cpp
*/

/*
 | Introduces the implementation of a binary search tree (BST) recursively.
 *
 - The recusrive insert function
    ? The bst_insert function inserts a new node into the binary search tree.
    ? The function is also implemented recursively and decides whether the new node should be inserted
    ?  into the left or right subtree of the current node based on the comparison between the values
 *
 - The recursive delete function
    ? The bst_delete function deletes a node with a specific value from the binary search tree.
    ? It handles various cases, including removing a leaf node, a node with only one subtree, 
    ? and an intermediate node with two subtrees. In the case of an intermediate node, 
    ? the successor (the smallest value in the right subtree) is found to maintain the search property of the tree.
  *
  - The recursive search function
    ? The bst_find function is implemented recursively to search for a specific value in the binary search tree. 
    ? It starts at the root of the tree and moves to the left or right subtree, with recursive calls, 
    ? depending on the comparison between the searched value and the value of the current node.
 *
 - The find_max function
    ? Scrolls all the way down the right subtree to the last leaf to look for the maximum value
 *
 - The find_min function
    ? Scrolls down the entire left subtree to the last leaf to look for the minimum value 
 *
 - The visist_in_order function
    ? In-order traversal visits the left subtree first, then the current node, and finally the right subtree. 
    ? This approach follows the "left-node-right" order. 
 *   
 - The visist_in_pre_order function
    ? Pre-order traversal prints the current node value before visiting the subtrees. 
    ? The order is "node-left-right".
 *
 - The visist_in_post_order function
    ? The post-order traversal first visits the subtrees (left and right) and then prints the value of the current node.
    ? The order is "left-right-node".
 *
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
// * typedef node * tree_ptr;
using tree = node * ; // tree_ptr

// - recursive insertion
void bst_insert(tree & root, int value){
    // ? if the tree is empty or as soon as it finds the empty node
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

// - recursive successor search
tree _successor(tree& curr_root){
    // ? if the node has no left child then it is the successor
    if(curr_root->left == nullptr){
        tree successor = curr_root;
        // ? replaces the successor with the right subtree of its parent node
        curr_root = curr_root->right; 
        return successor;
    }
    else{
        // ? if the node has no left child then it is the successor
        return _successor(curr_root->left);
    }
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
        // ? if it has only both left and right children
        if(root->left != nullptr && root->right != nullptr){
            // ? successor search
            tree successor = _successor(root->right);
            // ? replace the value to be deleted with that of the successor
            root->value = successor->value;
            // ? deallocate the successor
            delete successor;
            return;
        }
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
        if (value == current->value)
            return true;
        // ? recursive calls until it finds the node
        // ? the current node will become the main root to "check"
        if (value > current->value)
            return bst_find(current->right, value); 
        else
            return bst_find(current->left, value);
    }
}

// - search for max, scroll through the entire left subtree
const int find_max(tree current) {
    while (current->right != nullptr)
        current = current->right;
    return current->value;
}

// - search for min, scroll through the entire right subtree
const int find_min(tree current) {
    while (current->left != nullptr)
        current = current->left;
    return current->value;
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

    cout << "Visit in order : ";
    visit_in_order(mybst);
    cout << endl;
    
    cout << "Visit in pre order :";
    visit_in_pre_order(mybst);
    cout << endl;

    cout << "Visit in post order : ";
    visit_in_post_order(mybst);
    cout << endl;
    
    cout << "Enter value to delete : ";
    int v;
    cin >> v;
    bst_delete(mybst, v);
    
    cout << "Visit in post order : ";
    visit_in_post_order(mybst);
    cout << endl;
    
    cout << "Enter value to search for : ";
    cin >> v;
    
    if(bst_find(mybst, v))
        cout << "Value found " << endl;
    else
        cout << "Value not found " << endl;
    
    cout << "Max is: " << find_max(mybst) << endl;
    cout << "Min is: " << find_min(mybst) << endl;
    return 0;
}