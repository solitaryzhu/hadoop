#include "observable.h"

void Observable::notifyObservers(Argument* arg)
{
    if( !hasChanged())
    {
        return;
    }

    clearChange();

    for(std::set<Observer*>::iterator iter = observers.begin();
        iter != observers.end(); ++iter)
    {
        (*iter)->update(this, arg);
    }
}
