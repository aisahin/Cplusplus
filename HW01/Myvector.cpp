/**
 *
 * @author aliihsan.sahin
 */
#include <iostream>

using namespace std;

class Myvector {
private:
   int size, capacity;
   int *data;
public:
    // simple constructor
   Myvector( ) { size= capacity= 0; data=0; cout<<"constructor"<<endl;}
   // destructor
   ~Myvector( ) {cout<<"destructor"<<endl; free(data);}
   
   // copy constructor
   Myvector( const Myvector &obj ) {
       cout<<"========== Copy constructor called here =========="<<endl;
       size=obj.size; capacity=obj.capacity; data= new int; cout<<"constructor"<<endl;
   }
   // The assignment operator
   Myvector& operator = (const Myvector& obj) {
       cout<<"========== Assignment operator called here =========="<<endl;
   } 
   
   void push_back(int d) {
      if(size>= capacity) {
         capacity++;
         data= (int *)realloc(data, sizeof(int)*capacity);
      }
      data[size++]= d;
   }
   int pop_back( ) {
     if(size==0) { cerr<<"Myvector is empty"<<endl;exit(-1);}
     return data[--size];
   }
   const int& operator[](int i) const {
     cout<<"operator[] i:"<<i<<" size:"<<size<<endl;
     if(i<0 || i>=size) {cerr<<"Myvector boundary error:"<<i<<endl;exit(-1);}
     return data[i];
   }
   int& operator[](int i) {
      cout<<"2nd operator[]"<<endl;
      return data[i];
   }
};

int main( ) {
   Myvector v1, v2;
   
   v2 = v1;
   
   Myvector v3 = v1;

   v1.push_back(3);
   cout<<v1[0]<<endl;

   cout<<v1[1]<<endl;

   v1[0]= 99;
   return 0;
}
