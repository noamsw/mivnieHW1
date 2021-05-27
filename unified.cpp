#ifndef UNIFIED_H_
#define UNIFIED_H_

#include <iostream> 
#include <ctime>
#include <iomanip>
#include "library.h"
#include "assert.h"

template<typename T>
class AVLTree
{
public:
    class Node
    {
		public:
        //data, templated
        T data;
        Node *right_child;
        Node *left_child;
        Node *parent;
		//height from bottom of tree
        int height;

    	//default constructor
    	//Node();
		// Constructor initializing the data.
		Node(T t);
		//destructor
		//~Node(); not sure why this ruins things
		// Calculate the balance point.
		int getBalance();
		// Get the actual data.
		T getData();
		// Get the height.
		int getHeight();
		// Get the left subtree.
		Node *getLeftChild();
		// Get the node's parent.
		Node *getParent();
		// Get the right subtree.
		Node *getRightChild();
		// Remove the node's parent.
		void removeParent();
		// Set the left subtree.
		Node *setLeftChild(Node *newLeft);
		// Set the right subtree.
		Node *setRightChild(Node *newRight);
		// Set the node's height.
		int updateHeight();
		
    };
public:
	//a pointer to the root
  	Node *root;
 	//a pointer to the node with the lowest value
  	Node* lowest;
  	//a pointer to the node with the highest value
  	Node* highest;

  	//default constructor for empty tree
  	AVLTree();
  	//parametrized constructor with one value t 
  	AVLTree(T t);
  	//destructot
  	~AVLTree();
  	//get height
  	int getHeight();
  	//std::exception insert(const T& t);
  	bool insert(const T& t);
  	//returns lowest value
  	T getLowestValue();
  	//returns highest value
  	T getHighestValue();
	// return pointer to node with lowest value
	// T getLowest();
  	//returns pointer to node with highest value
  	AVLTree<T>::Node* getHighest();
  	//std::exception remove(const T& t);
  	bool remove(const T& t);
	// returns a pointer to highest node
  	void print();
	//turns sorted array of <T> elements to a Nodes Tree
	static AVLTree<T>::Node* arrToNodesTree(T arr[], int start, int end);
	//setting the node's height
	static int setNodesHeight(AVLTree<T>::Node* node);
	//setting the node's parent
	static void setNodesParent(AVLTree<T>::Node* node);
	//setting the linked-node's Highest node
	void setHighestNode(AVLTree<T>::Node* node);
	//setting the linked-node's Lowest node
	void setLowestNode(AVLTree<T>::Node* node);
	//setting the linked-node's Root	 
	void setNodesRoot(AVLTree<T>::Node* node);
	//turns sorted array of <T> elements to an AVLTree
	static AVLTree<T>* arrToAVLTree(T arr[], int start, int end);

public:
  	// Balance the tree
	void balanceAtNode(Node *n);
	// returns a pointe to node containing the data.
	// nullptr if not in tree
	Node *findNode(const T& t);
	// Rotate the subtree left.
	void rotateLeft(Node *n);
	// Rotate the subtree right.
	void rotateRight(Node *n);
	// Set the root.
	void setRoot(Node *n);
	void printSubtree(Node *subtree, int depth,int offset, bool first);
	int spacing(int offset);
};


// class used by the main types tree
// value of each model is determined
// by modelId only
class Model{
public:
    int type;
    int model;
    int grade=0;
    int numSold=0;

    Model();
    Model(int type, int model);
    Model(int type, int model, int grade, int numSold);
    Model(const Model& other) = default;
    void setModel(int type, int model);
    void complaint(int numMonths);
    Model& operator=(const Model& other) = default;
    bool operator==(const Model& other) const;
    bool operator>(const Model& other) const;
    bool operator<(const Model& other) const;
    bool operator==(const Model& other);
    bool operator>(const Model& other);
    bool operator<(const Model& other);
    friend std::ostream& operator<<(std::ostream& os, const Model& car);
};

// type used to in graded models tree
// value is determined by grades as well 
// as type and model
class GradedModel{
public:
    int type;
    int model;
    int grade=0;
    int numsold=0;

    GradedModel();
    GradedModel(int type, int model);
    GradedModel(int type, int model, int grade, int numSold);
    GradedModel(const GradedModel& other) = default;
    void setGradedModel(int type, int model,int grade, int numsold);
    void complaint(int numMonths);
    GradedModel& operator=(const GradedModel& other) = default;
    bool operator==(const GradedModel& other) const;
    bool operator>(const GradedModel& other) const;
    bool operator<(const GradedModel& other) const;
    bool operator==(const GradedModel& other);
    bool operator>(const GradedModel& other);
    bool operator<(const GradedModel& other);
    friend std::ostream& operator<<(std::ostream& os, const GradedModel& car);
};


class CarType
{
public:
    // tree of the models of type
    AVLTree<Model>* models;
    // type id
    int type;
    // a pointer to the best seller of type
    AVLTree<Model>::Node* best_seller;
public:
    // constructor
    // default constructor
    CarType();
    CarType(int type, int numOfModels);
    CarType(const CarType& cartype);
    ~CarType();
    // returns the model number of the best seller
    int getBestSeller() const;
    // returns a pointer to the best seller
    AVLTree<Model>::Node* getMostSold();
    // comparing method between to cartypes
    // detertmined by typeid
    bool operator<(const CarType& cartype) const;
    // instantiate operator=
    CarType& operator=(CarType& cartype);
    bool operator>(const CarType& cartype) const;
    bool operator==(const CarType& cartype) const;
    bool addModel(int model_num, int grade, int numSold);
    bool removeModel(int model_num);
    friend std::ostream& operator<<(std::ostream& os, const Model& car);
};


class MostSold{
public:
    int type;
    int model;
    int numsold=0;

    MostSold();
    MostSold(int type, int model, int numsold);
    MostSold(const MostSold& other) = default;
    MostSold& operator=(const MostSold& other) = default;
    void set(int type, int model, int numsold);
    bool operator==(const MostSold& other) const;
    bool operator>(const MostSold& other) const;
    bool operator<(const MostSold& other) const;
    bool operator==(const MostSold& other);
    bool operator>(const MostSold& other);
    bool operator<(const MostSold& other);
    friend std::ostream& operator<<(std::ostream& os, const MostSold& car);
};

class DSW
{
    public:
    // tree of trees, each node has a tree of models
    AVLTree<CarType>* typestree;
    // tree of trees, each node has a tree of models. 
    // contanins only models with a grade of zero
    AVLTree<CarType>* zerostree;
    // tree of models by grade
    AVLTree<GradedModel>* gradedmodels;
    // a tree with the systems best sellers
    // it is of type mostsold class
    // this contains type, model, numsold
    AVLTree<MostSold>* bestsellers;

    DSW();
    ~DSW();
    // adds a car type to the system
    // throws relevent exceptions
    StatusType addCarType(int typeId, int numOfModels);
    // removes a car type from the system
    // throws relevent exceptions
    StatusType removeCarType(int typeId);
    // Sell a car of typeid, model id and updates system
    // throws relevent exceptions
    StatusType sellCar(int typeId, int modelId);
    // files a complaint against a model
    // throws relevent exceptions
    StatusType MakeComplaint(int typeID, int modelID, int t);
    // returns the best seller of typeID
    //if typeID=0, returns system's best seller
    StatusType GetBestSellerModelByType(int typeID, int * modelID);
    // returns system's m lowest graded models
    StatusType GetWorstModels(int numOfModels, int *types, int *models);
};


// paramterized Constructor.
template<typename T>
AVLTree<T>::Node::Node(T val) {
  data = val;
  height = 0;
  parent = nullptr;
  left_child = nullptr;
  right_child = nullptr;
}
// Calculate the balance factoP: left.height-r.height
template<typename T>
int AVLTree<T>::Node::getBalance() {
  // If we don't have a left subtree, check the right.
  int result;
  if (left_child == nullptr){
	// If neither subtree exists, return zero.
	if (right_child == nullptr){
		result = 0;
	}
	// Otherwise, the right subtree exists so make
	// it's height negative and subtract one.
	else{
		result = -right_child->height-1;
	}
  // Otherwise, we have a left subtree so if we
  // don't have a right one, return the left's
  // height plus one.	  
  }

  else{
	  	if (right_child == nullptr){
		  result = left_child->height+1;
		}
		// Otherwise, both subtrees exist so subtract
		// them to return the difference.
		else{
			result = left_child->height-right_child->height;	 
		} 
  } 
  return result;
}

