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
    return '0';
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
    return '0';
}

char fmul(char a,char b,char &c){
    if(a=='0' || b=='0'){
        return '0';
    }
    else if(a=='1' || b=='1'){
        if(b=='1') return a;
        else return b;
    }
    else if(a=='2' || b=='2'){
        if(b=='2') b=a;
        switch (b) {
            case '2':
            return '4'; break;
            case '3':
            return '6'; break;
            case '4':
            return '8'; break;
            case '5':
            c='1'; return '0'; break;
            case '6':
            c='1'; return '2'; break;
            case '7':
            c='1'; return '4'; break;
            case '8':
            c='1'; return '6'; break;
            case '9':
            c='1'; return '9'; break;
        }
    }
    else if(a=='3' || b=='3'){
        if(b=='3') b=a;
        switch (b) {
            case '3':
            return '9'; break;
            case '4':
            c='1'; return '2'; break;
            case '5':
            c='1'; return '5'; break;
            case '6':
            c='1'; return '8'; break;
            case '7':
            c='2'; return '1'; break;
            case '8':
            c='2'; return '4'; break;
            case '9':
            c='2'; return '7'; break;
        }
    }
    else if(a=='4' || b=='4'){
        if(b=='4') b=a;
        switch (b) {
            case '4':
            c='1'; return '6'; break;
            case '5':
            c='2'; return '0'; break;
            case '6':
            c='2'; return '4'; break;
            case '7':
            c='2'; return '8'; break;
            case '8':
            c='3'; return '2'; break;
            case '9':
            c='3'; return '6'; break;
        }
    }
    else if(a=='5' || b=='5'){
        if(b=='5') b=a;
        switch (b) {
            case '5':
            c='2'; return '5'; break;
            case '6':
            c='3'; return '0'; c=1; break;
            case '7':
            c='3'; return '5'; c=1; break;
            case '8':
            c='4'; return '0'; break;
            case '9':
            c='4'; return '5'; break;
        }
    }
    else if(a=='6' || b=='6'){
        if(b=='6') b=a;
        switch (b) {
            case '6':
            c='3'; return '6'; break;
            case '7':
            c='4'; return '2'; break;
            case '8':
            c='4'; return '8'; break;
            case '9':
            c='5'; return '4'; break;
        }
    }
    else if(a=='7' || b=='7'){
        if(b=='7') b=a;
        switch (b) {
            case '7':
            c='4'; return '9'; break;
            case '8':
            c='5'; return '6'; break;
            case '9':
            c='6'; return '3'; break;
        }
    }
    else if(a=='8' || b=='8'){
        if(b=='8') b=a;
        switch (b) {
            case '8':
            c='6'; return '4'; break;
            case '9':
            c='7'; return '2'; break;
        }
    }
    else{
        c='8'; return '1';
    }
    return '0';
}

void addfun(list a1,list b1,list a2,list b2,list &res1,list &res2)
{
    if(!a2.head){
        res1=a1;res2=b1;
        return;
    }
    node *ref1,*ref2;
    char t,c1='0',c2='0';
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
}

void subtfun(list a1,list b1,list a2,list b2,list &res1,list &res2)
{
    char c1='0',c2='0',t;
    node *ref1,*ref2;
    ref1=b1.head;ref2=b2.head;
    if(ref1 && ref2){
        while(ref1->next && ref2->next){
            ref1=ref1->next;
            ref2=ref2->next;
        }
    }
    if(ref1 && ref1->next){
        if(!ref2) res2=b1;
        else{
            res2.head=ref1->next;
            res2.tail=b1.tail;
            (res2.head)->prev=NULL;
        }
    }
    else if(ref2 && ref2->next){
        while(ref2->next){
            b1.addend('0');
            ref2=ref2->next;
        }
        if(!ref1) b1.addend('0');
        ref1=b1.tail;
    }
    while(ref1 && ref2){
        c2='0';
        t=ref1->data;
        if(c1=='1') t=fsubt(ref1->data,c1,c2);
        t=fsubt(t,ref2->data,c2);
        c1=c2;
        res2.additem(t);
        ref1=ref1->prev;
        ref2=ref2->prev;
    }
    ref1=a1.tail;ref2=a2.tail;
    while(ref1 && ref2){
        c2='0';
        t=ref1->data;
        if(c1=='1') t=fsubt(ref1->data,c1,c2);
        t=fsubt(t,ref2->data,c2);
        c1=c2;
        res1.additem(t);
        ref1=ref1->prev;
        ref2=ref2->prev;
    }
    while(ref1){
        c2='0';
        t=ref1->data;
        if(c1=='1') t=fsubt(ref1->data,c1,c2);
        c1=c2;
        res1.additem(t);
        ref1=ref1->prev;
    }
}

