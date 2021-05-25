#ifndef CAR_TYPE_H_
#define CAR_TYPE_H_

#include "AVL.h"
#include "model.h"
#include "exceptions.h"

class CarType
{
public:
    AVLTree<Model>* models;
    int type;

    // constructor
    CarType(int type, int numOfModels);
    ~CarType();
    // returns the model number of the best seller
    int getBestSeller();
    // comparing method between to cartypes
    // detertmined by typeid
    bool operator<(const CarType& cartype);
    bool operator>(const CarType& cartype);
    bool operator==(const CarType& cartype);
    void addModel(int model_num, int grade, int numSold);
    void removeModel(int model_num);
};

#endif