#include <QCoreApplication>
#include <iostream>
#include "observable.h"
#include "outer.h"
#include "surrogate.h"
#include "try_template.h"
#include "zbitree.h"
#include "test_suit.h"
#include "adjmwgraph.h"
using namespace std;

void f(int n)
{
    if (0 == n)
    {
        return;
    }
    else
    {
        std::cout<<n%10;
        f(n/10);
        std::cout<<n%10;
        return;
    }
}

void visitGraph(char item)
{
    std::cout<<" "<<item;
}

int test_fun1(int arg)
{
    std::cout<<arg<<" ";
    return 1;
}
int test_fun2(int arg)
{
    std::cout<<arg<<" ";
    return 1;
}

void reverse(int* result, int arg)
{
    *result = arg%10;
    if (arg >= 10)
        reverse(result+1, arg/10);
}

const int i = 100;
const int j = i + 10;
long address = (long)&j;
char buf[j+10];

struct test
{
    int a;
    int b;
};

class kkk2
{
  public:
    kkk2(int x){y=x+1;}
    void Print() const {printf("%d", y);}
private:
    int y;
};

bool IsIPAddress(const char* addr)
{
    int nIPVle = 0;
    while(*(addr)!='\0')
    {
        if(*(addr) != '.')
        {
            if(*addr >= '0' && *addr <= '9')
                nIPVle = nIPVle*10 + (*addr-'0');
            else
                return false;
        }
        else
        {
            if(nIPVle>255)
                return false;
            nIPVle = 0;
        }
    }
    return true;
}

char getUpper(char arg)
{
    char rlt;
    if(arg < 'a' || arg > 'z')
    {
        return rlt;
    }
    rlt = (arg & 223);
    return rlt;
}

char getLower(char arg)
{
	char rlt;
	if(arg < 'A' || arg > 'Z')
	{
		return rlt;
	}
	rlt = (arg | 32);
	return rlt;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    std::cout<<"Hello World!"<<std::endl;

    // observer design
    std::cout<<"***********observer design************"<<std::endl;



    std::cout<<"***********observer design************"<<std::endl;

    std::cout<<"***********proxy design***************"<<std::endl;
    ProxyBase * pBase = new Proxy();
    pBase->ExecuteTask();
    std::cout<<"***********proxy design***************"<<std::endl;


    std::cout<<endl;
    std::cout<<endl;
    std::cout<<"***********inner class************"<<std::endl;

    //Outer outer("ben");
    //callPoing(outer);
    //callBing(outer);

    std::cout<<"***********inner class************"<<std::endl;

    f(1234);

    std::cout<<endl;
    Container<int, Array> container;
    container.append(10);
    container.append(20);
    int* p = container.begin();
    while(p != container.end())
        cout<<*p++<<endl;

    std::cout<<"***************Binary Tree******************"<<std::endl;
    ZBiTreeNode<int> * pRoot = new ZBiTreeNode<int>(10);
    ZBiTreeNode<int> * pNode = 0;
    insertBiSearchTree<int>(pNode, pRoot, 15);
    insertBiSearchTree<int>(pNode, pRoot, 20);
    insertBiSearchTree<int>(pNode, pRoot, 4);
    insertBiSearchTree<int>(pNode, pRoot, 3);
    insertBiSearchTree<int>(pNode, pRoot, 1);
    LevelScan<int, visit<int>>(pRoot);
    pNode = findFromSearchTree(pRoot, 3);
    visit(pNode->Data());

    std::cout<<std::endl;
    std::cout<<"*************** PreDefine ******************"<<std::endl;
    std::cout<<HELLOWORLD;
    std::cout<<HELLOKITTY;

    std::cout<<std::endl;
    std::cout<<"**************** const use *****************"<<std::endl;
    int nA = 10;
    int nB = 15;
    int* const ptrA = &nA;
    const int* ptrB = &nA;
    ptrB = &nB;

    std::cout<<std::endl<<"**************** encode learn *********************"<<std::endl;
    char sz[20] = "中文123";
    wchar_t wsz[20] = L"\x4E2D\x6587\x0031\x0032\x0033";

    setlocale(LC_ALL, ".936");
    printf("%s\n", sz);
    wprintf(L"%s\n", wsz);

    wchar_t* pwsz = 0;
    size_t tmp = mbstowcs(pwsz, sz, 20)+1;
    pwsz = new wchar_t[tmp];
    wmemset(pwsz, 0, tmp);
    mbstowcs(pwsz, sz, tmp);
    if(tmp != -1)
    {
        wprintf(L"%ls\n", wsz);
    }

    std::cout<<std::endl<<"********************* graph learn ********************"<<std::endl;
    AdjMWGraph graph;
    graph.insertVertex('1');
    graph.insertVertex('2');
    graph.insertVertex('3');
    graph.insertVertex('4');
    graph.insertVertex('5');
    graph.insertEdge(0,1,1);
    //graph.insertEdge(0,2,1);
    //graph.insertEdge(0,3,1);
    //graph.insertEdge(0,4,1);
    graph.insertEdge(1,2,1);
    graph.insertEdge(2,4,1);
    graph.insertEdge(3,1,1);
    /*for(int i=0; i<5; ++i)
    {
        for(int j=0; j<5; ++j)
        {
            if(i != j)
                graph.insertEdge(i, j, 1);
        }
    }*/
    int graphVerts[5] = {0};
    graph.DepthFirstSearch(graphVerts, visitGraph);

    std::cout<<std::endl;
    /*typedef int(*ptr)(int);
    ptr ptrs[10];*/
    //(int(*)(int)) ptrs[10];

    int (*ptrs[10])(int);
    ptrs[0] = test_fun1;
    //ptr ptr_func = test_fun;
    //ptr_func(5);
   /* ptrs[0] = test_fun1;
    ptrs[1] = test_fun2;
    ptrs[0](5);
    ptrs[1](10);*/

    //reverse one int data
    std::cout<<123%10<<std::endl;
    std::cout<<123/10<<std::endl;
    int arg = 12345;
    int result[10];
    reverse(result, arg);
    for(int i=0; i<5; ++i)
        std::cout<<result[i]<<std::endl;

    std::cout<<std::endl;

    // test union
    union
    {
        int i;
        char x[2];
    } kkk;

    kkk.i = 0;
    kkk.x[0] = 10;
    kkk.x[1] = 1;
    std::cout<<kkk.i<<" ";
    //std::cout<<kkk.x[0]<<" ";
    //std::cout<<kkk.x[1]<<" ";

    std::cout<<std::endl;
    kkk2 test_kkk2a = 0;
    kkk2 test_kkk2b(test_kkk2a);
    test_kkk2b.Print();

    //
    std::cout<<std::endl;
    float  fVle0 = 0.1f;
    double dVle1 = 0.23;
    double dVle2 = 0.001;
    std::cout<<"sizeof(float)"<<sizeof(fVle0)<<std::endl;
    std::cout<<"sizeof(double)"<<sizeof(dVle1)<<std::endl;

    int nVle = 100;
    nVle = nVle ^ 0x80000000;
    std::cout<<nVle<<std::endl;

    std::cout<<getUpper('a')<<std::endl;
	std::cout<<getLower('A')<<std::endl;

    return a.exec();
}
