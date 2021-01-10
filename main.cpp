#include <iostream>
#include "book_db.h"

using namespace bookdb;

int main() {
  int i = 0, choice;
  books* Bdb[20];
  char stitle[20], sauthor[20];
  
  while(1) {
    std::cout<<"\n\n\t\tMENU"
		<<"\n1. Entry of New Book"
		<<"\n2. Search For Book"
		<<"\n3. Exit"
		<<"\n\nEnter your Choice: ";
		std::cin>>choice;

    switch(choice){
      case 1:
        Bdb[i] = new books;
        Bdb[i] -> getdata();
        ++i;
        break;

      case 2:
        std::cin.ignore();
        std::cout<<"\nEnter Title name: ";   std::cin.getline(stitle,20);
        std::cout<<"Enter author name: ";   std::cin.getline(sauthor,20);
        int j;
        for( j = 0;j<i;j++){
          if(Bdb[j] -> search(stitle,sauthor)){
            std::cout<<"\nBook details......";
            Bdb[j] -> display();
            std::cout<<"\nEnter number of copy required: ";
            int ncopy;
            std::cin>>ncopy;
            Bdb[j] -> requestBook(ncopy);
            break;
          }
        }
        if(j == i){
            std::cout<<"Book not found";
          }
        break;
      case 3:
        exit(0);
      default:
        std::cout<<"\nInvalid Choice Entered";
    }
  }
  return 0;
}
