#include "class_a.hpp"

A * init_A1(A * const &S, double const & d){
  S->init();
  *S->p_D = d;
  return S;
}

double * get_p_D(A * const & S){
  return S->get_p_D();
}

A * set_species(A* a, A * b ){ 
    *a=b;
    return a;}

ArrayOfA * init_ArrayOfA1(ArrayOfA * const &SA, long int const &ns){
  SA->init(ns);
  return SA;
}

A* get_Ai(ArrayOfA * const &SA, long int const &i){
  return &((*SA)[i]);
}

class Init { 
	public:
  	Init();
};
Init init;
Init::Init(){

  // We add the A class to FreeFem
  Dcl_Type<A*>(InitP<A>,Destroy<A>); // declare a new type in freefem++ 
  zzzfff->Add("classa",atype<A* >()); // add the A type to freefem++ 

  TheOperators->Add("<-", new OneOperator2_<A *, A *, double >(&init_A1)); 
  TheOperators->Add("=",new OneOperator2<A *, A *, A *>(&set_species)); // Assignement by copy

  Add<A *>("D", ".", new OneOperator1_<double * , A *> (&get_p_D)); // getters in FreeFem

  // We then add the ArrayOfA  class to FreeFem
  Dcl_Type<ArrayOfA*>(InitP<ArrayOfA>,Destroy<ArrayOfA>); // declare a new type in freefem++ 
  zzzfff->Add("classarray",atype<ArrayOfA* >());

  TheOperators->Add("<-", new OneOperator2_<ArrayOfA *, ArrayOfA *, long int >(&init_ArrayOfA1));
	
  Add<ArrayOfA *>("(","",new OneOperator2_<A *, ArrayOfA *, long int>(get_Ai));
}