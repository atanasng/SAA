#include <iostream>

using namespace std;
int br(0); // bri el0ti v lista
// 1
struct elem
{

	int key;
	elem *next;

} *start = NULL;

// 2
void list()
{
	if(start)
	{
		cout << "\nThe list: ";
		elem *p = start;
		while(p)
		{
			cout << p->key << " ";
			p = p->next;
		}
	}
	else cout << "\nEmpty list!";
}

// �������� � ��������
// 3
void add_b(int n)
{
	elem *p = start;
	start = new elem;
	start -> key = n;
	start -> next = p;
}

// �������� � ����
// 4
void add_e(int n)
{
	elem *p = start;
	elem *q = new elem;
	q -> key = n;
	q -> next = NULL;
	if(start == NULL)
		start = q;
	else 
		{
			while(p -> next)
				p = p -> next;
				p -> next = q;
		}
}

// 5
void add_ak(int n, int k)
{

	elem *p = start;
	while(p -> key != k && p -> next)
		p = p -> next;
	
	if(p -> key == k)
	{
		elem *q = new elem;
		q -> next = p -> next;
		p -> next = q;
		p -> key = n;
		q -> key = n;
		q -> key = k;
	}
	else
		cout << "\nNo k ";
}

// 6
void add_bk(int n, int k)
{
	elem *p = start;
	while(p -> key != k && p -> next)
		p = p -> next;
	if(p -> key == k)
	{
		elem *q = new elem;
		q -> next = p -> next;
		p -> next = q;
		p -> key = n;
		q -> key = n;
	}
	else
		cout << "\nNo k ";
}

// 7
int del_b(int &n)
{
	if(start)
	{
		n = start -> key;
		elem *p = start;
		start = p -> next;
		delete p;
		return 1;
	}
	else
		return 0;
}

// 8
int del_e(int &n)
{
	if(start)
	{
		elem *p = start;
		elem *q = p;
		if(start -> next)
		{
			while(p -> next)
			{

				q = p;
				p = p -> next;
			}
			q -> next = NULL;
		}
		else
			start = NULL;
		n = p -> key;
		delete p;
		return 1;
	}
	else return 0;
}

// 9
int del_k(int k)
{
	if(start)
	{
		elem *p = start;
		elem *q = p;
		while(p -> key != k && p -> next)
		{
			q = p;
			p = p -> next;
		}

		if(p -> key == k)
		{
			if(start == p)
				start = p -> next;
			else
				q -> next = p -> next;
			delete p;
			return 1;
		}
		else
		{
			cout << "\nNo k ";
			return 0;
		}
	}
	else return 0;
}

// 10
int search_elem(int k)
{
	int flag = 0;
	elem *p = start;
	while(p -> key != k && p -> next)
		p = p -> next;
	if(p -> key == k)
		flag = 1;
	return flag;
}
// �-� �� ������������ ��� ��������� ������ � ����� :�
void add(int a)
{
	cout << "Do 0 se vyvejda \n";
	int n=1;
	if(a == 1)
	{
		do
		{
			cout << "N= ";
			cin >> n;
			if(n != 0) add_b(n);
		}while(n != 0);
	}
	else
	{
		do
		{
			cout << "N= ";
			cin >> n;
			if(n != 0) add_e(n);
		}while(n != 0);
	}
}

void add_k(int a)
{
	int n,k;

	if(a == 1)
	{
		cout << "N= ";
		cin >> n;
		cout << "K= ";
		cin >> k;
		add_ak(n, k);
	}
	else
	{
		cout << "N= ";
		cin >> n;
		cout << "K= ";
		cin >> k;
		add_bk(n, k);
	}
}

void Max()
{
	int buf;
	elem *z = start;

	if(start)
	{
		cout << "\n Sort.... \n";
		int buf;
		elem *p = start;
		elem *q;
		
		p = p -> next;//propuskame 1-q element 
		while(p)
		{
			q = start;//propuskame 1-q element 
			while(q)
			{
				if (q -> key > p -> key)      
				{ 
                    buf = p -> key;
					p -> key = q -> key;
                    q -> key = buf;
				}
				q = q -> next;
			}
			p = p -> next;
		}
	}
	else {cout << "\nEmpty list!"; exit(1);}
	br++;
	buf = 0;
	buf = z -> key;
	z = z -> next;
	while(z)
	{

		if (z -> key > buf ) {buf = z -> key; br++;}
		buf = z -> key;
		z = z -> next;
	}

	int *a = new int [br];
	int *b = new int [br];
	int brr(0);
	z = start;
	int i=0;
	a[0] = z -> key;

	do
	{
		buf = z -> key; 
		
		if (a[i] <= z -> key) brr++;
		if (a[i] < z -> key) {++i; a[i] = z -> key; brr = 1; }
		b[i] = brr;
		z = z -> next;

	} while(z);

	if (a[i] <= buf ){++i; a[i] = buf;}
	int max = 0; 
	
    for (int j=0 ;j< i;j++)
	{
		 //cout << "a[" << j << "]= " << a[j] << " " << "b[" << j << "]= " << b[j] << endl;
		if(max < b[j] ) max = b[j];
	}

	if(max > 1)
	{
		
		for (int j=0 ;j < i;j++)
		{
			if(max == b[j]) cout <<"Nay chesto sreshtaniq element e: "<<a[j]<<" s povtoreniq: ("<<b[j]<<")\n";
		
		}
	}
	else cout << "Nqma tajyv emenet \n";
}

int main()
{
	
	char choice;
	int n = 0;
	do
	{
		cout <<"\n";
			cout << "\t\t MAIN MENU\n";
			cout << "\n 1. Add first";
			cout << "\n 2. Add last";
			cout << "\n 3. Add before l ";
			cout << "\n 4. Add after k";
			cout << "\n 5. Del first ";
			cout << "\n 6. Del last";
			cout << "\n 7. Del k";
			cout << "\n 8. List";
			cout << "\n 9. Search k";
			cout << "\n 0. MAX ";
			cout << "\n Enter your choice: ";
			cin >> choice;

		switch(choice)
		{

			case '1': add(1); list(); system("pause>null");
				break;
			case '2': add(2); list(); system("pause>null");
				break;
			case '3': add_k(3); list(); system("pause>null");
				break;
			case '4': add_k(4); list(); system("pause>null");
				break;
			case '5': del_b(n); cout << "Del first :" << n << endl; list(); system("pause>null");
				break;
			case '6': del_e(n); cout << "Del last :" << n << endl; list(); system("pause>null");
				break;
			case '7': cout << "Del k :"; cin >> n; del_k(n); list(); system("pause>null");
				break;
			case '8': list(); system("pause>null");
				break;
			case '9': cout << "Search k :"; cin >> n; search_elem(n); list(); system("pause>null");
				break;
			case '0': Max(); list();//exit(1);
				break;
		}
	}while(true);
	system("pause");
	return 0;
}
