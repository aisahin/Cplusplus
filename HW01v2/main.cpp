#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

template<class T>
class Myvector {
    
    private:
        int size, capacity;
        T *data;
        
    public:
        // simple constructor
        Myvector( ) {
            
            size= capacity= 0; data=0;             
            cout<<"========== Simple constructor called =========="<<endl;
        }
        // deconstructor
        ~Myvector( ) {
            
            free(data);
            cout<<"========== Destructor called =========="<<endl; 
        }
        
        // copy constructor
        Myvector( const Myvector &obj ) {
        
            size=obj.size; capacity=obj.capacity; data= new int;
            cout<<"========== Copy constructor called =========="<<endl;
            cout << "size : "<<size<<" capacity: "<< capacity<<" data: "<<data<<endl;
            
        }

        void push_back(const T& d) {

            if(size>= capacity) {

                capacity++;
                data= (T *)realloc(data, sizeof(T)*capacity);
            }
            data[size++]= d;

            cout<<"push_back: D="<<d<<endl;
        }

        T pop_back( ) {

            if(size==0) { cerr<<"Myvector is empty"<<endl;exit(-1);}
            return data[--size];
        }

        const T& operator[](int i) const {

            cout<<"operator[] i:"<<i<<" size:"<<size<<endl;
            if(i<0 || i>=size) {cerr<<"Myvector boundary error:"<<i<<endl;exit(-1);}
            return data[i];
        }

        T& operator[](int i) {

            cout<<"2nd operator[]"<<endl;
            if(i<0 || i>=size) {cerr<<"Myvector boundary error:"<<i<<endl;exit(-1);}
            return data[i];
        }
    
        // The assignment operator
        Myvector<T>& operator=(const Myvector<T>& rhs) {

            size= rhs.size;
            capacity= rhs.capacity;
            data= (T *)malloc(sizeof(T)*capacity);
            memcpy(data, rhs.data, sizeof(T)*capacity);
            cout<<"========== Assignment operator called =========="<<endl; 
            return *this;
        }

        template<class U>
        friend ostream& operator<<(ostream& co, const Myvector<U>&);
};

template<class T>
ostream& operator<<(ostream& co, const Myvector<T>& d){

    co<<"[";
    for(int i=0; i< d.size;i++)
      co<<d.data[i]<<" ";
    co<<"]";
    return co;
}

int main( ) {

    Myvector<Myvector<int>> v1;
    Myvector<int> v2;
    Myvector<int> v3 = v2;
    
    v2.push_back(3);
    v2.push_back(5);
    v1.push_back(v2);
    
    cout<<"v1: "<<v1<<endl;
    cout<<"v2: "<<v2<<endl;
    cout<<"v3: "<<v3<<endl;
    return 0;
}