#include "class_d.hpp"
#include <ff++.hpp>

using namespace Fem2D;

// Cannot use this constructor apparently
/*Delta * init_Delta(Delta * const &D, double * const & d2)
{
  D->d = *d2;
  D->pd = new double(*d2);
  
  return NULL; // return value never used for now (13.1)
} */

Delta * init_Delta(Delta * const &D, double const & d2)
{
  if(D->pd !=0){
    delete D->pd;
    D->pd=0;
  }
  D->pd = new double(d2); //cout << "MYTIPE IS: " << typeid(D->pd).name() <<endl;
  
  return NULL; // return value never used for now (13.1)
} 

double * get_pd(Delta * const & D){
	return D->pd;
}

class Init { 
	public:
  	Init();
};
Init init;
Init::Init(){

  Dcl_Type<Delta*>(InitP<Delta>,Destroy<Delta>); // declare a new type for freefem++  
  zzzfff->Add("delta",atype<Delta* >()); // add the Delta type to freefem++ 

  TheOperators->Add("<-",new OneOperator2_<Delta *, Delta *, double >(&init_Delta)); // constructor of the Delta type in freefem
  //TheOperators->Add("<-",new OneOperator2_<Delta *, Delta *, double * >(&init_Delta)); // constructor of the Delta type in freefem
  // If 2 Add("->") for the same Class, then get Create ambiguity 2 error message. need to use one with no pointer (implicit cast)
  // How to overload init constructor?
  Add<Delta *>("pd", ".", new OneOperator1_<double *, Delta *> (&get_pd));
}