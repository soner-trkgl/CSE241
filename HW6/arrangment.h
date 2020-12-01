#ifndef ARRANGMENT_H
#define ARRANGMENT_H
#include<iostream>
#include<string>

using namespace std;


namespace System{

	enum Action{
		document = 0,
		slackness ,
		project ,
		lesson ,
		seminar ,
		academicPaper ,
		administration ,
		homeworkTime ,
		homeworkTimeout ,
		incident ,
		solution 
	};

	enum empType{
		lecturer = 0,
		researchAssistant ,
		secretary ,
		officer 
	};

	enum UniType{
		research = 0 ,
		linguistic ,
		technical 
	};

	struct Personal{
		string name ;
		string surname ;
	};

	class Complex{
		public:
			Complex(): value_int(0) , value_double(0.0) {}
			Complex(int value_int , double value_double ) : value_int(value_int) , value_double(value_double) {}
			Complex(int theInt) { value_int = theInt ; }
			Complex( double theDouble) { value_double = theDouble ; }
			int get_int() { return value_int ; }
			int get_double() { return value_double ; }
			void set_int( int theInt ) { value_int = theInt ; }
			void set_double( double theDouble ) { value_double = theDouble ; }
			const Complex operator +(const Complex&)const;
			const Complex operator +(int ) const;
			const Complex operator -(const Complex&)const;
			Complex& operator =(const Complex&);
			Complex& operator =(int theInt) { value_int = theInt ; value_double = (double)theInt ; return *this ;}
			Complex operator ++(int);
			friend ostream& operator <<(ostream& output, const Complex& c);
		private:
			int value_int;
			double value_double;
	};

	class Employee{

		public:
			Employee( int pid , string name , string surname , int happiness ): pid(pid) , name(name) , surname(surname) , happiness(happiness) {}
			Employee( string name , string surname ) : pid(0) , name(name) , surname(surname) , happiness(0)  {}
			Employee() : pid(0) , name("empty") , surname("empty") , happiness(0)  {}
			virtual int work(Action) = 0 ;
			void set_pid( int thePid ) { pid = thePid ; }
			void set_name( string theName ) { name = theName ; }
			void set_surname( string theSurname ) { surname = theSurname ; }
			void set_happiness( int theHapiness ){ happiness = theHapiness ; }
			int get_happiness() { return happiness ; }
			string get_name() { return name ; }
			string get_surname() { return surname ; }
			int get_pid() { return pid ; }
			
		private:
			int pid;
			string name;
			string surname;
			int happiness;
	};
	

	class Lecturer : public Employee{
		public:
			Lecturer( int pid , string name , string surname , int happiness ) : Employee(pid , name , surname , happiness ){}
			Lecturer( string name , string surname ) : Employee( name , surname ){}
			Lecturer() : Employee() {}
			int work( Action theAction );
			void set_pid( int thePid ) { Employee::set_pid( thePid ) ; }
			void set_name( string theName ) { Employee::set_name( theName ) ; }
			void set_surname( string theSurname ) { Employee::set_surname( theSurname ) ; }
			void set_happiness( int theHapiness ) { Employee::set_happiness( theHapiness ) ; }
			int get_happiness() { return Employee::get_happiness() ; }
			string get_name() { return Employee::get_name() ; }
			string get_surname() { return Employee::get_surname() ; }
			int get_pid() { return Employee::get_pid() ;}

	};

	class ResearchAssistant : public Employee{
		public:
			ResearchAssistant( int pid , string name , string surname , int happiness ) : Employee(pid , name , surname , happiness ){}
			ResearchAssistant( string name , string surname ) : Employee( name , surname ){}
			ResearchAssistant() : Employee() {}
			int work( Action theAction );
			void set_pid( int thePid ) { Employee::set_pid( thePid ) ; }
			void set_name( string theName ) { Employee::set_name( theName ) ; }
			void set_surname( string theSurname ) { Employee::set_surname( theSurname ) ; }
			void set_happiness( int theHapiness ) { Employee::set_happiness( theHapiness ) ; }
			int get_happiness() { return Employee::get_happiness() ; }
			string get_name() { return Employee::get_name() ; }
			string get_surname() { return Employee::get_surname() ; }
			int get_pid() { return Employee::get_pid() ;}
	};

	class Secretary : public Employee{
		public:
			Secretary( int pid , string name , string surname , int happiness ) : Employee(pid , name , surname , happiness ){}
			Secretary( string name , string surname ) : Employee( name , surname ){}
			Secretary() : Employee() {}
			int work( Action theAction );
			void set_pid( int thePid ) { Employee::set_pid( thePid ) ; }
			void set_name( string theName ) { Employee::set_name( theName ) ; }
			void set_surname( string theSurname ) { Employee::set_surname( theSurname ) ; }
			void set_happiness( int theHapiness ) { Employee::set_happiness( theHapiness ) ; }
			int get_happiness() { return Employee::get_happiness() ; }
			string get_name() { return Employee::get_name() ; }
			string get_surname() { return Employee::get_surname() ; }
			int get_pid() { return Employee::get_pid() ;}
			
	};

	class Officer : public Employee {
		public:
			Officer( int pid , string name , string surname , int happiness ) : Employee(pid , name , surname , happiness ){}
			Officer( string name , string surname ) : Employee( name , surname ){}
			Officer() : Employee() {}
			int work( Action theAction );
			void set_pid( int thePid ) { Employee::set_pid( thePid ) ; }
			void set_name( string theName ) { Employee::set_name( theName ) ; }
			void set_surname( string theSurname ) { Employee::set_surname( theSurname ) ; }
			void set_happiness( int theHapiness ) { Employee::set_happiness( theHapiness ) ; }
			int get_happiness() { return Employee::get_happiness() ; }
			string get_name() { return Employee::get_name() ; }
			string get_surname() { return Employee::get_surname() ; }
			int get_pid() { return Employee::get_pid() ;}
			
	};

	template<typename T >
	class University{
		public:
			University(): name("empty") , uniEmp(nullptr) , capacity(0) { }
			University(T contribution , string name , Employee* uniEmp , int capacity): contribution(contribution) , name(name) , capacity(capacity){}
			T get_contribution(){ return  contribution ; }
			string get_name() { return name ; }
			Employee** get_uniEmp() { return uniEmp ; }
			int get_capacity() { return capacity ; }
			void set_name( string theName) { name = theName ; }
			void set_contribution( T theContribution){ contribution = theContribution ; }
			void add_uniEmp( Employee* theP ) { 
				if( uniEmp == nullptr){
					uniEmp = &theP ;
					capacity++;
				}
				else{
					Employee** tempUniEmp = new Employee*[capacity + 1 ];
					for( int j = 0; j<capacity; j++){
						tempUniEmp[j] = uniEmp[j] ; 
					}
					tempUniEmp[capacity] = theP;
					uniEmp = tempUniEmp ;
					capacity++;
				}
			}
			string contribute(T theContribution ) { contribution = contribution +  theContribution ; return ( "contribution of uni is"  ) ; }
		private :
			Employee** uniEmp;
			string name;
			int capacity;
			T contribution ;
			
	};

	class YOK{
		public:
			template<class T > University<T>* foundUni( UniType theType ) 
			{ 
				if( theType == research ){
					University<T>* x = new University<T>( 0 , "empty" , nullptr , 0) ; return x ; 
				}
				else if( theType == linguistic ){
					University<T>* x = new University<T>( 0.0 , "empty" , nullptr , 0 ) ; return x ;
				}
				else if( theType == technical ){
					University<T>* x = new University<T> ; return x ;
				}
			}
			Employee* giveJob(string , string , empType );
	};


}


#endif