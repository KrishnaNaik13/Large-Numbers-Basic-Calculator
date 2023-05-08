#include <iostream>
#include <fstream>
using namespace std;

struct node
{
    char data;
    node *next;
    node *prev;
};

class list{
    public:
        node * head;
        node *tail;
    
        list()
        {
            head=NULL;
            tail=NULL;
            head=tail;
        }
        void additem(char d);
        void addend(char d);
        void deltop();
        void delend();
        void display();
    
};

void list::additem(char d)
{
    node *newnode = new node();
    newnode-> data = d;
    newnode-> prev = NULL;
    newnode->next = head;

    if(head!=NULL)
    {
	    head->prev = newnode;
    }
    head = newnode;

    if(head->next==NULL)
    {
        tail=head;
    }
}

void list::addend(char d)
{
	node* newnode = new node();
	newnode->data = d;
	if(tail!=NULL)
	{
		tail->next = newnode;
	}
    newnode->prev=tail;
    tail = newnode;
    tail->next = NULL;
    
    if (tail->prev==NULL)
    {
	    head=tail;
    }
}

void list::deltop()
{
    if(head==NULL)
    {
    
    }
    else if (head->next==NULL)
    {
	    head = NULL;
        tail=head;
    }
    else
    {
	    head=head->next;
	    delete (head->prev);
	    head->prev = NULL;
    }
}

void list::delend()
{
    if (tail==NULL)
    {
        
    }
    else if (tail->prev==NULL)
    {
	    tail = NULL;
        head=tail;
    }
    else
    {
	    tail = tail -> prev;
	    delete (tail->next);
	    tail->next = NULL;
    }
}

void list::display()
{
    node* current = head;
    while(current != NULL)
    {
	    cout << current->data;
	    current = current->next;
    }
}

char fadd(char a,char b,char &c)
{
    if(a=='0' || b=='0'){
        if(a=='0') return b;
        else return a;
    }
    else if(a=='1' || b=='1'){
        if(b=='1') b=a;
        switch (b) {
            case '1':
            return '2'; break;
            case '2':
            return '3'; break;
            case '3':
            return '4'; break;
            case '4':
            return '5'; break;
            case '5':
            return '6'; break;
            case '6':
            return '7'; break;
            case '7':
            return '8'; break;
            case '8':
            return '9'; break;
            case '9':
            c='1'; return '0'; break;
        }
    }
    else if(a=='2' || b=='2'){
        if(b=='2') b=a;
        switch (b) {
            case '2':
            return '4'; break;
            case '3':
            return '5'; break;
            case '4':
            return '6'; break;
            case '5':
            return '7'; break;
            case '6':
            return '8'; break;
            case '7':
            return '9'; break;
            case '8':
            c='1'; return '0'; break;
            case '9':
            c='1'; return '1'; break;
        }
    }
    else if(a=='3' || b=='3'){
        if(b=='3') b=a;
        switch (b) {
            case '3':
            return '6'; break;
            case '4':
            return '7'; break;
            case '5':
            return '8'; break;
            case '6':
            return '9'; break;
            case '7':
            c='1'; return '0'; break;
            case '8':
            c='1'; return '1'; break;
            case '9':
            c='1'; return '2'; break;
        }
    }
    else if(a=='4' || b=='4'){
        if(b=='4') b=a;
        switch (b) {
            case '4':
            return '8'; break;
            case '5':
            return '9'; break;
            case '6':
            c='1'; return '0'; break;
            case '7':
            c='1'; return '1'; break;
            case '8':
            c='1'; return '2'; break;
            case '9':
            c='1'; return '3'; break;
        }
    }
    else if(a=='5' || b=='5'){
        if(b=='5') b=a;
        switch (b) {
            case '5':
            c='1'; return '0'; break;
            case '6':
            c='1'; return '1'; c=1; break;
            case '7':
            c='1'; return '2'; c=1; break;
            case '8':
            c='1'; return '3'; break;
            case '9':
            c='1'; return '4'; break;
        }
    }
    else if(a=='6' || b=='6'){
        if(b=='6') b=a;
        switch (b) {
            case '6':
            c='1'; return '2'; break;
            case '7':
            c='1'; return '3'; break;
            case '8':
            c='1'; return '4'; break;
            case '9':
            c='1'; return '5'; break;
        }
    }
    else if(a=='7' || b=='7'){
        if(b=='7') b=a;
        switch (b) {
            case '7':
            c='1'; return '4'; break;
            case '8':
            c='1'; return '5'; break;
            case '9':
            c='1'; return '6'; break;
        }
    }
    else if(a=='8' || b=='8'){
        if(b=='8') b=a;
        switch (b) {
            case '8':
            c='1'; return '6'; break;
            case '9':
            c='1'; return '7'; break;
        }
    }
    else{
        c='1'; return '8';
    }
}

