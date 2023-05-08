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

int main()
{
    fstream myfile;
    myfile.open("input.txt");
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