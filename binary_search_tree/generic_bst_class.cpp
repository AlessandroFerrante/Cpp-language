/*
 author: Alessandro Ferrante
 * generic_bst_class.cpp
*/

/*
 | Introduces the implementation of a binary search tree (BST) recursively 
 | with class and methods internal and public with template.
  *
 | The creation of the bst occurs through a class with internal and private methods to manage the main operations of the tree. 
 | These "internal methods" work directly with the nodes, using the root as the starting point for operations, 
 | the class exposes "public methods" as an external interface that call the class's internal methods, often starting with the root as the entry point.
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
#include <string>

using namespace std;

template <typename K, typename D>
class node{
    private:
        // ? attributes
        K key;
        D data;
        node* left;
        node* right;
        // ? root of the tree
        node * root;

        // ? internal methods

        // - recursive internal insert method
        void internal_insert(node<K, D> *& root, K & key, D & data) {
            if(root == nullptr)
                root = new node(key, data);
            else{
                if(key > root->key)
                    internal_insert(root->right, key, data);
                else
                    internal_insert(root->left, key, data);
            }
        }

        // - recursive internal method to search the successor
        node<K, D> * internal_successor(node<K, D>  *& root){
            if(root->left == nullptr){
                node * successor = root; // ? stores the last left child
                root = root->right;
                return successor; // ? return the last left node
            }
            else
                return internal_successor(root->left); 
        }

        // - recursive internal method to delete node   
        void internal_delete(node<K, D> *& root, K key) {
            if(root == nullptr)
                return;
            if(root->key == key){
                // ? if the node is a leaf
                if(root->left == nullptr && root->right == nullptr) {
                    delete root;
                    root = nullptr;
                    return;
                }
                // ? if the node has only the left child
                if(root->right == nullptr) {
                    node* left_child = root->left;
                    delete root;
                    root = left_child;
                    return;
                }
                // ? if the node has only the right child
                if(root->left == nullptr) {
                    node* right_child = root->right;
                    delete root;
                    root = right_child;
                    return;
                }
                // ? if the node has both the right child and left child
                if(root->right != nullptr && root->left != nullptr){
                    node* successor = internal_successor(root->right);
                    root->key = successor->key;
                    root->data = successor->data;
                    delete successor;
                    return;
                }
            }
            else{
                if(key > root->key)
                    internal_delete(root->right, key);
                else
                    internal_delete(root->left, key);
            }
        }

        // - recursive internal method to print the visit in order
        void internal_visit_in_order(node<K, D> * root){
            if(root == nullptr)
                return;
            internal_visit_in_order(root->left);
            cout << "(" << root->key << ": " << root->data << ")  ";
            internal_visit_in_order(root->right);
        }
        
        // - recursive internal method to print the visit in preorder
        void internal_visit_in_preorder(node<K, D> * root){
            if(root == nullptr)
                return;
            cout << "(" << root->key << ": " << root->data << ")  ";                
            internal_visit_in_preorder(root->left);
            internal_visit_in_preorder(root->right);
        }
        
        // - recursive internal method to print the visit in postorder
        void internal_visit_in_postorder(node<K, D> * root){
            if(root == nullptr)
                return;
            internal_visit_in_postorder(root->left);
            internal_visit_in_postorder(root->right);
            cout << "(" << root->key << ": " << root->data << ")  ";                 
        }

        // - recursive internal method to find a value
        bool internal_find(node<K, D> * root, K key){
            if(root == nullptr)
                return false;
            if(root->key == key)
                return true;
            if(key > root->key)
                return internal_find(root->right, key);
            //else // ? it is possible to comment why it should be executed if the condition is not true
                return internal_find(root->left, key);
        }
        
        // - recursive internal method to find the max key
        node<K, D> * internal_find_max(node<K, D>* current){
            while(current->right != nullptr)
                current = current->right;
            return current;
        }
        
        // - recursive internal method to find the smallest key
        node<K, D> * internal_find_min(node<K, D>* current) {
            while(current->left != nullptr)
                current = current->left;
            return current;
        }

    public:
        // ? default constructor, for the tree
        node() : root(nullptr) { };

        // ? parameters constructor
        node(K key, D d) : key(key), data(d), left(nullptr), right(nullptr) { };

        // ? methods

        // - insert method to get the value that needs to be inserted
        void insert(K key, D data) {
            internal_insert(root, key, data);
        }
        
        // - delete method to get the value that needs to be deleted
        void del(K key) {
            internal_delete(root, key);
        }
       
        // - method to invoke the "internal method internal_visit_in_order "with the 'root'
        void visit_in_order(){
            internal_visit_in_order(root);
        }
        
        // - method to invoke the "internal method internal_visit_in_preorder" with the 'root'
        void visit_in_preorder(){
            internal_visit_in_preorder(root);
        }
        
        // - method to invoke the "internal method internal_visit_in_postorder" with the 'root'
        void visit_in_postorder(){
            internal_visit_in_postorder(root);
        }
        
        // - find method to get the value that needs to be searched
        bool find(K key) {
            internal_find(root, key);
        }
        
        // - find method to searched the max key
        void find_max(){
            cout << "Max is ";
            node<K, D>* max= internal_find_max(root);
            cout << max->key << ": " << max->data << endl;
        }
        
        // - find method to searched the smallest key
        void find_min(){
            cout << "Min is ";
            node<K, D>* min= internal_find_min(root);
            cout << min->key << ": " << min->data << endl;
        }

};

int main(int argc, char ** argv){
    
    node<int, string> mybst;

    mybst.insert(10, "aaa");
    mybst.insert(2, "bbb");
    mybst.insert(4, "ccc");
	mybst.insert(5, "ddd");
	mybst.insert(20, "eee");

    cout << "My bst in order : ";
    mybst.visit_in_order();
    cout << endl;

    cout << "My bst in pre order : ";
    mybst.visit_in_preorder();
    cout << endl;

    cout << "My bst in post order : ";
    mybst.visit_in_postorder();
    cout << endl;

    cout << "Find 2 : " << mybst.find(2) << endl;
	cout << "Find 3 : " << mybst.find(3) << endl;
	cout << "Find 10 : " << mybst.find(10) << endl;

    mybst.del(2); 
    mybst.del(20);
    
    cout << "My bst in order : ";
    mybst.visit_in_order();
    cout << endl;

    mybst.find_max();
    mybst.find_min();

    return 0;
}