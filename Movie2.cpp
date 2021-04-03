#include <iostream>
#include <windows.h>
#include <cstring>
#include <fstream>
#include <sstream>
#include "Data.h"
using namespace std;

int menu();

int main()
{
	MovieList list;
	Movie mov;
	Customer cus;
	int ch,rent, showrent;
  	int movieid, customerid;
	string line, line1, idstring;
	ifstream myfile("movietextfile.txt");
	
	while (getline(myfile,line)){
		movieid++;
	}
	
	
	ifstream customerfile("customerlist.txt");
	while(getline(customerfile, line1)){
		customerid++;
	}
	customerid -=4259337;
	customerfile.close();
	
	
	do
	{
    
		ch = menu();
		//system("clear");
		if (ch == 1)
		{
			cout << " << Add a movie >> " << endl << endl; //Insert
			cout << "Movie#: "  << movieid << endl;
			mov.code = movieid;
		    cout << "Enter movie title (Put underscore in between movie spaces): ";
		    cin >> mov.name;
		    cout << "Enter year of publication:";
		    cin >> mov.year;
		    cout << "Enter genre: "; 
		    cin >> mov.genre;
		    cout << "Enter number of copies: ";
		    cin >> mov.copies;
		    mov.length +=1;
			list.addMovie(mov);
		}
		else if (ch == 2)
		{
			cout << " << Return a Movie >> " << endl << endl; //append
		    cout << "Enter movie code: ";
			cin >> mov.code;
		    cout << "Enter movie title (Put underscore in between movie spaces): ";
		    cin >> mov.name;
		    cout << "Enter year of publication:";
		    cin >> mov.year;
		    cout << "Enter genre: "; 
		    cin >> mov.genre;
			list.returnMovie(mov);
		}
		else if (ch == 3)
		{
			cout << "Enter customer ID: ";
          	cin >> rent;
          	cout << "Enter Movie ID:";
         	cin >> idstring; 
			list.rentMovie(rent, idstring);
		}

		else if (ch == 4){
      cout << "Movie Details: " << endl << endl;// Traversal     
      list.showMovieDetails();
    }

		else if (ch == 5)
		{
			cout << " << Show Movie List >> " << endl << endl; // Traversal
			list.displayMovieList();
      system("sleep 3s");
		}
   
    else if(ch == 6){
      list.videoAvailability();
      
    }
    else if(ch == 7){
      int choice;
      cout << "Customer Maintenance" << endl << endl;
      cout << "[1] Add New Customer " << endl;
      cout << "[2] Show Customer Details " << endl;
      cout << "[3] List all videos rented by customer" << endl;
      cin >> choice;
      switch(choice){
        case 1:
          cout << "Enter details for customer# " << customerid << endl;
          cus.id = customerid;
          cout << "Enter name: ";
          cin.ignore();
          cin.getline(cus.name, 50);
          cout << "Enter address:";
          cin.getline(cus.address, 100);
          list.addCustomer(cus);
          break;
        case 2:
          list.showCustomerDetails();
          break;
        case 3:
          cout << "Enter customer id: ";
          cin >> showrent;
          list.customerRent(showrent);
          break;
        default:
          cout << "INVALID INPUT";                   
      }
  }
      else if (ch == 8)
		{
			cout << "Thank you for using the program!" << endl; //Exit
			list.~MovieList();
			exit(0);
		} 
		else
		{
			cout << "Invalid Input!" << endl << endl;
      Sleep(1000);
			break;
		}
		cout << endl;
	} while (ch >= 1 && ch <= 7);
}



int menu()
{
	int ch;
	system("CLS");
	cout << " << Rent-a-Movie >> " << endl << endl;
	cout << "[1] Add Movie" << endl;
	cout << "[2] Return Movie" << endl;
	cout << "[3] Rent a Movie" << endl;
	cout << "[4] Show Movie Details" << endl;
	cout << "[5] Show Movie List" << endl;
    cout << "[6] Check Video Availability" << endl;
	cout << "[7] Customer Maintenance" << endl;
	cout << "[8] Exit Program " << endl << endl;
	cout << "Enter Choice: ";
	cin >> ch;
	return(ch);
}
