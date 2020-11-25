// Name :  Nebil Gokdemir
// SSID : 1635427
// Assignment : 4
// Submission Date : 11/23/2020


/*
 
  Build an integer Vector class defined in namespaceCS52t hat has similar behavior tostd::vector.  The
 integer Vector will have a default constructor, an overloaded constructor, a copy constructor, and
 over-loaded operators (e.g.  bracket [], assignment = and stream insertion<<).  Use C++’s object oriented
 programming constructs like classes and resource management that relies on constructors and destructorsfor
 memory  management.

 
 */


#include <iostream>
#include <string>


using namespace::std;

namespace CS52 {

class Vector {

public:

Vector();
Vector( int size , int  int_val  );
Vector( const  Vector& that);
~Vector ();
int& at ( int i ) const  throw( std:: string  );
int  capacity ()  const;
void  clear ();
int* data()  const;
bool  empty()  const;
void  pop_back ();
void  push_back( int  element );
int  size()  const;
int& operator []   ( int  index   );
    
Vector& operator =( const  Vector& );
    
    
    friend  std:: ostream& operator <<(std:: ostream&, Vector const &);

private:

int _size = 0;
int  _capacity = 0;
int * _data   = nullptr;



};
}




using namespace CS52 ;

Vector::Vector() {

    
    _size = 0 ;
    _capacity = 0;
    _data =  new int[_capacity];
    


}


Vector:: ~Vector (){
    
    
    if(_data)
        delete [] _data;
    _data = nullptr;
    cout<< "Destruct called" << endl;
}


// copy contructor
Vector::Vector( const  Vector&  that) {
    _size = that._size;
    _capacity = that._capacity;
   
    _data =  new int[that._capacity];
    
    for (int i = 0 ; i < that.size(); i++) {
        
        _data[i] = that._data[i];
        
        
    }
    
    
    
    
}


Vector::Vector( int size , int  int_val  )  {
    _data =  new int[size];
   
    for (int i = 0; i < size; i++) {
       
     
       
        _data[i] = int_val;
        _capacity +=1;
        _size += 1;
        
    }
    
    
    
   
    
    
}
    
    
    int& Vector::operator []  ( int  index  ) {
        
        int returnIndex = -1;
        if (index >= 0 && index < size()) {
        
            returnIndex = _data[index];
        
        }
           
            return returnIndex;
        
    }
    
    

     std:: ostream &operator << (std:: ostream & output , Vector &p) {
        
       
       

          for (int i = 0; i < p.size(); i++) {
              output << p.at(i) << endl;


          }

        

          return output;

      }
          
   
          
    
    
    


int  Vector::size()  const {
    
    return _size;
}

bool  Vector:: empty()  const {
    
    if(size() == 0) {
        return true;
    }
    else {
        return false;
    }
    
    
}

Vector& Vector:: operator =( const  Vector& that){
  
    if(this != &that) {
    
    
    _size = that._size;
    _capacity = that._capacity;
   
        if(this ->_data)
            
            delete [] this -> _data;
        
        
        
    _data =  new int[that._capacity];
    
    for (int i = 0 ; i < that.size(); i++) {
        
        _data[i] = that._data[i];
        
    
    }
        
        
    }
    
    return (*this);
  
}


void  Vector::push_back( int  element  ) {
    
    if (capacity() > size()) {
        
    
    
    _data[_size] = element;
        
        
    
    }
    else {
    
        if(_capacity == 0) {
            
            _capacity = 1;
        }else {
            _capacity = _capacity * 2  ;
            
            
        }

        int * _newData   = nullptr;
       
        
        _newData = new int[_capacity];
        
        
        for(int i = 0; i <size(); i ++ ) {
            
            _newData[i] = _data[i];
            
        }
    
        _data = _newData;
        
        _data[_size] = element;
   
    
        
        
    }
    
  
    
    _size = _size + 1;
 

    
}


void Vector:: clear () {
    
    for (int i = 0 ; i < size(); i++) {
        
        _data[i] = 0;
    }
    _size = 0;
}


int* Vector::data()  const {
    
    return _data;
    
}

void Vector:: pop_back () {
    
    if(size() > 0) {
    
    _data[_size] = 0;
    _size = _size - 1;
    }
    
    }


int Vector::capacity ()  const {
    
    return _capacity;
    
    
}

int& Vector::at ( int i ) const  throw( std:: string  ) {
 
    if(i >= 0 && i < size()) {
        return _data[i];
    }
    else {
        
        cout << "out-of-bounds" << endl;
        throw "there is no i index";
       
      //  return  x;

    }
    
    
    

    
}














void  info(CS52:: Vector& v)
{
       cout  << "Size is: " << v.size() << "\n";
       cout  << "Capacity  is: " << v.capacity () << "\n";
       cout  << "Contents : ";
    
    for (int i = 0; i < v.size(); i++)
    {
         cout  << v[i] << " ";}
          cout  << "\n";
    
}








int main(int argc, const char * argv[]) {
    
    
    
    
   

    
    
    char  stop; std::cin  >> stop;
    
    return 0;
}
