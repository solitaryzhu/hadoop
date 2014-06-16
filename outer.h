#ifndef OUTER_H
#define OUTER_H
#include <iostream>

class Poingable
{
public:
    virtual void poing() = 0;
};

class Bingable
{
public:
    virtual void bing() = 0;
};

//void callPoing(Poingable& p){ p.poing(); }
//void callBing(Bingable& b){ b.bing(); }

class Outer
{
    class inner1;
    friend class Outer::inner1;
    class inner1 : public Poingable
    {
    public:
        Outer* pOuter;
        inner1(Outer* o):pOuter(o){}
        void poing(){ std::cout<<"poing->"<<pOuter->name.c_str()<<std::endl; }
    };

    class inner2;
    friend class Outer::inner2;
    class inner2 : public Bingable
    {
    public:
        Outer* pOuter;
        inner2(Outer* o):pOuter(o){}
        void bing(){ std::cout<<"bing->"<<pOuter->name.c_str()<<std::endl; }
    };

    std::string name;
    inner1 innerclass1;
    inner2 innerclass2;

public:
    Outer(std::string name):name(name), innerclass1(this), innerclass2(this){}
    ~Outer(){}
    operator Poingable&(){ return innerclass1; }
    operator Bingable&(){ return  innerclass2; }
};

#endif // OUTER_H
