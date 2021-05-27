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
    // default constructor
    CarType();
    CarType(int type, int numOfModels);
    CarType(const CarType& cartype);
    ~CarType();
    // returns the model number of the best seller
    int getBestSeller() const;
    // returns a pointer to the best seller
    AVLTree<Model>::Node* getMostSold();
    // comparing method between to cartypes
    // detertmined by typeid
    bool operator<(const CarType& cartype) const;
    // instantiate operator=
    CarType& operator=(CarType& cartype);
    bool operator>(const CarType& cartype) const;
    bool operator==(const CarType& cartype) const;
    bool addModel(int model_num, int grade, int numSold);
    bool removeModel(int model_num);
    friend std::ostream& operator<<(std::ostream& os, const Model& car);
};

#endif