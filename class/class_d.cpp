#include "class_d.hpp"
#include <ff++.hpp>
#include <iostream>

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

// Define how to print the value stored in *(D.pd)
ostream& operator<<(ostream& os, const Delta& D){
  os << *(D.pd);
  return os;
}

// This struc is required to define the binary operation "a << D" in .edp file
// std::binary_function is a function of the c++ std.
// Those structures are actually already defined in AFunction.cpp
// Instead of creating a new struct PrintD, I could have used directly PrintP<Delta>
// inside the TheOperators command at the end of this file.
struct PrintD: public binary_function<ostream*, Delta *, ostream*>{
  static ostream* f(ostream* const & os, Delta * const  & D)
  {
    *os << D; // calls the operator<< defined earlier in the class
    return os;
  }
};


//ostream& operator=()

class Init { 
	public:
  	Init();
};
Init init;
Init::Init(){

  Dcl_Type<Delta*>(InitP<Delta>,Destroy<Delta>); // declare a new type for freefem++  
  zzzfff->Add("delta",atype<Delta* >()); // add the Delta type to freefem++ 

  TheOperators->Add("<-", new OneOperator2_<Delta *, Delta *, double >(&init_Delta)); // constructor of the Delta type in freefem
  //TheOperators->Add("<-",new OneOperator2_<Delta *, Delta *, double * >(&init_Delta)); // constructor of the Delta type in freefem
  // If 2 Add("<-") for the same Class, then get Create ambiguity 2 error message. need to use one with no pointer (implicit cast)
  // How to overload init constructor?

  // To print the value of *(Delta.pd)
  TheOperators->Add("<<", new OneBinaryOperator<PrintD>); 
  //  TheOperators->Add("<<", new OneBinaryOperator<PrintP<Delta> >); // also works 
  Add<Delta *>("pd", ".", new OneOperator1_<double *, Delta *> (&get_pd));
}