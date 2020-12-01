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
		HomeworkTime ,
		homeworkTimeout ,
		incident ,
		solution ,
	};

	class University{
		public:
			University(int contribution): contribution(contribution){}
			University():contribution(0){}
			int get_contribution(){ return  contribution ; }
			void set_contribution( int theContribution){ contribution = theContribution ; }
		private :
			int contribution ;

	};

	class Employee{

		public:
			Employee( int pid , string name , string surname , int happiness , University* Uni): pid(pid) , name(name) , surname(surname) , Uni(Uni) {}
			Employee( int pid , string name , string surname ) : pid(pid) , name(name) , surname(surname) , happiness(0) , Uni(nullptr) {}
			Employee() : pid(0) , name("empty") , surname("empty") , happiness(0) , Uni(nullptr) {}
			void set_happiness( int theHapiness ){ happiness = theHapiness ; }
			int get_happiness() { return happiness ; }
			string get_name() { return name ; }
			string get_surname() { return surname ; }
			University* get_Uni() { return Uni ; }
			void drinkTea(){ if(Uni != nullptr){ Uni->set_contribution( Uni->get_contribution() + -2) ; happiness +=5 ; } }
			void submitPetition() { if(Uni != nullptr){ Uni->set_contribution( Uni->get_contribution() + -2) ; happiness +=1 ; } }
			int employ(University* theUni ) { if( theUni != nullptr ){ if( Uni == nullptr ){ Uni = theUni ; return 1;}else return 0 ; }else{ cout<<"the University is not available"<<endl ; } }

		private:
			int pid;
			string name;
			string surname;
			int happiness;
			University* Uni ;
	};
	

	class Lecturer : Employee{
		public:
			Lecturer( int pid , string name , string surname ) : Employee(pid , name , surname ){}
			Lecturer() : Employee() {}
			int get_happiness() { return Employee::get_happiness() ; }
			string get_name() { return Employee::get_name() ; }
			string get_surname() { return Employee::get_surname() ; }
			University* get_Uni() { return Employee::get_Uni() ; }
			void drinkTea() { Employee::drinkTea() ; }
			void submitPetition() { Employee::submitPetition() ; }
			void giveLesson() { if( get_Uni() != nullptr){ get_Uni()->set_contribution( get_Uni()->get_contribution() + 5) ; set_happiness( get_happiness() + 1 ) ; } }
			void seeSuccessfulStudent() { if(get_Uni() != nullptr){ get_Uni()->set_contribution( get_Uni()->get_contribution() ) ; set_happiness( get_happiness() + 10 ) ; } }
			void makePublish() { if(get_Uni() != nullptr){ get_Uni()->set_contribution( get_Uni()->get_contribution() + 5) ; set_happiness( get_happiness() + 2 ) ; } }
			void giveHW() { if(get_Uni() != nullptr){ get_Uni()->set_contribution( get_Uni()->get_contribution() + 1) ; set_happiness( get_happiness() - 2 ) ; } }
			int employ( University* theUni) { return Employee::employ(theUni) ;}


	};

	class ResearchAssistant : Employee{
		public:
			ResearchAssistant( int pid , string name , string surname ) : Employee(pid , name , surname ){}
			ResearchAssistant() : Employee() {}
			int get_happiness() { return Employee::get_happiness() ; }
			string get_name() { return Employee::get_name() ; }
			string get_surname() { return Employee::get_surname() ; }
			University* get_Uni() { return Employee::get_Uni() ; }
			void drinkTea() { Employee::drinkTea() ; }
			void submitPetition() { Employee::submitPetition() ; }
			void research() { if(get_Uni() != nullptr){ get_Uni()->set_contribution( get_Uni()->get_contribution() + 4) ; set_happiness( get_happiness() + 3 ) ; } }
			void seeSuccessfulStudent() { if(get_Uni() != nullptr){ get_Uni()->set_contribution( get_Uni()->get_contribution() ) ; set_happiness( get_happiness() + 10 ) ; } }
			void makePublish() { if(get_Uni() != nullptr){ get_Uni()->set_contribution( get_Uni()->get_contribution() + 5) ; set_happiness( get_happiness() + 2 ) ; } }
			void readHW() { if(get_Uni() != nullptr){ get_Uni()->set_contribution( get_Uni()->get_contribution() + 2) ; set_happiness( get_happiness() - 3 ) ; } }
			int employ( University* theUni) { return Employee::employ(theUni) ;}
	};

	class Secretary : Employee{
		public:
			Secretary( int pid , string name , string surname ) : Employee(pid , name , surname ){}
			Secretary() : Employee() {}
			int get_happiness() { return Employee::get_happiness() ; }
			string get_name() { return Employee::get_name() ; }
			string get_surname() { return Employee::get_surname() ; }
			University* get_Uni() { return Employee::get_Uni() ; }
			void drinkTea() { Employee::drinkTea() ; }
			void submitPetition() { Employee::submitPetition() ; }
			void manageProcess() { if(get_Uni() != nullptr){ get_Uni()->set_contribution( get_Uni()->get_contribution() + 2) ; set_happiness( get_happiness() - 1 ) ; } }
			void receivePetition() { if(get_Uni() != nullptr){ get_Uni()->set_contribution( get_Uni()->get_contribution() - 1) ; set_happiness( get_happiness() - 1 ) ; } }
			int employ( University* theUni) { return Employee::employ(theUni) ;}
	};

	class Officer : Employee {
		public:
			Officer( int pid , string name , string surname ) : Employee(pid , name , surname ){}
			Officer() : Employee() {}
			int get_happiness() { return Employee::get_happiness() ; }
			string get_name() { return Employee::get_name() ; }
			string get_surname() { return Employee::get_surname() ; }
			University* get_Uni() { return Employee::get_Uni() ; }
			void drinkTea() { Employee::drinkTea() ; }
			void submitPetition() { Employee::submitPetition() ; }
			void makeDoc(){ if(get_Uni() != nullptr){ get_Uni()->set_contribution( get_Uni()->get_contribution() + 3) ; set_happiness( get_happiness() - 2 ) ; } }
			void manageProcess() { if(get_Uni() != nullptr){ get_Uni()->set_contribution( get_Uni()->get_contribution() + 2) ; set_happiness( get_happiness() - 1 ) ; } }
			int employ( University* theUni) { return Employee::employ(theUni) ;}
	};


}


#endif