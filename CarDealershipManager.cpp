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
void DSW::addCarType(int typeId, int numOfModels)
{
    // check that the input is correct
    if( typeId<=0 || numOfModels<=0 )
        throw InvalidInput();
    CarType* type_to_insert = new CarType(typeId, numOfModels);
    AVLTree<Model>* typestree = new AVLTree<Model>();

}