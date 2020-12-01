#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<ctime>
#include<cstdlib>
#include"arrangment.h"

using namespace std;
using namespace System;

template<class T>															// filling the univesity inside
void fillUni( University<T>* , vector<Personal>& , YOK& );

template<class T>															// perform the action
void doAction( University<T>* );

template<class T>															// show contribution of university and each happiness of employee
void show( University<T>* );



int main(){
	srand(time(NULL));
	YOK y1;												// YOK
	vector<Personal> vPersonal;							// temporary vector keeping information in txt
	
	string readWord ;									
	int count=0 , randNum;

	ifstream inStream;
	inStream.open("personnellist.txt");					// open file


	cout.setf(ios::fixed);								// double precision
	cout.setf(ios::showpoint);
	cout.precision(2);

	if( !inStream.is_open() ){								// reading txt file				
		cout<<"file is not opened"<<endl;																	  
	}
	else{
		inStream>>readWord;
		while( !inStream.eof() ){
			vPersonal.push_back( Personal() );
			vPersonal[count].name = readWord ;
			inStream>>readWord;
			vPersonal[count].surname = readWord ;
			inStream>>readWord;		
			count++;
		}
		if ( count == 1 && readWord == ""){
			cout<<"there is no personal in txt"<<endl;
		}
	}
	
	inStream.close();

	University<int>* uniResearch = y1.foundUni<int>( research ) ;		       // foundation of university
	uniResearch->set_name( "GTU");

	University<double>* uniLinguistic = y1.foundUni<double>( linguistic ) ;    // foundation of university
	uniLinguistic->set_name( "ODTU");

	University<Complex>* uniTechnical = y1.foundUni<Complex>( technical ) ;    // foundation of university
	uniTechnical->set_name( "ITU");
	cout<<"\t\t\t\t Test Scenario 1 "<<endl;
	cout<<"(output)> University GTU is founded "<<endl;					
	cout<<"(output)> University ODTU is founded "<<endl;
	cout<<"(output)> University ITU is founded "<<endl;
	cout<<"\t\t\t\t Test Scenario 2 "<<endl;
	fillUni<int>( uniResearch , vPersonal , y1 );								
	fillUni<double>( uniLinguistic , vPersonal , y1 );
	fillUni<Complex>( uniTechnical , vPersonal , y1 );
	cout<<"\t\t\t\t Test Scenario 3 "<<endl;
	doAction<int>( uniResearch);
	doAction<double>( uniLinguistic);
	doAction<Complex>( uniTechnical);
cout<<"\t\t\t\t Test Scenario 4 "<<endl;
	show<int>( uniResearch );
	show<double>( uniLinguistic);
	show<Complex>( uniTechnical);
	

	

	return 0;
		
}


template<class T>
void fillUni( University<T>* theUni , vector<Personal>& tempPersonal , YOK& tempYOK ){				// university requesting employee , yok give job and university employ employee
	int count = 0;
	int randNum ;
	string job , name , surname ;
	while( count != 10 ){
		randNum = rand() % 4 ;
		if( randNum == lecturer)
			job = "Lecturer";
		else if( randNum == researchAssistant)
			job = "ResearchAssistant";
		else if( randNum == secretary)
			job = "Secretary";
		else if( randNum == officer)
			job = "Officer";
		cout<<"(output)> "<<theUni->get_name()<<" requests "<<job<<"."<<endl;
		randNum = rand() % tempPersonal.size() ;
		name = tempPersonal[randNum].name ;
		surname = tempPersonal[randNum].surname ;
		cout<<"(output)>YOK give job to "<<name<<" "<<surname<<" as "<<job<<"."<<endl;
		cout<<"(output)> "<<theUni->get_name()<<" "<<" employs "<<name<<" "<<surname<<" as "<<job<<"."<<endl;
		if( job == "Lecturer" )
			theUni->add_uniEmp( tempYOK.giveJob( name , surname , lecturer ) );
		else if( job == "ResearchAssistant" )
			theUni->add_uniEmp( tempYOK.giveJob( name , surname , researchAssistant ) );
		else if( job == "Secretary" )
			theUni->add_uniEmp( tempYOK.giveJob( name , surname , secretary ) );
		else if( job == "Officer" )
			theUni->add_uniEmp( tempYOK.giveJob( name , surname , officer ) );
		tempPersonal.erase( tempPersonal.begin() + randNum ) ;
		count++;
	}
}

