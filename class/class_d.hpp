#ifndef DELTA_CLASS
#define DELTA_CLASS

#include "ff++.hpp" 
using namespace Fem2D;

class Delta{
	public:
		// constructeur et destruteur inutiles si la classe est appelée dans un .edp avec FreeFem,
		// seul init et destroy sont appelés
		// par contre, ils sont important si on utilise cette classe dans un autre code de C++ compilé
		Delta();
		~Delta(){ delete pd; pd=0;} 

		double * pd;


		// constructeur et destructeur pour FreeFem
		// question : quel rapport avec le constr et dest de classe ?
		void init() {pd= new double();} 
		void destroy() { delete pd; pd=0;}

		double * get_pd (Delta *D){ return D->pd;}

	private:
		Delta(const Delta &); 
		void operator=(const Delta &);
};

#endif