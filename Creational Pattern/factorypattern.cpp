#include <iostream>
#include <string>

using namespace std;

 // Define a interface (pure virtual function) and concrete objects can inherit this interface
 // Each concrete class implements this interface  
 /* Basic Idea - In the Factory pattern, we create an object 
   without exposing the creation logic to the client and refer to newly created objects using a common interface.*/
class Shape;
class Circle : public Shape 
{
    public:
       void Draw() { cout << "I am circle" << endl; }
       friend class Shape;
};

class Square : public Shape 
{
    public:
       void Draw() { cout << "I am square" << endl; }
       friend class Shape;
};

class Rectangle : public Shape 
{
    public:
       void Draw() { cout << "I am rectangle " << endl; }
      friend class Shape;
};
class Shape 
{
    public:
       virtual void Draw() = 0;
       // This is the factory method responsible of creting different shapes based on type
       static Shape* ShapeFactory(string type);
};


Shape* Shape::ShapeFactory(string type)
{
    if ( type == "circle" ) return new Circle();
    if ( type == "square" ) return new Square();
    if ( type == "rectangle" ) return new Rectangle();
    return NULL;
}

int main(){
   Shape* obj1 = Shape::ShapeFactory("circle");
   Shape* obj2 = Shape::ShapeFactory("square");
   Shape* obj3 = Shape::ShapeFactory("rectangle");
   obj1->Draw();
   obj2->Draw();
   obj3->Draw();
}
