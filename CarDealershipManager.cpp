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

/*
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
*/

StatusType DSW::MakeComplaint(int typeID, int modelID, int t)
{
    // in wraped fuction, check if DS==NULL
    // checking input 
    if (typeID < 0 || modelID <= 0)
    {
        return INVALID_INPUT;
    }
    
    //create a cartype with the typeID
    CarType tmp_ct = CarType(typeID , 1);

    //finding the type at the typestree
    AVLTree<CarType>::Node* ct_node = typestree->findNode(tmp_ct); //what is the problem??
    if (ct_node==nullptr) // if the cartype is not in the typestree
    {
        return FAILURE;
    }


    Model tmp_m = Model(typeID, modelID); //should i use new?
    //finding the model at the type's models tree
    AVLTree<Model>::Node* m_node = ct_node->data.models->findNode(tmp_m)
    if (tmp_m) // if the model doesnt exist
    {
        //free curr_car_type?
        return FAILURE;
    }

    //update model's grade
    int original_grade = curr_model.grade;
    int complaint_grade= t / 100;
    curr_model.grade = curr_model.grade - complaint_grade ;

    //check if the model is in the zerostree
    CarType curr_car_type_zero = (*this).zerostree.findNode(typeID);
    if (!null) //if the car is in the zeros tree
    {
        //remove the car from the zeros tree
        //create a model with the new grade
        //insert the model into grademodels
        //free objects I created?
        //return SUCCESS;
    }

    //if the model isnt in the zeros, find it in the grademodels
    Model curr_model_grades = (*this).gradedmodels->findNode(original_grade, typeID, modelID);
    Model tmp = curr_model_grades ;
    tmp.grade = curr_model.grade; //setting the tmp's grade to the new one
    //remove curr_model_grades from grademodels
    //insert tmp to grade models
    //free objects
    //return SUCCESS;
}

