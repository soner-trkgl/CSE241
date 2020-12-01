#include<iostream>
#include<ctime>
#include<cstdlib>
#include"arrangment.h"
#include<string>




namespace University{


	Lecturer::Lecturer(string theName,string theSurname,int thePersonal_id,string theTitle){
		name=theName;
		surname=theSurname;
		personal_id=thePersonal_id;
		title=theTitle;
	}
	Lecturer::Lecturer(){
		name="empty";
		surname="empty";
		personal_id=0;
		title="empty";
	}


	void Lecturer::set_name(string theName){
		name=theName;
	}

	void Lecturer::set_surname(string theSurname){
		surname=theSurname;
	}

	void Lecturer:: set_personal_id(int thePersonal_id){
		personal_id=thePersonal_id;
	}

	void Lecturer::set_title(string theTitle){
		title=theTitle;
	}

	void Lecturer::set_profession(string thProfession){
		int i=0;
		string readWord;
		while( thProfession[i] != '\0' ){
			readWord.clear();
			while( thProfession[i] != '\0' && thProfession[i] != ','){
				readWord += thProfession[i];
				i++;
			}
			if( thProfession[i] != '\0')
				i++;
			profession.push_back( readWord );
		}
	}

	int Lecturer::get_personal_id()const{
		return personal_id;
	}

	vector<Course>& Lecturer::get_vCourses() {
		return vCourses;
	}
	vector<Course>& Lecturer::get_vElective() {
		return vElective;
	}


	void Lecturer::proposeCourse(const string& theString){
		int i=0 , count = 0;
		string readWord;
		while( theString[i] != '\0'){
			readWord.clear();
			while( theString[i] != '\0' && theString[i] != ' '){
				readWord += theString[i];
				i++;
			}
			if( theString[i] != '\0' )
				i++;
		}
		for( unsigned int j=0; j<profession.size(); j++){
			if( profession[j] == readWord ){
				vElective.push_back( Course() );
				readWord.clear();
				i=0;
				while( theString[i] != ' '){
					i++;
				}
				i++;
				while( theString[i] != ' '){
					i++;
				}
				i++;
				vElective[ vElective.size() -1 ].id = vElective.size() ;
				while( theString[i] != ' '){
					readWord += theString[i];
					i++;
				}
				vElective[ vElective.size() - 1].name = readWord;
				i++;
				readWord.clear();
				while( theString[i] != ' '){
					readWord += theString[i] ;
					i++;
				}
				vElective[ vElective.size() - 1].code = stoi( readWord );
				i++;
				readWord.clear();
				while( theString[i] != ' '){
					readWord += theString[i] ;
					i++;
				}
				vElective[ vElective.size() - 1].credit = stoi( readWord );
				i++;
				readWord.clear();
				while( theString[i] != ' '){
					readWord += theString[i] ;
					i++;
				}
				vElective[ vElective.size() - 1].total_hours = stoi( readWord );
				i++;
				readWord.clear();
				while( theString[i] != '\0'){
					readWord += theString[i] ;
					i++;
				}
				vElective[ vElective.size() - 1].field = readWord ;
				vElective[ vElective.size() - 1].isMandatory = false;
				cout<<"DONE!!!"<<endl;
				count++;
			}

		}
		if( count == 0){
			cout<<"Block: field and profession mismatch"<<endl;
		}

				
	}

