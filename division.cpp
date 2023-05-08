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

list quotient(list a1,list a2,list &rem)
{
    list temp1,temp2,temp3,res;
    node *ref1,*ref2;
    char t;
    if(compare(a1,a2)=='<'){
        res.addend('0');rem=a1;
    }
    else{
        ref1=a1.head;
        ref2=a2.head;
        while(ref2){
            temp1.addend(ref1->data);ref1=ref1->next;
            ref2=ref2->next;
        }
        if(compare(temp1,a2)=='<'){
            temp1.addend(ref1->data);ref1=ref1->next;
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
            if(ref1){
                temp1.addend(ref1->data);ref1=ref1->next;
                if((temp1.head)->data=='0') temp1.deltop();
            }
            else break;
            
            while(compare(temp1,a2)=='<'){
                res.addend('0');
                if(ref1){
                    temp1.addend(ref1->data);ref1=ref1->next;
                    if((temp1.head)->data=='0') temp1.deltop();
                }
                else break;
            }
        }
        rem=temp1;
    }
    if(!rem.head) rem.addend('0');
    return res;
}

void k__(list &k){
    char c1='1',c2='0',t;
    node *ref;
    
    ref=k.tail;
    while(ref && c1=='1'){
        c2='0';
        ref->data=fsubt(ref->data,c1,c2);
        c1=c2;
        ref=ref->prev;
    }
    while(k.head && (k.head)->data=='0')
    {
        k.deltop();
    }
}

int main()
{
    fstream myfile;
    myfile.open("input.txt");
    char t,s1,s2;   // s1 and s2 are signs of two input numbers
    list a1,b1,a2,b2,k,temp1,temp2,res,quo,rem;
    node *ref1,*ref2;

    myfile.get(t);
    if(t=='-'){
        s1='-';
        t=myfile.get();
    }
    else s1='+';
    while(t!='.' && t!='\n')
    {
        a1.addend(t);
        myfile.get(t);
    }

    if(t=='.'){
        myfile.get(t);
        while(t!='\n')
        {
            b1.addend(t);
            myfile.get(t);
        }
    }
    myfile.get(t);
    if(t=='-'){
        s2='-';
        myfile.get(t);
    }
    else s2='+';
    while(t!='.' && t!='\n')
    {
        a2.addend(t);
        myfile.get(t);
    }

    if(t=='.'){
        myfile.get(t);
        while(t!='\n')
        {
            b2.addend(t);
            myfile.get(t);
        }
    }
    while(myfile.get(t)){
        k.addend(t);
    }
    if(s1=='-') cout<<'-';
    a1.display();
    if(b1.head){
        cout<<".";
        b1.display();
    }
    cout<<endl;
    if(s2=='-') cout<<'-';
    a2.display();
    if(b2.head){
        cout<<".";
        b2.display();
    }
    cout<<endl;
    if((k.head)->data=='0') k.deltop();
    while(b1.head || b2.head)
    {
        if(b1.head){
            a1.addend((b1.head)->data);b1.deltop();
        }
        else a1.addend('0');
        if(b2.head){
            a2.addend((b2.head)->data);b2.deltop();
        }
        else a2.addend('0');
    }
    while((a1.head)->next && (a1.head)->data=='0'){
        a1.deltop();
    }
    while((a2.head)->data=='0'){
        a2.deltop();
    }
    
    res=quotient(a1,a2,rem);
    if((rem.head)->data!='0' && k.head) res.addend('.');
    while(k.head && (rem.head)->data!='0'){
        rem.addend('0');
        a1=rem;rem.head=NULL;rem.tail=rem.head;
        quo=quotient(a1,a2,rem);
        res.addend((quo.head)->data);quo.deltop();
        k__(k);
    }
    cout<<"result = ";
    if(s1!=s2) cout<<"-";
    res.display();cout<<endl;

    myfile.close();
}