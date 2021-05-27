#include "AVL.h"
#include "cartype.h"
#include "assert.h"
#include "model.h" 
#include "iostream"
#include "gradedmodels.h"
#include "dsw.h"
#include "assert.h"

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
    // check that the input is correct
    if( typeId<=0 || numOfModels<=0 )
        return INVALID_INPUT;
    CarType* to_insert = nullptr;
    try
    {
        to_insert = new CarType(typeId, numOfModels);
    }
    catch (std::exception& e)
    {
        return ALLOCATION_ERROR;
    }
    if(typestree->findNode(*to_insert))
    {
        delete to_insert;
        return FAILURE;
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
        delete zeroes_insert;
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

// removes a car type from the system
StatusType DSW::removeCarType(int typeId)
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

// Sell a car of typeid, model id and updates system
// throws relevent exceptions
StatusType DSW::sellCar(int typeId, int modelId)
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
        assert(zerostree->findNode(finder));
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
            zerostree->findNode(finder)->data.models->remove(Model(typeId,modelId));
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

StatusType DSW::MakeComplaint(int typeID, int modelID, int t)
{
    // checking input (in wraped fuction, check if DS==NULL)
    if (typeID < 0 || modelID <= 0)
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
    int complaint_grade = t / 100;
    int new_grade = original_grade - complaint_grade;
    int numsold = m_to_complaint->data.numSold;
    m_to_complaint->data.grade = m_to_complaint->data.grade - complaint_grade;

    // initialize the model we want to insert to models tree
    Model model_to_add= Model(typeID, modelID, m_to_complaint->data.grade, m_to_complaint->data.numSold);

    // check if the type is in the zerostree
    AVLTree<CarType>::Node* ct_node_zeros= zerostree->findNode(find_ct);
    if (ct_node_zeros != nullptr)
    {
        // check if the model is in the ct_node_zeros
        AVLTree<Model>::Node* m_node_zeros = ct_node_zeros->data.models->findNode(find_m);
        if (m_node_zeros != nullptr)
        {
            // remove the model from the zeros tree
            ct_node_zeros->data.removeModel(modelID);
            // insert te model to the grade tree
            // using the current grade and numsold
            gradedmodels->insert(GradedModel(typeID, modelID, new_grade, numsold));
            return SUCCESS;
        }
    }

    // if the model isnt in the zeros, it must be in the grademodels
    // check if the grade how now returned to zero
    // if so we must remove it from the gradedmodels
    // and insert into the zerostree
    if(new_grade == 0)
    {
        // find the type in the zerostree 
        AVLTree<CarType>::Node* ct_node_zeros= zerostree->findNode(find_ct);
        if (ct_node_zeros != nullptr)
        {
            // insert the model into the zeros tree
            ct_node_zeros->data.addModel(modelID, 0, numsold);
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

StatusType DSW::GetBestSellerModelByType(int typeID, int * modelID)
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


// functions for getWorstModels
void insertModelToArr(int* t_arr, int* m_arr, int* index, AVLTree<Model>::Node* model_node)
{
	t_arr[*index]=model_node->data.type;
	m_arr[*index]=model_node->data.model;
	(*index)+=1;
}


void inorderNegativeModel(int* t_arr, int* m_arr, int* index, AVLTree<Model>::Node* model_node,
											 int numOfModels, AVLTree<Model>::Node* first_positive_node)
{
	// stop-conditions 
	if(model_node == nullptr || (*index == numOfModels))
	{
		return;
	}

	// recursive call, first start with the left childs (lower values)
	inorderNegativeModel(t_arr, m_arr, index , model_node->getLeftChild(), numOfModels, first_positive_node);

	// push only the negative graded models to the arrays
	if (model_node->data.grade < 0)
	{
		insertModelToArr(t_arr, m_arr, index, model_node);	
	}

	// if the grade is not negative, we want to exit the recurrsion and keep the first positive node
	if(model_node->data.grade > 0)
	{
		first_positive_node = model_node;
		return;
	}

	// recursive call for the right childs
	inorderNegativeModel(t_arr, m_arr, index, model_node->getRightChild(), numOfModels, first_positive_node);
}

void inorderLowestNegativeModel(int* t_arr, int* m_arr, int* index, AVLTree<Model>::Node* model_node,
													 int numOfModels, AVLTree<Model>::Node* first_positive_node)
{
	// stop-conditions
	if (model_node == nullptr || (*index == numOfModels))
	{
		return;
	}

	// we only want to insert negative nodes. 
	if (model_node->data.grade >= 0)
	{
		// return the first positive node
		first_positive_node = model_node;
		return;
	}	

	// the node exist and its negative, add it to the arr 
	insertModelToArr(t_arr, m_arr, index, model_node);

	// use inorder algorithm to check&insert the node's right sub-tree
	inorderNegativeModel(t_arr, m_arr, index, model_node->getRightChild(), numOfModels, first_positive_node);

	// reccursive call to inorderLowestNegativeModel
	inorderLowestNegativeModel(t_arr, m_arr, index, model_node->getParent(), numOfModels, first_positive_node);	
}


void inorderZPModel(int* t_arr, int* m_arr, int* index, AVLTree<Model>::Node* model_node, int numOfModels)
{
	// stop-conditions 
	if(model_node == nullptr || (*index == numOfModels))
	{
		return;
	}

	// recursive call to the left childs
	inorderZPModel(t_arr, m_arr, index , model_node->getLeftChild(), numOfModels);

	// insert node to the arrays
	insertModelToArr(t_arr, m_arr, index, model_node);	

	// recursive call to the right childs
	inorderZPModel(t_arr, m_arr, index, model_node->getRightChild(), numOfModels);
}

void inorderZPLowesModel(int* t_arr, int* m_arr, int* index, AVLTree<Model>::Node* model_node, int numOfModels)
{
	// stop-conditions
	if (model_node == nullptr || (*index == numOfModels))
	{
		return;
	}

	// the node exist insert to the arr 
	insertModelToArr(t_arr, m_arr, index, model_node);

	// use inorder algorithm to check&insert the node's right sub-tree
	inorderZPModel(t_arr, m_arr, index, model_node->getRightChild(), numOfModels);

	// reccursive call to inorderZeroLowesModel
	inorderZPLowesModel(t_arr, m_arr, index, model_node->getParent(), numOfModels);	
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
  inorderZPModel(t_arr, m_arr, index, node->data.models->lowest, numOfModels);

  //recursive call to the right child
  inorderZerosCT(t_arr, m_arr, index, node->getRightChild(), numOfModels);
}

void inorderZerosLowestCT(int* t_arr, int* m_arr, int* index, AVLTree<CarType>::Node* node, int numOfModels)
{
	// stop conditions:
	if(node == nullptr || (*index == numOfModels))
	{
		return;
	}	

  inorderZPModel(t_arr, m_arr, index, node->data.models->lowest, numOfModels);
  inorderZerosCT(t_arr, m_arr, index, node->getRightChild(), numOfModels);
  inorderZerosLowestCT(t_arr, m_arr, index, node->getParent(), numOfModels);
}


StatusType DSW::GetWorstModels(int numOfModels, int *types, int *models)
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

	// initializing a null Model Node*
	// the node will keep the first positive graded model
	// first we insert the negative graded models
	// then we insert the zero graded models
	// and then we insert the positive graded models
	AVLTree<Model>::Node* first_positive_node = nullptr; //should i use new?

	// inserting the negative graded models
  inorderLowestNegativeModel(types, models , index, this->gradedmodels->lowest , numOfModels, first_positive_node);
  
  // if we filled the arrayes, finish
  if(*index == numOfModels)
  {
		//free first_positive_node
		//free index?
    return SUCCESS;
  } 
  
  // if we didnt fill the arrays, go to Zeros tree
  inorderZerosLowestCT(types, models, index, zerostree->lowest, numOfModels);

  // if we filled the arrayes, finish
  if(*index == numOfModels)
  {
		//free first_positive_node
		//free index?
    return SUCCESS;
  } 


  //if we didnt fill the array, go to models positive grades
  inorderZPLowesModel(types, models, index, first_positive_node, numOfModels);

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