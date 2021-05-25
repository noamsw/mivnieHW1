#ifndef CAR_TYPE_H_
#define CAR_TYPE_H_

#include "avl.h"
#include "model.h"
#include "exceptions.h"

class CarType
{
public:
    // tree of the models of type
    AVLTree<Model>* models;
    // type id
    int type;
    // a pointer to the best seller of type
    AVLTree<Model>::Node* best_seller;
public:
    // constructor
    CarType(int type, int numOfModels);
    CarType(CarType& cartype);
    ~CarType();
    // returns the model number of the best seller
    int getBestSeller() const;
    // returns a pointer to the best seller
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