// Get the actual data, consider making const
template <typename T>
T AVLTree<T>::Node::getData() {
  return data;
} 

// Get the height.
template<typename T>
int AVLTree<T>::Node::getHeight() {
  return height;
}

// Get the left subtree.
template<typename T>
typename AVLTree<T>::Node *AVLTree<T>::Node::getLeftChild() {
  return left_child;
}

// Get the right subtree.
template<typename T>
typename AVLTree<T>::Node *AVLTree<T>::Node::getRightChild() {
  return right_child;
}

// Get the node's parent.
template<typename T>
typename AVLTree<T>::Node *AVLTree<T>::Node::getParent() {
  return parent;
}

// Remove the node's parent.
template<typename T>
void AVLTree<T>::Node::removeParent() {
  parent = nullptr;
}

// Set the left subtree.
template<typename T>
typename AVLTree<T>::Node *AVLTree<T>::Node::setLeftChild(Node *newLeft)
 {
  // If there is a left node, set it's parent to
  // be us. In any event, make it our left subtree
  // and update the height.
  if (newLeft != nullptr){
	  newLeft->parent = this;
  }
  left_child = newLeft;
  updateHeight();
  return left_child;
}

// Set the right subtree.
template<typename T>
typename AVLTree<T>::Node *AVLTree<T>::Node::setRightChild(Node *newRight) {
  // If there is a right node, set it's parent to
  // be us. In any event, make it our right subtree
  // and update the height.
  if (newRight != nullptr){
	  newRight->parent = this;
  }
  right_child = newRight;
  updateHeight();
  return right_child;
}

// update the node's height.
template<typename T>
int AVLTree<T>::Node::updateHeight() {
  // If we don't have a left subtree, check the
  // right.
  if (left_child == nullptr){
	// If we don't have either subtree, the height
	// is zero.
	if (right_child == nullptr){
		height = 0;
	}
	// Otherwise, we only have the right subtree so
	// our height is one more than it's height.
	else{
		height = right_child->height+1;
	}	  
  }
  // Otherwise, the left subtree exists so if we
  // don't have a right one, our height is one
  // more than it's height.
  else {
	  if (right_child == nullptr)
	  height = left_child->height+1;
	// Otherwise, we have both subtree's so if the
	// left's height is greater than the right, our
	// height is one more than it.

  	else{
			if (left_child->height > right_child->height)
			height = left_child->height+1;
			// Otherwise, the right subtree's height will be
			// used so our height is one more than it.
			else
			height = right_child->height+1;		  
	 	}
  }
  return height;
}

//empty tree constructor, must decide how to instantiate
template<typename T>
AVLTree<T>::AVLTree() {
  root = nullptr;
  lowest = nullptr;
  highest = nullptr;
}

// Constructor to populate the tree with one node, not used in HW
template<typename T>
AVLTree<T>::AVLTree(T t) {
  root = new Node(t);
  lowest = root;
  highest = root;
}

//destructor, maybe should be from highest?
template<typename T>
AVLTree<T>::~AVLTree(){
	while(root!=nullptr)
	{
		remove(root->getData());
	}
}

// Balance the subtree. balancing the tree cannot change wich node is of highest or lowest value
//as such there is no need to update them
template<typename T>
void AVLTree<T>::balanceAtNode(Node *n) {

  // Get the current balance
  //determine which rotation is needed RR,LL,RL,LR
  int bal = n->getBalance();
  if (bal > 1) {
    //we are left heavy
    //determine if we are in LR case
	if (n->getLeftChild()->getBalance() < 0)
	  rotateLeft(n->getLeftChild());
	rotateRight(n);
    } 
  // Otherwise, we are right heavy
  // determine if we need RL or RR
  else if (bal < -1) {
	if (n->getRightChild()->getBalance() > 0)
	  rotateRight(n->getRightChild());
	rotateLeft(n);
  }
}

// Find the node containing the data.
template<typename T>
typename AVLTree<T>::Node *AVLTree<T>::findNode(const T& data) {
  // While nodes remain, if we found the right
  // node, exit the loop. If the value we want
  // is less than the current, check the left
  // subtree, otherwise, the right.
  Node *temp = root;
  while (temp != nullptr) {
	if (data == temp->getData())
	  break;
	else{
		if (data < temp->getData())
	  		temp = temp->getLeftChild();
		else
	  		temp = temp->getRightChild();
	}
  }
  return temp;
}

// Get the tree's height.
template <typename T>
int AVLTree<T>::getHeight() {
  return root->getHeight();
}


// Insert the value into the tree.
template <typename T>
bool AVLTree<T>::insert(const T& t) {
  // If the tree is empty, add the new node as the root.
  if (root == nullptr){
	 root = new Node(t);
	 lowest = root;
	 highest = root; 
  }
  // Otherwise, we need to find the insertion point.
  else {
	// Starting at the tree root search for the
	// insertion point, until we have added the new node.
	Node *added_node = nullptr;
	Node *temp = root;
	while (temp != nullptr && added_node == nullptr) {
	  // If the value is less than the current
	  // node's value, go left. If there isn't a
	  // left subtree, insert the node, otherwise,
	  // it is next to check.
	  if (t < temp->getData()) {
		if (temp->getLeftChild() == nullptr) {
		  added_node = temp->setLeftChild(new Node(t));
		  if(lowest!=nullptr){
			if(t < lowest->getData())
		  		lowest = added_node;
		  }
		  else lowest = added_node;
		}
    	else
		  temp = temp->getLeftChild();
		}
	  // Otherwise, if the value is greater than
	  // the current node's value, go right. If
	  // there isn't a right subtree, insert the
	  // node, otherwise, it is next to check.
	  else if (t > temp->getData()) {
		if (temp->getRightChild() == nullptr) {
		  added_node = temp->setRightChild(new Node(t));
      // if we are the furthest right node
      // we are the largest valued node
		  if(highest != nullptr){
			  if(t > highest->getData())
			  	highest = added_node;
		  }
		  else highest = added_node;
		} 
    	else
		  temp = temp->getRightChild();
		}
		// Otherwise, the value is already in the
		// tree so abort.
    	else
		//should update to Std::exception
			return false;
	}
	// From the new node upwards to the root,
	// updated the height and make sure the
	// subtree is balanced.
	temp = added_node;
	while(temp != nullptr) {
	  temp->updateHeight();
	  balanceAtNode(temp);
	  temp = temp->getParent();
	} 
  }
  return true;
}

