#include <fstream>
#include <math.h>
#include <iomanip>
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
void C_bst::createBalancedTree(){
   
        this->p_createBalancedTree();

}
/*
**    Author: Berlin Johnson
**    Function Purpose: 
**        
**    Function Output:
**    Side Effects: 
*/
void C_bst::createVine(){
        this->p_createVine();
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
    
}
/*
**    Author: Berlin Johnson
**    Function Purpose: 
**        
**    Function Output:
**    Side Effects: 
*/
void C_bst::formattedPrint(){
    if(this->root == NULL){
        return;
    } else {
        this->p_formattedPrint(this->root, this->nodeCount);
    }
}
/*
**    Author: Berlin Johnson
**    Function Purpose: 
**        
**    Function Output:
**    Side Effects: 
*/
int C_bst::height(void){
    return this->p_height(this->root);
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
        this->nodeCount++;

    }
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
/*
void C_bst::rotateLeft(B_NODE* parent){

}*/

/*
**    Author: Berlin Johnson
**    Function Purpose: 
**        
**    Function Output:
**    Side Effects: 
*/
/*void C_bst::rotateRight(B_NODE* parent){
    parent = this->root;
    if(parent != NULL){
        this->p_rotateRight(parent);
    }
}*/

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
void C_bst::p_createBalancedTree(){
    int n = this->nodeCount;
    if(n < 3){
        // the nunmber of nodes is less than 3 without balancing
        return;
    }
    int m = (1 << (int)log2(n + 1)) - 1;

    B_NODE* grandParent = NULL;
    B_NODE* parent = this->root;
    B_NODE* child = this->root->right;

    // the first stage: left-handed n - m times
    for(int i = 0; i < n - m; i++){
        this->p_rotateLeft(grandParent, parent, child);
        grandParent = child;
        parent = grandParent->right;

        if(NULL != parent){
            child = parent->right;
        } else {
            break;
        }
    }
   
   
    while (m > 1){ 
        B_NODE* grandParent = NULL;
        B_NODE* parent = this->root;
        B_NODE* child = this->root->right;
        m = m/2;
        this->root = this->root->right;
        for(int j = 0; j < m;++j){
                this->p_rotateLeft(grandParent, parent, child);
                grandParent = child;
                parent = grandParent->right;

                if(NULL != parent){
                    child = parent->right;
                }
            else {
                break;
            }
        }
    }
}
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

void C_bst::p_createVine(){
    B_NODE* grandParent = NULL;
    B_NODE* parent = this->root;
    B_NODE* child;

   /* while(NULL != parent){
        if(NULL != child){
            this->p_rotateRight(grandParent, parent, child);
            parent = child;
            
        } else {
            grandParent = parent;
            parent = parent->right;
        }
        // during the rotation process, if it rotated around the right node of the root, the root should be set 
        // to the right node of the original root node
        if(NULL == grandParent){
            this->root = child;
        }
    }*/
    while(NULL != parent){
        child = parent->left;
        if(NULL != child){
            this->p_rotateRight(grandParent, parent, child);
            parent = child;
        } else {
            grandParent = parent;
            parent = parent->right;
        }
        if(NULL == grandParent){
            this->root = child;
        }
    }
    
}
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


B_NODE* C_bst::p_findNode(B_NODE* node, int key){

    if(NULL == node){
        return NULL;
    } else if(node->value == key){
        return node;
    } else if(node->value < key){
        return this->p_findNode(node->right, key);
    } else {
        return this->p_findNode(node->left, key);
    }
}
/*
**    Author: Berlin Johnson
**    Function Purpose: 
**        
**    Function Output:
**    Side Effects: 
*/

void C_bst::p_formattedPrint(B_NODE* node, int indent){
    if( NULL == node ){
        return;
    } else {
        this->p_formattedPrint(node->left, indent+4);
        if( indent ){
            cout<<setw(indent)<<" ";
        }
        cout<<node->value<<endl;
        this->p_formattedPrint(node->right, indent+4);
    }
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
**    Author: Berlin Johnson
**    Function Purpose: 
**        
**    Function Output:
**    Side Effects: 
*/
void C_bst::p_rotateLeft(B_NODE* grandParent, B_NODE* parent, B_NODE* child){
    
    if(NULL != grandParent){
        grandParent->right = child;
    } else {
        root = child;
    }
    parent->right = child->left;
    child->left = parent;
}
/*
**    Author: Berlin Johnson
**    Function Purpose: 
**        
**    Function Output:
**    Side Effects: 
*/
void C_bst::p_rotateRight(B_NODE* grandParent, B_NODE* parent, B_NODE* child){
   
    if(NULL != grandParent){
        grandParent->right = child;
    } else {
        this->root = child;
    }
    parent->left = child->right;
    child->right = parent;
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

    /*for(int i = 0; i < this->nodeCount; ++i){
        cout << tempArr[i] << endl;
    }*/
    
}





