#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<ctime>
#include<cstdlib>
#include"arrangment.h"

using namespace std;
using namespace System;


int main(){
	srand(time(NULL));
	University u1 ;											// initializing the vector variable
	vector<Lecturer> vLecturer;
	vector<ResearchAssistant> vResearchAssistant;
	vector<Secretary> vSecretary ; 
	vector<Officer> vOfficer ;
	string readWord , readName , readSurname;
	int count=1 , randNum;

	ifstream inStream;
	inStream.open("personnellist.txt");


	if( !inStream.is_open() ){										// reading the txt file and create object 			
		cout<<"file is not opened"<<endl;																	  
	}
	else{
		while( !inStream.eof() ){
			inStream>>readWord;
			if(readWord == "Lecturer"){
				inStream>>readWord;
				readName = readWord ;
				inStream>>readWord;
				readSurname = readWord ;
				vLecturer.push_back( Lecturer(count , readName , readSurname) );
			}
			else if( readWord == "ResearchAssistant"){
				inStream>>readWord;
				readName = readWord ;
				inStream>>readWord;
				readSurname = readWord ;
				vResearchAssistant.push_back( ResearchAssistant(count , readName , readSurname) );
			}
			else if( readWord == "Secretary"){
				inStream>>readWord;
				readName = readWord ;
				inStream>>readWord;
				readSurname = readWord ;
				vSecretary.push_back( Secretary(count , readName , readSurname) );
			}
			else if( readWord == "Officer"){
				inStream>>readWord;
				readName = readWord ;
				inStream>>readWord;
				readSurname = readWord ;
				vOfficer.push_back( Officer(count , readName , readSurname) );
			}
			else{
				if( !inStream.eof() ){
					cout<<"Personal job is wrong in txt file "<<endl;
				}
				
			}			
			count++;
		}
		if ( count == 1){
			cout<<"there is no employee in txt"<<endl;
		}
	}
	
	inStream.close();
	count = 0;
	cout<<"(Output)> "<<"Program choose the this employee : "<<endl;
	while( count != 10 ){																// choose randomly 10 employee
		randNum = rand() % 4 ;
		if(randNum == 0){
			randNum = rand() % vLecturer.size() ;
			if( vLecturer[randNum].employ( &u1 ) ){
				cout<<"(Output)> "<<"Lecturer "<<vLecturer[randNum].get_name()<<" "<<vLecturer[randNum].get_name()<<endl;
				count++;
			}
		}
		else if( randNum == 1){
			randNum = rand() % vResearchAssistant.size() ;
			if( vResearchAssistant[randNum].employ( &u1 ) ){
				cout<<"(Output)> "<<"ResearchAssistant "<<vResearchAssistant[randNum].get_name()<<" "<<vResearchAssistant[randNum].get_surname()<<endl;
				count++;
			}
		}
		else if( randNum == 2){
			randNum = rand() % vSecretary.size() ;
			if( vSecretary[randNum].employ( &u1 ) ){
				cout<<"(Output)> "<<"Secretary "<<vSecretary[randNum].get_name()<<" "<<vSecretary[randNum].get_surname()<<endl;
				count++;
			}
		}
		else if( randNum == 3){
			randNum = rand() % vOfficer.size() ;
			if( vOfficer[randNum].employ( &u1 ) ){
				cout<<"(Output)> "<<"Officer "<<vOfficer[randNum].get_name()<<" "<<vOfficer[randNum].get_surname()<<endl;
				count++;
			}
		}
	}
	count = 0 ;
	while( count != 50){													// choose the 50 action randomly
		randNum = rand() % 11 ;
		switch( randNum ){
			case document :
				randNum = rand() % vOfficer.size() ;
				if( vOfficer[randNum].get_Uni() != nullptr ){
					vOfficer[randNum].makeDoc();
					cout<<"(Output)> "<<vOfficer[randNum].get_name()<<" have document.Therefore, "<<vOfficer[randNum].get_name()<<" makes DOC.Happiness of ";
					cout<<vOfficer[randNum].get_name()<<" is "<<vOfficer[randNum].get_happiness()<<", contribution of uni is "<<vOfficer[randNum].get_Uni()->get_contribution();
					cout<<endl;
					count++ ;
				}
				break;
			case slackness :
				randNum = rand() % 4 ;
				if(randNum == 0){
					randNum = rand() % vLecturer.size() ;
					if( vLecturer[randNum].get_Uni() != nullptr ){
						vLecturer[randNum].drinkTea() ;
						cout<<"(Output)> "<<vLecturer[randNum].get_name()<<" have slackness.Therefore, "<<vLecturer[randNum].get_name()<<" drinks tea.Happiness of ";
						cout<<vLecturer[randNum].get_name()<<" is "<<vLecturer[randNum].get_happiness()<<", contribution of uni is "<<vLecturer[randNum].get_Uni()->get_contribution();
						cout<<endl;
						count++;
					}
				}
				else if( randNum == 1){
					randNum = rand() % vResearchAssistant.size() ;
					if( vResearchAssistant[randNum].get_Uni() != nullptr ){
						vResearchAssistant[randNum].drinkTea( );
						cout<<"(Output)> "<<vResearchAssistant[randNum].get_name()<<" have slackness.Therefore, "<<vResearchAssistant[randNum].get_name()<<" drinks tea.Happiness of ";
						cout<<vResearchAssistant[randNum].get_name()<<" is "<<vResearchAssistant[randNum].get_happiness()<<", contribution of uni is ";
						cout<<vResearchAssistant[randNum].get_Uni()->get_contribution()<<endl;
						count++;
					}
				}
				else if( randNum == 2){
					randNum = rand() % vSecretary.size() ;
					if( vSecretary[randNum].get_Uni() != nullptr ){
						vSecretary[randNum].drinkTea();
						cout<<"(Output)> "<<vSecretary[randNum].get_name()<<" have slackness.Therefore, "<<vSecretary[randNum].get_name()<<" drinks tea.Happiness of ";
						cout<<vSecretary[randNum].get_name()<<" is "<<vSecretary[randNum].get_happiness()<<", contribution of uni is "<<vSecretary[randNum].get_Uni()->get_contribution();
						cout<<endl;
						count++;
					}
				}
				else if( randNum == 3){
					randNum = rand() % vOfficer.size() ;
					if( vOfficer[randNum].get_Uni() != nullptr ){
						vOfficer[randNum].drinkTea();
						cout<<"(Output)> "<<vOfficer[randNum].get_name()<<" have slackness.Therefore, "<<vOfficer[randNum].get_name()<<" drinks tea.Happiness of ";
						cout<<vOfficer[randNum].get_name()<<" is "<<vOfficer[randNum].get_happiness()<<", contribution of uni is "<<vOfficer[randNum].get_Uni()->get_contribution();
						cout<<endl;
						count++;
					}
				}
				break;
			case project :
				randNum = rand() % vResearchAssistant.size() ;
				if( vResearchAssistant[randNum].get_Uni() != nullptr ){
					vResearchAssistant[randNum].research();
					cout<<"(Output)> "<<vResearchAssistant[randNum].get_name()<<" have project.Therefore, "<<vResearchAssistant[randNum].get_name()<<" researchs.Happiness of ";
					cout<<vResearchAssistant[randNum].get_name()<<" is "<<vResearchAssistant[randNum].get_happiness()<<", contribution of uni is ";
					cout<<vResearchAssistant[randNum].get_Uni()->get_contribution()<<endl;
					count++ ;
				}
				break;
			case lesson:
				randNum = rand() % vLecturer.size() ;
				if( vLecturer[randNum].get_Uni() != nullptr ){
					vLecturer[randNum].giveLesson();
					cout<<"(Output)> "<<vLecturer[randNum].get_name()<<" have lesson.Therefore, "<<vLecturer[randNum].get_name()<<" gives lesson.Happiness of ";
					cout<<vLecturer[randNum].get_name()<<" is "<<vLecturer[randNum].get_happiness()<<", contribution of uni is "<<vLecturer[randNum].get_Uni()->get_contribution();
					cout<<endl;
					count++ ;
				}
				break;
			case seminar :
				randNum = rand() % 2 ;
				if( randNum == 0){
					randNum = rand() % vLecturer.size() ;
					if( vLecturer[randNum].get_Uni() != nullptr ){
						vLecturer[randNum].seeSuccessfulStudent() ;
						cout<<"(Output)> "<<vLecturer[randNum].get_name()<<" have seminar.Therefore, "<<vLecturer[randNum].get_name()<<" see successful student.Happiness of ";
						cout<<vLecturer[randNum].get_name()<<" is "<<vLecturer[randNum].get_happiness()<<", contribution of uni is "<<vLecturer[randNum].get_Uni()->get_contribution();
						cout<<endl;
						count++;
					}
				}
				else if( randNum == 1){
					randNum = rand() % vResearchAssistant.size() ;
					if( vResearchAssistant[randNum].get_Uni() != nullptr ){
						vResearchAssistant[randNum].seeSuccessfulStudent( );
						cout<<"(Output)> "<<vResearchAssistant[randNum].get_name()<<" have seminar.Therefore, "<<vResearchAssistant[randNum].get_name()<<" see successful student.Happiness of ";
						cout<<vResearchAssistant[randNum].get_name()<<" is "<<vResearchAssistant[randNum].get_happiness()<<", contribution of uni is ";
						cout<<vResearchAssistant[randNum].get_Uni()->get_contribution()<<endl;
						count++;
					}
				}
				break;
			case academicPaper :
				randNum = rand() % 2 ;
				if( randNum == 0){
					randNum = rand() % vLecturer.size() ;
					if( vLecturer[randNum].get_Uni() != nullptr ){
						vLecturer[randNum].makePublish() ;
						cout<<"(Output)> "<<vLecturer[randNum].get_name()<<" have academicPaper.Therefore, "<<vLecturer[randNum].get_name()<<" makes publish.Happiness of ";
						cout<<vLecturer[randNum].get_name()<<" is "<<vLecturer[randNum].get_happiness()<<", contribution of uni is "<<vLecturer[randNum].get_Uni()->get_contribution();
						cout<<endl;
						count++;
					}
				}
				else if( randNum == 1){
					randNum = rand() % vResearchAssistant.size() ;
					if( vResearchAssistant[randNum].get_Uni() != nullptr ){
						vResearchAssistant[randNum].makePublish( );
						cout<<"(Output)> "<<vResearchAssistant[randNum].get_name()<<" have academicPaper.Therefore, "<<vResearchAssistant[randNum].get_name()<<"  makes publish.Happiness of ";
						cout<<vResearchAssistant[randNum].get_name()<<" is "<<vResearchAssistant[randNum].get_happiness()<<", contribution of uni is ";
						cout<<vResearchAssistant[randNum].get_Uni()->get_contribution()<<endl;
						count++;
					}
				}
				break;
			case administration :
				randNum = rand() % 2 ;
				if( randNum == 0){
					randNum = rand() % vSecretary.size() ;
					if( vSecretary[randNum].get_Uni() != nullptr ){
						vSecretary[randNum].manageProcess() ;
						cout<<"(Output)> "<<vSecretary[randNum].get_name()<<" have administration.Therefore, "<<vSecretary[randNum].get_name()<<" manage process.Happiness of ";
						cout<<vSecretary[randNum].get_name()<<" is "<<vSecretary[randNum].get_happiness()<<", contribution of uni is "<<vSecretary[randNum].get_Uni()->get_contribution();
						cout<<endl;
						count++;
					}
				}
				else if( randNum == 1){
					randNum = rand() % vOfficer.size() ;
					if( vOfficer[randNum].get_Uni() != nullptr ){
						vOfficer[randNum].manageProcess( );
						cout<<"(Output)> "<<vOfficer[randNum].get_name()<<" have administration.Therefore, "<<vOfficer[randNum].get_name()<<" manage process.Happiness of ";
						cout<<vOfficer[randNum].get_name()<<" is "<<vOfficer[randNum].get_happiness()<<", contribution of uni is "<<vOfficer[randNum].get_Uni()->get_contribution();
						cout<<endl;
						count++;
					}
				}
				break;
			case HomeworkTime :
				randNum = rand() % vLecturer.size() ;
				if( vLecturer[randNum].get_Uni() != nullptr ){
					vLecturer[randNum].giveHW();
					cout<<"(Output)> "<<vLecturer[randNum].get_name()<<" have HomeworkTime.Therefore, "<<vLecturer[randNum].get_name()<<" gives HW.Happiness of ";
					cout<<vLecturer[randNum].get_name()<<" is "<<vLecturer[randNum].get_happiness()<<", contribution of uni is "<<vLecturer[randNum].get_Uni()->get_contribution();
					cout<<endl;
					count++ ;
				}
				break;
			case homeworkTimeout :
				randNum = rand() % vResearchAssistant.size() ;
				if( vResearchAssistant[randNum].get_Uni() != nullptr ){
					vResearchAssistant[randNum].readHW();
					cout<<"(Output)> "<<vResearchAssistant[randNum].get_name()<<" have homeworkTimeout.Therefore, "<<vResearchAssistant[randNum].get_name()<<" reads HW.Happiness of ";
					cout<<vResearchAssistant[randNum].get_name()<<" is "<<vResearchAssistant[randNum].get_happiness()<<", contribution of uni is ";
					cout<<vResearchAssistant[randNum].get_Uni()->get_contribution()<<endl;
					count++ ;
				}
				break;
			case incident :
				randNum = rand() % vSecretary.size() ;
				if( vSecretary[randNum].get_Uni() != nullptr ){
					vSecretary[randNum].receivePetition();
					cout<<"(Output)> "<<vSecretary[randNum].get_name()<<" have incident.Therefore, "<<vSecretary[randNum].get_name()<<" receives petition.Happiness of ";
					cout<<vSecretary[randNum].get_name()<<" is "<<vSecretary[randNum].get_happiness()<<", contribution of uni is "<<vSecretary[randNum].get_Uni()->get_contribution();
					cout<<endl;
					count++ ;
				}
				break;
			case solution :
				randNum = rand() % 4 ;
				if(randNum == 0){
					randNum = rand() % vLecturer.size() ;
					if( vLecturer[randNum].get_Uni() != nullptr ){
						vLecturer[randNum].submitPetition() ;
						cout<<"(Output)> "<<vLecturer[randNum].get_name()<<" have solution.Therefore, "<<vLecturer[randNum].get_name()<<" submits petition.Happiness of ";
						cout<<vLecturer[randNum].get_name()<<" is "<<vLecturer[randNum].get_happiness()<<", contribution of uni is "<<vLecturer[randNum].get_Uni()->get_contribution();
						cout<<endl;
						count++;
					}
				}
				else if( randNum == 1){
					randNum = rand() % vResearchAssistant.size() ;
					if( vResearchAssistant[randNum].get_Uni() != nullptr ){
						vResearchAssistant[randNum].submitPetition( );
						cout<<"(Output)> "<<vResearchAssistant[randNum].get_name()<<" have solution.Therefore, "<<vResearchAssistant[randNum].get_name()<<" submits petition.Happiness of ";
						cout<<vResearchAssistant[randNum].get_name()<<" is "<<vResearchAssistant[randNum].get_happiness()<<", contribution of uni is ";
						cout<<vResearchAssistant[randNum].get_Uni()->get_contribution()<<endl;
						count++;
					}
				}
				else if( randNum == 2){
					randNum = rand() % vSecretary.size() ;
					if( vSecretary[randNum].get_Uni() != nullptr ){
						vSecretary[randNum].submitPetition();
						cout<<"(Output)> "<<vSecretary[randNum].get_name()<<" have solution.Therefore, "<<vSecretary[randNum].get_name()<<" submits petition.Happiness of ";
						cout<<vSecretary[randNum].get_name()<<" is "<<vSecretary[randNum].get_happiness()<<", contribution of uni is "<<vSecretary[randNum].get_Uni()->get_contribution();
						cout<<endl;
						count++;
					}
				}
				else if( randNum == 3){
					randNum = rand() % vOfficer.size() ;
					if( vOfficer[randNum].get_Uni() != nullptr ){
						vOfficer[randNum].submitPetition();
						cout<<"(Output)> "<<vOfficer[randNum].get_name()<<" have solution.Therefore, "<<vOfficer[randNum].get_name()<<" submits petition.Happiness of ";
						cout<<vOfficer[randNum].get_name()<<" is "<<vOfficer[randNum].get_happiness()<<", contribution of uni is "<<vOfficer[randNum].get_Uni()->get_contribution();
						cout<<endl;
						count++;
					}
				}
				break;
			default:
				break;
				
		}

	}



	return 0;
		
}