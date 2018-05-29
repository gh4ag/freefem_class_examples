#ifndef STR_CLASS
#define STR_CLASS

#include "ff++.hpp" 
using namespace Fem2D;

class Str{
	public:
	// This constructor and destructor have to be implemented only if the class Delta
		// is called in another C++ piece of code (say another class)!
		// Otherwise, these constructor and destructeur are useless for calling just the Delta
		// type from a .edp with FreeFem. Only the init and destroy are called by FreeFem.
		Str(); // Sufficient for FreeFem that calls void init() (cf. class_str.cpp)
		// otherwise, one should write : Str(){pps = new string * [1]();}; 
		~Str() {delete* pps; pps=0; delete pps; pps=0; }

		string ** pps;

		// Constructor and destructor for FreeFem
		// Question : what is the link with the contructor and destructor of the class ?
		void init() {pps = new string * [1](); }  
		void destroy() {delete* pps; *pps=0; delete pps; pps=0; }

		//string ** get_pps(){ return pps;}

	private:
		Str(const Str &); 
		void operator=(const Str &);
};

#endif