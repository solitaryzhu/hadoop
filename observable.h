#ifndef OBSERVABLE_H
#define OBSERVABLE_H
#include <set>

class Observable;
class Argument{};

class Observer
{
  public:
    virtual void update(Observable* o, Argument* arg) = 0;
    virtual ~Observer();
};

class Observable
{
private:
    bool bChanged;
    std::set<Observer*> observers;
protected:
    virtual void setChanged(){ bChanged = true; }
    virtual void clearChange(){ bChanged = false; }
public:
    Observable(){}
    virtual ~Observable(){}

    virtual void addObserver(Observer& o){ observers.insert(&o); }
    virtual void deleteObserver(Observer& o){ observers.erase(&o); }
    virtual void deleteObservers(){ observers.clear(); }
    virtual int  countObservers(){ return observers.size(); }

    virtual bool hasChanged(){ bChanged = true; }
    virtual void notifyObservers(Argument* arg = 0);

};

#endif // OBSERVABLE_H