int main() {
    char t,c1='0',c2='0';
    list a1,b1,a2,b2,res1,res2;
    node *ref1,*ref2;
    fstream myfile;
    myfile.get(t);
    
    while(t!='.')
    {
        a1.addend(t);
        myfile.get(t);
    }
    myfile.get(t);
    while(t!='\n')
    {
        b1.addend(t);
        myfile.get(t);
    }
    myfile.get(t);
    while(t!='.'){
        a2.addend(t);
        myfile.get(t);
    }
    while(myfile.get(t)){
        b2.addend(t);
    }
    
    while((a1.head)->data=='0' && (a1.head)->next)
    {
        a1.deltop();
    }
    
    while((a2.head)->data=='0' && (a2.head)->next)
    {
        a2.deltop();
    }

    while(b1.tail && (b1.tail)->data=='0')
    {
        b1.delend();
    }
    while(b2.tail && (b2.tail)->data=='0')
    {
        b2.delend();
    }
    a1.display();
    if(b1.head)
    {
        cout<<".";
        b1.display();
    }
    cout<<endl;

    a2.display();
    if(b2.head)
    {
        cout<<".";
        b2.display();
    }
    cout<<endl;

    ref1=b1.head;
    ref2=b2.head;
    if(!ref1 || !ref2){
        if(ref1) res2=b1;
        else res2=b2;
    }
    else{
        while(ref1->next && ref2->next){
            ref1=ref1->next;
            ref2=ref2->next;
        }
        if(ref1->next){
            res2.head=ref1->next;
            res2.tail=b1.tail;
            (res2.head)->prev=NULL;
        }
        else if(ref2->next){
            res2.head=ref2->next;
            res2.tail=b2.tail;
            (res2.head)->prev=NULL;
        }
        while(ref1){
            c2='0';
            t=fadd(ref1->data,ref2->data,c2);
            if(c1=='1') t=fadd(t,c1,c2);
            c1=c2;
            res2.additem(t);
            ref1=ref1->prev;
            ref2=ref2->prev;
        }

    }

    ref1=a1.tail;
    ref2=a2.tail;
    while(1){
        c2='0';
        t=fadd(ref1->data,ref2->data,c2);
        if(c1=='1') t=fadd(t,c1,c2);
        c1=c2;
        res1.additem(t);
        ref1=ref1->prev;
        ref2=ref2->prev;
        if(!ref1 || !ref2){
            if(!ref1) ref1=ref2;
            while(ref1){
                c2='0';
                t=fadd(ref1->data,c1,c2);
                c1=c2;
                res1.additem(t);
                ref1=ref1->prev;
            }
            if(c1=='1') res1.additem('1');
            break;
        }
    }

    while(res2.tail && (res2.tail)->data=='0'){
        res2.delend();
    }
    cout<<"sum = ";
    res1.display();
    if(res2.head){
        cout<<".";
        res2.display();
    }
    cout<<endl;

    myfile.close();
    return 0;
}