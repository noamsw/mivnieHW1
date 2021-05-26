// #include "avl.h"
// #include "model.h"

// // random mains to test with:
// /*
// //used to test models.cpp
// int main() {

//   // Allocate an array to keep track of the data we
//   // add to the tree, initialize the random numbers,
//   // allocate an empty tree.
//   Model modelsarr[10];
//   for(int i=0; i<10; i++)
//   {
//     modelsarr[i].setModel(2, i);
//   }
//   for (int i = 0; i < 10; i++) 
//   {
// 	std::cout << "car " << modelsarr[i] << std::endl;
	
//   }
//   modelsarr[6].grade=100;
//   int i, j;
//     for (i = 0; i < 10-1; i++)
//     {
//         for (j = 0; j < 10-i-1; j++)
//             if (modelsarr[j] > modelsarr[j+1])
//                 {
//                     Model tcar = modelsarr[j];
//                     modelsarr[j] = modelsarr[j+1];
//                     modelsarr[j+1] = tcar;
//                 }
//     } 
//  std::cout << "after sort " << std::endl;  
//  for (int i = 0; i < 10; i++) 
//   {
// 	std::cout << modelsarr[i] << std::endl;
	
//   }

//   Model c1(1,0,20,10);
//   std::cout << "c1 " << c1 << std::endl;
//   c1.numSold = c1.numSold+1;
//   c1.complaint(10);
//   std::cout << "after complaint " << c1 << std::endl;
//   Model c2(2,3,10,1);
//   std::cout << "c2 " << c2 << std::endl;
//   Model tempc(c1);
//   std::cout << "tcar" << c2 << std::endl;
//   c1=c2; 
//   std::cout << "c1 " << c1 << std::endl;
//   c2=tempc;
//   std::cout << "c2 " << c2 << std::endl;


//   return 0;
// }
// */
// int main()
// {
	
// 	Model modelsarr[10];
//     for(int i=0; i<10; i++)
//     {
//         modelsarr[i].setModel(1, i);
//     }
// 	//AVLTree<int>* tree = arrToAVLTree(arr, 0, 8);
// 	AVLTree<Model>* models;
//   models = AVLTree<Model>::arrToAVLTree(modelsarr, 0, 9);;
// 	models->print();
// 	/*
// 	int arr[10];
//     for(int i=0; i<10; i++)
//     {
//         arr[i]=i;
//     }
// 	//AVLTree<int>* tree = arrToAVLTree(arr, 0, 8);
// 	AVLTree<int> tree = AVLTree<int>();
// 	tree.print();
// 	return 0;
//     */
// } 


// int main() {

//   // Allocate an array to keep track of the data we
//   // add to the tree, initialize the random numbers,
//   // allocate an empty tree.
//   Model modelsarr[10];
//   modelsarr[0].setModel(2, 21);
//   modelsarr[1].setModel(2, 34);
//   modelsarr[2].setModel(2, 13);
//   modelsarr[3].setModel(3, 0);
//   modelsarr[4].setModel(2, 3);
//   modelsarr[5].setModel(2, 6);
//   modelsarr[6].setModel(2, 8);
//   modelsarr[7].setModel(2, 17);
//   modelsarr[8].setModel(1, 42);
//   modelsarr[9].setModel(2, 27);
//   AVLTree<Model> *tree = new AVLTree<Model>();

//   for (int i = 0; i < 10; i++) 
//   { 
//     tree->insert(modelsarr[i]);
// 	std::cout << "Adding " << modelsarr[i] << std::endl;
// 	tree->print();
//   } // for


//   // Remove each of the numbers by displaying the
//   // number being removed, performing the removal,
//   // and displaying the current state of the tree.
//   for (int i = 0; i < 10; i++) {
// 	std::cout << "Removing " << modelsarr[i] << std::endl;
// 	tree->remove(modelsarr[i]);
// 	tree->print();
//   } // for
//   return 0;
// }


// // used to test mostsold
// int main() {

//   // Allocate an array to keep track of the data we
//   // add to the tree, initialize the random numbers,
//   // allocate an empty tree.
//   MostSold modelsarr[10];
//   modelsarr[3].set(3,4,0);
//   modelsarr[4].set(4,5,3);
//   modelsarr[5].set(5,3,6);
//   modelsarr[6].set(7,8,8);
//   modelsarr[0].set(1,3,10);
//   modelsarr[2].set(6,2,13);
//   modelsarr[7].set(8,9,17);
//   modelsarr[9].set(0,6,27);
//   modelsarr[1].set(2,2,34);
//   modelsarr[8].set(9,5,42);
//   AVLTree<MostSold> *tree = new AVLTree<MostSold>();

//   for (int i = 0; i < 10; i++) 
//   { 
//     tree->insert(modelsarr[i]);
// 	std::cout << "Adding " << modelsarr[i] << std::endl;
// 	tree->print();
//   } // for


