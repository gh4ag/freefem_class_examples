#include "class_str.hpp"
#include <ff++.hpp>

using namespace Fem2D;

Str * init_Str(Str * const &S, string * const & s2)
{
  if (S->pps !=0){
    if(*(S->pps) !=0){
      delete *(S->pps);
      *(S->pps)=0;
    }
    delete S->pps;
    S->pps=0;
  }
  S->pps =  (string **) new string(); // (string **) new string(); equivalent to new string * [1]();
  *(S->pps) = new string(*s2);
  //cout << "My Str.pps is initialized to:  " << **(S->pps) << endl;
  
  return NULL; // return value never used for now (13.1)
} 

string ** get_pps(Str * const &S){
    return S->pps;
}

class Init { 
	public:
  	Init();
};
Init init;
Init::Init(){

  Dcl_Type<Str*>(InitP<Str>,Destroy<Str>); // declare a new type for freefem++  
  zzzfff->Add("str",atype<Str* >()); // add the Str type to freefem++ 

  TheOperators->Add("<-",new OneOperator2_<Str *, Str *, string * >(&init_Str)); 
  Add<Str *>("pps",".",new OneOperator1_<string **, Str *>(&get_pps) );
}