// Remove the value from the tree.
template <typename T>
bool AVLTree<T>::remove(const T& t) {
	// Find the node to delete and if none, exit.
	Node *toBeRemoved = findNode(t);
	if (toBeRemoved == nullptr){
		//should be std::exception
		return false;
	}
	// Get the parent and set the side the node is
	// on of the parent.
	enum {left, right} side;
	Node *p = toBeRemoved->getParent();
	//enum is right also if the node is a root
	if (p != nullptr && p->getLeftChild() == toBeRemoved)
		side = left;
	else
		side = right;
	// If the node to be removed doesn't have a left
	// subtree, check it's right subtree to figure
	// out our next move.
	if (toBeRemoved->getLeftChild() == nullptr){
			// If we don't have any subtrees, we are the
			// leaf so our parent doesn't need us.
			if (toBeRemoved->getRightChild() == nullptr) {
				// If we don't have a parent, the tree is now
				// empty so change the root to null and delete
				// our node.
				if (p == nullptr) {
					setRoot(nullptr);
					delete toBeRemoved;
          toBeRemoved = nullptr;
					lowest = nullptr;
					highest = nullptr;
				}
				// Otherwise, change the parent so it doesn't
				// point to us, delete ourself, update the
				// parent's height, and rebalance the tree. 
				//if there is a node in the tree there is a lowest and highest value
				//in order to be the highest or lowest value we must be a leaf
				//check if we are the highest or lowest value
				//update as needed
				else {
					if (side == left){
						if(toBeRemoved->getData() == lowest->getData()){
							lowest = lowest->getParent();
						}
						p->setLeftChild(nullptr);
					}
					else{
						if(toBeRemoved->getData() == highest->getData()){
							highest = highest->getParent();
						}
						p->setRightChild(nullptr);
					} 
					delete toBeRemoved;
					p->updateHeight();
					balanceAtNode(p);
				} 
			}
			// Otherwise, there is a right subtree so use
			// it to replace ourself.
			else {
				// If we don't have a parent, the tree is now
				// the right subtree and delete our node.
				if (p == nullptr) {
					//deal with the case where the lowest value is the parent
					lowest = toBeRemoved->getRightChild();
					setRoot(toBeRemoved->getRightChild());
					delete toBeRemoved;
				}
				// Otherwise, change the parent so it doesn't
				// point to us, delete ourself, update the
				// parent's height, and rebalance the tree.
				else {
					if (side == left)
          {
            // in this case, the lowest node is now our right son
            if(lowest == toBeRemoved)
              lowest = toBeRemoved->getRightChild();
            p->setLeftChild(toBeRemoved->getRightChild());
          }
					else
						p->setRightChild(toBeRemoved->getRightChild());
					delete toBeRemoved;
					p->updateHeight();
					balanceAtNode(p);
			  } 
			} 
		}
  	// Otherwise, we have a left subtree so check the
	// right one of the node being removed to decide
	// what is next. If there isn't a right subtree,
	// the left one will replace ourself.
	else 
			if (toBeRemoved->getRightChild() ==nullptr) {
				// If we don't have a parent, the tree is now
				// the left subtree and delete our node.
				if (p == nullptr) {
					highest = toBeRemoved->getLeftChild();
					setRoot(toBeRemoved->getLeftChild());
					delete toBeRemoved;
				}
				// Otherwise, change the parent so it doesn't
				// point to us, delete ourself, update the
				// parent's height, and rebalance the tree.
				else {
					if(side == left)
          {
						p->setLeftChild(toBeRemoved->getLeftChild());
          }
					else
          {
            // in this case our left son is now the highest
            if(highest == toBeRemoved)
              highest = toBeRemoved->getLeftChild();
						p->setRightChild(toBeRemoved->getLeftChild());
          }
					p->updateHeight();
					balanceAtNode(p);
				}
			}
		// Otherwise, the node to remove has both subtrees
		// so decide the best method to remove it.
		else {
		// Check the balance to see which way to go.
		// If the left side is deeper, modify it.
		Node *replacement;
		Node *replacement_parent;
		Node *temp_node;
		int bal = toBeRemoved->getBalance();
		if (bal > 0) {
			// If the right subtree of the node's
			// left subtree is empty, we can move the
			// node's right subtree there.
			if (toBeRemoved->getLeftChild()->
				getRightChild() == nullptr) {
				replacement = toBeRemoved->getLeftChild();
				replacement->setRightChild(
					toBeRemoved->getRightChild());
				temp_node = replacement;

			// Otherwise, find the right most empty subtree
			// of our node's left subtree and it's
			// parent. This is our replacement. Make it's
			// parent point to it's left child instead
			// of itself. It is now free to replace the
			// deleted node. Copy both of the deleted
			// nodes subtrees into the replacement leaving
			// fixing up the parent below.
		}
		else {
			replacement = toBeRemoved->
				getLeftChild()->getRightChild();
			while (replacement->getRightChild() !=nullptr)
				replacement = replacement->getRightChild();
			replacement_parent = replacement->getParent();
			replacement_parent->setRightChild(replacement->getLeftChild());
			temp_node = replacement_parent;
			replacement->setLeftChild(toBeRemoved->getLeftChild());
			replacement->setRightChild(toBeRemoved->getRightChild());
		}
		// Otherwise, we are going to modify the right
		// side so, if the left subtree of the node's
		// right subtree is empty, we can move the
		// node's left subtree there.
		} 
		else if (toBeRemoved->getRightChild()->getLeftChild() == nullptr) {
			replacement = toBeRemoved->getRightChild();
			replacement->setLeftChild(toBeRemoved->getLeftChild());
			temp_node = replacement;
			// Otherwise, find the left most empty subtree
			// of our node's right subtree and it's
			// parent. This is our replacement. Make it's
			// parent point to it's right child instead
			// of itself. It is now free to replace the
			// deleted node. Copy both of the deleted
			// nodes subtrees into the replacement leaving
			// fixing up the parent below.
		} 
		else {
			replacement = toBeRemoved->getRightChild()->getLeftChild();
			while (replacement->getLeftChild() !=nullptr)
				replacement = replacement->getLeftChild();
			replacement_parent = replacement->getParent();
			replacement_parent->setLeftChild(replacement->getRightChild());
			temp_node = replacement_parent;
			replacement->setLeftChild(toBeRemoved->getLeftChild());
			replacement->setRightChild(toBeRemoved->getRightChild());
		}
		// Fix the parent to point to the new root.
		// If there isn't a parent, update the actual
		// tree root. Otherwise, there is a parent so
		// if we were the left subtree, update it,
		// otherwise, the right. In all cases, delete
		// the node and rebalance the tree.
		if (p == nullptr)
			setRoot(replacement);
		else if (side == left)
				p->setLeftChild(replacement);
			else
				p->setRightChild(replacement);
		delete toBeRemoved;
		balanceAtNode(temp_node);
	}
	return true;
}

// Rotate the subtree left.
template <typename T>
void AVLTree<T>::rotateLeft(Node *n) {
  // Get the node's parent and if it exists and the
  // node was it's left subtree, remember we are
  // processing the left, otherwise, the right.
  enum {left, right} side;
  Node *p = n->getParent();
  if (p != nullptr && p->getLeftChild() == n)
	side = left;
  else
	side = right;
  // Get the node's right subtree as the new root
  // and that subtree's left subtree. Make that
  // left subtree the node's new right. Put our
  // original node as the left subtree of our
  // new root.
  Node *temp = n->getRightChild();
  //setrightchild updates parent
  n->setRightChild(temp->getLeftChild());
  temp->setLeftChild(n);
  // Fix the original parent to point to the new
  // root. If there isn't a parent, update the
  // actual tree root. Otherwise, there is a
  // parent so if we were the left subtree, update
  // it, otherwise, the right.
  if (p == nullptr)
	setRoot(temp);
  else if (side == left)
		p->setLeftChild(temp);
  	else
		p->setRightChild(temp);
}

// Rotate the subtree right.
template <typename T>
void AVLTree<T>::rotateRight(Node *n) {
  // Get the node's parent and if it exists and the
  // node was it's left subtree, remember we are
  // processing the left, otherwise, the right.
  enum {left, right} side;
  Node *p = n->getParent();
  if (p != nullptr && p->getLeftChild() == n)
	side = left;
  else
	side = right;
  // Get the node's left subtree as the new root
  // and that subtree's right subtree. Make that
  // right subtree the node's new left. Put our
  // original node as the right subtree of our
  // new root.
  Node *temp = n->getLeftChild();
  n->setLeftChild(temp->getRightChild());
  temp->setRightChild(n);
  // Fix the original parent to point to the new
  // root. If there isn't a parent, update the
  // actual tree root. Otherwise, there is a
  // parent so if we were the left subtree, update
  // it, otherwise, the right.
  if (p == nullptr)
	setRoot(temp);
  else if (side == left)
		p->setLeftChild(temp);
  	else
		p->setRightChild(temp);
}

// Set the root. Change the tree root to the node
// and if it exists, remove it's parent.
template <typename T>
void AVLTree<T>::setRoot(Node *n) {
  root = n;
  if (root != nullptr)
	root->removeParent();
}



//return lowest value, can only be used on a non empty tree
template<typename T>
T AVLTree<T>::getLowestValue(){
	if(lowest!=nullptr)
		return lowest->getData();
}

//return highest value can only be used on a non empty tree
template<typename T>
T AVLTree<T>::getHighestValue(){
	if(highest!=nullptr)
		return highest->getData();
}

// returns a pointer to the node woth the highest value
template<typename T>
typename AVLTree<T>::Node* AVLTree<T>::getHighest(){
	return highest;
}

//print the tree
template <typename T>
void AVLTree<T>::print() {

  // If the tree is empty, say so.
  if (root == nullptr)
	std::cout << "Tree is empty!" <<std::endl;

  // Otherwise, if the tree has a height more than 4
  // (5 rows), it is too wide.
  else if (root->getHeight() > 4)
	std::cout << "Not currently supported!" <<std::endl;

  // Otherwise, set up to display the tree. Get
  // the maximum depth and for each possible
  // level, output that level's elements and
  // finish off the line.
  else {
	int max = root->getHeight();
	for (int depth = 0; depth <= max; depth++) {
	  printSubtree(root, depth, max-depth+1, true);
	  std::cout << std::endl;
	} // for
  } 
} // print

