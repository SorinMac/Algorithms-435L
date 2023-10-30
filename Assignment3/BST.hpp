//librarys that are always used in c++
#include <iostream>
using namespace std;

//This class will be the nodes that are made to make the link list
//The data type for data is char since there will characters passed to make the list
struct BST{
    string data;
    BST* left = nullptr;
    BST* right = nullptr;
    BST* parent = nullptr;
};

string BSTTreeInsert(BST*& root, string value){
    BST* trailing = nullptr;
    BST* current = root;
    string path = "";

    BST* node = new BST;
    node->data = value;

    while(current != nullptr){
        trailing = current;
        if(node->data < current->data){
            current = current->left; // have to make current the node that needs to be checked for
            path = path + "L"; 
        }else{
            current = current->right; // have to make current the node that needs to be checked for
            path = path + "R";
        }
    }

    node->parent = trailing;
    if(trailing == nullptr){
        root = node;
    }else{
        if(node->data < trailing->data){
            trailing->left = node; // check if these are working too seems not really since the stuff up there is not
        }else{
            trailing->right = node; // check if these are working too seems not really since the stuff up there is not
        }
    }

    delete node;
    return path;

}

BST* BSTSearch(BST*& node, string key){
    if(node->left == nullptr && node->right == nullptr || node->data == key){
        cout << ":-" << node->data << " is done searching." << "\n";
        return node;
    }else if(key < node->data){
        cout << "L";
        return BSTSearch(node->left, key);
    }else{
        cout << "R";
        return BSTSearch(node->right, key);
    }
}
