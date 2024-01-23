/*
 author: Alessandro Ferrante
 * tracking.cpp
*/

/*
 | This file is designed to automate the analysis of interactions on Instagram. 
 "Given that a web application or WebView on Android, via JavaScript code, 
 manages the retrieval of data on followers and followed users, subsequently saving the data in JSON format." 
 | The C++ code coordinates the information processing, in particular, 
 | it reads JSON files obtaining the elements in a JSON array, 
 | organizes them into binary search trees and compares them to obtain unfollowers and new followers.
*/
#include <iostream>
#include <string>
#include <fstream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;
using namespace std;

template <typename U, typename F>class node{
    private: 
        // attributes
        U username;
        F fullname;
        node<U, F>* left;
        node<U, F>* right;
        // root of the tree
        node<U, F>* root;

        // internal methods
    
        void internal_insert(node<U, F> *& root, U & username, F & fullname){
            if(root==nullptr){
                root = new node(username, fullname);
            }
            else{
                if(username > root->username)
                    internal_insert(root->right, username, fullname);
                else    
                    internal_insert(root->left, username, fullname);
            }
        } 

        node<U, F>* internal_successor(node<U, F> *& root){
            if(root->right == nullptr){
                node* successor = root;
                root = root->right;
                return successor;
            }
            else
                return internal_successor(root->left);
        }

        void internal_delete(node<U, F> *& root, U username){
            if(root == nullptr)
                return;
            if(root->username.compare(username)==0){
                if(root->left == nullptr && root->right == nullptr){
                    delete root;
                    root = nullptr;
                    return;
                }
                if(root->right == nullptr){
                    node* left_child = root->left;
                    delete root;
                    root = left_child;
                    return;
                }
                if(root->left == nullptr){
                    node* right_child = root->right;
                    delete root;
                    root = right_child;
                    return;
                }
                if(root->left != nullptr && root->right != nullptr){
                    node* successor = internal_successor(root->right);
                    root->username = successor->username;
                    root->fullname = successor->fullname;
                    delete successor;
                    return;
                }
            }
            else{
                if(root->username.compare(username)<0 )
                    return internal_delete(root->right, username);
                else
                    internal_delete(root->left, username);
            }

        }
        // - FIND
        int internal_find(node<U, F> * root, U username){
            if(root == nullptr)
                return 0;
            if(root->username.compare(username)==0)
                return 1;
            if(root->username.compare(username)<0)
                return internal_find(root->right, username);
            return internal_find(root->left, username);
        }/*
        void internal_visit(node<U, F>* root){
            if (root == nullptr) {
                return;
            }

            internal_visit(root->left);
            internal_visit(root->right);

            // Visit operations, for example, you can print node data:
            cout << "Visiting: " << root->username << endl;
        }*/
        void internal_visit_and_delete(node<U, F>* root, node<U, F>& other_tree) {
            if (root == nullptr) {
                return;
            }

            // Recursive calls on the left and right subtrees
            internal_visit_and_delete(root->left, other_tree);
            internal_visit_and_delete(root->right, other_tree);

            //Visit operations, for example, you can print node data:
            //cout << "Visiting: " << root->username << endl;

            // Check if the username is present in the other tree
            if (other_tree.find(root->username) == 1) {
                // If present, delete the username from the other tree
                other_tree.del(root->username);
                //cout << "Deleted: " << root->username << " from the other tree" << endl;
            }
        }

        json internal_tree_data(node<U, F>* root) {
            json jsonData;

            if (root == nullptr) {
                return jsonData;
            }

            json jsonDataLeft = internal_tree_data(root->left);
            json jsonDataRight = internal_tree_data(root->right);

            // Iterate jsonDataLeft array and add unique elements to jsonData
            for (const auto& element : jsonDataLeft) {
                if (std::find(jsonData.begin(), jsonData.end(), element) == jsonData.end()) {
                    jsonData.push_back(element);
                }
            }

            // Iterate jsonDataRight array and add unique elements to jsonData
            for (const auto& element : jsonDataRight) {
                if (std::find(jsonData.begin(), jsonData.end(), element) == jsonData.end()) {
                    jsonData.push_back(element);
                }
            }

            // Add current node data to jsonData if it's unique
            json currentNode;
            currentNode["username"] = root->username;
            currentNode["full_name"] = root->fullname;

            if (std::find(jsonData.begin(), jsonData.end(), currentNode) == jsonData.end()) {
                jsonData.push_back(currentNode);
            }

            //cout << "DEBUG: jsonData for " << root->username << ":\n" << jsonData.dump(2) << endl;

            return jsonData;
        }
        void internal_visit_in_order(node<U, F>* root){
            if(root == nullptr)
                return;
            internal_visit_in_order(root->left);
            cout << "{\n" << " username : " << root->username << ",\n" << " full_name : " << root->fullname << "\n}," << endl;
            internal_visit_in_order(root->right); 
        }
        void internal_visit_in_preorder(node<U, F>* root){
            if(root==nullptr)
                return;
            cout << "(" << root->username << " - " << root->fullname << ") ";
            internal_visit_in_preorder(root->left);
            internal_visit_in_preorder(root->right);
        }
        void internal_visit_in_postorder(node<U, F>* root){
            if(root==nullptr)
                return;
            internal_visit_in_postorder(root->left);
            internal_visit_in_postorde(root->right);
            cout << "(" << root->username << " - " << root->fullname << ") ";
        }
    public:
        // default constructor, for the tree
        node() : root(nullptr) { }
        node(U _username, F _fullname) : username(_username), fullname(_fullname), left(nullptr), right(nullptr) { };

        void insert(U username, F fullname){
            internal_insert(root, username, fullname);
        }

        void del(U username){
            internal_delete(root, username);
        }
        void visit(){
            internal_visit(root);
        }
        void visit_in_order(){
            internal_visit_in_order(root);
        }
        void visist_in_pre_order(){
            internal_visit_in_preorder(root);
        }
        void visit_in_postorder(){
            internal_visit_in_postorde(root);
        }

        int find(const U username){
            return internal_find(root, username);
        }
        void visit_and_delete(node<U, F> & old_followers){
            internal_visit_and_delete(root, old_followers);
        }
        void writeFile(const string filename){
            json jsonData_out;
            ofstream file(filename, ios_base::out ); // edit with app(append) to add to existing data
            bool first = true;
            if (file.is_open()) {    

                json fixedRecord;
                //fixedRecord["username"] = "People who stopped following you"";
                //fixedRecord["full_name"] = "";
                //jsonData_out.push_back(fixedRecord);
                fixedRecord = internal_tree_data(root);
                for (const auto& element : fixedRecord){
                    if (std::find(jsonData_out.begin(), jsonData_out.end(), element) == jsonData_out.end()) {
                        jsonData_out.push_back(element);
                    }
                }
                if (!first) {
                    file << "," << endl;
                }
                    file << " " << setw(4) << jsonData_out.dump(2);
                    first = false;
                file.close();        
            }else{
                cerr << "File1 opening error" << endl;
                return;
            }
        }
};


