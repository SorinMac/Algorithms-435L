//librarys that are always used in c++
#include <iostream>
using namespace std;

//This class will be the nodes that are made to make the Binary Search Tree
//The data type for data is string since there will whole strings passed into it
struct BST{
    string data;
    //the left side for values lesser than the one before
    BST* left = nullptr;
    //the right side for values greater than the one before
    BST* right = nullptr;
    //to find the one that it came from
    BST* parent = nullptr;
};

string BSTTreeInsert(BST*& root, string value){
    //used to find the parent node this will be trailing one behind in the search
    BST* trailing = nullptr;
    //the one you are on will start at the root and then go up the tree
    BST* current = root;
    //the pathway that will be taken
    string path = "";

    //a new node that will have the value passed as the data for it so we have a new node where the node gets place 
    BST* node = new BST;
    node->data = value;

    //while the place you are at is not at the end check
    while(current != nullptr){
        //make the trailing the current so we are a step behind
        trailing = current;
        //if less then the current is the left side
        if(node->data < current->data){
            current = current->left; 
            path = path + "L"; 
        //if greater then the current is the right side
        }else{ // greater
            current = current->right; 
            path = path + "R";
        }
    }

    //the parent become the one behind it so we know where it came from
    node->parent = trailing;
    //if trailing is null than that node is the root
    //so the first node will always be the root
    if(trailing == nullptr){
        root = node;
    }else{
        //if not and the data is less then at the the end the new node is the left side
        if(node->data < trailing->data){
            trailing->left = node; 
        //if not and the data is greater then at the the end the new node is the right side
        }else{ // greater
            trailing->right = node; 
        }
    }

    //return the path string taken for print out
    return path;

}

//passes the key we are looking for and the node (the start or root)
BST* BSTSearch(BST*& node, string key){
    //if the node left and right is null then output (not there), if the data is the key also output (found)
    if(node->data == key){
        cout << ":-" << node->data << " is done searching." << "\n";
        return node;
    //if the key does not exists in the search tree
    }else if(node->left && node->right == nullptr){
        cout << ":-" << key << " is not found" << "\n";
        return node;
    //if the key is less then data then return the left side to go down next
    }else if(key < node->data){
        cout << "L";
        return BSTSearch(node->left, key);
    //if the key is greater then data then return the right side to go down next
    }else{ // greater
        cout << "R";
        return BSTSearch(node->right, key);
    }
}
