#include <iostream>
using namespace std;
class Hours {
	public:
		int hour,minutes;
		
		friend ostream& operator<<( ostream& , const Hours& H) { 
        	cout <<H.hour<<":"<<H.minutes;
         	return cout;            // OPERATOR OVERLOADING FOR OUTPUT (<<) OPERATOR.
      	} 

        friend istream& operator>>( istream & cin, Hours& H ) { 
        	cin >> H.hour >> H.minutes;
        	return cin;            // OPERATOR OVERLOADING FOR INPUT (>>) OPERATOR.
        }
};
class Animals {
	protected:
		string id,animalName;
		string ownerName,ownerSurname;
		int totalMins;
		Hours totalHours;
	public:
		Animals(string a1, string b1, string c1, string d1) 
		{	//constructor by using member initialization for id, animalName, ownerName, ownerSurname.
			id=a1;
			animalName=b1;
			ownerName=c1;
			ownerSurname=d1;
		}
		int calculateMinutes(Hours check_in,Hours check_out)
		 {
			if(check_out.hour >= check_in.hour && check_out.minutes >= check_in.minutes)
			{	totalMins = (check_out.hour-check_in.hour)*60 + (check_out.minutes-check_in.minutes);	}
			
			else if(check_out.hour > check_in.hour && check_out.minutes < check_in.minutes)
			{	totalMins =((check_out.hour-1)-check_in.hour)*60 + ((check_out.minutes+60)-check_in.minutes);	}
				
			else 
			{	cout<<"Please enter appropriate time. \n";	}	
		 	return totalMins;		
			//returns the total time that the animal stays in the clinic as minutes.
	     }
};
class Cat: public Animals { 	// Cat class which is inherited from Animal class.
	protected:
		string type;
	public:
		Cat(string a,string b,string c,string d) : Animals(a,b,c,d) 
		{
			type="Cat";	 //constructor with member initialization for all data members.
			id=a;
			animalName=b;
			ownerName=c;
			ownerSurname=d;
		}
		void printInfo()
		{
			cout<<"Id of the animal is "<<id<<endl;
			cout<<"Name of the animal is "<<animalName<<endl;
			cout<<"Name of the animal's owner is "<<ownerName<<endl;
			cout<<"Surname of the animal's owner is "<<ownerSurname<<endl;
			cout<<"Type of the animal is "<<type<<endl;
		}
};
int main() 
{
	Cat A("123456","Goofy","Kobe","Bryant");
	A.printInfo();
	Hours check_in, check_out;
	cout<<"Enter the check in time of the animal :\n";
	cin>>check_in; 							 
	//operator overloading (>>) operator.
	cout<<"Enter the check out time of the animal :\n";
	cin>>check_out;							 
	cout<<"Check in and check out times are "<<check_in<<"/"<<check_out<<endl; 
	//operator overloading (<<) operator.
	cout<<"The total time animal stays in the clinic is "<<A.calculateMinutes(check_in, check_out)<<" minutes. !";
	return 0;
}
