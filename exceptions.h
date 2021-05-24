#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H
#include <string>
#include <exception>

    class Exception : std::exception{
    public:
    virtual std::string what() {return "exception";};
    };
    
// RemoveCar- negative type id
// SellCar- negative type id, negative model id
// MakeComplaint- negative type id, negative model id
// GetBestSellerByType- negative type id
// GewtWorstModels- numOfModels is negative
    class InvalidInput : Exception{
    public:
    std::string what() {return "InvalidInput";};    
    };
// RemoveCar- car type does not exist
// SellCar- car type of num model does not exist 
// MakeComplaint- car type of num model does not exist 
// GetBestSellerByType- car type id does not exist, tree is empty and 0 entered
// GewtWorstModels- less Models in tree then numOfMOdels
    class Failure : Exception{
    public:
    std::string what() {return "Failure";};    
    };
// RemoveCar- succesfully removed car
// SellCar- succesfully sold car
// MakeComplaint- succesfully filed complaint
// GetBestSellerByType- " " "
// GewtWorstModels
    class Success : Exception{
    public:
    std::string what() {return "Success";};
    };


  

#endif