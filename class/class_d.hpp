#ifndef DELTA_CLASS
#define DELTA_CLASS

#include "ff++.hpp" 
#include <iostream>
using namespace Fem2D;

class Delta{
	public:
		// This constructor and destructor have to be implemented only if the class Delta
		// is called in another C++ piece of code (say another class)!
		// Otherwise, these constructor and destructeur are useless for calling just the Delta
		// type from a .edp with FreeFem. Only the init and destroy are called by FreeFem.
		Delta();
		~Delta(){ delete pd; pd=0;} 

		double * pd;


		// Constructor and destructor for FreeFem
		// Question : what is the link with the contructor and destructor of the class ?
		void init() {pd= new double();} 
		void destroy() { delete pd; pd=0;}

		double * get_pd (Delta *D);
		friend ostream& operator<<(ostream& os, const Delta& D);

	private:
		Delta(const Delta &); 
		void operator=(const Delta &);
};

#endif