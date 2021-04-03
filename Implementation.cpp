#include <iostream>
#include <windows.h>
#include <string>
#include <string.h>
#include <fstream>
#include <sstream>
#include "Data.h"
using namespace std;


MovieList::MovieList()
{
	head = NULL;
	head1 = NULL;
}
MovieList::~MovieList()
{
	MovieNode *nodePtr, *nextNode;
	CustomerNode *nodePtr1, *nextNode1;

	nodePtr = head;
	nodePtr1 = head1;
	while (nodePtr != NULL)
	{
		nextNode = nodePtr->next;
		delete nodePtr;
		nodePtr = nextNode;
	}
	while (nodePtr1 != NULL)
	{
		nextNode1 = nodePtr1->next;
		delete nodePtr1;
		nodePtr1 = nextNode1;
	}
	cout << "Linked List has been destroyed!" << endl;
}


void MovieList::addMovie(Movie mov)
{
	MovieNode *newNode, *nodePtr;
	
	newNode = new MovieNode;
	newNode->movie = mov;
	newNode->next = NULL;
	
	if (!head)
		head = newNode;
	else	
	{
		
		nodePtr = head;
		
		while (nodePtr->next)
			nodePtr = nodePtr->next;
		
		nodePtr->next = newNode;
	}
	cout << endl << "Input has been successfully Appended!" << endl;
	stringstream ss;
	ss << mov.code;
	string str = ss.str();
	string identifier = "M";
	mov.movieID = identifier + str;
	ofstream out;
	out.open("movietextfile.txt", ios::app);
	out <<  mov.copies << "\t" << mov.movieID << "\t\t" << mov.name << "\t\t" 
	<<mov.genre << "\t\t" << mov.year<< endl;
}

void MovieList::displayMovieList()
{
	MovieNode *nodePtr;
	if (head == NULL)
		cout << "The list is empty!" << endl;
	else
	{
		cout << "The movies in the List are... " << endl;
		nodePtr = head;
		while (nodePtr)
		{
			cout << "Movie " << nodePtr->movie.code << ": ";
      cout << nodePtr->movie.name << endl;
			nodePtr = nodePtr->next;
		}
	}
  char c;
	FILE *fp;
	fp = fopen("movietextfile.txt", "r");
	char ch;
	
	while(!feof(fp)){
		ch = fgetc(fp);
		cout << ch;
		
	}
	cout << "Press any button to continue";
	  cin >> c;
	  cin.ignore();
	  system("cls");
}

void MovieList::returnMovie(Movie mov)
{
	MovieNode *newNode, *nodePtr, *previousNode;

	
	newNode = new MovieNode;
	newNode->movie = mov;

	if (!head)
	{
		head = newNode;
		newNode->next = NULL;
	}
	else	
	{
		
		nodePtr = head;
		previousNode = NULL;

		
		while (nodePtr != NULL && nodePtr->movie.code < nodePtr->movie.length)
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}
		
		if (previousNode == NULL)
		{
			head = newNode;
			newNode->next = nodePtr;
		}
		else
		{
			previousNode->next = newNode;
			newNode->next = nodePtr;
		}
	}
	cout << endl << "Input has been successfully Inserted!" << endl;
}

void MovieList::rentMovie(int cusid, string movid)
{
//	MovieNode *nodePtr, *previousNode;
//	int found = 0;
//
//	
//	if (!head)
//	{
//		cout << "List is empty!" << endl;
//		return;
//	}
//
//	
//	if (head->movie.code == num)
//	{
//		nodePtr = head->next;
//		delete head;
//		head = nodePtr;
//		cout  <<  "Movie has been rented" << endl;
//		found = 1;
//    system("sleep 1");
//	}
//	else
//	{
//		
//		nodePtr = head;
//		previousNode = NULL;
//
//		
//		while (nodePtr != NULL && nodePtr->movie.code != num)
//		{
//				previousNode = nodePtr;
//				nodePtr = nodePtr->next;
//		}
//
//		
//		if (nodePtr != NULL)
//		 {
//			previousNode->next = nodePtr->next;
//			delete nodePtr;
//			cout << "Thanks for renting"  << endl;
//			found = 1;
//		}
//    Sleep(2000);
//    
//	}
//	if (found == 0)
//		cout << "Movie is not found on the list" << endl;
	ofstream out;
	out.open("customerrent.txt", ios::app);
	out <<  cusid << "\t\t" << movid << endl;
	out.close();
	
	string search;
	ifstream in;
	string line;
	char c;
	in.open("movietextfile.txt");

	if(!in){
	cout << "Unable to open file" << endl;
	exit(1);
	}
	search = movid;
	
	
	size_t pos;
	if(videoAvailability() == 1){
	while(in.good())
	  {
	      getline(in,line); // get line from file
	      pos=line.find(search); // search
	      if(pos!=string::npos) 
	        {	
			    cout <<"MOVIE DATA: " << search << endl;
			    cout << "Copies\t\tID\t\tName\t\tGenre\t\tYear" << endl;
	            cout << line  ;
	            break;
	        }	        	        	       
	  }
		}
		else{
			cout << "Video is not available!" << endl;
		}		
	  cout << endl;
	  cout << "Press any button to continue";
	  cin >> c;
	  cin.ignore();
	  system("cls");
}