	void Lecturer::assignCourse( vector <Course>& thevCourse , int getId  ){

		vector<Course> theCopy=thevCourse;
		string word;
		char x;
		int i=0 , count = 1  , number = 0 , del=0 ;
		srand(time(NULL));

		if ( getId == 0){
			
			for(unsigned int j=0 ; j<theCopy.size() ; j++){
				del=0;
				for ( unsigned int k=0; k<profession.size(); k++){
					if ( theCopy[j].field == profession[k] ){
						del++;
					}
				}
				if(del != 1){
					theCopy.erase( theCopy.begin() + j);
					j--;
				}
				
			}
			while( theCopy.size() != 0){
				if( vCourses.size() < 3 ){
					number= rand() % theCopy.size() ;
					word=theCopy[number].field;
					vCourses.push_back( Course( theCopy[number] ) );
					for( unsigned int t=0; t<thevCourse.size(); t++){
						if( thevCourse[t].name == theCopy[number].name )
							thevCourse[t].field += "+";
					}
					for( unsigned int k=0 ; k<theCopy.size() ; k++){
						if( theCopy[k].field == word  ){
							if( profession.size() <= 2){
								word="empty";
								theCopy.erase( theCopy.begin() + number);
								k--;
							}
							else{
								theCopy.erase( theCopy.begin() + k);
								k--;
							}
							
						}
					}
				}
			}
			if( vCourses.size() < 3 ){
				if( vElective.size() < 3 - vCourses.size() ){

					cout<<" ( "<<name<<" "<<surname<<" ) "<<"Mandatory lecture is not sufficient add elective lecture"<<endl;
				}
				else{
					while(  vCourses.size() != 3){
						number= rand() % vElective.size() ;
						vCourses.push_back( Course( vElective[number] ) );
						vElective.erase( vElective.begin() + number);
					}
					cout<<"DONE!!!"<<endl;
				}
				
			}

		}
		else {
			if( vCourses.size() < 3){
				for( unsigned int j=0; j<theCopy.size(); j++){
					if ( theCopy[j].id == getId){
						for( unsigned int k=0; k<profession.size(); k++){
							if( theCopy[j].field == profession[k] ){
								vCourses.push_back( Course( theCopy[j] ) );
								thevCourse[j].field += "+";
								count++;
							}	
						}
						count++;
					}
				}
				if( count == 0 ){
					cout<<"Error: no course"<<endl;
				}
				else if( count == 1){
					cout<<"profession mismatch or already have"<<endl;
				}
				else
					cout<<"DONE!!!"<<endl;

			}
			else{
				cout<<"Lecturer course is full"<<endl;
			}	
			
		}

	}




	void Administrator::arrangeTimeTable(  vector<Lecturer>& thevLecturer , int getId ) const {
		int count=0 , approval=0;
		int hour1,hour2, sumHours = 0;
		string dayC ;
		srand( time(NULL) );
		for( unsigned int i=0; i<thevLecturer.size(); i++){
			if ( thevLecturer[i].get_vCourses().size() != 3 ){
				count++;
			}
		}
		if( count == 0){

			if( getId == 0){
			
				for (unsigned int i=0; i<thevLecturer.size(); i++){
					vector<Course>& copyCourses = thevLecturer[i].get_vCourses();
					for ( unsigned int j = 0; j<copyCourses.size() ; j++){
						if( copyCourses[j].lecture_dates.size() == 0){
							sumHours=0;
							while ( sumHours != copyCourses[j].total_hours ){
								approval=0;
								if( 1 == ( rand() % 5 ) + 1){
									dayC = "Mon";
								}
								else if(2 == ( rand() % 5 ) + 1){
									dayC = "Tue";
								}
								else if(3 == ( rand() % 5 ) + 1){
									dayC = "Wed";
								}
								else if(4 == ( rand() % 5 ) + 1){
									dayC = "Thu";
								}
								else if(5 == ( rand() % 5 ) + 1){
									dayC = "Fri";
								}
								hour1 = ( rand() % ( copyCourses[j].total_hours - sumHours ) ) + 1;
								hour2 = ( rand() % ( 9 - hour1 ) ) +  9  ;
								for ( unsigned int k=0; k<copyCourses.size() ; k++){
									if( copyCourses[k].lecture_dates.size() != 0 ){
										for( unsigned int t=0; t<copyCourses[k].lecture_dates.size(); t++ ){
											if( dayC == copyCourses[k].lecture_dates[t].day ){
												for( int r=hour2; r<hour2+hour1; r++){
													for( int l = copyCourses[k].lecture_dates[t].hourB ; l<copyCourses[k].lecture_dates[t].hourE ; l++){
														if( r == l){
															approval++;
														}
													}
												}
											}
										}	
									}
								}
								if( approval == 0) {
									copyCourses[j].lecture_dates.push_back( date() );
									copyCourses[j].lecture_dates[ copyCourses[j].lecture_dates.size() - 1 ].day = dayC ;
									copyCourses[j].lecture_dates[ copyCourses[j].lecture_dates.size() - 1 ].hourB = hour2;
									copyCourses[j].lecture_dates[ copyCourses[j].lecture_dates.size() - 1 ].hourE = hour2 + hour1;
									sumHours +=  hour1 ;
								}
							}
						}
					}
				}
			}
			else{
				for( unsigned int i=0; i<thevLecturer.size(); i++ ){
					vector<Course>& copyCourses = thevLecturer[i].get_vCourses();
					for ( unsigned int j = 0; j<copyCourses.size() ; j++){
						if( copyCourses[j].id == getId ){
							if( copyCourses[j].lecture_dates.size() == 0 ){
								sumHours=0;
								while ( sumHours == copyCourses[j].total_hours ){
									approval=0;
									if( 1 == ( rand() % 5 ) + 1){
										dayC = "Mon";
									}
									else if(2 == ( rand() % 5 ) + 1){
										dayC = "Tue";
									}
									else if(3 == ( rand() % 5 ) + 1){
										dayC = "Wed";
									}
									else if(4 == ( rand() % 5 ) + 1){
										dayC = "Thu";
									}
									else if(5 == ( rand() % 5 ) + 1){
										dayC = "Fri";
									}
									hour1 = ( rand() % ( copyCourses[j].total_hours - sumHours ) ) + 1;
									hour2 = ( rand() % ( 9 - hour1 ) ) +  9  ;
									for ( unsigned int k=0; k<copyCourses.size() ; k++){
										if( copyCourses[k].lecture_dates.size() != 0 ){
											for( unsigned int t=0; t<copyCourses[k].lecture_dates.size(); t++ ){
												if( dayC == copyCourses[k].lecture_dates[t].day ){
													for( int r=hour2; r<hour2+hour1; r++){
														for( int l = copyCourses[k].lecture_dates[t].hourB ; l<copyCourses[k].lecture_dates[t].hourE ; l++){
															if( r == l){
																approval++;
															}
														}
													}
												}
											}	
										}
									}
									if( approval == 0) {
										copyCourses[j].lecture_dates.push_back( date() );
										copyCourses[j].lecture_dates[ copyCourses[j].lecture_dates.size() - 1 ].day = dayC ;
										copyCourses[j].lecture_dates[ copyCourses[j].lecture_dates.size() - 1 ].hourB = hour2;
										copyCourses[j].lecture_dates[ copyCourses[j].lecture_dates.size() - 1 ].hourE = hour2 + hour1;
										sumHours +=  hour1 ;
										cout<<"DONE!!!"<<endl;
									}
								}
							}
							else{
								cout<<"Assigned before ("<<getId<<") "<<copyCourses[j].name<<" ";
								for(unsigned int k =0; k< copyCourses[j].lecture_dates.size(); k++){
									cout<<copyCourses[j].lecture_dates[k].day<<"_";
									cout<<copyCourses[j].lecture_dates[k].hourB<<"-"<<copyCourses[j].lecture_dates[k].hourB;
									if( k>1)
										cout<<",";
								}
							}
						}

					}
				}
				if ( count == 0 ){
					cout<<"Error: no course"<<endl;
				}

			}


		}
		else {
			cout<<"lecture  have not  assigned yet "<<endl;
		}



	}

