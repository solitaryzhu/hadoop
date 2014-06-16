#ifndef SURROGATE_H
#define SURROGATE_H
#include <iostream>

class ProxyBase
{
public:
    ProxyBase(){}
    ~ProxyBase(){}
    virtual void ExecuteTask() = 0;
};

class ImplementTask : public ProxyBase
{
public:
    ImplementTask(){}
    ~ImplementTask(){}
    void ExecuteTask()
    {
        std::cout<<"The job of safeguard world peace is assigned to you!!"<<std::endl;
    }
};

class Proxy : public ProxyBase
{
private:
    ProxyBase * m_pProxyBase;
public:
    Proxy(){ m_pProxyBase = 0; }
    ~Proxy()
    {
        if(0 != m_pProxyBase)
        {
            delete m_pProxyBase;
            m_pProxyBase = 0;
        }
    }
    void ExecuteTask()
    {
        if (0 == m_pProxyBase)
        {
            m_pProxyBase = new ImplementTask();
        }
        m_pProxyBase->ExecuteTask();
    }
};

#endif // SURROGATE_H
