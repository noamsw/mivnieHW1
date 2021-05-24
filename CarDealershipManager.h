#ifndef CARDEALERSHIPMANAGER_H_
#define CARDEALERSHIPMANAGER_H_

#include "AVL.h"
#include "cartype.h"
#include "model.h" 
#include "iostream"

class DSW
{
    // tree of trees, each node a tree of models
    AVLTree<CarType>* typestree;
    // tree of trees, each node a tree of models. 
    // contaning only models with a grade of zero
    AVLTree<CarType>* zerostree;
    // tree of models by grade
    AVLTree<Model>* gradedmodels;
    // a pointer to the systems best selling model
    AVLTree<Model>::Node* bestseller;

    public:
    DSW();
    ~DSW();
    // adds a car type to the system
    // throws relevent exceptions
    void addCarType(int typeId, int numOfModels);
    // removes a car type from the system
    // throws relevent exceptions
    void removeCarType(int typedId);
    // Sell a car of typeid, model id and updates system
    // throws relevent exceptions
    void sellCarr(int typeId, int modelId);
    // files a complaint against a model
    // throws relevent exceptions
    void makeComplaint(int typeId, int numOfMonths);
    void getBestSellerModelByType(int typeId, int* modelId);
    void getWorstModels(int numOfModels, int* types, int* models);
};

#endif 