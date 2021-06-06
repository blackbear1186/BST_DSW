#include "customErrorClass.h"
#include "binarySearchTree.h"
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]){
    C_binarySearchTree bst;

    ifstream myFile;

    int input;
    
    myFile.open("assign.dat");

    if(myFile.is_open()){
        while(!myFile.eof()){
            myFile >> input;
            bst.insertValue(input);
        }
    }
    bst.printTree();

    myFile.close();

    return 0;
}