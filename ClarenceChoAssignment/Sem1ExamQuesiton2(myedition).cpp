#include <iostream>
using namespace std;

void user_input(char*,char*,int*);
void package_room(char*,char*,int*);
void package_suites(char*,char*,int*);

void user_input(char*type,char*accom,int*nights)
{
	cout <<"Choose Which Type of Service R = Room , S = Suites: ";
	cin >> *type;
	
	cout <<"Choose Which Accomodation N = Normal , D = Deluxe: " ;
	cin >>*accom;
	
	cout <<"Enter How many nights (1 = 1 night) , (2 = 2 night): ";
	cin >>*nights;
}
void package_room(char type, char accom, int nights)
{
	switch(type)
	{
	   case 'R':
	   case 'r':
	   	if(accom == 'N' && nights == 1)
	   	{
	   		cout<<"Room Price for 1 Night: (RM)" << 1* 350;
		}
		else if(accom == 'N' && nights == 2)
		{
			cout <<"Room Price for 2 Night: (RM)" << 2*350;
	    }
	  
	  else if(accom =='D' || nights == 1)
	  {
	  	cout <<"Deluxe Price for 1 Night: (RM) " << 1*670;
	  }
	  else if(accom =='D' || nights == 2)
	  {
	  	cout <<"Deluxe Price for 2 Night: (RM) " << 2*670;
	  }
	  else
	  {
	  	cout <<"Error";
	  }
	  }
	}
void package_suites(char type, char accom, int nights)
{
	switch(type)
	{
	   case 'S':
	   case 's':
	   	if(accom == 'N' && nights == 1)
	   	{
	   		cout<<"Price for 1 Night Room is: (RM)" << 1* 550;
		}
		else if(accom == 'N' && nights == 2)
		{
			cout <<"Price is for 2 Night Room is: (RM)" << 2*550;
		}
	  
	  else if(accom =='D' && nights == 1)
	  {
	  	cout <<"Price for 1 night Deluxe is: (RM) " << 1*760;
	  }
	  else if(accom =='D' && nights == 2)
	  {
	  	cout <<"Price for 2 night Deluxe is: (RM) " << 2*760;
	  }
	  else
	  {
	  	cout <<"Error" ;
	  }
	}
}
int main()
{
	char type,accom;
	int nights;
	cout <<"Hotel Room Service" << endl;
	cout <<"Choose Package Room or Suites, Accomodation and how many nights" << endl;
	cout <<"---------------------------------------------" << endl;
	user_input(&type,&accom,&nights);
	package_room(type,accom,nights);
	package_suites(type,accom,nights);
}

