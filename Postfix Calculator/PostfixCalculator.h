#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <math.h>
#include <string>
#include <iomanip>
#include <iostream>
using namespace std;

#define info(q) (q->info)
#define next(q) (q->next)
#define prev(q) (q->prev)
#define head(Q) ((Q).head)
#define tail(Q) ((Q).tail)

//Data Queue
struct infoDat
{
    string nama,a,b;
};
typedef struct elmD *adrD;
struct elmD{
    infoDat info;
    adrD next;
    adrD prev;
};
struct queueD{
    adrD head;
    adrD tail;
};
void createQueueD(queueD &Q);
void createElmD(infoDat x, adrD &q);
void enqueueD(queueD &Q, adrD q);
void dequeueD(queueD &Q, adrD &q);

//Stack Char
const int NMAX = 20;
struct stackC{
    char info[NMAX];
    int top;
};
void createStackC(stackC &S);
void pushC(stackC &S, char x);
void popC(stackC &S, char &x);
bool isEmptyC(stackC S);

//Stack Integer
struct stackI{
    int info[NMAX];
    int top;
};
void createStackI(stackI &S);
void pushI(stackI &S, int x);
void popI(stackI &S, int &x);
bool isEmptyI(stackI S);

//F&P++
bool Operand(char c);
bool Operator(char c);
bool valid(string x);
int getPriority(char c);
string InfixToPostfix(string infix);
string CalculatePostfix(string postfix);
void showRaw(queueD Q);
void showBefore(queueD Q);
void showAfter(queueD Q);
void showAll(queueD Q1, queueD Q2);
void inputing(queueD &Q1,queueD &Q2,int &counter);
void deleteN(int N,queueD &Q1,queueD &Q2,int &counter);
char menu();

#endif // HEADER_H_INCLUDED