	void Administrator::arrangeClassroom( vector<Lecturer>& thevLecturer , const  vector<Classroom>& thevClassroom , int getId , string getC1  , string getC2  )const{
		srand( time(NULL));
		int number , search=0 ,flag = 0;
		int count = 0;
		for ( unsigned int i = 0; i<thevLecturer.size() ; i++){
			for( unsigned int j=0; j<thevLecturer[i].get_vCourses().size( ); j++)
			{
				if( thevLecturer[i].get_vCourses()[j].lecture_dates.size() == 0 ){
					count++;
				}
			}
			if( thevLecturer[i].get_vCourses().size() == 0 ){
				count++;
			}
			
		}
		
		if ( count == 0){
			if( getId == 0 ){
				for( unsigned int i = 0 ; i<thevLecturer.size(); i++){
					number = rand() %  thevClassroom.size() + 1;
					for( unsigned int j=0; j<thevLecturer[j].get_vCourses().size(); j++){
						if( thevLecturer[i].get_vCourses()[j].c_name.size() == 0){
							thevLecturer[i].get_vCourses()[j].c_name.push_back( thevClassroom[number].c_no );
						}
					}
				}
			}
			else{
				if( getC2 == ""){
					for( unsigned int i =0; i<thevLecturer.size(); i++){
						if( thevLecturer[i].get_personal_id() != getId){
							search++;
						}

					}
					for( unsigned int i=0; i<thevClassroom.size(); i++){
						if( thevClassroom[i].c_no != getC1 ){
							search++;
						}
					}
					if( search != 0){
						cout<<"Error: no class or no course"<<endl;
					}
				}
			}

		}
		else{
			cout<<"timetable not arranged yet"<<endl;
		}

	}

}