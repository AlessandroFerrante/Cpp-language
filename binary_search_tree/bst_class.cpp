/*
 author: Alessandro Ferrante
 * bst_class.cpp
*/

/*
 | Introduces the implementation of a binary search tree (BST) recursively with class and methods.
 *
 | The creation of the bst occurs through a class with internal and private methods to manage the main operations of the tree. 
 | These "internal methods" work directly with the nodes, using the root as the starting point for operations, 
 | the class exposes "public methods" as an external interface that call the class's internal methods, often starting with the root as the entry point.
 *
 - The recusrive internal_insert function
    ? The internal_insert function inserts a new node into the binary search tree.
    ? The function is also implemented recursively and decides whether the new node should be inserted
    ?  into the left or right subtree of the current node based on the comparison between the values
 *
 - The recursive internal_delete function
    ? The internal_delete function deletes a node with a specific value from the binary search tree.
    ? It handles various cases, including removing a leaf node, a node with only one subtree, 
    ? and an intermediate node with two subtrees. In the case of an intermediate node, 
    ? the successor (the smallest value in the right subtree) is found to maintain the search property of the tree.
  *
  - The recursive internal_successor function
    ? The internal_successor function searches for the internal successor of a node in a binary search tree.
    ? If the left subtree is present, the function moves to the left; otherwise, 
    ? it returns the current node as the successor and updates the pointer to the right subtree.
  *
  - The recursive search function
    ? The bst_find function is implemented recursively to search for a specific value in the binary search tree. 
    ? It starts at the root of the tree and moves to the left or right subtree, with recursive calls, 
    ? depending on the comparison between the searched value and the value of the current node.
 *
 - The visist_in_order function
    ? In-order traversal visits the left subtree first, then the current node, and finally the right subtree. 
    ? This approach follows the "left-node-right" order. 
 *
*/

#include <iostream>

using namespace std;

class node{
    private:
        // attributes
        int value;
        node * left;
        node * right;
        // ? root of the tree
        node * root;

        // ? internal methods
        void internal_insert(node*& root, int value);
        void internal_delete(node*& root, int value);
        bool internal_find(node* current, int value);
        void internal_visit_in_order(node* root);
        node * internal_successor(node*& root);

    public: 
        // default constructor, for the tree
        node() : root(nullptr) { };
        // parameter constructor
        node(int v) : value(v), left(nullptr), right(nullptr) { };
        
        // public methods
        void insert(int value);
        void del(int value);
        void visit_in_order();
        bool find(int value);

};  

// - recursive internal insert method
void node::internal_insert(node *& root, int value) {
    if(root == nullptr)
        root = new node(value);
    else{
        if(value < root->value)
            internal_insert(root->left, value);
        else
            internal_insert(root->right, value);
    }
}
// - insert method to get the value that needs to be inserted
void node:: insert(int value){
    internal_insert(root, value);
}

// - recursive internal method to search the successor
node* node::internal_successor(node *& curr_root) { 
    if(curr_root->left == nullptr){
        node * successor = curr_root;
        curr_root = curr_root->right;
        return successor; // ? return the last left node
    }
    else
        return internal_successor(curr_root->left);
}

// - recursive internal method to delete node
void node::internal_delete(node *& root, int value) {
    if(root == nullptr)
        return;
    if(root->value == value){
        // id the node is a leaf
        if(root->right == nullptr && root->left == nullptr){
            delete root;
            root = nullptr;
            return;
        }
        // if the node has only the left child
        if(root->right == nullptr) {
            node* left_child = root->left;
            delete root;
            root = left_child;
            return;
        }
        // if the node has only the right child
        if(root->left == nullptr) {
            node* right_child = root->right;
            delete root;
            root = right_child;
            return;
        }

        if(root->left != nullptr && root->right != nullptr) {
            node * successor = internal_successor(root->right);
            root->value = successor->value;
            delete successor;
            return;
        }
    }
    else{
        if(value > root->value)
            internal_delete(root->right, value);
        else
            internal_delete(root->left, value);
    }
}

// - delete method to get the value that needs to be deleted
void node::del(int value) {
    internal_delete(root, value);
}

// - recursive internal method to find a value
bool node::internal_find(node * current, int value) {
    if(current == nullptr)
        return false;
    else{
        if (value == current->value)
            return true;
        if (value > current->value)
            return internal_find(current->right, value);
        else
            return internal_find(current->left, value);
    }
}

// - find method to get the value that needs to be searched
bool node::find(int value){
    return internal_find(root, value);
}

// - recursive internal method to print the visit in order
void node::internal_visit_in_order(node * root) {
    if(root != nullptr) {
        internal_visit_in_order(root->left);
        cout << root->value << " ";
        internal_visit_in_order(root->right);
    }
}

// - method to invoke the internal method with the 'root'
void node::visit_in_order() {
    internal_visit_in_order(root);
}

int main(int argc, char ** argv) {
    
    node mybst; // with default constructor initialize root to nullptr

    mybst.insert(10);
    mybst.insert(2);
    mybst.insert(4);
    mybst.insert(5);
    mybst.insert(20);

    mybst.visit_in_order(); cout << endl;

	cout << "Find 2 : " << (int)mybst.find(2) << endl;
	cout << "Find 3 : " << (int)mybst.find(3) << endl;
	cout << "Find 10 : " << (int)mybst.find(10) << endl;
	
	mybst.del(2);
	mybst.visit_in_order(); cout << endl;
    return 0;
}