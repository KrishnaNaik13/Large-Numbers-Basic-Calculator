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

char fsubt(char a,char b,char &c)
{
    if(a==b) return '0';
    if(a=='0' || b=='0'){
        if(b=='0') return a;
        c='1';
        switch (b) {
            case '1':
            return '9'; break;
            case '2':
            return '8'; break;
            case '3':
            return '7'; break;
            case '4':
            return '6'; break;
            case '5':
            return '5'; break;
            case '6':
            return '4'; break;
            case '7':
            return '3'; break;
            case '8':
            return '2'; break;
            case '9':
            return '1'; break;
        }
    }
    else if(a=='1' || b=='1'){
        if(b=='1'){
            switch (a) {
                case '2':
                return '1'; break;
                case '3':
                return '2'; break;
                case '4':
                return '3';break;
                case '5':
                return '4'; break;
                case '6':
                return '5'; break;
                case '7':
                return '6'; break;
                case '8':
                return '7'; break;
                case '9':
                return '8'; break;
            }
        }
        c='1';
        switch (b) {
            case '2':
            return '9'; break;
            case '3':
            return '8'; break;
            case '4':
            return '7'; break;
            case '5':
            return '6'; break;
            case '6':
            return '5'; break;
            case '7':
            return '4'; break;
            case '8':
            return '3'; break;
            case '9':
            return '2'; break;
        }
    }
    else if(a=='2' || b=='2'){
        if(b=='2'){
            switch (a) {
                case '3':
                return '1'; break;
                case '4':
                return '2';break;
                case '5':
                return '3'; break;
                case '6':
                return '4'; break;
                case '7':
                return '5'; break;
                case '8':
                return '6'; break;
                case '9':
                return '7'; break;
            }
        }
        c='1';
        switch (b) {
            case '3':
            return '9'; break;
            case '4':
            return '8'; break;
            case '5':
            return '7'; break;
            case '6':
            return '6'; break;
            case '7':
            return '5'; break;
            case '8':
            return '4'; break;
            case '9':
            return '3'; break;
        }
    }
    else if(a=='3' || b=='3'){
        if(b=='3'){
            switch (a) {
                case '4':
                return '1';break;
                case '5':
                return '2'; break;
                case '6':
                return '3'; break;
                case '7':
                return '4'; break;
                case '8':
                return '5'; break;
                case '9':
                return '6'; break;
            }
        }
        c='1';
        switch (b) {
            case '4':
            return '9'; break;
            case '5':
            return '8'; break;
            case '6':
            return '7'; break;
            case '7':
            return '6'; break;
            case '8':
            return '5'; break;
            case '9':
            return '4'; break;
        }
    }
    else if(a=='4' || b=='4'){
        if(b=='4'){
            switch (a) {
                case '5':
                return '1'; break;
                case '6':
                return '2'; break;
                case '7':
                return '3'; break;
                case '8':
                return '4'; break;
                case '9':
                return '5'; break;
            }
        }
        c='1';
        switch (b) {
            case '5':
            return '9'; break;
            case '6':
            return '8'; break;
            case '7':
            return '7'; break;
            case '8':
            return '6'; break;
            case '9':
            return '5'; break;
        }
    }
    else if(a=='5' || b=='5'){
        if(b=='5'){
            switch (a) {
                case '6':
                return '1'; break;
                case '7':
                return '2'; break;
                case '8':
                return '3'; break;
                case '9':
                return '4'; break;
            }
        }
        c='1';
        switch (b) {
            case '6':
            return '9'; c=1; break;
            case '7':
            return '8'; c=1; break;
            case '8':
            return '7'; break;
            case '9':
            return '6'; break;
        }
    }
    else if(a=='6' || b=='6'){
        if(b=='6'){
            switch (a) {
                case '7':
                return '1'; break;
                case '8':
                return '2'; break;
                case '9':
                return '3'; break;
            }
        }
        c='1';
        switch (b) {
            case '7':
            return '9'; break;
            case '8':
            return '8'; break;
            case '9':
            return '7'; break;
        }
    }
    else if(a=='7' || b=='7'){
        if(b=='7'){
            switch (a) {
                case '8':
                return '1'; break;
                case '9':
                return '2'; break;
            }
        }
        c='1';
        switch (b) {
            case '8':
            return '9'; break;
            case '9':
            return '8'; break;
        }
    }
    else {
        if(b=='8') return '1';
        c='1';
        return '9';
    }
}

