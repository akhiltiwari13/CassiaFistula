/* Definition:Singleton desing pattern defines a class that has only one intance and provides a global point of access for that instance. */

/* Singleton Implementation requirements. */
/* lazy initialization */
/* no ownership */

/* USAGE=> 1.for creating threadpools.
 * 2. for creating Loggers
 * 3. for creating config reader.*/
 
#include <bits/stdc++.h>

class Singleton{
    private:
        static Singleton* _instance;
        int _classValue;

        //constructor destructor should be private for singleton.
        Singleton(){}
        Singleton(Singleton &rhs){}
    public:
        //only static member functions can operate on static data members.
        static Singleton* getInstance()
        {
             if(_instance == nullptr)
                 _instance = new Singleton();

             return _instance;
        }
};

Singleton *Singleton::_instance;
int main(int argc, char **argv){
    std::cout<<"Singleton Implementation."<<std::endl;
    
    return 0;
}
