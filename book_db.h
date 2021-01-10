#ifndef BOOK_DB_H
#define BOOK_DB_H
namespace bookdb{

  class books{
   
   private:
    char* author, *title, *publisher;
    float *price;
    int *copies;

   public: 
    books();
    void getdata();
    int search(char[],char[]);
    void display();
    void requestBook(int);
    
  };
}
#endif
