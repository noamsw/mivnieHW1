#include "AVL.h"
#include "cartype.h"
#include "model.h" 
#include "iostream"
#include "CarDealershipManager.h"

// default constructer
// initializes all trees to empty trees
// bestseller to nullptr
DSW::DSW()
{
    typestree = new AVLTree<CarType>();
    zerostree = new AVLTree<CarType>();
    gradedmodels = new AVLTree<Model>();
    bestseller = nullptr;
}

// destructor
DSW::~DSW()
{
    delete typestree;
    delete zerostree;
    delete gradedmodels;
}

// adds a cartype to the system. 
// inserting it into the typetree, and zeroestree
StatusType DSW::addCarType(int typeId, int numOfModels)
{
    // check that the input is correct
    if( typeId<=0 || numOfModels<=0 )
        return INVALID_INPUT;
    CarType* to_insert;
    try
    {
        to_insert = new CarType(typeId, numOfModels);
    }
    catch (std::exception& e)
    {
        return ALLOCATION_ERROR;
    }
    if(!typestree->insert(*to_insert))
        return FAILURE;
    if (bestseller == nullptr)
        bestseller = to_insert->getMostSold();
    if(bestseller->data < (to_insert->getMostSold())->data)
        bestseller = to_insert->getMostSold();
    CarType* zeroes_insert;
    try
    {
        zeroes_insert = new CarType(typeId, numOfModels);
    }
    // do i have to delete all the trees? 
    catch(std::exception& e)
    {
        return ALLOCATION_ERROR;
    }
    zerostree->insert(*zeroes_insert);
    return SUCCESS;
}

// removes a car type from the system
// we must check how the mostSold node is update in cartype
StatusType DSW::removeCarType(int typeId)
{
    CarType to_remove = CarType(typeId , 1);
    if(!zerostree->remove(to_remove))
    {
        // if this is false, the type was not in the tree
        return FAILURE;
    }
    AVLTree<CarType>::Node* node_to_remove = typestree->findNode(to_remove);
    while(node_to_remove->data.models->root != nullptr)
    {
        // remove the model from graded models
        gradedmodels->remove(node_to_remove->data.models->root->data);
        // remove the model from the graded models tree
        node_to_remove->data.models->remove(node_to_remove->data.models->root->data);
    }
    typestree->remove(to_remove);
    // chech the state of the highest seller
    if(gradedmodels != nullptr)
    {   
        // if the car is in graded models than it has sold a model.
        // therefore it is of course a higher seller than zerosTree
        bestseller = gradedmodels->getHighest();
    }
    else if(gradedmodels != nullptr)
        {
            // if there are no gradedmodels
            // there are no sold models
            // therefor, by definition the best model is the lowest id num lowest type
            bestseller = typestree->getHighest()->data.mostSold;
        }
    bestseller = nullptr;
    return SUCCESS;
}

// Sell a car of typeid, model id and updates system
// throws relevent exceptions
StatusType DSW::sellCarr(int typeId, int modelId)
{
    // check arguments
    if(typeId <= 0 || modelId <=0)
        return INVALID_INPUT;
    CarType finder = CarType(typeId , 1);
    // check that the type was in the tree
    AVLTree<CarType>::Node* type_to_update = typestree->findNode(finder);
    if(!type_to_update)
        return FAILURE;
    // check that the model was in the tree
    AVLTree<Model>::Node* model_to_update 
        = type_to_update->data.models->findNode(Model(typeId,modelId));
    if(!model_to_update)
        return FAILURE;
    // create an updated model to insert
    int grade = model_to_update->data.grade + 10;
    int sold = model_to_update->data.numSold+1;
    Model model_to_insert = Model(typeId, modelId, grade, sold);
    // remove and then insert the updated model
    type_to_update->data.models->remove(Model(typeId,modelId));
    type_to_update->data.models->insert(model_to_insert);
    // find and remove from zerostree, checking that its there
    if(zerostree->findNode(finder))
        zerostree->findNode(finder)->data.models->remove(model_to_insert);
    // remove and reinsert in gradedmodels
    gradedmodels->remove(model_to_insert);
    gradedmodels->insert(model_to_insert);
    // check if we need to update bestseller
    // make sure that the grade is positive. 
    if(grade>0)
    {
        if(gradedmodels->getHighest()->data==model_to_insert)
                bestseller = gradedmodels->getHighest();
    }
    return SUCCESS;  
}


