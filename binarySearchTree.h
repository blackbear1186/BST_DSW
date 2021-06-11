#ifndef __BINARY_SEARCH_TREE__H__
#define __BINARY_SEARCH_TREE__H__

#include <iostream>

using namespace std;

struct B_NODE {
        int value;
        int key;
        B_NODE *left;
        B_NODE *right;
}; 

class C_binarySearchTree{

   
    
    public:
        C_binarySearchTree();
        ~C_binarySearchTree();

        B_NODE *createNode(int);
        void insertValue(int);
        void findNode();
        void printTree();
        void sortTree();
        int getHeight();

    private:
        B_NODE *head;
        B_NODE *root;
        int nodeCount;

        void p_createTree(int*, int, int);
        B_NODE* p_insertValue(B_NODE*, B_NODE*);
        void p_findNode(B_NODE*);
        void p_printTree(B_NODE*);
        void p_sortTree();
        void p_populateArray(B_NODE*, int*, int);
        void p_height(B_NODE*);
        void p_deleteTree(B_NODE*);
        void p_createVine();
        void p_rotateRight(B_NODE*,B_NODE*,B_NODE*);
        void p_rotateLeft(B_NODE*,B_NODE*,B_NODE*);
        void p_createTree();
        
};

#endif