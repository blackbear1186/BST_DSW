#include <fstream>
#include <math.h>
#include "bst.h"
#include "customErrorClass.h"

using namespace std;

C_bst::C_bst(void){
    this->root = NULL;
    this->nodeCount = 0;
}

C_bst::~C_bst(void){
    this->p_deleteTree(this->root);
}

/*
**    Author: Berlin Johnson
**    Function Purpose: 
**        
**    Function Output:
**    Side Effects: 
*/

bool C_bst::findNode(int value){
    B_NODE* temp = this->p_findNode(this->root, value);

    if(temp == NULL){
        return false;
    } 
    return true;
    
   /* if(NULL == temp){
        return false;
    } else if(value == temp->value){
        this->p_findNode(this->root, temp);
    }
    return true;*/
    
}
/*
**    Author: Berlin Johnson
**    Function Purpose: 
**        
**    Function Output:
**    Side Effects: 
*/

void C_bst::insertValue(int value){
    B_NODE *node = this->p_createNode(value);

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

void C_bst::printTree(){
    if(NULL == this->root){
        return;
        //throw MyException("ERROR: The tree is empty.");
    } else {
        this->p_printTree(this->root);
    }
    
}
/*
**    Author: Berlin Johnson
**    Function Purpose: 
**        
**    Function Output:
**    Side Effects: 
*/
void C_bst::rotateLeft(B_NODE* parent){

}
/*
**    Author: Berlin Johnson
**    Function Purpose: 
**        
**    Function Output:
**    Side Effects: 
*/
void C_bst::rotateRight(B_NODE* parent){

}
/*
**    Author: Berlin Johnson
**    Function Purpose: 
**        
**    Function Output:
**    Side Effects: 
*/

void C_bst::sortTree(){
    this->p_sortTree();
}
/*
**    Author: Berlin Johnson
**    Function Purpose: 
**        
**    Function Output:
**    Side Effects: 
*/

B_NODE* C_bst::p_createNode(int value){
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
void C_bst::p_createTree(int *myArray, int start, int end){
    if(start > end){
        return;
    } else {
        int middle = floor((start + end) / 2);
        this->insertValue(myArray[middle]);
        this->p_createTree(myArray, start, middle - 1);
        this->p_createTree(myArray, middle + 1, end);
    }
}
/*
**    Author: Berlin Johnson
**    Function Purpose: 
**        
**    Function Output:
**    Side Effects: 
*/
/*
B_NODE* C_bst::p_createVine(B_NODE* root){
    if(NULL == root){
       // return NULL;
    } else {
        B_NODE* temp = root;
        while(temp != NULL){
            if(temp->right != NULL){
                this->p_rotateRight(temp);
            }
        }
    } 
      return temp;  
   
}*/
/*
**    Author: Berlin Johnson
**    Function Purpose: 
**        
**    Function Output:
**    Side Effects: 
*/

void C_bst::p_deleteTree(B_NODE* node){
    if(NULL == node){
        //throw MyException("ERROR: The tree is empty.");
    } else {
        this->p_deleteTree(node->left);
        this->p_deleteTree(node->right);
        delete node;
    }
}
/*
**    Author: Berlin Johnson
**    Function Purpose: 
**        
**    Function Output:
**    Side Effects: 
*/


B_NODE* C_bst::p_findNode(B_NODE* parent, int key){

    if(NULL == parent){
        return NULL;
    } else if(parent->value == key){
        return parent;
    } else if(parent->value < key){
        return this->p_findNode(parent->right, key);
    } else {
        return this->p_findNode(parent->left, key);
    }
}
/*
**    Author: Berlin Johnson
**    Function Purpose: 
**        
**    Function Output:
**    Side Effects: 
*/

B_NODE* C_bst::p_insertValue(B_NODE* parent, B_NODE* currentNode){

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
B_NODE* C_bst::p_rotateLeft(B_NODE* parent){
    B_NODE* temp = parent->right;
    parent->right = temp->left;
    temp->left = parent;
    return temp;
}
/*
**    Author: Berlin Johnson
**    Function Purpose: 
**        
**    Function Output:
**    Side Effects: 
*/
B_NODE* C_bst::p_rotateRight(B_NODE* parent){
 
    B_NODE* temp = parent->left;
    parent->left = temp->right;
    temp->right = parent;
    return temp;
}



/*
**    Author: Berlin Johnson
**    Function Purpose: 
**        
**    Function Output:
**    Side Effects: 
*/
void C_bst::p_sortTree(){
    int *tempArr = new int[this->nodeCount];
    
    this->p_populateArray(this->root, tempArr, 0);

    this->root = NULL;
    this->p_createTree(tempArr, 0, this->nodeCount - 1);

    for(int i = 0; i < this->nodeCount; ++i){
        cout << tempArr[i] << endl;
    }
    
}

/*
**    Author: Berlin Johnson
**    Function Purpose: 
**        
**    Function Output:
**    Side Effects: 
*/
void C_bst::p_populateArray(B_NODE* node, int *myArray, int index){
    if(NULL == node){
        return;
        //throw MyException("ERROR: The Array is empty.");
    } else {
        this->p_populateArray(node->left, myArray, index + 1);
        myArray[index] = node->value;
        this->p_populateArray(node->right, myArray, index + 1);
    }
}
/*
**    Author: Berlin Johnson
**    Function Purpose: 
**        
**    Function Output:
**    Side Effects: 
*/

void C_bst::p_printTree(B_NODE* node){
    if(NULL == node){
        return;
    } else {
        this->p_printTree(node->left);
        cout << node->value << endl;
        this->p_printTree(node->right);
    }
}




/*
int C_bst::height(void){
    return this->p_height(this->root);
}

int C_bst::p_height(B_NODE* node){
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