void multfun(list a1,list b1,char m,list &res1,list &res2){
    node *ref;
    char t,c1='0',c2='0',c3='0';
    ref=b1.tail;
    while(ref){
        c2='0';c3='0';
        t=fmul(ref->data,m,c2);
        t=fadd(t,c1,c3);
        res2.additem(t);
        c1='0';
        c1=fadd(c2,c3,t);
        ref=ref->prev;
    }
    ref=a1.tail;
    while(ref){
        c2='0';c3='0';
        t=fmul(ref->data,m,c2);
        t=fadd(t,c1,c3);
        res1.additem(t);
        c1='0';
        c1=fadd(c2,c3,t);
        ref=ref->prev;
    }
    if(c1!='0') res1.additem(c1);
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

void iaddfun(list a1,list a2,list &res1)
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
void isubtfun(list a1,list a2,list &res1)
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
                    iaddfun(a2,temp3,temp2);
                }
                temp2=temp3;
                temp3=temp1;temp1.head=NULL;temp1.tail=temp1.head;
                isubtfun(temp3,temp2,temp1);
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

void add(){
    fstream myfile;
    myfile.open("input.txt");
    char z1,z2;
    myfile.get(z1);myfile.get(z2);
    char t,s1,s2,s3;   // s1 and s2 are signs of two input numbers
    list a1,b1,a2,b2,res1,res2;
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
        s2='+';
        myfile.get(t);
    }
    else s2='-';
    while(1)
    {
        a2.addend(t);
        if(myfile.get(t)){}
        else break;
        if(t=='.'){
            while(myfile.get(t)){
                b2.addend(t);
            }
            break;
        }
    }
    if(s1=='-') cout<<'-';
    a1.display();
    if(b1.head){
        cout<<".";
        b1.display();
    }
    cout<<endl;
    if(s2=='+') cout<<'-';
    a2.display();
    if(b2.head){
        cout<<".";
        b2.display();
    }
    cout<<endl;
    if(s1!=s2){
        s3=s1;
        addfun(a1,b1,a2,b2,res1,res2);
    }
    else
    {
        ref1=a1.head;ref2=a2.head;
        while(ref1 && ref2){
            ref1=ref1->next;ref2=ref2->next;
        }
        if(ref1){
            s3=s1;
            subtfun(a1,b1,a2,b2,res1,res2);
        }
        else if(ref2){
            if(s1=='+') s3='-';
            else s3='+';
            subtfun(a2,b2,a1,b1,res1,res2);
        }
        else{
            ref1=a1.head;ref2=a2.head;
            while(ref1){
                if(ref1->data!=ref2->data) break;
                ref1=ref1->next;
            }
            if(ref1){
                if(ref1->data>ref2->data) {s3=s1;subtfun(a1,b1,a2,b2,res1,res2);}
                else {
                    if(s1=='+') s3='-';
                    else s3='+';
                    subtfun(a2,b2,a1,b1,res1,res2);
                }
            }
            else{
                ref1=b1.head;ref2=b2.head;
                while(ref1 && ref2){
                    if(ref1->data!=ref2->data) break;
                    ref1=ref1->next;ref2->next;
                }
                if(ref1 && ref2){
                    if(ref1->data>ref2->data) {s3=s1;subtfun(a1,b1,a2,b2,res1,res2);}
                    else {
                        if(s1=='+') s3='-';
                        else s3='+';
                        subtfun(a2,b2,a1,b1,res1,res2);
                    }
                }
                else if(ref1) {s3=s1;subtfun(a1,b1,a2,b2,res1,res2);}
                else if(ref2) {
                    if(s1=='+') s3='-';
                    else s3='+';
                    subtfun(a2,b2,a1,b1,res1,res2);
                }
            }
        }
    }
    cout<<"addition = ";
    if(!(res1.head)) cout<<"0";
    else{
        while((res1.head)->data=='0' && (res1.head)->next){
            res1.deltop();
        }
        while(res2.tail && (res2.tail)->data=='0'){
            res2.delend();
        }
        if(s3=='-') cout<<'-';
        res1.display();
        if(res2.head){
            cout<<".";
            res2.display();
        }
    }
    cout<<endl;
    myfile.close();
}

