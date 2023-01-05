#include "PostfixCalculator.h"

//Data Queue
void createQueueD(queueD &Q)
{
    head(Q)=NULL;
    tail(Q)=NULL;
}
void createElmD(infoDat x, adrD &q)
{
    q=new elmD;
    info(q)=x;
    next(q)=NULL;
    prev(q)=NULL;
}
void enqueueD(queueD &Q, adrD q)
{
    if(head(Q)==NULL){
        head(Q)=q;
        tail(Q)=q;
    }
    else{
        next(tail(Q))=q;
        prev(q)=tail(Q);
        tail(Q)=q;
    }
}
void dequeueD(queueD &Q, adrD &q)
{
    if(head(Q)==NULL){
        q=NULL;
        cout<<"Data Kosong"<<endl;
    }
    else if(next(head(Q))==NULL){
        q = head(Q);
        head(Q)=NULL;
        tail(Q)=NULL;
    }
    else{
        q = head(Q);
        head(Q)=next(q);
        next(q)=NULL;
        prev(head(Q))=NULL;
    }
}

//stack Char
void createStackC(stackC &S)
{
    S.top=-1;
}
void pushC(stackC &S, char x)
{
    if(S.top!=NMAX-1){
        S.top++;
        S.info[S.top]=x;
    }
    else{
        cout<<"Stack full"<<endl;
    }
}
void popC(stackC &S, char &x)
{
    if(!isEmptyC(S)){
        x = S.info[S.top];
        S.top--;
    }
    else{
        cout<<"Stack is empty"<<endl;
    }
}
bool isEmptyC(stackC S)
{
    if(S.top==-1){
        return true;
    }
    else{
        return false;
    }
}

//Stack Integer
void createStackI(stackI &S)
{
    S.top=-1;
}
void pushI(stackI &S, int x)
{
    if(S.top!=NMAX-1){
        S.top++;
        S.info[S.top]=x;
    }
    else{
        cout<<"Stack full"<<endl;
    }
}
void popI(stackI &S, int &x)
{
    if(!isEmptyI(S)){
        x = S.info[S.top];
        S.top--;
    }
    else{
        cout<<"Stack is empty"<<endl;
    }
}
bool isEmptyI(stackI S)
{
    if(S.top==-1){
        return true;
    }
    else{
        return false;
    }
}