template<class T>										// showing contribition and happiness
void show( University<T>* theUni){											
	cout<<"(output)> Contribution of "<<theUni->get_name()<<" : "<<theUni->get_contribution()<<endl;
	cout<<"(output)> Employee of "<<theUni->get_name()<<" : "<<endl;
	for( int i = 0; i<theUni->get_capacity() ; i++){
		cout<<"(output)> "<<theUni->get_uniEmp()[i]->get_name()<<" "<<theUni->get_uniEmp()[i]->get_surname()<<" happiness : "<<theUni->get_uniEmp()[i]->get_happiness()<<endl;
	}
}


template<class T>												// perfom the action
void doAction( University<T>* theUni){
	int randNum1 , randNum2 ,count = 0;
	string name ,  surname ;
	T temp;
	while( count != 50){
		randNum1 = rand() % 11 ;
		randNum2 = rand() % theUni->get_capacity();
		if( randNum1 == 0){
			if( theUni->get_uniEmp()[randNum2]->work( document ) == -5 ){

			}
			else{
				temp = theUni->get_uniEmp()[randNum2]->work( document );
				name = theUni->get_uniEmp()[randNum2]->get_name();
				surname = theUni->get_uniEmp()[randNum2]->get_surname();
				cout<<"(Output)> "<<name<<" "<<surname<<" have document. Therefore, "<<name<<" "<<surname<<" makes doc. Happiness of "<<name<<" "<<surname<<" is " ;
				cout<<theUni->get_uniEmp()[randNum2]->get_happiness()<<", "<<theUni->contribute( temp )<<" "<< theUni->get_contribution()<<endl;
				++count;
			}
				                                 
		}
		else if( randNum1 == 1){
			if( theUni->get_uniEmp()[randNum2]->work( slackness ) == -5 ){

			}
			else{
				temp = theUni->get_uniEmp()[randNum2]->work( slackness );
				name = theUni->get_uniEmp()[randNum2]->get_name();
				surname = theUni->get_uniEmp()[randNum2]->get_surname();
				cout<<"(Output)> "<<name<<" "<<surname<<" have slackness. Therefore, "<<name<<" "<<surname<<" drinks tea. Happiness of "<<name<<" "<<surname<<" is " ;
				cout<<theUni->get_uniEmp()[randNum2]->get_happiness()<<", "<<theUni->contribute( temp )<<" "<< theUni->get_contribution()<<endl;
				++count;
			}
		}
		else if( randNum1 == 2){
			if( theUni->get_uniEmp()[randNum2]->work( project ) == -5 ){

			}
			else{
				temp = theUni->get_uniEmp()[randNum2]->work( project );
				name = theUni->get_uniEmp()[randNum2]->get_name();
				surname = theUni->get_uniEmp()[randNum2]->get_surname();
				cout<<"(Output)> "<<name<<" "<<surname<<" have project. Therefore, "<<name<<" "<<surname<<" researchs. Happiness of "<<name<<" "<<surname<<" is " ;
				cout<<theUni->get_uniEmp()[randNum2]->get_happiness()<<", "<<theUni->contribute( temp )<<" "<< theUni->get_contribution()<<endl;
				++count;
			}
		}
		else if( randNum1 == 3){
			if( theUni->get_uniEmp()[randNum2]->work( lesson ) == -5 ){

			}
			else{
				temp = theUni->get_uniEmp()[randNum2]->work( lesson );
				name = theUni->get_uniEmp()[randNum2]->get_name();
				surname = theUni->get_uniEmp()[randNum2]->get_surname();
				cout<<"(Output)> "<<name<<" "<<surname<<" have lesson. Therefore, "<<name<<" "<<surname<<" gives lesson. Happiness of "<<name<<" "<<surname<<" is " ;
				cout<<theUni->get_uniEmp()[randNum2]->get_happiness()<<", "<<theUni->contribute( temp )<<" "<< theUni->get_contribution()<<endl;
				++count;
			}
		}
		else if( randNum1 == 4){
			if( theUni->get_uniEmp()[randNum2]->work( seminar ) == -5 ){

			}
			else{
				temp = theUni->get_uniEmp()[randNum2]->work( seminar );
				name = theUni->get_uniEmp()[randNum2]->get_name();
				surname = theUni->get_uniEmp()[randNum2]->get_surname();
				cout<<"(Output)> "<<name<<" "<<surname<<" have seminar. Therefore, "<<name<<" "<<surname<<" sees successful student. Happiness of "<<name<<" "<<surname<<" is " ;
				cout<<theUni->get_uniEmp()[randNum2]->get_happiness()<<", "<<theUni->contribute( temp )<<" "<< theUni->get_contribution()<<endl;
				++count;
			}
		}
		else if( randNum1 == 5){
			if( theUni->get_uniEmp()[randNum2]->work( academicPaper ) == -5 ){

			}
			else{
				temp = theUni->get_uniEmp()[randNum2]->work( academicPaper );
				name = theUni->get_uniEmp()[randNum2]->get_name();
				surname = theUni->get_uniEmp()[randNum2]->get_surname();
				cout<<"(Output)> "<<name<<" "<<surname<<" have academicPaper. Therefore, "<<name<<" "<<surname<<" makes publish. Happiness of "<<name<<" "<<surname<<" is " ;
				cout<<theUni->get_uniEmp()[randNum2]->get_happiness()<<", "<<theUni->contribute( temp )<<" "<< theUni->get_contribution()<<endl;
				++count;
			}
		}
		else if( randNum1 == 6){
			if( theUni->get_uniEmp()[randNum2]->work( administration ) == -5 ){

			}
			else{
				temp = theUni->get_uniEmp()[randNum2]->work( administration );
				name = theUni->get_uniEmp()[randNum2]->get_name();
				surname = theUni->get_uniEmp()[randNum2]->get_surname();
				cout<<"(Output)> "<<name<<" "<<surname<<" have administration. Therefore, "<<name<<" "<<surname<<" manages process. Happiness of "<<name<<" "<<surname<<" is " ;
				cout<<theUni->get_uniEmp()[randNum2]->get_happiness()<<", "<<theUni->contribute( temp )<<" "<< theUni->get_contribution()<<endl;
				++count;
			}
		}
		else if( randNum1 == 7){
			if( theUni->get_uniEmp()[randNum2]->work( homeworkTime ) == -5 ){

			}
			else{
				temp = theUni->get_uniEmp()[randNum2]->work( homeworkTime );
				name = theUni->get_uniEmp()[randNum2]->get_name();
				surname = theUni->get_uniEmp()[randNum2]->get_surname();
				cout<<"(Output)> "<<name<<" "<<surname<<" have homeworkTime. Therefore, "<<name<<" "<<surname<<" gives HW. Happiness of "<<name<<" "<<surname<<" is " ;
				cout<<theUni->get_uniEmp()[randNum2]->get_happiness()<<", "<<theUni->contribute( temp )<<" "<< theUni->get_contribution()<<endl;
				++count;
			}
		}
		else if( randNum1 == 8){
			if( theUni->get_uniEmp()[randNum2]->work( homeworkTimeout ) == -5 ){

			}
			else{
				temp = theUni->get_uniEmp()[randNum2]->work( homeworkTimeout );
				name = theUni->get_uniEmp()[randNum2]->get_name();
				surname = theUni->get_uniEmp()[randNum2]->get_surname();
				cout<<"(Output)> "<<name<<" "<<surname<<" have homeworkTimeout. Therefore, "<<name<<" "<<surname<<" reads HW. Happiness of "<<name<<" "<<surname<<" is " ;
				cout<<theUni->get_uniEmp()[randNum2]->get_happiness()<<", "<<theUni->contribute( temp )<<" "<< theUni->get_contribution()<<endl;
				++count;
			}
				
		}
		else if( randNum1 == 9){
			if( theUni->get_uniEmp()[randNum2]->work( incident ) == -5 ){

			}
			else{
				temp = theUni->get_uniEmp()[randNum2]->work( incident );
				name = theUni->get_uniEmp()[randNum2]->get_name();
				surname = theUni->get_uniEmp()[randNum2]->get_surname();
				cout<<"(Output)> "<<name<<" "<<surname<<" have incident. Therefore, "<<name<<" "<<surname<<" receives petition. Happiness of "<<name<<" "<<surname<<" is " ;
				cout<<theUni->get_uniEmp()[randNum2]->get_happiness()<<", "<<theUni->contribute( temp )<<" "<< theUni->get_contribution()<<endl;
				++count;
			}
		}
		else if( randNum1 == 10){
			if( theUni->get_uniEmp()[randNum2]->work( solution ) == -5 ){

			}
			else{
				temp = theUni->get_uniEmp()[randNum2]->work( solution );	
				name = theUni->get_uniEmp()[randNum2]->get_name();
				surname = theUni->get_uniEmp()[randNum2]->get_surname();
				cout<<"(Output)> "<<name<<" "<<surname<<" have solution. Therefore, "<<name<<" "<<surname<<" submits petition. Happiness of "<<name<<" "<<surname<<" is " ;
				cout<<theUni->get_uniEmp()[randNum2]->get_happiness()<<", "<<theUni->contribute( temp )<<" "<< theUni->get_contribution()<<endl;
				++count;
			}
				
		}
	}

}