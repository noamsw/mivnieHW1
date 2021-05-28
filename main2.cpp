#include "unified.cpp"
int main() 
	{
	  DSW cd;
	  cd.addCarType(3,10);
	  cd.addCarType(4,10);
    cd.zerostree->print();
    std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^" << std::endl;
    cd.zerostree->lowest->data.models->print();
    std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^" << std::endl;
    cd.zerostree->highest->data.models->print();
    std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^" << std::endl;
	  int t_arr[20];
	  int m_arr[20];
      for(int i=0; i<20; i++)
      {
          t_arr[i]=0;
          m_arr[i]=0;
      }
    
	  std::cout << cd.GetWorstModels(20, t_arr, m_arr) << std::endl;
	
	  for (int i=0; i<20; i++)
	  {
	    std::cout << "t:" <<t_arr[i] << std::endl;
	    std::cout << "m:" <<m_arr[i] << std::endl;
	    std::cout << std::endl;
	  }
  
  }
