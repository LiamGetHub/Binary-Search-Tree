/*
Liam Fitting
CPSC 223
4/4/23
*/

#include "bst.h"

BST::BST(int val) {
  root = new Node(val);
  size++;
}

//-------------------------------------------------------------

//public funct
void BST::insert(int value) {
  root = insert(root, value);
  size++;
}

//private recursive function
Node* BST::insert(Node* node, int value) {
  if(node==nullptr) {
    return new Node(value);
  } 
  else {
    if(value < node->value) {
      node->leftChild = insert(node->leftChild, value);
    } 
    else {
      node->rightChild = insert(node->rightChild, value);
    }
  }
  return node;
}

//-------------------------------------------------------------

//helper to call recursive one
void BST::printInOrder(){
  if (root == nullptr) {
    std::cout << "tree is empty" << std::endl;
    return;
  }

  printInOrder(root);
}

//left root right
void BST::printInOrder(Node* node) {
  if(node == nullptr) {
    return;
  }
  printInOrder(node->leftChild);
  std::cout << node->value <<" ";
  printInOrder(node->rightChild);

}

//-------------------------------------------------------------

void BST::printPreOrder(){
  if (root == nullptr) {
    std::cout << "tree is empty" << std::endl;
    return;
  }

  printPreOrder(root);
}

void BST::printPreOrder(Node * node){
  if(node == nullptr){
    return;
  }

  std::cout << node->value <<" ";
  printPreOrder(node->leftChild);
  printPreOrder(node->rightChild);


}

//-------------------------------------------------------------

void BST::printPostOrder(){
  if (root == nullptr) {
    std::cout << "tree is empty" << std::endl;
    return;
  }

  printPostOrder(root);
}

void BST::printPostOrder(Node * node){
  if(node == nullptr){
    return;
  }

  printPostOrder(node->leftChild);
  printPostOrder(node->rightChild);
  std::cout << node->value <<" ";

}

//-------------------------------------------------------------

bool BST::find(int value) {
  //checking if tree is empty in this function because we dont want to repeadadly check it is the recursive portion.
  if (root == nullptr) {
    std::cout << "tree is empty" << std::endl;
    return false;
  }

  
  return find(root, value);
}

bool BST::find(Node * node, int value) {
  if (node == nullptr) {
    return false; //travered entire tree, not found anything, must check this before deciding to go down left or right path, otherwise you could acces null memory (segfualt).
  }
  else if (value < node->value) {
    return find(node->leftChild, value);
  }
  else if (value > node->value) {
    return find(node->rightChild, value);
  }
  else { // if not at end, value !> or !< then you found it, so reurn true.
    return true;
  } 
}


//-------------------------------------------------------------


void BST::remove(int value){
  remove(root, value);
}

Node * BST::remove(Node* node, int value) {
  return nullptr;
                                  //Atempt 2
  
/*
  
  //base case
  if (node == nullptr){
    size--;
    return node;
  }
  else if (value < node->value) {
    node->leftChild = remove(node->leftChild, value);
    return node;
  }
  else if (value > node->value) {
    node->rightChild = remove(node->rightChild, value);
    return node;
  }
  
  //found node 
  // if left child null
  else if (node->leftChild == nullptr) {
    Node * temp = root->rightChild;
    delete node;
    return temp;
  }
  //if right child null
  if (node->rightChild == nullptr){
    Node* temp = root->leftChild;
    delete node;
    return temp;
  }
    
  else { //found it

    Node * parentNode = node;
    Node * prevNode = node->rightChild;

    
    while (prevNode->leftChild != nullptr) {
      parentNode = prevNode;
      prevNode = prevNode->leftChild;
    }
    if (parentNode != node){
      parentNode->leftChild = prevNode->rightChild;
    }
    else {
      parentNode->rightChild = prevNode->rightChild;
    }
    node->value = prevNode->value;
    delete prevNode;
    return node;
  }
*/


                            //Attempt 1
  /*
    //case 1: one childrem
    if (node->leftChild != nullptr && node->rightChild == nullptr) {
      //only left child
      Node* tempLeft = node;
      node = node->leftChild;
      tempLeft->leftChild = node;
      return nullptr;
    }
    else if (node->leftChild == nullptr && node->rightChild != nullptr) {
        //only right child
      Node* tempLeft = node;
      node = node->leftChild;
      tempLeft->rightChild = node;
      return nullptr;
    }
    // case 2: two children
    else if (node->leftChild != nullptr && node->rightChild != nullptr) {
      node->value = findMin(node->rightChild);
      remove(node->rightChild, node->value);
    }
  }
  delete node;
  return nullptr;
  */
}



 
  


//-------------------------------------------------------------

int BST::findMax() {
    if (root == nullptr) {
      std::cout << "tree is empty" << std::endl;
      return 0;
    }


  return findMax(root);
}

int BST::findMax(Node * node) {

  while(node->rightChild != nullptr) {
    node = node->rightChild;
  }
  
  return node->value;
  
}

//-------------------------------------------------------------

int BST::findMin() {
    if (root == nullptr) {
      std::cout << "tree is empty" << std::endl;
      return 0;
    }


  return findMin(root);
}

int BST::findMin(Node * node) {

  while(node->leftChild != nullptr) {
    node = node->leftChild;
  }

  return node->value;

}

BST::BST(){
  root = nullptr;
}


int BST::getSize() {
  return size;
}
