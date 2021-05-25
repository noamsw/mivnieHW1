#include "mostsold.h"
#include "avl.h"
//default constructor for model. all fields initialized to 0
MostSold::MostSold():type(0), model(0), numsold(0){};

// constuctor for Model. grade is initialized to 0 
MostSold::MostSold(int type, int model, int numsold):type(type),numsold(numsold){};

// comparing operator, returns true if equal
// cars are equal to one another if
// both type and model are equal const
bool MostSold::operator==(const MostSold& other) const
{
    if(type == other.type && model == other.model)
        return true;
    return false;
}

// comparing operator, returns true if equal
// cars are equal to one another if
// both type and model are equal
bool MostSold::operator==(const MostSold& other) 
{
    if(type == other.type && model == other.model)
        return true;
    return false;
}

// comparing operator, compares numsold of cars
bool MostSold::operator<(const MostSold& other)
{
    // if the numsold is smaller, return true
    if(numsold < other.numsold){
        return true;
    }
    // otherwise check if the numsold is equal
    if(numsold == other.numsold)
    {
        // now, if the grade is equal, but the type is bigger
        // than it is still smaller, return true
        if(type > other.type)
            return true;
        // if the type is equal, check that the model is bigger
        if(type == other.type)
            if(model > other.model)
                return true;
    }
    // the numsold is either larger
    // or the grade is equal but the type is smaller
    // or the grade and type are equal but the model is smaller
    // in all of these cases the car is a more sold model
    // return false
    return false; 
}
// comparing operator, compares grades of cars const
bool MostSold::operator<(const MostSold& other) const
{
    // if the numsold is smaller, return true
    if(numsold < other.numsold){
        return true;
    }
    // otherwise check if the numsold is equal
    if(numsold == other.numsold)
    {
        // now, if the grade is equal, but the type is bigger
        // than it is still smaller, return true
        if(type > other.type)
            return true;
        // if the type is equal, check that the model is bigger
        if(type == other.type)
            if(model > other.model)
                return true;
    }
    // the numsold is either larger
    // or the grade is equal but the type is smaller
    // or the grade and type are equal but the model is smaller
    // in all of these cases the car is a more sold model
    // return false
    return false; 
}

// comparing operator, compares grades of cars
bool MostSold::operator>(const MostSold& other)
{
    // check if the model is smaller
    // if not, it is larger as there are no two different models that are equal
    return !(*this < other);
}

// comparing operator, compares grades of cars const
bool MostSold::operator>(const MostSold& other) const
{
    // check if the model is smaller
    // if not, it is larger as there are no two different models that are equal
    return !(*this < other);
}


std::ostream& operator<<(std::ostream& os, const MostSold& car)
{
    // os << car.type << "." << car.model << "." << car.numsold;
    os << car.model ;
    return os;
}