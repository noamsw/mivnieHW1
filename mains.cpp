#include "avl.h"
#include "model.h"
// random mains to test with:
/*
//used to test models.cpp
int main() {

  // Allocate an array to keep track of the data we
  // add to the tree, initialize the random numbers,
  // allocate an empty tree.
  Model modelsarr[10];
  for(int i=0; i<10; i++)
  {
    modelsarr[i].setModel(2, i);
  }
  for (int i = 0; i < 10; i++) 
  {
	std::cout << "car " << modelsarr[i] << std::endl;
	
  }
  modelsarr[6].grade=100;
  int i, j;
    for (i = 0; i < 10-1; i++)
    {
        for (j = 0; j < 10-i-1; j++)
            if (modelsarr[j] > modelsarr[j+1])
                {
                    Model tcar = modelsarr[j];
                    modelsarr[j] = modelsarr[j+1];
                    modelsarr[j+1] = tcar;
                }
    } 
 std::cout << "after sort " << std::endl;  
 for (int i = 0; i < 10; i++) 
  {
	std::cout << modelsarr[i] << std::endl;
	
  }

  Model c1(1,0,20,10);
  std::cout << "c1 " << c1 << std::endl;
  c1.numSold = c1.numSold+1;
  c1.complaint(10);
  std::cout << "after complaint " << c1 << std::endl;
  Model c2(2,3,10,1);
  std::cout << "c2 " << c2 << std::endl;
  Model tempc(c1);
  std::cout << "tcar" << c2 << std::endl;
  c1=c2; 
  std::cout << "c1 " << c1 << std::endl;
  c2=tempc;
  std::cout << "c2 " << c2 << std::endl;


  return 0;
}
*/
int main()
{
	
	Model modelsarr[10];
    for(int i=0; i<10; i++)
    {
        modelsarr[i].setModel(1, i);
    }
	//AVLTree<int>* tree = arrToAVLTree(arr, 0, 8);
	AVLTree<Model>* models;
  models = AVLTree<Model>::arrToAVLTree(modelsarr, 0, 9);;
	models->print();
	/*
	int arr[10];
    for(int i=0; i<10; i++)
    {
        arr[i]=i;
    }
	//AVLTree<int>* tree = arrToAVLTree(arr, 0, 8);
	AVLTree<int> tree = AVLTree<int>();
	tree.print();
	return 0;
    */
} 