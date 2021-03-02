/* #include<iostream>
#include<conio.h>
#include<stdlib.h>

using namespace std;

class Node
{
public:
int data;
Node* next;
};

class list:public Node
{
Node* listptr, *temp;

public:
list()
{
listptr=NULL;
temp=NULL;
}

void create();
void display();
void insert_start();
void insert_end();
void insert_intermediate();
void delete_start();
void delete_end();
void delete_intermediate();
void Invert();
void concat(list);
};


int main()
{

list l, l1;
    int choice, a = 1;
    int arr[9];
    while (a == 1)
{
cout << endl << "Insert the elements of your linked list(max 9):",l.create();
for(int i=0;i<9;i++)
 cin >> arr[i];
cout << endl << "1. Insert to the list from the start:";
cout << endl << "2. Insert to the list from the intermediate:";
cout << endl << "3. Insert to the list from the end:";
cout << endl << "4. Delete to the list from the start:";
cout << endl << "5. Delete to the list from the intermediate:";
cout << endl << "6. Delete to the list from the end:";
        cout << endl << "7. Invert the list";
        cout << endl << "8. Concat the list";
        cout << endl << "9. Display the list";
        cout << endl << "10. Exit";
        cout << endl << "Enter your choice: ";
        cin >> choice;
        switch(choice) {
            case 1:
                l.insert_start();
                break;
            case 2:
                l.insert_intermediate();
                break;
            case 3:
l.insert_end();
break;
case 4:
l.delete_start();
break;
case 5:
l.delete_intermediate();
break;
case 6:
l.delete_end();
break;
case 7:
l.Invert();
break;
case 8:
l.concat(l1);
break;
case 9:
l.display();
break;    
            case 10:
                a = 0;
                break;
            default:
                cout << endl << "Wrong choice";
        }
    }
    return 0;
}
void list::create()
{
int x,n;
cout<<"Enter no of nodes";
cin>>n;
for(int i=0;i<n;i++)
{
Node*newnode=new Node;    //creating new node
cout<<"Enter data";
cin>>x;
newnode->data=x;
newnode->next=NULL;
if(listptr==NULL)
{  
listptr=newnode;
    temp=newnode;
}
else
{
temp->next=newnode; //listptr->next=newnode;(this statement will only work if we add a 2nd node wont work if its a 3rd or 4th node)//
temp=temp->next;             //( temp=newnode; =this is an alternate to it)
}
}
}

void list::display()
{
temp=listptr;
cout<<temp->data;
while(temp->next!=NULL)
{
temp=temp->next;  //traversing statement
cout<<temp->data;
}
while(temp);    //value of temp
while(temp!=NULL);   //node NUll ho nahi value null tAB TAK value display karega-'
}

void list::insert_start()
{
int x;
Node*newnode=new Node;
cout<<"Enter Value";
cin>>x;
newnode->data=x;
newnode->next=NULL;
newnode->next=listptr;
listptr=newnode;
}


void list::insert_end()
{
int x;
Node*newnode=new Node;
cout<<"Enter value";
cin>>x;
newnode->data=x;
newnode->next=NULL;
temp=listptr;
while(temp->next!=NULL)
{
temp=temp->next;
}
temp->next=newnode;
}


void list::insert_intermediate()
{
int x;int n,i;
Node*newnode=new Node;
cout<<"Enter value";
cin>>x;
//Enter x into data part & NULL insert

newnode->data=x;
newnode->next=NULL;
cout<<"Enter position";
cin>>n;
while(i!=n-1)
{
temp=temp->next;
i++;
}
newnode->next=temp->next;
temp->next=newnode;
}


void list::delete_start()
{
temp=listptr;
listptr=temp->next; //(listptr=temp->next=alternate ststement)
delete(temp);
}


void list::delete_end()
{
temp=listptr;
Node*q;
while(temp->next->next!=NULL)
{
temp=temp->next;
}
q=temp->next;
temp->next=NULL;
delete(q);
}


void list::delete_intermediate()
{
int n;
Node*q;
temp=listptr;
cout<<"Position:";
cin>>n;
//(check=temp=listptr);
for(int i=0;i<n-1;i++)
{
temp=temp->next;
}
q=temp->next;
temp->next=q->next;//(temp->next=temp->next->next=alternate statement)
delete(q);
}


void list::Invert()
{
Node*forward, *current, *back;
forward=listptr;
current=NULL;
while(forward!=NULL)
{
back=current;
current=forward;
forward=forward->next;
current->next=back;
}
listptr=current;
}
void concat(list l2)
{
	temp=listptr;
while(temp->next!=NULL)
{
temp=temp->next;
}
temp->next=l2.listptr;
display();
}
*/