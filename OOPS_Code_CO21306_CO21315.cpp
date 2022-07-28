#include <iostream> // input/output library
#include <cstdlib> // standard library
#include <time.h> // time library

using namespace std;

int len; // length of password (global variable)

// PASS function ~ to print random character
void PASS(int start,int range,char choice){
	if(choice=='y'){
		cout<<char((rand() % range) + start);
		len-=1;
	}
}

int main(){
	srand(time(0)); // time seed for pseudo-random function
	int r; // store random number
	char a,b,c,d,gen; // store user choices
	
	// USER INPUT
	cout<<"PASSWORD GENERATOR\n";
	cout<<"------------------\n";
	cout<<"Submitted by : \n";
	cout<<"CO21306 : Akshit Chhikara\n";
	cout<<"CO21315 : Chetan Kumar\n";
	cout<<"------------------\n";
	cout<<"Enter the length of password : ";
	cin>>len;
	cout<<"\n";
	cout<<"Do you want your password to contain (y/n) ~\n";
	cout<<"Lowercase letters ? : ";
	cin>>a;
	cout<<"Uppercase letters ? : ";
	cin>>b;
	cout<<"Numbers ? : ";
	cin>>c;
	cout<<"Special characters ? : ";
	cin>>d;
	cout<<"------------------\n";
	
	int clen = len; // store copy of password length
	
	while(1){
		if(a!='y'&&b!='y'&&c!='y'&&d!='y'){
			cout<<"Error : Enter y (yes) to atleast one preference\n";
			break;
		}
		cout<<"Generated Password : ";
		while(len!=0){
			r = rand() % 4; // randomly selects character type
			switch(r){
				case 0:
					PASS(97,26,a); // for lowercase letter
					break;
				case 1:
					PASS(65,26,b); // for uppercase letter
					break;
				case 2:
					PASS(48,10,c); // for numbers
					break;
				case 3:
					PASS(33,15,d); // for special characters
					break;
			}
		}
		cout<<"\n------------------\n";
		
		// Ask user to generate another password
		cout<<"Generate another password ? (y/n) : ";
		cin>>gen;
		cout<<"\n";
		
		if(gen=='y') len = clen;
		else break;
	}
	cout<<"------------------\n";
	cout<<"Thanks for using Password Generator";
	return 0;
}
