#include <string.h>

using namespace std;

class Human {
    string *Secondname;
    string *Name;
    string *Surname;
    string *Birthdate;
    string *sex;
public:
    void Human(string, string, string, string, string);
    ~Human();
};

class  Employee : public Human
{
    string *Subdivision;
    string *Position;
    string *Salary;
public:
    void Employee();
};

class Client : public Human{
    List fhdjsfbjd;
};
