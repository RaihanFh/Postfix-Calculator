#include "PostfixCalculator.h"

int main()
{
    queueD Q1;
    queueD Q2;
    createQueueD(Q1);
    createQueueD(Q2);
    char loop ='Y',pilihan;
    int N,counter=0;

    cout<<"==========SELAMAT DATANG DI POSTFIX CALCULATOR=========="<<endl
        <<"Silakan masukan data pertama anda"<<endl;
    inputing(Q1,Q2,counter);
    while((loop=='Y'||loop=='y')){
        pilihan = menu();
        switch (pilihan){
        case '0':
            loop='N';
            break;
        case '1':
            inputing(Q1,Q2,counter);
            break;
        case '2':
            showBefore(Q2);;
            cout<<"Kembali ke menu utama? (Y/N) : ";
            cin>>loop;
            break;
        case '3':
            showAfter(Q1);
            cout<<"Kembali ke menu utama? (Y/N) : ";
            cin>>loop;
            break;
        case '4':
            showAll(Q1,Q2);
            cout<<"Kembali ke menu utama? (Y/N) : ";
            cin>>loop;
            break;
        case '5':
            cout<<"Banyak data yang dihapus : ";
            cin>>N;
            if(N<=counter){
                deleteN(N,Q1,Q2,counter);
            }
            else{
                cout<<"Melebihi banyaknya data"<<endl;
            }
            cout<<"Kembali ke menu utama? (Y/N) : ";
            cin>>loop;
            break;
        case '6':
            createQueueD(Q1);
            createQueueD(Q2);
            cout<<"Kembali ke menu utama? (Y/N) : ";
            cin>>loop;
            break;
        default:
            cout<<"Pilihan tidak valid"<<endl;
            cout<<"Kembali ke menu utama? (Y/N) : ";
            cin>>loop;
        }
    }
    cout<<endl
        <<"=============================="<<endl
        <<"ANDA TELAH KELUAR DARI PROGRAM"<<endl
        <<"=============================="<<endl;

    return 0;
}