// --------------------------------------------------
// Print the subtree.  The leftmost branch will have
// first true. The level counts up from the bottom
// for the line we are doing. The depth is how
// many layers to skip over.
template <typename T>
void AVLTree<T>::printSubtree(Node *subtree, int depth,
	int level, bool first) {

  // If we need to go deeper in the subtree, do so.
  // If the subtree is empty, pass it down, otherwise
  // pass both left and right subtrees.
  if (depth > 0) {
	if (subtree == nullptr) {
	  printSubtree(subtree, depth-1, level, first);
	  printSubtree(subtree, depth-1, level, false);
	} else {
	  printSubtree(subtree->getLeftChild(), depth-1,
		  level, first);
	  printSubtree(subtree->getRightChild(), depth-1,
		  level, false);
	} // if

  // Otherwise, if the subtree is empty, display
  // an empty element. The leftmost element only
  // needs half the spacing.
  } else if (subtree == nullptr)
	std::cout << std::setw((first)?
		spacing(level)/2:spacing(level)) << "-";

  // Otherwise, we have a live element so display
  // it. Once more, use half spacing for the
  // leftmost element.
  else
	std::cout << std::setw((first)?
		spacing(level)/2:spacing(level)) <<
		subtree->getData();
} // printSubtree

// Figure out the default spacing for element. Each
// higher level doubles the preceeding. The bottom
// level is one.
template<typename T>
int AVLTree<T>::spacing(int level) {
  int result = 2;
  for (int i = 0; i < level; i++)
	result += result;
  return result;
}



template<typename T>
typename AVLTree<T>::Node* AVLTree<T>::arrToNodesTree(T arr[], int start, int end)
{
    // Base Case
    if (start > end) 
    return NULL; 

    // Get the middle element and make it root
    int mid = (start + end)/2; 
	Node* node = new Node(arr[mid]);

	//Recursively construct the left subtree and make it left child of root
	node->left_child = arrToNodesTree(arr, start, mid-1);

	// Recursively construct the right subtree and make it right child of root
	node->right_child = arrToNodesTree(arr, mid+1, end);

	return node;
} 


template<typename T>
int AVLTree<T>::setNodesHeight(AVLTree<T>::Node* node)
{
	//if the node has no child
	if (node->getLeftChild()==nullptr && node->getRightChild()==nullptr)
	{
		node->height=0;
		return 0;
	}

	//if the node has only Left child
	if (node->getRightChild()==nullptr)
	{
		node->height=1;
		node->getLeftChild()->height=0;
		return 1;
	}

	//if the node has only Right child
	if (node->getLeftChild()==nullptr)
	{
		node->height=1;
		node->getRightChild()->height=0;
		return 1;
	}

	//if the node has both childs:
	if (node->getLeftChild()!=nullptr && node->getRightChild()!=nullptr)
	{
		node->height= 1+std::max(setNodesHeight(node->getLeftChild()), setNodesHeight(node->getRightChild()));
	}
	return node->height;
}

template<typename T>
void AVLTree<T>::setNodesParent(AVLTree<T>::Node* node)
{
	//if the node has no child
	if(node==nullptr || (node->getLeftChild()==nullptr && node->getRightChild()==nullptr))
	{
		return;
	}

	//if the node has a Left child
	if (node->getLeftChild() != nullptr)
	{
		node->getLeftChild()->parent= node;
		setNodesParent(node->getLeftChild());
	}

	//if the node has a Right child
	if (node->getRightChild() != nullptr)
	{
		node->getRightChild()->parent= node;
		setNodesParent(node->getRightChild());
	}	

	return;
}



//setting the linked-node's Highest node
template<typename T>
void AVLTree<T>::setHighestNode(AVLTree<T>::Node* node)
{
	while (node->getRightChild() != nullptr)
	{
		node = node->getRightChild();
	}
	this->highest= node;
	return;
}

//setting the linked-node's Lowest node
template<typename T>
void AVLTree<T>::setLowestNode(AVLTree<T>::Node* node)
{
	while (node->getLeftChild() != nullptr)
	{
		node = node->getLeftChild();
	}
	this->lowest= node;
	return;
}

//setting the linked-node's Root
template<typename T>	 
void AVLTree<T>::setNodesRoot(AVLTree<T>::Node* node)
{
	this->root=node;
	return;
}


//creates an AVLTree from sorted array
template<typename T>
AVLTree<T>* AVLTree<T>::arrToAVLTree(T arr[], int start, int end)
{ 
	//turns the sorted array to linked nodes
	typename AVLTree<T>::Node* node = AVLTree<T>::arrToNodesTree(arr, start, end);
	//seting the height of each node
	AVLTree<T>::setNodesHeight(node);
	//setting the parent of each node
	AVLTree<T>::setNodesParent(node);
	//initializing the AVLTree
	// perhaps should be encased in a trycatch block?
	AVLTree<T>* tree = new AVLTree<T>();
	//setting the root of the tree
	tree->setNodesRoot(node);
	//setting the highest node of the tree
	tree->setHighestNode(node);
	//setting the lowest node of the tree
	tree->setLowestNode(node);

	return tree;
}


//default constructor for model. all fields initialized to 0
Model::Model():type(0), model(0), grade(0), numSold(0){};

// constuctor for Model. grade is initialized to 0 
Model::Model(int type, int model):type(type),model(model){};

// parameterized constuctor for Model. 
Model::Model(int type, int model, int grade, int numSold):type(type),model(model), grade(grade), numSold(numSold){};

// updates grade when a model recieves a complaint
void Model::complaint(int numMonths)
{
    int lowered = 100/numMonths;
    grade = grade - lowered;
}

// comparing operator, returns true if equal
// cars are equal to one another if
// both type and model are equal const
bool Model::operator==(const Model& other) const
{
    if(type == other.type && model == other.model)
        return true;
    return false;
}

// comparing operator, returns true if equal
// cars are equal to one another if
// both type and model are equal
bool Model::operator==(const Model& other) 
{
    if(type == other.type && model == other.model)
        return true;
    return false;
}

// comparing operator, compares grades of cars
bool Model::operator<(const Model& other)
{
    // if the models have the same model and type
    // we should consider them equal
    if((*this) == other)
      return false;
    // if type is smaller than it is considered smaller
    if(type < other.type)
        return true;
    // if the type is equal, check that the model is smaller
    if(type == other.type)
        if(model < other.model)
            return true;
    // the type is either larger
    // or the types are equal but the model is larger
    // in all of these cases the car is a better model
    // return false
    return false; 
}
// comparing operator, compares grades of cars const
bool Model::operator<(const Model& other) const
{
    // if the models have the same model and type
    // we should consider them equal
    if((*this) == other)
      return false;
    // if type is smaller than it is considered smaller
    if(type < other.type)
        return true;
    // if the type is equal, check that the model is smaller
    if(type == other.type)
        if(model < other.model)
            return true;
    // the type is either larger
    // or the types are equal but the model is larger
    // in all of these cases the car is a better model
    // return false
    return false; 
}

// comparing operator, compares grades of cars
bool Model::operator>(const Model& other)
{
    // if the models have the same model and type
    // we should consider them equal
    if((*this) == other)
      return false;
    // check if the model is smaller
    // if not, it is larger as there are no two different models that are equal
    return !(*this < other);
}

// comparing operator, compares grades of cars const
bool Model::operator>(const Model& other) const
{
    // if the models have the same model and type
    // we should consider them equal
    if((*this) == other)
      return false;
    // check if the model is smaller
    // if not, it is larger as there are no two different models that are equal
    return !(*this < other);
}

void Model::setModel(int type, int model)
{
    (*this).type= type;
    (*this).model= model;
}

std::ostream& operator<<(std::ostream& os, const Model& car)
{
    os << car.type << "." << car.model << "." << car.grade;
    //os << car.model ;
    return os;
}


//default constructor for gradedmodel. all fields initialized to 0
GradedModel::GradedModel():type(0), model(0), grade(0), numsold(0){};

