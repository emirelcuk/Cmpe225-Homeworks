#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class Date {
	public:
		int day,year;
		string month;
		Date(int d,string mn,int y)
		{	//Member initialization for the classes (CONSTRUCTOR)
			day=d;
			month=mn;
			year=y;	
		}
};
class Player{
		string first,last;
		Date birthdate;
	public:
		Player(string nm,string snm,int d,string mn,int yr): birthdate(d,mn,yr)
		{		// Member initialization for the classes.
			first=nm;
			last=snm;
		}
		void setMonth(string mnth)
		{	
			birthdate.month=mnth;	
		}
		void printInfo()
		{		
			cout<<first<<" "<<last<<" "<<birthdate.day<<" "<<birthdate.month<<" "<<birthdate.year<<endl;	
		}
		int getDay(){
			return birthdate.day;
		}
		int getYear(){
			return birthdate.year;
		}
};
	int main(){
	 string name,surname,month;
	 string months[12];
	 int flag;
	 int day,year;
	 months[0]="January"; // Array of all months with correct writing.
	 months[1]="February";
	 months[2]="March";
	 months[3]="April";
	 months[4]="May";
	 months[5]="June";
	 months[6]="July";
	 months[7]="August";
	 months[8]="September";
	 months[9]="October";
	 months[10]="November";
	 months[11]="December";
	 ifstream fin("input.txt");
	 ofstream fout("output.txt");
	 while(!fin.eof()){ 	//Check whether the end of file or not.
	fin>>name>>surname>>day>>month>>year;
	// Input each line from the input file input.txt, and using Exception Handling, check the month.
	try
	{
		flag=0; // Flag, to check that inputted month writing true or not.
		for(int i=0;i<12;i++)
		{
			if(months[i]==month)
			{	
				flag=1;
				fout<<name<<" "<<surname<<" -- "<<month<<" "<<day<<", "<<year<<endl;
				break;
			}		
		}
		if(flag==0)
		{
			throw (Player(name,surname,day,month,year));	
		}
	}
		catch(Player& obj1) //Object is created.
		{ 	
			for(int i=0 ; i<12 ;i++)
			{ 	//Check the first three letters of the months and compare them.
				if(months[i].substr(0,3)==month.substr(0,3))
				{
					cout<<"Incorrectly inputted month: "<<month<<" is corrected to "<<months[i]<<"."<<endl;
					fout<<name<<" "<<surname<<" -- "<<months[i]<<" "<<obj1.getDay()<<", "<<obj1.getYear()<<endl;	
				}	// Send all the correct or corrected inputs output.txt file .
			}
		}
	}
	fin.close();
	fout.close(); //Close the opened files. (Don't need to close them.)
	return 0;
}

