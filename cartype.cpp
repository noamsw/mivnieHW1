#include "cartype.h"
#include "iostream"

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
    //models = new AVLTree<Model>();

    //turning the sorted array into AVLTree
    models->arrToAVLTree(modelsarr, 0, numOfModels-1); 

    // the model with the highest value at initialization
    // is defined to be the model with the lowest model number
    // which is defined as the best selling model at initialization
    mostSold=models->getHighest(); //check
    delete[] modelsarr;
}

//destructor for CarType, must delete models
CarType::~CarType()
{
    delete models;
}
// returns pointer to most sold model
AVLTree<Model>::Node* CarType::getMostSold()
{
    return mostSold;
}
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

void* CarType::addModel(int model_num, int grade, int numSold)
{
    Model model_to_add= Model(this->type, model_num, grade, numSold);
    this->models->insert(model_to_add);
    //should I free model_to_add?
}

void* CarType::removeModel(int model_num)
{
    Model model_to_delete= Model(this->type, model_num);
    this->models->remove(model_to_delete);
    delete &model_to_delete;
}

int main()
{
    CarType ct = CarType(3,6);
    return 0;
}