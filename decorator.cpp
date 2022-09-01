#include <iostream>
using namespace std;

class Pizza
{
  public:
  virtual int price() = 0;
  virtual string description() = 0;
};

class Plain : public Pizza
{
  public:
    int price()
    {
      return 100;
    }
    string description()
    {
      return "Plain Pizza ";
    }
};

class PizzaDecorator : public Pizza
{
  protected:
  Pizza *p;
  public:
  PizzaDecorator(Pizza * p): p(p){}
  int price() {return p->price();}
  string description() {return p->description();}
};

class Mozerella : public PizzaDecorator
{
  public:
    Mozerella(Pizza *p):PizzaDecorator(p){};
    int price()
    {
     return p->price() + 10; 
    }
    string description()
    {
      return p->description() + " Mozerella ";
    }
};



class Corn : public PizzaDecorator
{
  public:
    Corn(Pizza *p):PizzaDecorator(p){};
    int price()
    {
     return p->price() + 50; 
    }
    string description()
    {
      return p->description() + " Corn ";
    }
};


int main() 
{
    Pizza *p =  new Mozerella(new Corn(new Mozerella(new Plain())));
    
    cout << p->description() << endl;
    
    cout << p->price() << endl;

    return 0;
}