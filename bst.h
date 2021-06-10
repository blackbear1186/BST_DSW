#ifndef __BST__H__
#define __BST__H__

#include <iostream>

using namespace std;

struct B_NODE {
        int value;
        B_NODE *left;
        B_NODE *right;
}; 

class C_bst{
    public:
        C_bst();
        ~C_bst();

        void insertValue(int);
        bool findNode(int);
        void printTree();
        void sortTree();
        int height();
        void createVine();
        void rotateRight(B_NODE*);
        void rotateLeft(B_NODE*);

    private:
        B_NODE *root;
        int nodeCount;

        B_NODE* p_createNode(int);
        void p_createTree(int*, int, int);
        B_NODE* p_insertValue(B_NODE*, B_NODE*);
        B_NODE* p_findNode(B_NODE*, int);
        void p_printTree(B_NODE*);
        void p_sortTree();
        void p_populateArray(B_NODE*, int*, int);
        int p_height(B_NODE*);
        void p_deleteTree(B_NODE*);

        B_NODE* p_createVine(B_NODE*);
        B_NODE* p_rotateRight(B_NODE*);
        B_NODE* p_rotateLeft(B_NODE*);
        
};

#endif