void MovieList::showMovieDetails()
{
//  MovieNode *nodePtr, *previousNode;
//	int found = 0;
//
//	
//	if (!head)
//	{
//		cout << "No movies in the list" << endl;
//		return;
//	}
//
//	// Determine if the first node is the one.
//	if (head->movie.code == num)
//	{
//    cout << "Movie Title: " << head->movie.name << endl;
//    cout << "Year Published: " << head->movie.year << endl;
//    cout << "Genre: " << head->movie.genre << endl;
//		//nodePtr = head->next;
//		//head = nodePtr;
//		found = 1;
//	}
//	else
//	{
//		// Initialize nodePtr to head of list
//		nodePtr = head;
//		previousNode = NULL;
//
//		// Skip all nodes whose value member is 
//		// not equal to num.
//		while (nodePtr != NULL && nodePtr->movie.code != num)
//		{
//       
//				previousNode = nodePtr;
//				nodePtr = nodePtr->next;
//		}
//
//		
//		if (nodePtr != NULL)
//		 {
//      cout << "Movie Title: " << nodePtr->movie.name << endl;
//      cout << "Year Published: " << nodePtr->movie.year << endl;
//      cout << "Genre: " << nodePtr->movie.genre << endl;
//			
//			found = 1;
//		}
//	}
//	
//  Sleep(5000);
//	if (found == 0)
//		cout << "Movies not found on the list!" << endl;
	string search;
	ifstream in;
	string line;
	char c;
	in.open("movietextfile.txt");

	if(!in){
	cout << "Unable to open file" << endl;
	exit(1);
	}
	cout << "Enter movie id:  ";
	cin >>search;
	
	
	size_t pos;
	
	while(in.good())
	  {
	      getline(in,line); // get line from file
	      pos=line.find(search); // search
	      if(pos!=string::npos) 
	        {	
			    cout <<"MOVIE DATA: " << search << endl;
			    cout << "Copies\t\tID\t\tName\t\tGenre\t\tYear" << endl;
	            cout << line  ;
	            break;
	        }
	        
	        
	       
	  }
	  cout << endl;
	  cout << "Press any button to continue";
	  cin >> c;
	  cin.ignore();
	  system("cls");
}

void MovieList::addCustomer(Customer cus){
  CustomerNode *newNode1, *nodePtr1;
	
	newNode1 = new CustomerNode;
	newNode1->customer = cus;
	newNode1->next = NULL;
	
	if (!head1)
		head1 = newNode1;
	else	
	{
		
		nodePtr1 = head1;
		
		while (nodePtr1->next)
			nodePtr1 = nodePtr1->next;
		
		nodePtr1->next = newNode1;
	}
	
  cout << endl << "Input has been successfully Appended!" << endl;
  ofstream out;
  out.open("customerlist.txt", ios::app);
  out << cus.id << "	" << cus.name << "		" <<  cus.address << endl;
  out.close();
  
}

void MovieList::showCustomerDetails(){
  string search;
	ifstream in;
	string line;
	char c;
	in.open("customerlist.txt");

	if(!in){
	cout << "Unable to open file" << endl;
	exit(1);
	}
	cout << "Enter customer id:  ";
	cin >>search;
	
	size_t pos;
	
	while(in.good())
	  {
	      getline(in,line); // get line from file
	      pos=line.find(search); // search
	      if(pos!=string::npos) 
	        {	
			    cout <<"Customer Data: " << search << endl;
			    cout << "ID\tName\t\tAddress" << endl;
	            cout << line  ;
	            break;
	        }
	    	string s = line.substr(0,1);
	    	cout << s;
	        
	       
	  }
	  cout << endl;
	  cout << "Press any button to continue";
	  cin >> c;
	  cin.ignore();
	  system("cls");
}
void MovieList::customerRent(int num){
  
}

bool MovieList::videoAvailability()
{
	bool avail;
	string search, s,i;
	ifstream in;
	string line;
	char c;
	in.open("movietextfile.txt");

	if(!in){
	cout << "Unable to open file" << endl;
	exit(1);
	}
	cout << "Enter movie id:  ";
	cin >>search;
	
	
	size_t pos;
	
	while(in.good())
	  {
	      getline(in,line); // get line from file
	      pos=line.find(search); // search
	      if(pos!=string::npos) 
	        {	
			    cout <<"MOVIE DATA: " << search << endl;
			    cout << "ID Copies\tName\t\tGenre\t\tYear" << endl;
	            cout << line << endl;
	            break;
	        }    		        
	       
	  }
	  s = line.substr(0);
	  int copy = stoi(s);
	  if(copy > 0){
	  	cout << "Video Available!";
	  	avail = true;
	  }
	  else{
	  	cout << "Video Not Available!"; 
	  	avail = false;
	  }
	  
	  cout << endl;
	  cout << "Press any button to continue";
	  cin >> c;
	  cin.ignore();
	  system("cls");
	  return avail;
}