//   // Remove each of the numbers by displaying the
//   // number being removed, performing the removal,
//   // and displaying the current state of the tree.
//   for (int i = 0; i < 10; i++) {
// 	std::cout << "Removing " << modelsarr[i] << std::endl;
// 	tree->remove(modelsarr[i]);
// 	tree->print();
//   } // for
//   return 0;
// }


// // used for debuging dsw
// int main() 
// {
//   DSW cd;
//   // cd.sellCarr(4, 4);
//   // cd.MakeComplaint(4, 4, 2);
//   // int types[3]= {0, 0, 0};
//   // int models[3]= {0, 0, 0};
//   // cd.GetWorstModels(3, types , models);
//   // cd.sellCarr(6, 1);
//   // std::cout << types[0] <<" , "<< types[1] <<" , "<< types[4] <<" , ";
//   // std::cout << models[0] <<" , "<< models[1] <<" , "<< models[4] <<" , ";
  
//   cd.addCarType(4,6);
//   cd.addCarType(3,4);
//   // cd.addCarType(6,3);
//   std::cout << "best sellers"  << std::endl;
//   cd.bestsellers->print();
//   // cd.typestree->highest->data.models->print();
//   // cd.typestree->lowest->data.models->print();
//   // cd.removeCarType(6);
//   // std::cout << "removed" << std::endl;
//   std::cout << "id 4 zeros tree before sale"  << std::endl;
//   cd.zerostree->highest->data.models->print();
//   std::cout << "id 3 zeros tree before sale"  << std::endl;
//   cd.zerostree->lowest->data.models->print();
//   // cd.bestsellers->print();
//   cd.sellCar(4,3);
//   cd.sellCar(3,2);
//   // if(cd.sellCar(6,1) == FAILURE)
//   //   std::cout << "no such typeId"  << std::endl;
//   std::cout << "id 4 zeros tree after sale, 4,3"  << std::endl;
//   cd.zerostree->highest->data.models->print();
//   // std::cout << "id 3 models tree"  << std::endl;
//   // cd.typestree->lowest->data.models->print();
//   std::cout << "id 3 zero tree after sale 3,2"  << std::endl;
//   cd.zerostree->lowest->data.models->print();
//   std::cout << "best sellers"  << std::endl;
//   cd.bestsellers->print();
//   std::cout << "graded models"  << std::endl;
//   cd.gradedmodels->print();
//   return 0;
// }
 
// // main used to debug insert
// int main() {

//   AVLTree<Model> *tree = new AVLTree<Model>();
  
//   tree->insert(Model(4,3));
//   tree->insert(Model(4,3,10,1));
//   tree->insert(Model(4,3,10,2));
//   tree->insert(Model(4,3,10,3));
//   tree->insert(Model(4,3,10,5));
//   tree->print();
//   tree->remove((Model(4,3)));
//   tree->print();
//   tree->insert(Model(4,3,10,1));
//   tree->print();
//   tree->remove(Model(4,2));
//   tree->insert(Model(4,2,52,2));
//   tree->print();
// }


// // used to debug sellcar DSW
// int main() 
// {
//   DSW cd;
//   cd.addCarType(4,6);
//   cd.addCarType(3,4);
//   std::cout << "best sellers"  << std::endl;
//   cd.bestsellers->print();
//   std::cout <<              "----------------------"  << std::endl;
//   std::cout << "id 4 zeros tree before sale"  << std::endl;
//   cd.zerostree->highest->data.models->print();
//   std::cout <<              "----------------------"  << std::endl;
//   std::cout << "id 4 types tree before sale"  << std::endl;
//   cd.typestree->highest->data.models->print();
//   std::cout <<              "----------------------"  << std::endl;
//   std::cout << "id 3 types tree before sale"  << std::endl;
//   cd.typestree->lowest->data.models->print();
//   std::cout <<              "----------------------"  << std::endl;
//   std::cout << "id 3 zeros tree before sale"  << std::endl;
//   cd.zerostree->lowest->data.models->print();
//   std::cout <<              "----------------------"  << std::endl;
//   // cd.bestsellers->print();
//   cd.sellCar(4,3);
//   cd.sellCar(3,2);
//   // if(cd.sellCar(6,1) == FAILURE)
//   //   std::cout << "no such typeId"  << std::endl;
//   std::cout << "id 4 zeros tree after sale, 4,3"  << std::endl;
//   cd.zerostree->highest->data.models->print();
//   std::cout <<              "----------------------"  << std::endl;
//   // std::cout << "id 3 models tree"  << std::endl;
//   // cd.typestree->lowest->data.models->print();
//   std::cout << "id 3 zero tree after sale 3,2"  << std::endl;
//   cd.zerostree->lowest->data.models->print();
//   std::cout <<              "----------------------"  << std::endl;
//   std::cout << "best sellers"  << std::endl;
//   cd.bestsellers->print();
//   std::cout <<              "----------------------"  << std::endl;
//   std::cout << "graded models"  << std::endl;
//   cd.gradedmodels->print();
//   return 0;
// }
