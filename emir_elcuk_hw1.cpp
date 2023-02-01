#include <iostream>
using namespace std;

	class DigitalBookArchive{
	private: //private member variables.
	string type;
	int digitalBookCount;
	string name;
	
	public:	//public constructor and overloaded constructor.
	DigitalBookArchive(string name_Book)
	{
	name=name_Book;
	}
	DigitalBookArchive(string name_Book, string type_Book): digitalBookCount(20)//There are 20 books in the beginning.
	{
	name=name_Book; //getting both the name and the type of the book.
	type=type_Book;
	}
	
	void addBook();
	void readBook();
	void getName();
	void print();
	};
	void DigitalBookArchive::addBook()//Declared the member functions outside of the class.
	{
	cout<<"A new digital book is added. \n";
	digitalBookCount++;
	}
	void DigitalBookArchive::readBook()
	{
	cout<<"You've read a digital book. \n";
	digitalBookCount--;
	}
	void DigitalBookArchive::getName()
	{
	cout<<"Digital Book Archive name set to "<<name<<endl;
	cout<<"Digital book type is: "<<type<<endl;
	}
	void DigitalBookArchive::print()
	{
	cout<<"The number of remaining digital book is "<<digitalBookCount<<endl;
	}
	int main()//the main function
	{
		string name,type;
		char answer;
		cout<<"Enter the name of the Digital Book Archive: \n";
		cin>>name;
		cout<<"Enter the type of the digital book: \n";
		cin>>type;
		DigitalBookArchive digital_Book(name,type);
		digital_Book.getName();
		do    //do-while loop to get the information until user type 'C'.
		{
			cout<<"Do you want to add or read a digital book (a/r),\n";
			cout<<"or enter(C) for exit the system: ";
			cin>>answer;
				switch(answer)
				{
				case 'a':
					digital_Book.addBook();
				break;
		
				case 'r':
					digital_Book.readBook();
				break;
				case 'C':
					digital_Book.print();
				}
		}
		while( answer != 'C' );
		return 0;
	}



