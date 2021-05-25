#include "model.h"

//default constructor for model. all fields initialized to 0
Model::Model():type(0), model(0), grade(0), numSold(0){};

// constuctor for Model. grade is initialized to 0 
Model::Model(int type, int model):type(type),model(model){};

// parameterized constuctor for Model. 
Model::Model(int type, int model, int grade, int numSold):type(type),model(model), grade(grade), numSold(numSold){};

// updates grade when a model recieves a complaint
void Model::complaint(int numMonths)
{
    int lowered = 100/numMonths;
    grade = grade - lowered;
}

// comparing operator, returns true if equal
// cars are equal to one another if
// both type and model are equal const
bool Model::operator==(const Model& other) const
{
    if(type == other.type && model == other.model)
        return true;
    return false;
}

// comparing operator, returns true if equal
// cars are equal to one another if
// both type and model are equal
bool Model::operator==(const Model& other) 
{
    if(type == other.type && model == other.model)
        return true;
    return false;
}

// comparing operator, compares grades of cars
bool Model::operator<(const Model& other)
{
    // if the grade is smaller, return true
    if(grade < other.grade){
        return true;
    }
    // otherwise check if the grade is equal
    if(grade == other.grade)
    {
        // now, if the grade is equal, but the type is bigger
        // than it is still smaller, return true
        if(type > other.type)
            return true;
        // if the type is equal, check that the model is larger
        if(type == other.type)
            if(model > other.model)
                return true;
    }
    // the grade is either smaller
    // or the grade is equal but the type is smaller
    // or the grade and type are equal but the model is smaller
    // in all of these cases the car is a better model
    // return false
    return false; 
}
// comparing operator, compares grades of cars const
bool Model::operator<(const Model& other) const
{
    // if the grade is smaller, return true
    if(grade < other.grade){
        return true;
    }
    // otherwise check if the grade is equal
    if(grade == other.grade)
    {
        // now, if the grade is equal, but the type is bigger
        // than it is still smaller, return true
        if(type > other.type)
            return true;
        // if the type is equal, check that the model is larger
        if(type == other.type)
            if(model > other.model)
                return true;
    }
    // the grade is either smaller
    // or the grade is equal but the type is smaller
    // or the grade and type are equal but the model is smaller
    // in all of these cases the car is a better model
    // return false
    return false; 
}

// comparing operator, compares grades of cars
bool Model::operator>(const Model& other)
{
    // check if the model is smaller
    // if not, it is larger as there are no two different models that are equal
    return !(*this < other);
}

// comparing operator, compares grades of cars const
bool Model::operator>(const Model& other) const
{
    // check if the model is smaller
    // if not, it is larger as there are no two different models that are equal
    return !(*this < other);
}

void Model::setModel(int type, int model)
{
    (*this).type= type;
    (*this).model= model;
}

std::ostream& operator<<(std::ostream& os, const Model& car)
{
    // os << "typeId: " << car.type << " modelId: " << car.model << " grade: " << car.grade;
    os << car.model ;
    return os;
}