void readFile(node<string, string> & new_followers, const string filename){
    ifstream file2;
    file2.open(filename, fstream::in | fstream::out);
        
    json jsonData;
    if (file2.is_open()) {
        // Read the JSON file
        file2 >> jsonData;
        file2.close();
        // Check if the file is a JSON array
        if (jsonData.is_array()) {
            //Iterate through the elements of the array
            for (const auto& entry : jsonData) {
                // Extract and print the values ​​of "username" and "full_name"
                string username = entry["username"];
                string fullname = entry["full_name"];
                new_followers.insert(username, fullname);
            }
        }
        else {
            cerr << "The file" << filename << " does not contain a JSON array." << endl;
            exit(1);
            return ;
        }
    } 
    else {
        cerr << "File2 opening error" << endl;
        return;
    }
}

int main(int argc, char ** argv){
    node<string, string> old_followers1;
    node<string, string> old_followers2;
    node<string, string> new_followers;
    string str[5];
    cout << "Enter the file name or data path of the old followers : ";
    cin >> str[0]; 
    readFile(old_followers1, str[0]);
    readFile(old_followers2, str[0]);
    cout << "Enter the file name or data path of the current followers : ";
    cin >> str[1]; 
    readFile(new_followers, str[1]);
    new_followers.visit_and_delete(old_followers1); // delete new followers from the old tree, to get unfollowers
    old_followers2.visit_and_delete(new_followers); // delete old followers from the new tree, to get new ones
    
    cout << "Unfollower: "  << endl;
    old_followers1.visit_in_order();
    cout << "New follower: " << endl;
    new_followers.visit_in_order();

    //prints both unlost and new ones
    cout << "Enter the file name or data path of where you want to save the new followers: ";
    cin >> str[2]; 
    new_followers.writeFile(str[2]);
    cout << "Enter the file name or data path of where you want to save the unfollowers: ";
    cin >> str[3]; 
    old_followers1.writeFile(str[3]);

    do{
        cout << "Press Enter to end the process." << endl;
    }while(getline(cin, str[4]) && str[4]!="");

 return 0;
}