void addfun(list a1,list a2,list &res1)
{
    node *ref1,*ref2;
    char t,c1='0',c2='0';

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

}
void subtfun(list a1,list a2,list &res1)
{
    char c1='0',c2='0',t;
    node *ref1,*ref2;
    
    ref1=a1.tail;ref2=a2.tail;
    while(ref2){
        c2='0';
        t=ref1->data;
        if(c1=='1') t=fsubt(ref1->data,c1,c2);
        t=fsubt(t,ref2->data,c2);
        c1=c2;
        res1.additem(t);
        ref1=ref1->prev;
        ref2=ref2->prev;
    }
    while(res1.head && (res1.head)->data=='0')
    {
        res1.deltop();
    }
}

char compare(list a,list b)
{
    node *ref1,*ref2;
    ref1=a.head;ref2=b.head;
    while(ref1 && ref2)
    {
        ref1=ref1->next;
        ref2=ref2->next;
    }
    if(ref1) return '>';
    if(ref2) return '<';
    ref1=a.head;ref2=b.head;
    while(ref1){
        if(ref1->data>ref2->data) return '>';
        else if(ref1->data<ref2->data) return '<';
        else {ref1=ref1->next;ref2=ref2->next;}
    }
    return '=';
}

int main()
{
    fstream myfile;
    myfile.open("input.txt");
    char t,s1,s2,s3;   // s1 and s2 are signs of two input numbers
    list a1,a2,res,temp1,temp2,temp3,rem,tres;
    node *ref1,*ref2;

    myfile.get(t);
    if(t=='-'){
        s1='-';
        t=myfile.get();
    }
    else s1='+';
    while(t!='\n')
    {
        a1.addend(t);
        myfile.get(t);
    }

    myfile.get(t);
    if(t=='-'){
        s2='-';
        myfile.get(t);
    }
    else s2='+';
    while(1)
    {
        a2.addend(t);
        if(myfile.get(t)){}
        else break;
    }
    if(s1=='-') cout<<"-";
    a1.display();
    cout<<endl;
    if(s2=='-') cout<<"-";
    a2.display();
    cout<<endl;
    if(compare(a1,a2)=='<'){
        res.addend('0');rem=a1;
    }
    else{
        ref2=a2.head;
        while(ref2){
            temp1.addend((a1.head)->data);a1.deltop();
            ref2=ref2->next;
        }
        if(compare(temp1,a2)=='<'){
            temp1.addend((a1.head)->data);a1.deltop();
        }
        while(1){
            if(compare(temp1,a2)!='<'){
                t='0';temp2=a2;
                while(compare(temp1,temp2)!='<'){
                    temp3=temp2;temp2.head=NULL;temp2.tail=temp2.head;
                    t=fadd(t,'1',t);
                    addfun(a2,temp3,temp2);
                }
                temp2=temp3;
                temp3=temp1;temp1.head=NULL;temp1.tail=temp1.head;
                subtfun(temp3,temp2,temp1);
                res.addend(t);
            }
            if(a1.head){
                temp1.addend((a1.head)->data);a1.deltop();
                if((temp1.head)->data=='0') temp1.deltop();
            }
            else break;
            
            while(compare(temp1,a2)=='<'){
                res.addend('0');
                if(a1.head){
                    temp1.addend((a1.head)->data);a1.deltop();
                    if((temp1.head)->data=='0') temp1.deltop();
                }
                else break;
            }
        }
        rem=temp1;
    }
    if(s1!=s2) s3='-';
    else s3='+';
    
    cout<<"quotient = ";
    if(s3=='-') cout<<s3;
    res.display();cout<<endl;
    cout<<"remainder = ";
    if(rem.head){
        if(s3=='-') cout<<s3;
        rem.display();
    }
    else cout<<'0';
    cout<<endl;
    myfile.close();
}