void subt(){
    fstream myfile;
    myfile.open("input.txt");
    char z1,z2;
    myfile.get(z1);myfile.get(z2);
    char t,s1,s2,s3;   // s1 and s2 are signs of two input numbers
    list a1,b1,a2,b2,res1,res2;
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
    while(1)
    {
        a2.addend(t);
        if(myfile.get(t)){}
        else break;
        if(t=='.'){
            while(myfile.get(t)){
                b2.addend(t);
            }
            break;
        }
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
    if(s1!=s2){
        s3=s1;
        addfun(a1,b1,a2,b2,res1,res2);
    }
    else
    {
        ref1=a1.head;ref2=a2.head;
        while(ref1 && ref2){
            ref1=ref1->next;ref2=ref2->next;
        }
        if(ref1){
            s3=s1;
            subtfun(a1,b1,a2,b2,res1,res2);
        }
        else if(ref2){
            if(s1=='+') s3='-';
            else s3='+';
            subtfun(a2,b2,a1,b1,res1,res2);
        }
        else{
            ref1=a1.head;ref2=a2.head;
            while(ref1){
                if(ref1->data!=ref2->data) break;
                ref1=ref1->next;
            }
            if(ref1){
                if(ref1->data>ref2->data) {s3=s1;subtfun(a1,b1,a2,b2,res1,res2);}
                else {
                    if(s1=='+') s3='-';
                    else s3='+';
                    subtfun(a2,b2,a1,b1,res1,res2);
                }
            }
            else{
                ref1=b1.head;ref2=b2.head;
                while(ref1 && ref2){
                    if(ref1->data!=ref2->data) break;
                    ref1=ref1->next;ref2->next;
                }
                if(ref1 && ref2){
                    if(ref1->data>ref2->data) {s3=s1;subtfun(a1,b1,a2,b2,res1,res2);}
                    else {
                        if(s1=='+') s3='-';
                        else s3='+';
                        subtfun(a2,b2,a1,b1,res1,res2);
                    }
                }
                else if(ref1) {s3=s1;subtfun(a1,b1,a2,b2,res1,res2);}
                else if(ref2) {
                    if(s1=='+') s3='-';
                    else s3='+';
                    subtfun(a2,b2,a1,b1,res1,res2);
                }
            }
        }
    }
    cout<<"difference = ";
    if(!(res1.head)) cout<<"0";
    else{
        while((res1.head)->data=='0' && (res1.head)->next){
            res1.deltop();
        }
        while(res2.tail && (res2.tail)->data=='0'){
            res2.delend();
        }
        if(s3=='-') cout<<'-';
        res1.display();
        if(res2.head){
            cout<<".";
            res2.display();
        }
    }
    cout<<endl;
    myfile.close();
}

void mult(){
    fstream myfile;
    myfile.open("input.txt");
    char z1,z2;
    myfile.get(z1);myfile.get(z2);
    char t,s1,s2;   // s1 and s2 are signs of two input numbers
    list a1,b1,a2,b2,fres1,fres2,res1,res2,tres1,tres2;
    node *ref;

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
    while(1)
    {
        a2.addend(t);
        if(myfile.get(t)){}
        else break;
        if(t=='.'){
            while(myfile.get(t)){
                b2.addend(t);
            }
            break;
        }
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
    ref=b2.tail;
    while(ref){
        multfun(a1,b1,ref->data,res1,res2);
        tres1=fres1;tres2=fres2;
        fres1.head=NULL;fres1.tail=fres1.head;
        fres2.head=NULL;fres2.tail=fres2.head;
        addfun(res1,res2,tres1,tres2,fres1,fres2);
        if(b1.head){
            a1.addend((b1.head)->data);
            b1.deltop();
        }
        else a1.addend('0');
        res1.head=NULL;res1.tail=res1.head;
        res2.head=NULL;res2.tail=res2.head;
        ref=ref->prev;
    }
    ref=a2.tail;
    while(ref){
        res1.head=NULL;res1.tail=res1.head;
        res2.head=NULL;res2.tail=res2.head;
        multfun(a1,b1,ref->data,res1,res2);
        tres1=fres1;tres2=fres2;
        fres1.head=NULL;fres1.tail=fres1.head;
        fres2.head=NULL;fres2.tail=fres2.head;
        addfun(res1,res2,tres1,tres2,fres1,fres2);
        if(b1.head){
            a1.addend((b1.head)->data);
            b1.deltop();
        }
        else a1.addend('0');
        ref=ref->prev;
    }
    ref=b2.head;
    while(ref){
        if(fres1.tail){
            fres2.additem((fres1.tail)->data);
            fres1.delend();
        }
        else fres2.additem('0');
        ref=ref->next;
    }
    if(!fres1.head){
        fres1.additem('0');
    }
    while(fres2.tail && (fres2.tail)->data=='0'){
        fres2.delend();
    }
    cout<<"product = ";
    if(s1!=s2) cout<<'-';
    fres1.display();
    if(fres2.head){
        cout<<".";
        fres2.display();
    }
    cout<<endl;

    myfile.close();
}

void int_div(){
    fstream myfile;
    myfile.open("input.txt");
    char z1,z2;
    myfile.get(z1);myfile.get(z2);
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
                    iaddfun(a2,temp3,temp2);
                }
                temp2=temp3;
                temp3=temp1;temp1.head=NULL;temp1.tail=temp1.head;
                isubtfun(temp3,temp2,temp1);
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

void red_fract(){
    fstream myfile;
    myfile.open("input.txt");
    char z1,z2;
    myfile.get(z1);myfile.get(z2);
    char t;
    list a1,a2,temp1,temp2,temp3,rem;

    myfile.get(t);
    while(t!='/')
    {
        a1.addend(t);
        myfile.get(t);
    }
    while(myfile.get(t))
    {
        a2.addend(t);
    }
    a1.display();cout<<"/";
    a2.display();cout<<endl;
    temp1=a1,temp2=a2;
    while((temp2.head)->data!='0')
    {
        rem=temp2;
        temp2.head=NULL;temp2.tail=temp2.head;
        quotient(temp1,rem,temp2);
        temp1=rem;
    }
    temp1.head=NULL;temp1.tail=temp1.head;
    a1=quotient(a1,rem,temp1);
    temp1.head=NULL;temp1.tail=temp1.head;
    a2=quotient(a2,rem,temp1);
    cout<<"reduced form = ";
    a1.display();cout<<"/";
    a2.display();cout<<endl;

    myfile.close();
}

void division(){
    fstream myfile;
    myfile.open("input.txt");
    char z1,z2;
    myfile.get(z1);myfile.get(z2);
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
    cout<<"division = ";
    if(s1!=s2) cout<<"-";
    res.display();cout<<endl;

    myfile.close();
}

int main(){
    cout<<"In the input file write in the format"<<endl;
    cout<<"1"<<endl<<"a"<<endl<<"b"<<endl<<"for addition"<<endl;
    cout<<"2"<<endl<<"a"<<endl<<"b"<<endl<<"for subtraction"<<endl;
    cout<<"3"<<endl<<"a"<<endl<<"b"<<endl<<"for multiplication"<<endl;
    cout<<"4"<<endl<<"a"<<endl<<"b"<<endl<<"for integer division"<<endl;
    cout<<"5"<<endl<<"a/b"<<endl<<"for fraction reduction"<<endl;
    cout<<"6"<<endl<<"a"<<endl<<"b"<<endl<<"k"<<endl<<"for division"<<endl;
    cout<<"where a,b are decimal numbers for addition, subtraction, multiplication, division and integers for integer division, fraction reduction and k is number of decimal places we have to calculate"<<endl;
    cout<<endl;
    fstream myfile;
    myfile.open("input.txt");
    char t,t1;
    myfile.get(t);myfile.get(t1);
    myfile.close();
    if(t=='1') add();
    else if(t=='2') subt();
    else if(t=='3') mult();
    else if(t=='4') int_div();
    else if(t=='5') red_fract();
    else division();
    return 0;
}