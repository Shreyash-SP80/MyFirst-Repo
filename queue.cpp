#include<iostream>
#define  max  5
using namespace std;

class  queue {

       int item[max];
       int  front, rare;
       public:
          void  create(queue*);
          void  isempty(queue*);
          void  isfull(queue*);
          void  insert(queue*, int);
          int   remove(queue*);
          void  display(queue*);
};

void  queue::create(queue *p) {
      p -> front = -1;
      p -> rare = -1;
      cout << "\nQueue is created.." << endl;
}

void  queue::isempty(queue *p) {
      if (p -> front == p -> rare) {
          cout << "\nQueue Is EMPTY.." << endl;
      }
      else {
          cout << "\nQueue Is Not EMPTY.." << endl;
      }
}

void  queue::isfull(queue *p) {
      if (p -> rare == max - 1) {
          cout << "\nQueue Is FULL.." << endl;
      }
      else {
          cout << "\nQueue Is NOT FULL.." << endl; 
      }
}

void  queue::insert(queue *p, int ele) {
      if (p -> rare == max - 1) {
          cout << "\nQueue Overflows.." << endl;
      }
      else {
          p -> item[++ p -> rare] = ele;
          cout << "\nElement is Inserted.." << endl;
      }
}

int  queue::remove(queue *p) {
     if (p -> front == p -> rare) { 
         cout << "\nQueue underflows.." << endl;
         return 0;
     } 
     else {
          return p -> item[++p -> front];
     }
}

void  queue::display(queue *p) {
   
    if (p -> front == p -> rare) {
        cout << "\nQueue is Empty.." << endl;
    }
    else { 
      cout << "\nElements :\n\t";
      for (int i = p->front + 1; i <= p->rare; i++) {
          cout << p->item[i] << "  ";
      }
      cout << endl;
    }
}

int  main() {
    int ele, ch;
    queue obj;
    queue *ptr = &obj;
    
    do {
      cout << "\n1 : Create\n2 : Isempty\n3 : Isfull\n4 : Insert\n5 : Remove\n6 : Display\n7 : Exit\nEnter your choice : ";
      cin >> ch; 
      
      switch(ch) {
           case 1:
              obj.create(ptr);
              break;
           case 2:
              obj.isempty(ptr);
              break;
           case 3:
              obj.isfull(ptr);
              break;
           case 4:
              cout << "\nEnter element to insert : ";
              cin >> ele;
              obj.insert(ptr, ele);
              break;
           case 5:
              cout << "\nRemoved element " << obj.remove(ptr);
              break;
           case 6:
              obj.display(ptr);
              break;
           case 7:
              cout << "\n\nExited.." << endl;
              break;
      }
    } while(ch != 7);
    
    return 0;
}
