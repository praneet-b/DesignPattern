#include<iostream>

// Practice different versions of Singleton pattern

// Acheiving Singleton with pointers 
class SingletonPtr
{
    private:

        static int s_instanceCount;
        static SingletonPtr* s_instance;
        // The constructor is made prpivate 
        SingletonPtr()
        {

        }
    public:

        //delete copy constructor and copy assgnmnt 
        SingletonPtr(const SingletonPtr&) = delete; 
        SingletonPtr& operator=(const SingletonPtr&) = delete;
        
        
        // The getInstance function is responsible for fetching the singleton instance
        static SingletonPtr* getInstance()
        {
            if(s_instance == nullptr)
                s_instance = new SingletonPtr();
            s_instanceCount++;
            return s_instance;
        } 

        static int getUserCount()
        {
            return s_instanceCount;
        }

};

SingletonPtr* SingletonPtr::s_instance = nullptr;
int SingletonPtr::s_instanceCount = 0;

// Achieving singleton pattern with reference 
class SingletonRef
{
  
        static int s_instanceCount;
        static SingletonRef s_instance;
        // The constructor is made private 
        SingletonRef()
        {

        }
    public:
        
        SingletonRef(const SingletonRef&) = delete;
        SingletonRef& operator=(const SingletonRef&) = delete;
        
        // The getInstance function is responsible for fetching the singleton instance
        static SingletonRef& getInstance()
        {
        //    static SingletonRef s_instance;   // This is initialized once only as it is static
        // Alternatively the private member var can be replaced by the above line
            s_instanceCount++;
            return s_instance;
        } 

        static int getUserCount()
        {
            return s_instanceCount;
        }

};
SingletonRef SingletonRef::s_instance;
int SingletonRef::s_instanceCount = 0;

int main()
{
    SingletonPtr *ptr{SingletonPtr::getInstance()};
    std::cout<<"The address of instance 1 is :"<< ptr;

    SingletonPtr *ptr1{SingletonPtr::getInstance()};
    std::cout<<"The address of instance 2 is :"<< ptr1;

    // It is important to add a &before declaring ref, ref1 . 
    //Otherwise it is just a copy and will produce an error as we have deleted copy constructor
    SingletonRef& ref{SingletonRef::getInstance()};   
    SingletonRef& ref1{SingletonRef::getInstance()};
    
    std::cout<<std::endl<<&ref<<std::endl<<&ref1<<std::endl<<"Total users logged in: "<<SingletonRef::getUserCount();
    
    //SingletonPtr *ptr2{new SingletonPtr()};     // Cannot create objects/pointer here as constructor is provate
    return 0;
}
