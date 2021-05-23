#ifndef CARDEALERSHIPMANAGER_H_
#define CARDEALERSHIPMANAGER_H_

#include "AVL.h"
#include "cartype.h"
#include "model.h" 
#include "iostream"

class DSW
{
    AVLTree<CarType>* allTypes;
    AVLTree<CarType>* zeros;
    AVLTree<Model>* gradedModels;
    //pointer to system's bestSeller

    public:
    DSW();
    ~DSW();


};

#endif 