// constuctor for GradedModel. grade is initialized to 0 
GradedModel::GradedModel(int type, int model):type(type),model(model){};

// parameterized constuctor for GradedModel. 
GradedModel::GradedModel(int type, int model, int grade, int numSold):type(type),model(model), grade(grade), numsold(numSold){};

// updates grade when a model recieves a complaint
void GradedModel::complaint(int numMonths)
{
    int lowered = 100/numMonths;
    grade = grade - lowered;
}

// comparing operator, returns true if equal
// cars are equal to one another if
// both type and model are equal const
bool GradedModel::operator==(const GradedModel& other) const
{
    if(type == other.type && model == other.model)
        return true;
    return false;
}

// comparing operator, returns true if equal
// cars are equal to one another if
// both type and model are equal
bool GradedModel::operator==(const GradedModel& other) 
{
    if(type == other.type && model == other.model)
        return true;
    return false;
}

// comparing operator, compares grades of cars
bool GradedModel::operator<(const GradedModel& other)
{
    // if the models have the same model and type
    // we should consider them equal
    if((*this) == other)
      return false;
    // if the grade is smaller, return true
    if(grade < other.grade){
        return true;
    }
    // otherwise check if the grade is equal
    if(grade == other.grade)
    {
        // now, if the grade is equal, but the type is smaller
        // than it is still smaller, return true
        if(type < other.type)
            return true;
        // if the type is equal, check that the model is smaller
        if(type == other.type)
            if(model < other.model)
                return true;
    }
    // the grade is either smaller
    // or the grade is equal but the type is smaller
    // or the grade and type are equal but the model is smaller
    // in all of these cases the car is a better model
    // return false
    return false; 
}
// comparing operator, compares grades of cars const
bool GradedModel::operator<(const GradedModel& other) const
{
    // if the models have the same model and type
    // we should consider them equal
    if((*this) == other)
      return false;
    // if the grade is smaller, return true
    if(grade < other.grade){
        return true;
    }
    // otherwise check if the grade is equal
    if(grade == other.grade)
    {
        // now, if the grade is equal, but the type is smaller
        // than it is still smaller, return true
        if(type < other.type)
            return true;
        // if the type is equal, check that the model is smaller
        if(type == other.type)
            if(model < other.model)
                return true;
    }
    // the grade is either smaller
    // or the grade is equal but the type is smaller
    // or the grade and type are equal but the model is smaller
    // in all of these cases the car is a better model
    // return false
    return false; 
}

// comparing operator, compares grades of cars
bool GradedModel::operator>(const GradedModel& other)
{
    // if the models have the same model and type
    // we should consider them equal
    if((*this) == other)
      return false;
    // check if the model is smaller
    // if not, it is larger as there are no two different models that are equal
    return !(*this < other);
}

// comparing operator, compares grades of cars const
bool GradedModel::operator>(const GradedModel& other) const
{
    // if the models have the same model and type
    // we should consider them equal
    if((*this) == other)
      return false;
    // check if the model is smaller
    // if not, it is larger as there are no two different models that are equal
    return !(*this < other);
}

void GradedModel::setGradedModel(int type, int model, int grade, int numsold)
{
    (*this).type= type;
    (*this).model= model;
    (*this).grade= grade;
    (*this).numsold= numsold;

}

std::ostream& operator<<(std::ostream& os, const GradedModel& car)
{
    os << car.type << "." << car.model << "." << car.grade;
    //os << car.model ;
    return os;
}


// default constructor
CarType::CarType()
{
    models = nullptr;
    type = 0;
    best_seller = nullptr;
}

CarType::CarType(int type, int numOfModels):type(type)
{
    //initializing a sorted array for insert into AVLTree
    // had to use new as size is determined during runtime
    Model* modelsarr= new Model[numOfModels];
    for(int i=0; i<numOfModels; i++)
    {

        modelsarr[i].setModel(this->type, i);
    }
    
    //initializing the models AVLTree
    //AVLTree<Model>* modelstree = new AVLTree<Model>();
    this->models = new AVLTree<Model>;
    //turning the sorted array into AVLTree
    models = AVLTree<Model>::arrToAVLTree(modelsarr, 0, numOfModels-1); 

    // the model with the highest value at initialization
    // is defined to be the model with the lowest model number
    // which is defined as the best selling model at initialization
    best_seller = models->lowest;
    delete[] modelsarr;
}

// copy constructor
CarType::CarType(const CarType& cartype):type(cartype.type)
{
    models = cartype.models;
    best_seller = cartype.best_seller;
}

//destructor for CarType, must delete models
CarType::~CarType()
{
    //delete models;
}
// returns pointer to most sold model
AVLTree<Model>::Node* CarType::getMostSold()
{
    return best_seller;
}

// returns the model number of the best seller
int CarType::getBestSeller() const
{
    return best_seller->data.model;
}

// copy assignment operator
CarType& CarType::operator=(CarType& cartype)
{
    models = cartype.models;
    type = cartype.type;
    best_seller = cartype.best_seller;
    return *this;
}

//comparing operator, compares types by typeID
bool CarType::operator<(const CarType& cartype) const
{
    return this->type < cartype.type;
}

//comparing operator, compares types by typeID
bool CarType::operator>(const CarType& cartype) const
{
    return this->type > cartype.type;
}

//comparing operator, compares types by typeID
bool CarType::operator==(const CarType& cartype) const
{
    return this->type == cartype.type;
}

bool CarType::addModel(int model_num, int grade, int numSold)
{
    Model model_to_add= Model(this->type, model_num, grade, numSold);
    return(this->models->insert(model_to_add));
}

bool CarType::removeModel(int model_num)
{
    Model model_to_delete= Model(this->type, model_num);
    return(this->models->remove(model_to_delete));
}

std::ostream& operator<<(std::ostream& os, const CarType& car)
{
    os <<  "t:" << car.type ;
    return os;
}


//default constructor for model. all fields initialized to 0
MostSold::MostSold():type(0), model(0), numsold(0){};

// constuctor for Model. grade is initialized to 0 
MostSold::MostSold(int type, int model, int numsold):type(type),model(model),numsold(numsold){};

void MostSold::set(int type, int model, int numsold)
{
    this->type = type;
    this->model = model;
    this->numsold = numsold;
}

// comparing operator, returns true if equal
// cars are equal to one another if
// both type and model are equal const
bool MostSold::operator==(const MostSold& other) const
{
    if(type == other.type && model == other.model)
        return true;
    return false;
}

// comparing operator, returns true if equal
// cars are equal to one another if
// both type and model are equal
bool MostSold::operator==(const MostSold& other) 
{
    if(type == other.type && model == other.model)
        return true;
    return false;
}

// comparing operator, compares numsold of cars
bool MostSold::operator<(const MostSold& other)
{
    // if the numsold is smaller, return true
    if(numsold < other.numsold){
        return true;
    }
    // otherwise check if the numsold is equal
    if(numsold == other.numsold)
    {
        // now, if the grade is equal, but the type is bigger
        // than it is still smaller, return true
        if(type > other.type)
            return true;
        // if the type is equal, check that the model is bigger
        if(type == other.type)
            if(model > other.model)
                return true;
    }
    // the numsold is either larger
    // or the grade is equal but the type is smaller
    // or the grade and type are equal but the model is smaller
    // in all of these cases the car is a more sold model
    // return false
    return false; 
}
// comparing operator, compares grades of cars const
bool MostSold::operator<(const MostSold& other) const
{
    // if the numsold is smaller, return true
    if(numsold < other.numsold){
        return true;
    }
    // otherwise check if the numsold is equal
    if(numsold == other.numsold)
    {
        // now, if the grade is equal, but the type is bigger
        // than it is still smaller, return true
        if(type > other.type)
            return true;
        // if the type is equal, check that the model is bigger
        if(type == other.type)
            if(model > other.model)
                return true;
    }
    // the numsold is either larger
    // or the grade is equal but the type is smaller
    // or the grade and type are equal but the model is smaller
    // in all of these cases the car is a more sold model
    // return false
    return false; 
}

// comparing operator, compares grades of cars
bool MostSold::operator>(const MostSold& other)
{
    // check if the model is smaller
    // if not, it is larger as there are no two different models that are equal
    return !(*this < other);
}

