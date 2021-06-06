#include <fstream>
#include "binarySearchTree.h"
#include "customErrorClass.h"

using namespace std;

C_binarySearchTree::C_binarySearchTree(void){
    this->root = NULL;
    this->nodeCount = 0;
}

C_binarySearchTree::~C_binarySearchTree(void){
    this->p_deleteTree(this->root);
}
/*
**    Author: Berlin Johnson
**    Function Purpose: 
**        
**    Function Output:
**    Side Effects: 
*/

B_NODE* C_binarySearchTree::createNode(int value){
    B_NODE* temp = new B_NODE;

    temp->value = value;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}
/*
**    Author: Berlin Johnson
**    Function Purpose: 
**        
**    Function Output:
**    Side Effects: 
*/

void C_binarySearchTree::insertValue(int value){
    B_NODE *node = this->createNode(value);

    if(NULL == this->root){
        this->root = node;
    } else {
        this->p_insertValue(this->root, node);
    }
    this->nodeCount++;
    return;
} 
/*
**    Author: Berlin Johnson
**    Function Purpose: 
**        
**    Function Output:
**    Side Effects: 
*/

B_NODE* C_binarySearchTree::p_insertValue(B_NODE* parent, B_NODE* currentNode){

    if(NULL == parent){
        return currentNode;
    } else {
        if(currentNode->value < parent->value){
            parent->left = this->p_insertValue(parent->left, currentNode);
        } else if(currentNode->value > parent->value){
            parent->right = this->p_insertValue(parent->right, currentNode);
        } 
    }
    return parent;
}
/*
**    Author: Berlin Johnson
**    Function Purpose: 
**        
**    Function Output:
**    Side Effects: 
*/
/*
void C_binarySearchTree::findNode(int value){

}*/
/*
**    Author: Berlin Johnson
**    Function Purpose: 
**        
**    Function Output:
**    Side Effects: 
*/
/*
B_NODE* C_binarySearchTree::p_findNode(B_NODE* parent, B_NODE* currentNode){
    if(NULL == parent){
        return currentNode;
    } else {
        if(currentNode->value < parent->value){
            parent->left = this->p_insertValue(parent->left, currentNode);
        } else if(currentNode->value > parent->value){
            parent->right = this->p_insertValue(parent->right, currentNode);
        } 
    }
    return parent;
}*/

/*
**    Author: Berlin Johnson
**    Function Purpose: 
**        
**    Function Output:
**    Side Effects: 
*/

void C_binarySearchTree::sortTree(){
    this->p_sortTree();
}
/*
**    Author: Berlin Johnson
**    Function Purpose: 
**        
**    Function Output:
**    Side Effects: 
*/
void C_binarySearchTree::p_sortTree(){
    int *tempArr = new int[this->nodeCount];
    this->p_populateArray(this->root, tempArr, 0);
}

/*
**    Author: Berlin Johnson
**    Function Purpose: 
**        
**    Function Output:
**    Side Effects: 
*/

void C_binarySearchTree::printTree(){
    if(NULL != this->root){
        this->p_printTree(this->root);
    } else {
        cout << "Empty Tree" << endl;
    }
}
/*
**    Author: Berlin Johnson
**    Function Purpose: 
**        
**    Function Output:
**    Side Effects: 
*/

void C_binarySearchTree::p_printTree(B_NODE* node){
    if(NULL == node){
        return;
    } else {
        this->p_printTree(node->left);
        cout << node->value << endl;
        this->p_printTree(node->right);
    }
}

/*
**    Author: Berlin Johnson
**    Function Purpose: 
**        
**    Function Output:
**    Side Effects: 
*/
void C_binarySearchTree::p_populateArray(B_NODE* node, int *myArray, int key){
    if(NULL == node){
        return;
    } else {
        this->p_populateArray(node->left, myArray, key + 1);
        myArray[key] = node->value;
        this->p_populateArray(node->right, myArray, key + 1);
    }
}

/*
**    Author: Berlin Johnson
**    Function Purpose: 
**        
**    Function Output:
**    Side Effects: 
*/

void C_binarySearchTree::p_deleteTree(B_NODE* node){
    if(NULL == node){
        return;
    } else {
        this->p_deleteTree(node->left);
        this->p_deleteTree(node->right);
        delete node;
    }
}
/*
int C_binarySearchTree::height(void){
    return this->p_height(this->root);
}

int C_binarySearchTree::p_height(B_NODE *node){
    if(NULL == node){
       return 0;
    } else {
        int lHeight = 0;
        int rHeight = 0;
        // move through the tree, store left and right height 
        lHeight = this->p_height(node->left);
        rHeight = this->p_height(node->right);

        // Return whichever node is the largest
        if(lHeight > rHeight) {
            return lHeight + 1;
        } else {
            return rHeight + 1;
        }
    }
}*/