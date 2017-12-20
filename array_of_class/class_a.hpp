#ifndef A_CLASS
#define A_CLASS

#include "ff++.hpp" 
#include <vector>
using namespace Fem2D;

class A{
	public:
		// constructeur et destruteur inutiles si la classe est appelée dans un .edp avec FreeFem,
		// seul init et destroy sont appelés
		// par contre, ils sont important si on utilise cette classe dans un autre code de C++ compilé
		//A();
		A(){p_D= new double(); }
		~A() {
	   		if(p_D){delete p_D; p_D=0;}
	   	} 

		double * p_D; 

		// constructeur et destructeur pour FreeFem
		// question : quel rapport avec le constr et dest de classe ?
		void init(){ 
			p_D = new double();
		} 
		void destroy() { 
	   		if(p_D){delete p_D; p_D=0;}
		}
		double * get_p_D (){ return p_D;}

		A& operator=(A const &S){
			if (this != &S){
				this->~A();
				p_D = new double(*S.p_D);
			}	
			return *this;
		}

		A& operator=(A * const &S){
			if (this != S){
				this->~A();
				p_D = new double(*S->p_D);
			}	
			return *this;
		}

		A(A * const & S){
			*this = *S;
		};

		A(A  const & S){
			*this = S;
		};

		//void operator=(const A &); // to put in private to prevent assignment by copy
};

class ArrayOfA{
public:
	
	long int ns;
	A * S;

	ArrayOfA() : ns(0){
		S = new A [0] ();
	}

	ArrayOfA(const ArrayOfA& a) :ns(a.ns), S(new A[a.ns]) { operator=(a);}

	ArrayOfA(long int n) : ns(n), S(new A[n]) { 
		cout << "Here it goes!" << endl;
	} 

	~ArrayOfA() {
		if(S){delete[] S; S=0;}
	}

	ArrayOfA& operator=(ArrayOfA const &a) {
		assert(ns==a.ns);
		for(int i=0;i<ns;i++) 
			S[i]=a.S[i];
		return *this;
	}

	A & operator[](int i) const {
		assert(i>=0 && i <ns);
		return S[i];
	}
	ArrayOfA operator+(ArrayOfA const &a) const;
	ArrayOfA operator*(A &a) const ;

	void init(){ 
			//cout << "Init of species" << endl;
			cout << "ArrayfOfA default constructor!" << endl;
			ns = 0;
			S = new A [0] ();
		} 

	void init(int long const &n){ 
			//cout << "Init of species" << endl;
			cout << "ArrayfOfA constructor with int!" << endl;
			assert(n >=0);
			ns = n;
			S = new A [ns] ();
			for (long int i=0; i<ns; i++){
				S[i] = A();
			}
		}
	void destroy() {
		if(S){delete[] S; S=0;}
	}

};

#endif