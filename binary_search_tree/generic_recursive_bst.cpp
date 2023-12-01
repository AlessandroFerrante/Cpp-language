/*
 author: Alessandro Ferrante
 * generic_recursive_bst.cpp
*/

/*
 | Introduces the implementation of a binary search tree (BST) recursively with TEMPLATE.
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

template <typename K, typename D> class node {
    public:
        K key;
        D data;
        node<K, D>* left;
        node<K, D>* right;

        node(K _key, D _data) : key(_key), data(_data), left(nullptr), right(nullptr) { };
};

// - recursive insert function
template <typename K, typename D>
void bst_insert(node<K, D>*& root,K key, D data) {
    if (root == nullptr)
        root = new node<K, D> (key, data);
    else{
        if(key > root->key)
            bst_insert(root->right, key, data);
        else
            bst_insert(root->left, key, data);
    }
}

// - recursive successor search
template <typename K, typename D>
node<K, D>* _successor(node<K, D>* & curr_root) {
    // ? if the node has no left child then it is the successor
    if(curr_root->left == nullptr){
        node<K, D>* successor = curr_root;
        // ? replaces the successor with the right subtree of its parent node
        curr_root = curr_root->right;
        return successor;
    }
    else {
        // ? if the node has no left child then it is the successor
        return _successor<K, D>(curr_root->left);
    }
}

template <typename K, typename D>
void bst_delete(node<K, D>*& root,K key) {
    if(root == nullptr)
        return;
    if(root->key == key){
        // ? if the node is a leaf
        if(root->right == nullptr && root->left == nullptr){
            delete root;
            root = nullptr;
            return;
        }
        // ? if the node has only the left child
        if(root->right == nullptr) {
            node<K, D>* left_child = root->left;
            delete root;
            root = left_child;
            return;
        }
        // ? if the node has only the right child
        if(root->left == nullptr) {
            node<K, D>* right_child = root->right;
            delete root;
            root = right_child;
            return;
        }

        // ? if it has only both left and right children
        node<K, D>* successor = _successor<K, D>(root->right);
        root->key = successor->key;
        root->data = successor->data;
        delete successor;
        return;
    }
    else{
        // ? recursive calls to search in the correct subtree          
        if(key > root->key)
            bst_delete<K, D>(root->right, key);
        else
            bst_delete<K, D>(root->left, key);
    }
}

// - recursive value search
template <typename K, typename D> 
bool bst_find(node<K, D>*& root, K key) {
    if (root == nullptr)
        return false;
    else{
        if(root->key == key)
            return true;
        // ? recursive calls until it finds the node
        // ? the current node will become the main root to "check"
        if(root->key > key)
            return bst_find(root->left, key);
        else
            return bst_find(root->right, key);
    }
}   

// - search for max, scroll through the entire left subtree
template <typename K , typename D>  
node<K, D>* find_max(node<K,D>* current){
    while(current->right != nullptr)
        current= current->right;
    return current;
}

// - search for min, scroll through the entire right subtree
template <typename K, typename D>
node<K, D>* find_min(node<K, D>* current) {
    while(current->left != nullptr)
        current = current->left;
    return current;
}

// - left-node-right
template <typename K, typename D>
void  visit_in_order(node<K, D>* root) {
    if (root != nullptr) {
        visit_in_order(root->left);
        cout << "(" << root->key << " : " << root->data << ")  ";
        visit_in_order(root->right);
    }
}

// - node-left-right
template <typename K, typename D>
void visit_in_preorder(node<K, D>* root){
    if(root != nullptr){
        cout << "(" << root->key << " : " <<  root->data <<")  ";
        visit_in_preorder(root->left);
        visit_in_preorder(root->left);
    }
}

// - right-left-node
template <typename K, typename D>
void visit_in_postorder(node<K, D>* root) { 
    if(root != nullptr){
        visit_in_postorder(root->left);
        visit_in_postorder(root->right);
        cout << "(" << root->key << " : " << root->data << ")  ";
    }  
}

int main(int argc, char ** argv){
    node<int, string>* mybst = nullptr;
    
    bst_insert<int, string>(mybst, 10, "aaa");
    bst_insert<int, string>(mybst, 5, "bbb");
    bst_insert<int, string>(mybst, 2, "ccc");
    bst_insert<int, string>(mybst, 30, "ddd");
    bst_insert<int, string>(mybst, 20, "eee");
    bst_insert<int, string>(mybst, 15, "fff");
    bst_insert<int, string>(mybst, 18, "ggg");
    bst_insert<int, string>(mybst, 40, "hhh");
    bst_insert<int, string>(mybst, 35, "iii");
    bst_insert<int, string>(mybst, 1, "jjj");
    bst_insert<int, string>(mybst, 3, "kkk");
    bst_insert<int, string>(mybst, 37, "lll");
    bst_insert<int, string>(mybst, 11, "mmm");
    bst_insert<int, string>(mybst, 22, "nnn");
    
    /*
    cout << "How many values ​​do you want to insert?";
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int k;
        string s;       
        cout << "Insert key : "; cin >> k;
        cout << "Insert data : "; cin >> s;
        bst_insert<int, string>(mybst, k, s);
    }
    */

    cout << "Visit in order is: ";
    visit_in_order<int, string>(mybst);
    cout << endl;
    cout << "Visit in pre order is: ";
    visit_in_preorder<int, string>(mybst);
    cout << endl;
    cout << "Visit in post order is: ";
    visit_in_postorder<int, string>(mybst);
    cout << endl;

    bst_delete<int, string>(mybst, 35);
    bst_delete<int, string>(mybst, 22);
    bst_delete<int, string>(mybst, 10);

    cout << "Visit in order is: ";
    visit_in_order<int, string>(mybst);
    cout << endl;

    cout << "Trova 5: " << (int)bst_find<int, string>(mybst, 5) << endl;
    cout << "Trova 7: " << (int)bst_find<int, string>(mybst, 7) << endl;
    cout << "Trova 10: " << (int)bst_find<int, string>(mybst, 10) << endl;

    return 0;
    return 0;
}