/*
Liam Fitting
CPSC 223
4/4/23
*/

#include<iostream>
#include "bst.h"
#include "node.h"
#include "tests.h"



int main(){
  
  testInsert();
  std::cout << std::endl;
  testInOrderTest();
  std::cout << std::endl;
  testCreateTree();
  std::cout << std::endl;
  testFind();
  std::cout << std::endl;
  testPreOrderTest();
  std::cout << std::endl;
  testPostOrderTest();
  std::cout << std::endl;
  testFindMax();
  std::cout << std::endl;
  testFindMin();
  std::cout << std::endl;
  testSize();
//testRemove();



  return 0;
}

void testInsert(){
  BST tree(10);
  tree.insert(12);

  if (tree.root != nullptr &&
    tree.root->rightChild != nullptr &&
    tree.root->value == 10 &&
    tree.root->rightChild->value == 12) {
    std::cout << "testInsert...PASS" << std::endl;
  }else {
    std::cout << "testInsert...FAIL" << std::endl;
  }
}

void testInOrderTest(){
  BST tree(10);
  tree.insert(8);
  tree.insert(12);

  std::cout << "Expected: 8 10 12" << std::endl;
  std::cout << "Actual: ";
  tree.printInOrder();
  std::cout << std::endl;
}

void testCreateTree(){

    //this will throw an error until you implement the EVC
    BST tree(17);

    if(tree.root->value == 17){
        std::cout << "testCreateTree...PASS" << std::endl;
    }else{
        std::cout << "testCreateTree...FAIL" << std::endl;
    }
}

void testPreOrderTest(){
  BST tree(10);
  tree.insert(8);
  tree.insert(12);

  std::cout << "Expected: 10 8 12" << std::endl;
  std::cout << "Actual: ";
  tree.printPreOrder();
  std::cout << std::endl;
}

void testPostOrderTest(){
  BST tree(10);
  tree.insert(8);
  tree.insert(12);

  std::cout << "Expected: 8 12 10" << std::endl;
  std::cout << "Actual: ";
  tree.printPostOrder();
  std::cout << std::endl;
}

void testFind(){
  BST tree(10);

  tree.insert(5);
  tree.insert(7);
  tree.insert(3);
  tree.insert(9);
  tree.insert(2);
  tree.insert(6);
  tree.insert(4);

//SEARCH ELEMENT NOT IN TREE
  bool found = tree.find(6);
  if (found == true){
    std::cout << "testFind...PASS" << std::endl;
  }
  else {
    std::cout << "testFind...FAIL" << std::endl;
  }
}


void testFindMax(){
  BST tree(10);
  tree.insert(8);
  tree.insert(12);  
  tree.insert(11);
  tree.insert(15);

  
  if(tree.findMax() == 15){
      std::cout << "testFindMax...PASS" << std::endl;
  }else{
      std::cout << "testFindMax...FAIL" << std::endl;
  }
  
}

void testFindMin(){
  BST tree(10);
  tree.insert(8);
  tree.insert(12);  
  tree.insert(11);
  tree.insert(15);
  tree.insert(5);
  tree.insert(2);

  if(tree.findMin() == 2){
      std::cout << "testFindMin...PASS" << std::endl;
  }else{
      std::cout << "testFindMin...FAIL" << std::endl;
  }

}


void testSize(){
  BST tree(10);
  tree.insert(8);
  tree.insert(12);  
  tree.insert(11);
  tree.insert(15);
  tree.insert(5);
  tree.insert(2);
  
  if(tree.getSize() == 7){
      std::cout << "testSize...PASS" << std::endl;
  }else{
      std::cout << "testSize...FAIL" << std::endl;
  }
 
 

}
