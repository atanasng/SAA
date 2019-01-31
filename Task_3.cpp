#include <iostream>
using namespace std;

int M=0,N;

struct elem
{
    int Num;
    elem *Next;
}*First=NULL,*Last=NULL;

void push(int Number)
{
    elem *p;
    if(!First)
    {
        First=new elem;
        First->Num=Number;
        First->Next=NULL;
        Last=First;
    }
    else
    {
        p=Last;
        Last=new elem;
        Last->Num=Number;
        Last->Next=NULL;
        p->Next=Last;
    }
    M++;
}

int Get()
{
    elem *p;
    int TmpNum;
    if(!First)
        TmpNum=0;
    else
    {
        TmpNum = First -> Num;
        p = First -> Next;
        delete First;
        First = p;
        M--;
    }
    return TmpNum;
}

void OutP()
{
    elem *P = First;
    while(P)
    {
        cout<< P -> Num << endl;
        P = P -> Next;
    }
}

void del()
{
    elem *P,*Tmp;
    P = First;
    while(P)
    {
        Tmp = P ->Next;
        delete P;
        P = Tmp;
    }
}

int main()
{
	system("chcp 1251");//�����������
    int Nmbr = 1,i;
    while(Nmbr != 0)
    {
		cout<<" ����� = ";
		cin>>Nmbr;
        if(Nmbr != 0) push(Nmbr);
    }

    do
	{
		cout<<endl<<"N (�� 1 �� "<< M <<" )= ";
		cin>>N;
	}while(N<1||N>M);

    for(i = 0;i < M-N;i++)  
		push(Get());

    cout<<"������� �" << N << " ��� �������� = " << Get() <<" � ������ "<< endl<<endl;
	
    for(i=0;i<N-1;i++)  
		push(Get());

    OutP(); 
	del();
	system("pause");
    return 0;
}