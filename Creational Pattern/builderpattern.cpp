// The builder pattern consists of 4 main components 
// 1. The AbstractBuilder class -> ex PlaneBuilder, PersonBuilder, MenuBuilder
// 2. Concrete builders which inherits astractbuilders  ex Boing747PlaneBuilder and F77PlaneBuilder.
// 3. Director class that takes care of construction of object and has a Abstract builder in the class
// 4. Product -> The final object 

#include <iostream>
using namespace std;

// Creates a builder to create objects with varied specifications
// Helps get rid of long construction calls
class PersonBuilder;

// Main product class
class Person
{
    std::string m_name, m_street_address, m_post_code, m_city;  // Personal Detail
    std::string m_company_name, m_position, m_annual_income;    // Employment Detail
    Person(std::string name) : m_name(name) {}
public:
    // Builder class now has access to private members
    friend class PersonBuilder;
    friend ostream& operator<<(ostream&  os, const Person& obj);
    // This is called to create object according to specific needs
    static PersonBuilder create(std::string name);
};

PersonBuilder Person::create(string name) { return PersonBuilder{name}; }
ostream& operator<<(ostream& os, const Person& obj)
{
    return os << obj.m_name
              << std::endl
              << "lives : " << std::endl
              << "at " << obj.m_street_address
              << " with postcode " << obj.m_post_code
              << " in " << obj.m_city
              << std::endl
              << "works : " << std::endl
              << "with " << obj.m_company_name
              << " as a " << obj.m_position
              << " earning " << obj.m_annual_income;
}

// Aggregation -> has Person in the class definition 
class PersonBuilder
{
    Person person;
public:
    PersonBuilder(string name) : person(name) {}
    operator Person() const 
    {
         return move(person);
    }
    
    PersonBuilder&  PersonBuilder::lives() { return *this; }
    PersonBuilder&  PersonBuilder::works() { return *this; }
    
    PersonBuilder&  PersonBuilder::with(string company_name)
    {
        person.m_company_name = company_name; 
        return *this;
    }
    PersonBuilder&  PersonBuilder::as_a(string position) 
    {
        person.m_position = position; 
        return *this;
    }
    PersonBuilder&  PersonBuilder::earning(string annual_income)
    {
        person.m_annual_income = annual_income; 
        return *this;
    }
    PersonBuilder&  PersonBuilder::at(std::string street_address)
    {
        person.m_street_address = street_address; 
        return *this;
    }
    PersonBuilder&  PersonBuilder::with_postcode(std::string post_code) 
    {
        person.m_post_code = post_code; 
        return *this;
    }
    PersonBuilder&  PersonBuilder::in(std::string city) 
    {
        person.m_city = city; 
        return *this;   
    }

};


int main()
{
    // Move constructor called
    Person p = Person::create("John")
                                .lives()
                                    .at("123 London Road")
                                    .with_postcode("SW1 1GB")
                                    .in("London")
                                .works()
                                    .with("PragmaSoft")
                                    .as_a("Consultant")
                                    .earning("10e6");
    cout << p << endl;
    return 0;
}
