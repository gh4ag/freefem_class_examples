#ifndef STR_CLASS
#define STR_CLASS

#include "ff++.hpp" 
using namespace Fem2D;

class Str{
	public:
		// constructeur et destruteur inutiles si la classe est appelée dans un .edp avec FreeFem,
		// seul init et destroy sont appelés
		// par contre, ils sont important si on utilise cette classe dans un autre code de C++ compilé
		Str(); // suffisant pour FreeFem qui appel void init() (cf. class_str.cpp)
		// autrement, il faudrait écrire : Str(){pps = new string * [1]();}; 
		~Str() {delete* pps; pps=0; delete pps; pps=0; }

		string ** pps;

		// constructeur et destructeur pour FreeFem
		// question : quel rapport avec le constr et dest de classe ?
		void init() {pps = new string * [1](); }  
		void destroy() {delete* pps; *pps=0; delete pps; pps=0; }

		//string ** get_pps(){ return pps;}

	private:
		Str(const Str &); 
		void operator=(const Str &);
};

#endif