// comparing operator, compares grades of cars const
bool MostSold::operator>(const MostSold& other) const
{
    // check if the model is smaller
    // if not, it is larger as there are no two different models that are equal
    return !(*this < other);
}


std::ostream& operator<<(std::ostream& os, const MostSold& car)
{
    os << car.type << "." << car.model << "." << car.numsold;
    //os << car.model ;
    return os;
}

// default constructer
// initializes all trees to empty trees
// bestseller to nullptr
DSW::DSW()
{
    typestree = new AVLTree<CarType>();
    zerostree = new AVLTree<CarType>();
    gradedmodels = new AVLTree<GradedModel>();
    bestsellers = new AVLTree<MostSold>();
}

// destructor
DSW::~DSW()
{
    // i think this should work
    delete typestree;
    delete zerostree;
    delete gradedmodels;
    delete bestsellers;
}


// adds a cartype to the system. 
// inserting it into the typetree, and zeroestree
StatusType DSW::addCarType(int typeId, int numOfModels)
{
  try
  {
    // check that the input is correct
    if( typeId<=0 || numOfModels<=0 )
        return INVALID_INPUT;
    
    // check if the cartype alredy exists in the system
    // if so return failure
    if(typestree->findNode(CarType(typeId, 1)))
    {
        return FAILURE;
    }
    CarType* to_insert = nullptr;
    try
    {
        to_insert = new CarType(typeId, numOfModels);
    }
    catch (std::exception& e)
    {
        return ALLOCATION_ERROR;
    }
    try
    {
        (typestree->insert(*to_insert));
    }
    catch(std::exception& e)
    {
        delete to_insert;
        return ALLOCATION_ERROR;
    }
    bestsellers->insert(MostSold(typeId,0,0));
    CarType* zeroes_insert = nullptr;
    try
    {
        zeroes_insert = new CarType(typeId, numOfModels);
    }
    // do i have to delete all the trees? 
    catch(std::exception& e)
    {
        // delete to_insert; this may cause mem err
        return ALLOCATION_ERROR;
    }
    // insert must also be wrapped in try catch
    // as there is a dynamic mem allocation here as well
    try
    {
        zerostree->insert(*zeroes_insert);
    }
    catch (std::exception& e)
    {
        // may want to check that we are not deleting something twice
        delete zeroes_insert;
        return ALLOCATION_ERROR;
    }
    return SUCCESS;
  }
  catch(std::exception& e)
  {
    return ALLOCATION_ERROR;
  }
}

// removes a car type from the system
StatusType DSW::removeCarType(int typeId)
{
  try
  {
    // check validity of input
    if(typeId <= 0)
        return INVALID_INPUT;
    CarType to_remove(typeId , 1);
    if(!zerostree->remove(to_remove))
    {
        // if this is false, the type was not in the tree
        return FAILURE;
    }
    // if we are here then the car was in the tree
    AVLTree<CarType>::Node* type_to_remove = typestree->findNode(to_remove);
    assert(type_to_remove != nullptr);
    // remove from the bestsellers tree
    // in order to do so we will find the relevent information
    // from the typestree node
    int grade = type_to_remove->data.best_seller->data.numSold;
    int model = type_to_remove->data.best_seller->data.model;
    // remove from the bestsellers tree
    bestsellers->remove(MostSold(typeId, model, grade));
    // best seller will be updated automatically as highest node 
    // of the tree
    while(type_to_remove->data.models->root != nullptr)
    {
        // remove the model from gradedmodels
        // no need to check whats actually there
        int model = type_to_remove->data.models->root->data.model;
        int grade = type_to_remove->data.models->root->data.grade;
        int numsold = type_to_remove->data.models->root->data.numSold;
        gradedmodels->remove(GradedModel(typeId, model, grade, numsold));
        // remove the model from the typestree tree node
        type_to_remove->data.models->remove(type_to_remove->data.models->root->data);
    }
    typestree->remove(to_remove);
    return SUCCESS;
  }
  catch(std::exception& e)
  {
    return ALLOCATION_ERROR;
  }
}

// Sell a car of typeid, model id and updates system
// throws relevent exceptions
StatusType DSW::sellCar(int typeId, int modelId)
{
    try
    {
    // check arguments
    if(typeId <= 0 || modelId <0)
        return INVALID_INPUT;
    CarType finder(typeId , 1);
    // check that the type was in the tree
    AVLTree<CarType>::Node* tree_of_models_to_update = typestree->findNode(finder);
    if(!tree_of_models_to_update)
        return FAILURE;
    // check that the model was in the tree
    AVLTree<Model>::Node* model_to_update 
        = tree_of_models_to_update->data.models->findNode(Model(typeId,modelId));
    if(!model_to_update)
        return FAILURE;
    // create an updated model to insert
    int grade = model_to_update->data.grade + 10;
    int sold = model_to_update->data.numSold+1;
    Model model_to_insert = Model(typeId, modelId, grade, sold);
    // remove and then insert the updated model
    tree_of_models_to_update->data.models->remove(Model(typeId,modelId));
    try
    {
        tree_of_models_to_update->data.models->insert(model_to_insert);
    }
    catch (std::exception& e)
    {
        // need to decide what to do if a bad allocation happens
        throw ALLOCATION_ERROR;
    }
    // check if this is now the best seller
    // if its a null pointer it was and remains best seller
    if(tree_of_models_to_update->data.best_seller == nullptr)
    {
        //update the bestsellers tree
        bestsellers->remove(MostSold(typeId,modelId,sold-1));
        bestsellers-> insert(MostSold(typeId,modelId,sold));
        //update the best seller in the tree of models
        tree_of_models_to_update->data.best_seller 
            = tree_of_models_to_update->data.models->findNode(model_to_insert);
    }    
    // if it was not a null pointer than check
    // if the current model has now sold more models
    else
    {
        if(tree_of_models_to_update->data.best_seller->data.numSold < sold)
        {
            // update the bestsellers tree
            int model = tree_of_models_to_update->data.best_seller->data.model;
            int old_sold = tree_of_models_to_update->data.best_seller->data.numSold;
            bestsellers->remove(MostSold(typeId,model,old_sold));
            bestsellers-> insert(MostSold(typeId,modelId,sold));
            // update the tree of models best seller
            tree_of_models_to_update->data.best_seller 
            = tree_of_models_to_update->data.models->findNode(model_to_insert);

        } 
        // final case - equal
        else if(tree_of_models_to_update->data.best_seller->data.numSold == sold)
        {
            
            if(tree_of_models_to_update->data.best_seller->data.model >= modelId)
            {
                // update the bestsellers tree
                int model = tree_of_models_to_update->data.best_seller->data.model;
                int old_sold = tree_of_models_to_update->data.best_seller->data.numSold;
                bestsellers->remove(MostSold(typeId,model,old_sold));
                bestsellers-> insert(MostSold(typeId,modelId,sold));
                // update the tree of models best seller
                tree_of_models_to_update->data.best_seller 
                = tree_of_models_to_update->data.models->findNode(model_to_insert);
            }
        }
           
    } 

    // check if the grade is now 0
    // if it was it was in the graded tree and not in zeros tree
    // remove from the graded models tree
    // enter into zeroes tree
    if(grade == 0)
    {
        // insert into zerostree
        // first check if the zeros tree contains our type
        // if not we must reinsert it
        if(!zerostree->findNode(finder))
        {
          // create a cartype
          // remove the default model inside
          // insert the wanted model
          // this must be in a try
          try
          {
            CarType* to_insert = new CarType(typeId,1);
            to_insert->models->remove(Model(typeId,0));
            to_insert->models->insert(Model(typeId,modelId,0,sold));
            try
            {
              zerostree->insert(*to_insert);         
            }
            catch(const std::exception& e)
            {
              delete to_insert;
            }
            
          }   
          catch (std::exception& e)
          {
              return ALLOCATION_ERROR;
          }
        }
        zerostree->findNode(finder)->data.models->insert(model_to_insert);
        // remove from gradedmodels
        // using the old grade
        // and the oldnumsold
        int old_grade = grade - 10;
        int old_numsold = sold - 1;
        gradedmodels->remove(GradedModel(typeId,modelId,old_grade,old_numsold));
    }
    else
    {
        // if the grade was 0
        // remove from zeros tree
        // insert into graded models
        if(grade == 10)
        {
            // remove from zerostree
            assert(zerostree->findNode(finder));
            AVLTree<CarType>::Node* zeros_tree_of_type = zerostree->findNode(finder);
            zeros_tree_of_type->data.models->remove(Model(typeId,modelId));
            // check if this zeros tree of type typeid is empty
            // if so remove from zeros tree
            if(zeros_tree_of_type->data.models->root == nullptr)
            { 
              zerostree->remove(zeros_tree_of_type->data);
            }
            // insert into graded models
            // using the current grade
            // and current numsold
            try
            {

                gradedmodels->insert(GradedModel(typeId, modelId, grade, sold));
            }
            catch (std::exception& e)
            {
                throw ALLOCATION_ERROR;
            }            
        }
        // else simply update graded models
        else
        {
            try
            {
                // remove using the old grade and numsold
                int old_grade = grade - 10;
                int old_numsold = sold - 1;
                gradedmodels->remove(GradedModel(typeId, modelId, old_grade, old_numsold));
                // update with new
                gradedmodels->insert(GradedModel(typeId, modelId, grade, sold));
            }
            catch (std::exception& e)
            {
                throw ALLOCATION_ERROR;
            }
        }      
    } 
    return SUCCESS;   
    }
  catch(std::exception& e)
  {
    return ALLOCATION_ERROR;
  }
}

