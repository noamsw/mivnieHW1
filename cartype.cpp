#include "cartype.h"
#include "iostream"

CarType::CarType(int type, int numOfModels):type(type)
{
    models = new AVLTree<Model>();
    //initializing a sorted array for insert into AVLTree
    int modelsarr[numOfModels];
    for(int i=0; i<numOfModels; i++)
    {
        modelsarr[i]=i;
    }
    if(!arrToTree(modelsarr, 0, numOfModels-1))
    {
        delete models;
        // throw exception??
    }
    // the model with the highest value at initialization
    // is defined to be the model with the lowest model number
    // which is defined as the best selling model at initialization
    mostSold=models->highest;
}

//destructor for CarType, must delete models
CarType::~CarType()
{
    delete models;
}


/*
bool CarType::sellModel(int model)
{
    Node* model_to_be_sold = models->findNode(Model(this->type, model));
    Node* new_node= Model(this->type, model_to_be_sold->)
    models->remove(Node*);
}
*/

/*
// here we have two options,
// 1. make cartype inherit from AVLTree
// 2. make a method that returns a pointer to a node
// which can than be used to update the data of model
// right now im am implenting in the 2. way

bool CarType::sellModel(int model)
{
    // find the node which contains the model
    Node* sold = models->findNode(Model(type,model));
    if(sold != nullptr)
    {
        sold->data->sold();
        //check if we must update mostSold
        if(sold->data->numSold > mostSold->data->numSold)
            mostSold=sold;
        return true
    }
    return false;
}
*/


//comparing operator, compares types by typeID
bool CarType::operator<(const CarType& cartype)
{
    return this->type < cartype.type;
}

//comparing operator, compares types by typeID
bool CarType::operator>(const CarType& cartype)
{
    return this->type > cartype.type;
}

//comparing operator, compares types by typeID
bool CarType::operator==(const CarType& cartype)
{
    return this->type == cartype.type;
}



Node* CarType::arrToTree(int arr[], int start, int end)
{ 
    // Base Case
    if (start > end) 
    return;
  
    /* Get the middle element and make it root */
    int mid = (start + end)/2; 
    Node root = Model(type, arr[mid]); 
  
    // Recursively construct the left subtree and make it left child of root

    root->left = sortedArrayToBST(arr, start, mid - 1); 
  
    // Recursively construct the right subtree and make it right child of root
    root->right = sortedArrayToBST(arr, mid + 1, end); 
  
    return root; 
}