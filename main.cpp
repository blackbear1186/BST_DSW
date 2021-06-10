#include "customErrorClass.h"
#include "bst.h"
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]){
    C_bst bst;

    ifstream myFile;

    int input;
    
    myFile.open("assign.dat");

    if(myFile.is_open()){
        while(!myFile.eof()){
            myFile >> input;
            bst.insertValue(input);
        }
    }
    cout << bst.findNode(4) << endl; 
    //bst.printTree();
    //bst.sortTree();
    myFile.close();

    return 0;
}