StatusType DSW::MakeComplaint(int typeID, int modelID, int t)
{
    try
    {
    // checking input (in wraped fuction, check if DS==NULL)
    if (typeID <= 0 || modelID < 0 || t==0)
    {
        return INVALID_INPUT;
    }
    
    // create a cartype with the typeID
    CarType find_ct(typeID , 1);

    // finding the type at the typestree
    AVLTree<CarType>::Node* ct_to_complaint = typestree->findNode(find_ct);
    if (ct_to_complaint==nullptr) // if the cartype is not in the typestree
    {
        return FAILURE;
    }

    Model find_m = Model(typeID, modelID);
    // finding the model at the type's models tree
    AVLTree<Model>::Node* m_to_complaint = ct_to_complaint->data.models->findNode(find_m);
    if (m_to_complaint==nullptr) // if the model doesnt exist
    {
        return FAILURE;
    }

    // update model's grade in the typestree
    int original_grade = m_to_complaint->data.grade;
    int complaint_grade = 100 / t;
    int new_grade = original_grade - complaint_grade;
    int numsold = m_to_complaint->data.numSold;
    m_to_complaint->data.grade = new_grade;

    // initialize the model we want to insert to models tree
    // Model model_to_add= Model(typeID, modelID, new_grade , m_to_complaint->data.numSold);

    // check if the type is in the zerostree
    // if the original grade was 0
    // then the model was in the zeros tree
    // find in the zeros tree and remove.
    // insert into gradedmodels tree
    if(original_grade == 0)
    {
      AVLTree<CarType>::Node* ct_node_zeros= zerostree->findNode(find_ct);
      // find the model in the ct_node_zeros
      // AVLTree<Model>::Node* m_node_zeros = ct_node_zeros->data.models->findNode(find_m);
      // remove the model from the zeros tree
      ct_node_zeros->data.removeModel(modelID);
      // check if this zeros tree of type typeid is empty
      // if so remove from zeros tree
      if(ct_node_zeros->data.models->root == nullptr)
      { 
        zerostree->remove(ct_node_zeros->data);
      }

      // insert the model to the grade tree
      // using the current grade and numsold
      gradedmodels->insert(GradedModel(typeID, modelID, new_grade, numsold));
      return SUCCESS;
    }

    // if the model isnt in the zeros, it must be in the grademodels
    // check if the grade has now returned to zero
    // if so we must remove it from the gradedmodels
    // and insert into the zerostree
    if(new_grade == 0)
    {
      // find the type in the zerostree 
      AVLTree<CarType>::Node* ct_node_zeros= zerostree->findNode(find_ct);
      if(!ct_node_zeros)
      {
        // create a cartype
        // remove the default model inside
        // insert the wanted model
        try
        {
          CarType* to_insert = new CarType(typeID,1);
          to_insert->models->remove(Model(typeID,0));
          try
          {
            to_insert->models->insert(Model(typeID, modelID, 0, numsold));
          }
          catch(const std::exception& e)
          {
            delete to_insert;
          }
          zerostree->insert(*to_insert);
        }
        catch(const std::exception& e)
        {
          return ALLOCATION_ERROR;
        }
        // remove from the gradedmodels tree
        // using the old grade
        gradedmodels->remove(GradedModel(typeID, modelID, original_grade, numsold));
        return SUCCESS;
      }
      if (ct_node_zeros != nullptr)
      {
        // insert the model into the zeros tree
        ct_node_zeros->data.models->insert(Model(typeID, modelID, 0, numsold));
        // remove from the gradedmodels tree
        // using the old grade
        gradedmodels->remove(GradedModel(typeID, modelID, original_grade, numsold));
        return SUCCESS;
      }        
    }
    // find the model in the gradesmodel 
    // the only case left is the grade was not zero before
    // and is not 0 now
    //remove the previous grade
    gradedmodels->remove(GradedModel(typeID, modelID, original_grade, numsold));
    // reinsert using the new grade
    gradedmodels->insert(GradedModel(typeID, modelID, new_grade, numsold));
    return SUCCESS;
    }
  catch(std::exception& e)
  {
    return ALLOCATION_ERROR;
  }
}

StatusType DSW::GetBestSellerModelByType(int typeID, int * modelID)
{
  try
  {
    //checking input
    //if typeID==0 && DS is empty, we should throe FAILURE
    if (typeID<0)
    {
        return INVALID_INPUT;
    }

    //if typeID=0, we should return system's best seller
    if (typeID==0)
    {
        // we must check if highest is a null pointer
        if(bestsellers->getHighest() != nullptr)
        {
          *modelID = bestsellers->getHighest()->data.model;
          return SUCCESS;
        }
        else
          return FAILURE;
    }

    //check if typeID is in the system
    CarType ct_find(typeID, 1);
    AVLTree<CarType>::Node* ct_node = typestree->findNode(ct_find);
    if (ct_node==nullptr)
    {
        //the typeID is not in the system
        return FAILURE;
    }

    //the typeId is in the system
    *modelID = ct_node->data.getBestSeller();
    return SUCCESS;
  }
  catch(std::exception& e)
  {
    return ALLOCATION_ERROR;
  }
}


// functions for getWorstModels
// used to insert a Models info into arrays
// updates the index
void insertModelToArr(int* t_arr, int* m_arr, int* index, AVLTree<Model>::Node* model_node, int numOfModels)
{
  if (*index == numOfModels)
    return;
	t_arr[*index]=model_node->data.type;
	m_arr[*index]=model_node->data.model;
	(*index)+=1;
}

// a function used to insert a gradedmodels info
// in the relevent index in the arrays
// updates the index
void insertGradedModelToArr(int* t_arr, int* m_arr, int* index, AVLTree<GradedModel>::Node* model_node, int numOfModels)
{
  if (*index == numOfModels)
    return;
	t_arr[*index]=model_node->data.type;
	m_arr[*index]=model_node->data.model;
	(*index)+=1;
}


// recursive call used by inorderlowestneg
// on the right subtree 
// inserts the tree Inorder into the arrs
void inorderNegativeModel(int* t_arr, int* m_arr, int* index, AVLTree<GradedModel>::Node* model_node,
											 int numOfModels, AVLTree<GradedModel>::Node** ptr_first_positive_node)
{
	// stop-conditions 
	if(model_node == nullptr || (*index == numOfModels))
	{
		return;
	}

	// recursive call, first start with the left childs (lower values)
	inorderNegativeModel(t_arr, m_arr, index , model_node->getLeftChild(), numOfModels, ptr_first_positive_node);

	// push only the negative graded models to the arrays
	if (model_node->data.grade < 0)
	{
		insertGradedModelToArr(t_arr, m_arr, index, model_node, numOfModels);	
	}

	// if the grade is not negative, we want to exit the recurrsion and keep the first positive node
	if(model_node->data.grade > 0)
	{
    if(*ptr_first_positive_node == nullptr)
    {
      *(ptr_first_positive_node) = model_node;
    }
		return;
	}

	// recursive call for the right childs
	inorderNegativeModel(t_arr, m_arr, index, model_node->getRightChild(), numOfModels, ptr_first_positive_node);
}


