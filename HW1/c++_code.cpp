#include<iostream>

/* Author:Soner Türkoðlu
 *
 *
 *
 */

using namespace std;

int fibonacci(int);       // fibonacci function take number and return result of term who belong number

int main(){
	
	int num; 					// int number for getting number user
	int heartOfpyramid; 		
	int term;					// number for assigning function result to term
	
	cout<<"Please enter number  "<<endl;
	cin>>num;
	
	while(num<0 || num>46){																			// loop for suitable entry 
		cout<<"Please enter number again ( not negatif number and not bigger than 45)"<<endl;
		cin>>num;
	}
	
	
	for(int i=1; i<=num+1; i++){					// loop of fibonacci pyramid pattern
		for(int j=1; j<=i; j++){
			
			term=fibonacci(i-j+1) * fibonacci(j);			// pattern formula
			
			cout<<term<<" ";
			if( i == ( ( num+1 ) / 2 ) + 1 ){						// finding heartofpyramid
				if( i%2 == 1 && j == ( i / 2 ) + 1 )
					heartOfpyramid=term;
				if( i%2 == 0 && j ==  i / 2 )
					heartOfpyramid=term;
			}
		}
		cout<<endl;
	}
	cout<<"Biggest number:"<<fibonacci(num+1)<<endl;
	
	if( ( ( ( num+1 ) / 2 ) + 1 ) % 2 == 1){
		cout<<"Heart of the pyramid :"<<heartOfpyramid;
	}
	else
		cout<<"Heart of the pyramid :"<<heartOfpyramid<<" "<<heartOfpyramid;
	
	return 0;
}


int fibonacci(int n_term){
	
	int result=1;					
	int term1=0,term2=1; 			// first and second term of fibonacci
	
	if(n_term == 0)
		return 0;
	if(n_term < 0)
		return -1;
	
	for(int i=1; i<n_term; i++){
		result=term1+term2;
		term1=term2;
		term2=result;
	}
	return result;
	
};
