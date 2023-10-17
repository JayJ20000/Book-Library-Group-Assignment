#ifndef LIBRARY_H
#define LIBRARY_H

#include <string>
#include <iostream>

using namespace std;

class Node{
    Node *next;
    int data;
};

class Library{
    private:
      Node *head, *tail;
      string Title;
      string authorName;
      int Pages;
      string isbn;
      float coverPrice;
      int Year;
    
    public:
      Library();
      ~Library();
      void push_back();
      void push_front();
      void read_from_file(string fileName);
      void write_to_file(string fileName);
      void insert_sorted();
      void find_author();
      void find_album();
      void delete(string bName, string aName);
      
};


#endif //LIBRARY_H
