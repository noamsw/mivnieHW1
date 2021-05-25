#ifndef CAR_TYPE_H_
#define CAR_TYPE_H_

#include "avl.h"
#include "model.h"
#include "exceptions.h"

class CarType
{
public:
    AVLTree<Model>* models;
    int type;
public:
    // constructor
    CarType(int type, int numOfModels);
    CarType(CarType& cartype);
    ~CarType();
    // returns the model number of the best seller
    int getBestSeller();
    // returns a pointer to the highest selling model
    AVLTree<Model>::Node* getMostSold();
    // comparing method between to cartypes
    // detertmined by typeid
    bool operator<(const CarType& cartype);
    // instantiate operator=
    CarType& operator=(CarType& cartype);
    bool operator>(const CarType& cartype);
    bool operator==(const CarType& cartype);
    bool addModel(int model_num, int grade, int numSold);
    bool removeModel(int model_num);
};

#endif