//F&P++
bool Operand(char c)
{
    if(c>=48 && c<=57){
        return true;
    }
    else{
        return false;
    }
}
bool Operator(char c)
{
    if(c=='+'||c=='-'||c=='*'||c=='/'||c=='^'||c=='('||c==')'){
        return true;
    }
    else{
        return false;
    }
}
bool valid(string x)
{
    for(int i=0;i<x.length();i++){
        if(!Operand(x[i])&&!Operator(x[i])){
            return false;
        }
    }
    return true;
}
int getPriority(char c)
{
    if(c=='+' || c=='-'){
        return 1;
    }
    else if(c=='*' || c=='/'){
        return 2;
    }
    else if(c=='^'){
        return 3;
    }
    return 0;
}
string InfixToPostfix(string infix)
{
    stackC S;
    createStackC(S);
    string postfix="";
    char c,poped;
    for(int i=0;i<infix.length();i++){
        c=infix[i];
        if(Operand(c)){
            postfix+=c;
        }
        else{
            if(c=='('){
                pushC(S,c);
            }
            else if(c==')'){
                while(S.info[S.top]!='('){
                    popC(S,poped);
                    postfix+=poped;
                }
                popC(S,poped);
            }
            else{
                while(!isEmptyC(S)&&getPriority(c)<=getPriority(S.info[S.top])){
                    popC(S,poped);
                    postfix+=poped;
                }
                pushC(S,c);
            }
        }
    }
    while(!isEmptyC(S)){
        popC(S,poped);
        postfix+=poped;
    }
    return postfix;
}
string CalculatePostfix(string postfix)
{
    stackI S;
    createStackI(S);
    int a,b,len = postfix.length();
    for(int i=0;i<len;i++){
        if(Operand(postfix[i])){
            pushI(S,postfix[i]-'0');
        }
        else{
            popI(S,a);
            popI(S,b);
            switch (postfix[i])
            {
                case '+':
                          pushI(S,b + a);
                          break;
                case '-':
                          pushI(S,b - a);
                          break;
                case '*':
                          pushI(S,b * a);
                          break;
                case '/':
                          pushI(S,b / a);
                          break;
                case '^':
                          pushI(S,pow(b,a));
                          break;
            }
        }
    }
    return to_string(S.info[S.top]);
}
void showRaw(queueD Q)
{
    adrD p = head(Q);
    int i=1;
    cout<<"--------------hasil input---------------"<<endl;
    cout<<"|"<<"No| "<<left<<setw(10)<<"  Nama"<<" | "<<left<<setw(20)<<"      operasi"<<" | "<<endl;
    while(p!=NULL){
        cout<<"|"<<i<<" | "<<left<<setw(10)<<info(p).nama<<" | "<<left<<setw(20)<<info(p).a<<" | "<<endl;
        p=next(p); i++;
    }
    cout<<"----------------------------------------"<<endl;
}
void showBefore(queueD Q)
{
    cout<<"==============================================================="<<endl;
    if(head(Q)!=NULL){
        int i = 1;
        adrD p = head(Q);
        cout<<"|"<<"No| "<<left<<setw(10)<<"  Nama"<<" | "<<left<<setw(20)<<"        Infix"<<" | "<<left<<setw(20)<<"       Postfix"<<" |"<<endl;
        while(p!=NULL){
            cout<<"|"<<i<<" | "<<left<<setw(10)<<info(p).nama<<" | "<<left<<setw(20)<<info(p).a<<" | "<<left<<setw(20)<<info(p).b<<" |"<<endl;
            p=next(p); i++;
        }
    }
    else{
        cout<<"                         Data Kosong"<<endl;
    }
    cout<<"==============================================================="<<endl;
}
void showAfter(queueD Q)
{
    cout<<"===================================================="<<endl;
    if(head(Q)!=NULL){
        int i = 1;
        adrD p = head(Q);
        cout<<"|"<<"No| "<<left<<setw(10)<<"  Nama"<<" | "<<left<<setw(20)<<"       Operasi"<<"  | "<<left<<setw(5)<<"  Hasil"<<"  |"<<endl;
        while(p!=NULL){
            cout<<"|"<<i<<" | "<<left<<setw(10)<<info(p).nama<<" | "<<left<<setw(20)<<info(p).a<<"  |    "<<left<<setw(5)<<info(p).b<<" |"<<endl;
            p=next(p); i++;
        }
    }
    else{
        cout<<"                    Data Kosong"<<endl;
    }
    cout<<"===================================================="<<endl;
}
void showAll(queueD Q1, queueD Q2)
{
    cout<<"==============================================================================="<<endl;
    if(head(Q1)!=NULL){
        int i = 1;
        adrD p1 = head(Q1),p2 = head(Q2);
        cout<<"|"<<"No| "<<left<<setw(10)<<"  Nama"<<" | "<<left<<setw(20)<<"        Infix"<<"  | "<<left<<setw(20)<<"         Postfix"<<"     | "<<left<<setw(5)<<"  Hasil"<<"  |"<<endl;
        while(p1!=NULL){
            cout<<"|"<<i<<" | "<<left<<setw(10)<<info(p1).nama<<" | "<<left<<setw(20)<<info(p1).a<<"  |    "<<left<<setw(20)<<info(p2).b<<"  |    "<<left<<setw(5)<<info(p1).b<<" |"<<endl;
            p1=next(p1); p2=next(p2); i++;
        }
    }
    else{
        cout<<"                                 Data Kosong"<<endl;
    }
    cout<<"==============================================================================="<<endl;
}
void inputing(queueD &Q1,queueD &Q2,int &counter)
{
    infoDat x;
    adrD p1,p2;
    char jalan = 'Y';
    while(jalan=='Y'||jalan=='y'){
        cout<<"Nama : ";
        cin>>x.nama;
        cout<<"Operasi : ";
        cin>>x.a;
        if(valid(x.a)){
            createElmD(x,p1);
            enqueueD(Q1,p1);
            showRaw(Q1);
            createElmD(x,p2);
            info(p2).b=InfixToPostfix(info(p1).a);
            enqueueD(Q2,p2);
            counter++;
        }
        else{
            cout<<"Masukan bukan operasi bilangan"<<endl;
        }
        cout<<"Masukan data lagi? (Y/N) : ";
        cin>>jalan;
    }
    p1=head(Q1);
    p2=head(Q2);
    while(p1!=NULL){
        info(p1).b=CalculatePostfix(info(p2).b);
        p1=next(p1);
        p2=next(p2);
    }
}
void deleteN(int N,queueD &Q1,queueD &Q2,int &counter)
{
    adrD p1=head(Q1),p2=head(Q2);
    for(int i=0;i<N;i++){
        dequeueD(Q1,p1);
        p1=next(p1);
        dequeueD(Q2,p2);
        p2=next(p2);
        counter--;
    }
}
char menu(){
    cout<<endl<<"=======================MENU=========================="<<endl;
    cout<<left<<setw(51)<<"| 1. Menambah data baru"<<" |"<<endl;
    cout<<left<<setw(51)<<"| 2. Menampilkan operasi infix dan postfix"<<" |"<<endl;
    cout<<left<<setw(51)<<"| 3. Menampilkan operasi infix dan hasil"<<" |"<<endl;
    cout<<left<<setw(51)<<"| 4. Menampilkan oerasi infix, postfix dan hasilnya"<<" |"<<endl;
    cout<<left<<setw(51)<<"| 5. Hapus N banyak data"<<" |"<<endl;
    cout<<left<<setw(51)<<"| 6. Reset semua data"<<" |"<<endl;
    cout<<left<<setw(51)<<"| 0. Exit"<<" |"<<endl;
    cout<<"====================================================="<<endl;
    cout<<" Masukkan menu : ";
    char input;
    cin>>input;
    cout<<endl;
    return input;
}