// recursive function that enters the models with a negative grade
// into the provided arrays
// it updates the index which keeps count of num models inserted
// provides a pointer to the first positive graded model found
// in order to continue the recursion later
void inorderLowestNegativeModel(int* t_arr, int* m_arr, int* index, AVLTree<GradedModel>::Node* model_node,int numOfModels, AVLTree<GradedModel>::Node** ptr_first_positive_node)													 
{
	// stop-conditions
  // we have insereted requested amount of models
  // there are no more models
	if (model_node == nullptr || (*index == numOfModels))
	{
		return;
	}

	// we only want to insert negative nodes. 
	if (model_node->data.grade >= 0)
	{
		// return the first positive node
    if(*ptr_first_positive_node == nullptr)
    {
      *(ptr_first_positive_node) = model_node;
    }
		return;
	}	

	// the node exist and its negative, add it to the arr 
	insertGradedModelToArr(t_arr, m_arr, index, model_node, numOfModels);

	// use inorder algorithm to check&insert the node's right sub-tree
	inorderNegativeModel(t_arr, m_arr, index, model_node->getRightChild(), numOfModels, ptr_first_positive_node);

	// reccursive call to inorderLowestNegativeModel

  // after having inserted the current node,
  // then its right sub tree
  // it calls the function on the parent node
	inorderLowestNegativeModel(t_arr, m_arr, index, model_node->getParent(), numOfModels, ptr_first_positive_node);	
}

// recursive call used by inorderZerolowestmod
// on the right subtree 
// inserts the tree Inorder into the arrs
void inorderZeroModel(int* t_arr, int* m_arr, int* index, AVLTree<Model>::Node* model_node, int numOfModels)
{
	// stop-conditions 
	if(model_node == nullptr || (*index == numOfModels))
	{
		return;
	}

	// recursive call to the left childs
	inorderZeroModel(t_arr, m_arr, index , model_node->getLeftChild(), numOfModels);

	// insert node to the arrays
	insertModelToArr(t_arr, m_arr, index, model_node, numOfModels);	

	// recursive call to the right childs
	inorderZeroModel(t_arr, m_arr, index, model_node->getRightChild(), numOfModels);
}

// recursive function that enters the models with a grade of 0
// into the provided arrays
// it updates the index which keeps count of num models inserted
void inorderZeroLowestModel(int* t_arr, int* m_arr, int* index, AVLTree<Model>::Node* model_node, int numOfModels)
{
	// stop-conditions
	if (model_node == nullptr || (*index == numOfModels))
	{
		return;
	}

	// the node exist insert to the arr 
	insertModelToArr(t_arr, m_arr, index, model_node, numOfModels);

	// use inorder algorithm to check&insert the node's right sub-tree
	inorderZeroModel(t_arr, m_arr, index, model_node->getRightChild(), numOfModels);

	// reccursive call to inorderZeroLowestModel
  // after having inserted the current node,
  // then its right sub tree
  // it calls the function on the parent node
	inorderZeroLowestModel(t_arr, m_arr, index, model_node->getParent(), numOfModels);	
}

void inorderZerosCT(int* t_arr, int* m_arr, int* index, AVLTree<CarType>::Node* node, int numOfModels)
{
  //stop condition
  if (node==nullptr || *index == numOfModels)
  {
    return;
  }

  // reccursive call to the left child
  inorderZerosCT(t_arr, m_arr, index, node->getLeftChild(), numOfModels);

  // getting in to CarType's models
  inorderZeroModel(t_arr, m_arr, index, node->data.models->lowest, numOfModels);

  //recursive call to the right child
  inorderZerosCT(t_arr, m_arr, index, node->getRightChild(), numOfModels);
}

// in order to start inserting models
// we must first access correct node of zeros tree
void inorderZerosLowestCT(int* t_arr, int* m_arr, int* index, AVLTree<CarType>::Node* node, int numOfModels)
{
	// stop conditions:
	if(node == nullptr || (*index == numOfModels))
	{
		return;
	}	
  
  inorderZeroLowestModel(t_arr, m_arr, index, node->data.models->lowest, numOfModels);
  inorderZerosCT(t_arr, m_arr, index, node->getRightChild(), numOfModels);
  inorderZerosLowestCT(t_arr, m_arr, index, node->getParent(), numOfModels);
}

// recursive call used by inorderlowestPos
// on the right subtree 
// inserts the tree Inorder into the arr
void inorderPositiveModel(int* t_arr, int* m_arr, int* index, AVLTree<GradedModel>::Node* model_node, int numOfModels)
{
	// stop-conditions 
	if(model_node == nullptr || (*index == numOfModels))
	{
		return;
	}

	// recursive call, first start with the left childs (lower values)
	inorderPositiveModel(t_arr, m_arr, index , model_node->getLeftChild(), numOfModels);

	// insert graded model to the arrays
	insertGradedModelToArr(t_arr, m_arr, index, model_node, numOfModels);	

	// recursive call for the right childs
	inorderPositiveModel(t_arr, m_arr, index, model_node->getRightChild(), numOfModels);
}

// reccursive call to inorderLowestPositivemod
// after having inserted the current node,
// then its right sub tree
// it calls the function on the parent node
void inorderLowestPositiveModel(int* t_arr, int* m_arr, int* index, AVLTree<GradedModel>::Node* model_node, int numOfModels)
{
	// stop-conditions
	if (model_node == nullptr || (*index == numOfModels))
	{
		return;
	}

	// the node exist, and we havent filled the arrays, insert it 
	insertGradedModelToArr(t_arr, m_arr, index, model_node, numOfModels);

	// use inorder algorithm to check&insert the node's right sub-tree
	inorderPositiveModel(t_arr, m_arr, index, model_node->getRightChild(), numOfModels);

	// reccursive call to inorderLowestNegativeModel
  // after having inserted the current node,
  // then its right sub tree
  // it calls the function on the parent node
  AVLTree<GradedModel>::Node* first_positive_parent = model_node->parent;
  while (first_positive_parent!= nullptr && first_positive_parent->data.grade < 0)
  {
    first_positive_parent = first_positive_parent->parent;
  }
	inorderLowestPositiveModel(t_arr, m_arr, index, first_positive_parent, numOfModels);
}

// a function used to return the worst models by grade
// in order to do this we must traverse tree in a unique way
// right sub tree in order
// current node
// if we have not finished recursivly call funtions
// on parent node
StatusType DSW::GetWorstModels(int numOfModels, int *types, int *models)
{
  try
  {
  // checking the input
  if (numOfModels<=0)
  {
      return INVALID_INPUT;
  }

	// initializing int_ptr as an index to the arrays
	// model&type ID's are inserted in the arr[index]
	//if(*index == numOfModels) we stop the iterration
  int i= 0;
  int* index = &i;

	// initializing a null GradedModel Node*
	// the node will keep the first positive graded model
	// first we insert the negative graded models
	// then we insert the zero graded models
	// and then we insert the positive graded models
	AVLTree<GradedModel>::Node* first_positive_node = nullptr; //should i use new?
  AVLTree<GradedModel>::Node** ptr_first_positive_node = &first_positive_node;

  inorderLowestNegativeModel(types, models , index, this->gradedmodels->lowest , numOfModels, ptr_first_positive_node);
  
  // if we filled the arrayes, finish
  if(*index == numOfModels)
  {
		//free first_positive_node
		//free index?
    return SUCCESS;
  } 
  
  // if we didnt fill the arrays, go to Zeros tree
  // there access the lowest node, which is a tree of models
  // insert said models as needed
  // if finished return
  // else go over zeros tree in the order needed
  inorderZerosLowestCT(types, models, index, zerostree->lowest, numOfModels);

  // if we filled the arrayes, finish
  if(*index == numOfModels)
  {
		//free first_positive_node
		//free index?
    return SUCCESS;
  } 


  //if we didnt fill the array, go to models positive grades
  inorderLowestPositiveModel(types, models, index, *ptr_first_positive_node, numOfModels);

  // if we didnt fill the array, there arnt enough nodes in the system. 
	if (*index < numOfModels)
	{
		//free first_positive_node
		//free index?
		//free the array?
		return FAILURE;
	}

	return SUCCESS;
  }
  catch(std::exception& e)
  {
    return ALLOCATION_ERROR;
  }
}

#endif

