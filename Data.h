#include <string>
#pragma once
using namespace std;
struct Movie
{
  string movieID;	
  int code;
  int length = 0;
  char name[50];
  char genre[20];
  int year;
  int copies;
};
struct Customer
{
	int id;
	char name[50];
	char address[100];
};
	class MovieList
	{
	   private:
		   struct MovieNode
		   {
			   Movie movie;
			   struct MovieNode *next;
		   };
		   struct CustomerNode
		   {
		   	Customer customer;
		   	struct CustomerNode *next;
		   };
		   MovieNode *head;
		   CustomerNode *head1;
	   public:
		   MovieList();
		   ~MovieList();
		   void addMovie(Movie movie);
		   void returnMovie(Movie movie);
		   void rentMovie(int cusid, string movid);
       	   void showMovieDetails();
		   void displayMovieList();
		   void addCustomer(Customer cus);
		   void showCustomerDetails();
		   void customerRent(int num);
		   bool videoAvailability();
    };


