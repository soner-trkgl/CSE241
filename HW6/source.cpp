#include"arrangment.h"


namespace System{

	const Complex Complex::operator +(const Complex& c2)const{
		int tempInt = value_int + c2.value_int ;
		int tempDouble = value_double + c2.value_double ;
		return Complex( tempInt , tempDouble ) ;		
	}
	const Complex Complex::operator +(int theInt )const{
		int tempInt = value_int + theInt ;
		int tempDouble = value_double + (double) theInt ;
		return Complex( tempInt , tempDouble ) ;		
	}

	const Complex Complex::operator -(const Complex& c2)const{
		int tempInt = value_int - c2.value_int ;
		int tempDouble = value_double - c2.value_double ;
		return Complex( tempInt , tempDouble ) ;		
	}

	Complex& Complex::operator =( const Complex& c2){
		value_int = c2.value_int ;
		value_double = c2.value_double ;
		return *this;
	}

	Complex Complex::operator ++(int garbage){
		int tempInt = value_int ;
		double tempDouble = value_double ;
		value_int ++;
		value_double ++ ;
		return Complex(tempInt , tempDouble ); 
	}

	ostream& operator <<( ostream& output , const Complex& c ){
		output<<c.value_int<<" "<<c.value_double;
		return output;
	}

	Employee* YOK::giveJob( string theName , string theSurname , empType theType ){
		static int i = 1 ;
		if( theType == lecturer )
			return new Lecturer( i , theName , theSurname , 0 ) ;
		else if( theType == researchAssistant )
			return new ResearchAssistant( i , theName , theSurname , 0 ) ;
		else if( theType == secretary )
			return new Secretary( i , theName , theSurname , 0 ) ;
		else if( theType == officer )
			return new Officer( i , theName , theSurname , 0 ) ;
		i++;
	}

	int Lecturer::work( Action theAction ){
		if( theAction == document || theAction == project || theAction == administration || theAction == homeworkTimeout || theAction== incident ){
			return -5;
		}
		else if( theAction == slackness){
			Employee::set_happiness( Employee::get_happiness() + 5 );
			return -2 ;
		}
		else if( theAction == lesson){
			Employee::set_happiness( Employee::get_happiness() + 1 );
			return 5 ;
		}
		else if( theAction == seminar ){
			Employee::set_happiness( Employee::get_happiness() + 10 );
			return 0 ;
		}
		else if( theAction == academicPaper ){
			Employee::set_happiness( Employee::get_happiness() + 2 );
			return 5 ;
		}
		else if( theAction == homeworkTime ){
			Employee::set_happiness( Employee::get_happiness() + - 2 );
			return 1 ;
		}
		else if( theAction == solution ){
			Employee::set_happiness( Employee::get_happiness() + 1 );
			return -2 ;
		}
		return -5;
	}

	int ResearchAssistant::work( Action theAction ){
		if( theAction == document || theAction == lesson || theAction == administration || theAction == homeworkTime || theAction== incident ){		
			return -5;
		}
		else if( theAction == slackness){
			Employee::set_happiness( Employee::get_happiness() + 5 );
			return -2 ;

		}
		else if( theAction == project){
			Employee::set_happiness( Employee::get_happiness() + 3 );
			return 4 ;
		}
		else if( theAction == seminar ){
			Employee::set_happiness( Employee::get_happiness() + 10 );
			return  0 ;
		}
		else if( theAction == academicPaper ){
			Employee::set_happiness( Employee::get_happiness() + 2 );
			return 5 ;
		}
		else if( theAction == homeworkTimeout ){
			Employee::set_happiness( Employee::get_happiness() + - 3 );
			return 2 ;
		}
		else if( theAction == solution ){
			Employee::set_happiness( Employee::get_happiness() + 1 );
			return -2 ;
		}
		return -5;
	}

	int Secretary::work( Action theAction ){
		if( theAction == document || theAction == project || theAction == lesson || theAction == seminar || theAction== academicPaper || theAction == homeworkTime || theAction == homeworkTimeout ){
			return -5;
		}

		else if( theAction == slackness){
			Employee::set_happiness( Employee::get_happiness() + 5 );
			return  -2 ;
		}
		else if( theAction == administration){
			Employee::set_happiness( Employee::get_happiness() + -1 );
			return 2 ;
		}
		else if( theAction == incident ){
			Employee::set_happiness( Employee::get_happiness() + -1 );
			return -1  ;
		}
		else if( theAction == solution ){
			Employee::set_happiness( Employee::get_happiness() + 1 );
			return -2 ;
		}
		return -5;	
	}

	int Officer::work( Action theAction ){
		
		if( theAction == project || theAction == lesson || theAction == seminar || theAction == academicPaper || theAction == homeworkTime || theAction == homeworkTimeout || theAction== incident ){
			return -5;
		}
		else if( theAction == slackness){
			Employee::set_happiness( Employee::get_happiness() + 5 );
			return  -2 ;
		}
		else if( theAction == document){
			Employee::set_happiness( Employee::get_happiness() + -2 );
			return 3 ;
		}
		else if( theAction == administration ){
			Employee::set_happiness( Employee::get_happiness() + -1 );
			return 2 ;
		}
		else if( theAction == solution ){
			Employee::set_happiness( Employee::get_happiness() + 1 );
			return -2 ;
		}
		return -5;
	}
	
}