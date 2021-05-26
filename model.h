#ifndef MODEL_H_
#define MODEL_H_

#include "iostream"
#include "avl.h"

// class used by the main types tree
// value of each model is determined
// by modelId only
class Model{
public:
    int type;
    int model;
    int grade=0;
    int numSold=0;

    Model();
    Model(int type, int model);
    Model(int type, int model, int grade, int numSold);
    Model(const Model& other) = default;
    void setModel(int type, int model);
    void complaint(int numMonths);
    Model& operator=(const Model& other) = default;
    bool operator==(const Model& other) const;
    bool operator>(const Model& other) const;
    bool operator<(const Model& other) const;
    bool operator==(const Model& other);
    bool operator>(const Model& other);
    bool operator<(const Model& other);
    friend std::ostream& operator<<(std::ostream& os, const Model& car);
};



#endif



