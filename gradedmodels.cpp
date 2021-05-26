#include "gradedmodels.h"
#include <string>
#include <iostream>
//default constructor for gradedmodel. all fields initialized to 0
GradedModel::GradedModel():type(0), model(0), grade(0), numsold(0){};

// constuctor for GradedModel. grade is initialized to 0 
GradedModel::GradedModel(int type, int model):type(type),model(model){};

// parameterized constuctor for GradedModel. 
GradedModel::GradedModel(int type, int model, int grade, int numSold):type(type),model(model), grade(grade), numsold(numSold){};

// updates grade when a model recieves a complaint
void GradedModel::complaint(int numMonths)
{
    int lowered = 100/numMonths;
    grade = grade - lowered;
}

// comparing operator, returns true if equal
// cars are equal to one another if
// both type and model are equal const
bool GradedModel::operator==(const GradedModel& other) const
{
    if(type == other.type && model == other.model)
        return true;
    return false;
}

// comparing operator, returns true if equal
// cars are equal to one another if
// both type and model are equal
bool GradedModel::operator==(const GradedModel& other) 
{
    if(type == other.type && model == other.model)
        return true;
    return false;
}

// comparing operator, compares grades of cars
bool GradedModel::operator<(const GradedModel& other)
{
    // if the models have the same model and type
    // we should consider them equal
    if((*this) == other)
      return false;
    // if the grade is smaller, return true
    if(grade < other.grade){
        return true;
    }
    // otherwise check if the grade is equal
    if(grade == other.grade)
    {
        // now, if the grade is equal, but the type is smaller
        // than it is still smaller, return true
        if(type < other.type)
            return true;
        // if the type is equal, check that the model is smaller
        if(type == other.type)
            if(model < other.model)
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
bool GradedModel::operator<(const GradedModel& other) const
{
    // if the models have the same model and type
    // we should consider them equal
    if((*this) == other)
      return false;
    // if the grade is smaller, return true
    if(grade < other.grade){
        return true;
    }
    // otherwise check if the grade is equal
    if(grade == other.grade)
    {
        // now, if the grade is equal, but the type is smaller
        // than it is still smaller, return true
        if(type < other.type)
            return true;
        // if the type is equal, check that the model is smaller
        if(type == other.type)
            if(model < other.model)
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
bool GradedModel::operator>(const GradedModel& other)
{
    // if the models have the same model and type
    // we should consider them equal
    if((*this) == other)
      return false;
    // check if the model is smaller
    // if not, it is larger as there are no two different models that are equal
    return !(*this < other);
}

// comparing operator, compares grades of cars const
bool GradedModel::operator>(const GradedModel& other) const
{
    // if the models have the same model and type
    // we should consider them equal
    if((*this) == other)
      return false;
    // check if the model is smaller
    // if not, it is larger as there are no two different models that are equal
    return !(*this < other);
}

void GradedModel::setGradedModel(int type, int model, int grade, int numsold)
{
    (*this).type= type;
    (*this).model= model;
    (*this).grade= grade;
    (*this).numsold= numsold;

}

std::ostream& operator<<(std::ostream& os, const GradedModel& car)
{
    os << car.type << "." << car.model << "." << car.grade;
    //os << car.model ;
    return os;
}