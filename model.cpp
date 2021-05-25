#include "model.h"
#include "avl.h"
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
        // now, if the grade is equal, but the type is smaller
        // than it is still smaller, return true
        if(type < other.type)
            return true;
        // if the type is equal, check that the model is smaller
        if(type == other.type)
            if(model < other.model)
                return true;
    }
    // the grade is either larger
    // or the grade is equal but the type is larger
    // or the grade and type are equal but the model is larger
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
        if(type < other.type)
            return true;
        // if the type is equal, check that the model is larger
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
    // os << car.type << "." << car.model << "." << car.grade;
    os << car.model ;
    return os;
}
/*
int main() {

  // Allocate an array to keep track of the data we
  // add to the tree, initialize the random numbers,
  // allocate an empty tree.
  Model modelsarr[10];
  modelsarr[0].setModel(2, 21);
  modelsarr[1].setModel(2, 34);
  modelsarr[2].setModel(2, 13);
  modelsarr[3].setModel(3, 0);
  modelsarr[4].setModel(2, 3);
  modelsarr[5].setModel(2, 6);
  modelsarr[6].setModel(2, 8);
  modelsarr[7].setModel(2, 17);
  modelsarr[8].setModel(1, 42);
  modelsarr[9].setModel(2, 27);
  AVLTree<Model> *tree = new AVLTree<Model>();

  for (int i = 0; i < 10; i++) 
  { 
    tree->insert(modelsarr[i]);
	std::cout << "Adding " << modelsarr[i] << std::endl;
	tree->print();
  } // for


  // Remove each of the numbers by displaying the
  // number being removed, performing the removal,
  // and displaying the current state of the tree.
  for (int i = 0; i < 10; i++) {
	std::cout << "Removing " << modelsarr[i] << std::endl;
	tree->remove(modelsarr[i]);
	tree->print();
  } // for
  return 0;
}
*/



