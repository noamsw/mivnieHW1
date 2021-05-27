#ifndef CARDEALERSHIPMANAGER_H_
#define CARDEALERSHIPMANAGER_H_

#include "AVL.h"
#include "cartype.h"
#include "mostsold.h" 
#include "model.h"
#include "iostream"
#include "library.h"
#include "gradedmodels.h"

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

#endif 