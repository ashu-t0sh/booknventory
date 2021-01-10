#include <iostream>
#include<string.h>
#include<stdlib.h>
#include "book_db.h"

using namespace bookdb;
using namespace std;

books::books(){
  author = new char[20];
  title  = new char[20];
  publisher = new char[20];
  price = new float;
  copies = new int;
}

void books::getdata(){
  cin.ignore();
	cout<<"\nEnter Author Name: ";    cin.getline(author,20);
	cout<<"Enter Title Name: ";       cin.getline(title,20);
	cout<<"Enter Publisher Name: ";   cin.getline(publisher,20);
	cout<<"Enter Price: ";            cin>>*price;
	cout<<"Enter Stock Position: ";   cin>>*copies;  
}

int books::search(char stitle[20],char sauthor[20]){
  if(strcmp(stitle,title) == 0 && strcmp(sauthor,author) == 0)
    return 1;
  else
    return 0;
}

void books::display(){
  cout<<"\nAuthor : "<<author;
	cout<<"\nTitle : "<<title;
	cout<<"\nPublisher : "<<publisher;
	cout<<"\nPrice: "<<*price;
	cout<<"\nStock Position: "<<*copies; 
}

void books::requestBook(int ncopy){
  if(ncopy < *copies){
    *copies -= ncopy;
    cout<<"\nTotal Amount: Rs. "<<(*price)*ncopy;
    } 
  else
    cout<<"Required copies are not in stock";
}
