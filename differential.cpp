#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;
string diff(string s);

////////////    please don't use spaces in input     ////////////

/* Sir, I have used
x^(2) but not x^2
2cos(x) but not 2*cos(x)
(cos(x))^(2) but not cos^(2)(x)
used sin,cos,tan,sec,csc,cot
used ln(x) but not log(x)
arcsin(x) or arccos(x) but not sin-1(x) or cos-1(x)
(2)^(x) but not 2^(x)
(sin(x))(cos(x)) but not sin(x)cos(x)
////////////////////      (x^(2))(sin(x)+cos(x))(tan(x)) but not x^(2)(sin(x)+cos(x))tan(x)     /////////////// 
///////////////////       please write every function in brackets while multiplying           ///////////////////

*/

string cts(int a)  // it converts number to string
{
    string temp="";
    char t;
    while(a>0){
        t=a%10+48;
        temp=t+temp;a/=10;
    }
    return temp;
}

int ctn(string s)   // it converts string to number
{
    int i=0,a=0;
    if(s[i]=='-') i++;
    while(i<s.length()){
        a=a*10+(s[i]-'0');i++;
    }
    if(s[0]=='-') a=a*(-1);
    return a;
}

string termmult(string s1,string s2)
{
    if(s1=="0" || s2=="0") return "0";
    string ans="",temp="";
    int i=0,j=0,b=1,a=0,lb=0,rb=0;
    if(s1[i]=='-') {b*=-1;i++;}
    while(i<s1.length() && s1[i]>='0' && s1[i]<='9'){
        a=a*10+(s1[i]-'0');i++;
    }
    if(a!=0) b*=a;
    a=0;
    if(s2[j]=='-') {b*=-1;j++;}
    while(j<s2.length() && s2[j]>='0' && s2[j]<='9'){
        a=a*10+(s2[j]-'0');j++;
    }
    if(a!=0) b*=a;
    if(b<0) {b*=-1;ans+='-';}
    if(b!=1) ans+=cts(b);
    
    if(s1[i]=='('){
        while(1){
            if(s1[i]=='(') lb++;
            else if(s1[i]==')') rb++;
            if(lb!=rb) temp+=s1[i];
            else break;
            i++;
        }
        if(i==s1.length()-1) ans+=temp+")";
        else{
            ans+='('+temp;
            while(i!=s1.length()) {ans+=s1[i];i++;}
            ans+=')';
        }
    }
    else if(i!=s1.length()){
        ans+='(';
        while(i!=s1.length()) {ans+=s1[i];i++;}
        ans+=')';
    }
    if(s2[j]=='('){
        lb=0;rb=0;temp="";
        while(1){
            if(s2[j]=='(') lb++;
            else if(s2[j]==')') rb++;
            if(lb!=rb) temp+=s2[j];
            else break;
            j++;
        }
        if(j==s2.length()-1) ans+=temp+")";
        else{
            ans+='('+temp;
            while(j!=s2.length()) {ans+=s2[j];j++;}
            ans+=')';
        }
    }
    else if(j!=s2.length()){
        ans+='(';
        while(j!=s2.length()) {ans+=s2[j];j++;}
        ans+=')';
    }
    if(ans=="") return "1";
    else if(ans=="-") return "-1";
    else return ans;
}

string termdiff(string s)
{
    string c="",ans="1",temp1,temp2;
    int i=0,temp;
    if(s[i]=='-') {ans="-1";i++;}
    while(i<s.length() && s[i]>='0' && s[i]<='9') {c.push_back(s[i]);i++;}
    if(c.length()) ans=termmult(ans,c);

    if(i==s.length()) return "0";

    if(s[i]=='('){
        i++;
        int lb=1,rb=0;
        while(1){
            if(s[i]=='(') lb++;
            else if(s[i]==')') rb++;
            if(lb!=rb) temp1+=s[i];
            else break;
            i++;
        }
        i++;
        if(i==s.length()){
            temp1=termdiff(temp1);
            ans=termmult(ans,temp1);
            return ans;
        }
        i+=2;c="";
        while(i!=s.length()-1) {c.push_back(s[i]);i++;}
        if(termdiff(temp1)=="0"){
            temp2="("+temp1+")^("+c+")ln("+temp1+")";
            ans=termmult(ans,termdiff(c));
            ans=termmult(ans,temp2);
            return ans;
        }
        temp=ctn(c);temp--;
        ans=termmult(ans,c);
        ans=termmult(ans,termdiff(temp1));
        if(temp<0){
            temp*=-1;c="-"+cts(temp);
        }
        else c=cts(temp);
        if(c!="1") temp2="("+temp1+")^("+c+")";
        else temp2=temp1;
        ans=termmult(ans,temp2);
        return ans;
    }
    
    if(s[i]=='e'){
        if(i+1==s.length()) return "0";
        i+=3;
        while(i!=s.length()-1) {temp1.push_back(s[i]);i++;}
        temp2="e^("+temp1+")";
        temp1=termdiff(temp1);
        ans=termmult(ans,temp1);
        ans=termmult(ans,temp2);
        return ans;
    }
    if(s[i]=='x'){
        if(i+1<s.length() && s[i+1]=='^'){
            i+=3;
            while(i!=s.length()-1) {temp1.push_back(s[i]);i++;}
            temp=ctn(temp1);temp--;
            ans=termmult(ans,temp1);
            if(temp==1) temp2="x";
            else if(temp<0){
                temp*=-1;
                temp1=cts(temp);
                temp2="x^(-"+temp1+')';
            }
            else{
                temp1=cts(temp);
                temp2="x^("+temp1+")";
            }
            ans=termmult(ans,temp2);
            return ans;
        }
        return ans;
    }
    if(s[i]=='l'){
        i+=3;
        while(i!=s.length()-1) {temp1.push_back(s[i]);i++;}
        temp2="(1/("+temp1+"))";
        temp1=termdiff(temp1);
        ans=termmult(ans,temp1);
        ans=termmult(ans,temp2);
        return ans;
    }
    if(s[i]=='a'){
        i+=3;
        if(s[i]=='s' && s[i+1]=='i'){
            i+=4;
            while(i!=s.length()-1) {temp1.push_back(s[i]);i++;}
            temp2="(1/((1-("+temp1+")^(2))^(0.5)))";
            temp1=termdiff(temp1);
            ans=termmult(ans,temp1);
            ans=termmult(ans,temp2);
            return ans;
        }
        if(s[i]=='s' && s[i+1]=='e'){
            i+=4;
            while(i!=s.length()-1) {temp1.push_back(s[i]);i++;}
            temp2="(1/(|"+temp1+"|*(("+temp1+")^(2)-1)^(0.5)))";
            temp1=termdiff(temp1);
            ans=termmult(ans,temp1);
            ans=termmult(ans,temp2);
            return ans;
        }
        if(s[i]=='c' && s[i+2]=='s'){
            i+=4;
            while(i!=s.length()-1) {temp1.push_back(s[i]);i++;}
            temp2="(-1/((1-("+temp1+")^(2))^(0.5)))";
            temp1=termdiff(temp1);
            ans=termmult(ans,temp1);
            ans=termmult(ans,temp2);
            return ans;
        }
        if(s[i]=='c' && s[i+2]=='c'){
            i+=4;
            while(i!=s.length()-1) {temp1.push_back(s[i]);i++;}
            temp2="(-1/(|"+temp1+"|*(("+temp1+")^(2)-1)^(0.5)))";
            temp1=termdiff(temp1);
            ans=termmult(ans,temp1);
            ans=termmult(ans,temp2);
            return ans;
        }
        if(s[i]=='c' && s[i+2]=='t'){
            i+=4;
            while(i!=s.length()-1) {temp1.push_back(s[i]);i++;}
            temp2="(-1/(1+("+temp1+")^(2)))";
            temp1=termdiff(temp1);
            ans=termmult(ans,temp1);
            ans=termmult(ans,temp2);
            return ans;
        }
        if(s[i]=='t'){
            i+=4;
            while(i!=s.length()-1) {temp1.push_back(s[i]);i++;}
            temp2="(1/(1+("+temp1+")^(2)))";
            temp1=termdiff(temp1);
            ans=termmult(ans,temp1);
            ans=termmult(ans,temp2);
            return ans;
        }
    }
    if(s[i]=='s' && s[i+1]=='i' && s[i+3]=='h'){
        i+=5;
        while(i!=s.length()-1) {temp1.push_back(s[i]);i++;}
        temp2="cosh("+temp1+")";
        temp1=termdiff(temp1);
        ans=termmult(ans,temp1);
        ans=termmult(ans,temp2);
        return ans;
    }
    if(s[i]=='c' && s[i+2]=='s' && s[i+3]=='h'){
        i+=5;
        while(i!=s.length()-1) {temp1.push_back(s[i]);i++;}
        temp2="sinh("+temp1+")";
        temp1=termdiff(temp1);
        ans=termmult(ans,temp1);
        ans=termmult(ans,temp2);
        return ans;
    }
    if(s[i]=='c' && s[i+2]=='c' && s[i+3]=='h'){
        i+=5;
        while(i!=s.length()-1) {temp1.push_back(s[i]);i++;}
        temp2="-coth("+temp1+")*csch("+temp1+")";
        temp1=termdiff(temp1);
        ans=termmult(ans,temp1);
        ans=termmult(ans,temp2);
        return ans;
    }
    if(s[i]=='s' && s[i+1]=='e' && s[i+3]=='h'){
        i+=5;
        while(i!=s.length()-1) {temp1.push_back(s[i]);i++;}
        temp2="-tanh("+temp1+")*sech("+temp1+")";
        temp1=termdiff(temp1);
        ans=termmult(ans,temp1);
        ans=termmult(ans,temp2);
        return ans;
    }
    if(s[i]=='t' && s[i+3]=='h'){
        i+=5;
        while(i!=s.length()-1) {temp1.push_back(s[i]);i++;}
        temp2="(1-(tanh("+temp1+"))^(2))";
        temp1=termdiff(temp1);
        ans=termmult(ans,temp1);
        ans=termmult(ans,temp2);
        return ans;
    }
    if(s[i]=='c' && s[i+2]=='t' && s[i+3]=='h'){
        i+=5;
        while(i!=s.length()-1) {temp1.push_back(s[i]);i++;}
        temp2="(1-(coth("+temp1+"))^(2))";
        temp1=termdiff(temp1);
        ans=termmult(ans,temp1);
        ans=termmult(ans,temp2);
        return ans;
    }
    if(s[i]=='s' && s[i+1]=='i'){
        i+=4;
        while(i!=s.length()-1) {temp1.push_back(s[i]);i++;}
        temp2="cos("+temp1+")";
        temp1=termdiff(temp1);
        ans=termmult(ans,temp1);
        ans=termmult(ans,temp2);
        return ans;
    }
    if(s[i]=='c' && s[i+2]=='s'){
        i+=4;
        while(i!=s.length()-1) {temp1.push_back(s[i]);i++;}
        temp2="-sin("+temp1+")";
        temp1=termdiff(temp1);
        ans=termmult(ans,temp1);
        ans=termmult(ans,temp2);
        return ans;
    }
    if(s[i]=='c' && s[i+2]=='c'){
        i+=4;
        while(i!=s.length()-1) {temp1.push_back(s[i]);i++;}
        temp2="-cot("+temp1+")*csc("+temp1+")";
        temp1=termdiff(temp1);
        ans=termmult(ans,temp1);
        ans=termmult(ans,temp2);
        return ans;
    }
    if(s[i]=='s' && s[i+1]=='e'){
        i+=4;
        while(i!=s.length()-1) {temp1.push_back(s[i]);i++;}
        temp2="-tan("+temp1+")*sec("+temp1+")";
        temp1=termdiff(temp1);
        ans=termmult(ans,temp1);
        ans=termmult(ans,temp2);
        return ans;
    }
    if(s[i]=='t'){
        i+=4;
        while(i!=s.length()-1) {temp1.push_back(s[i]);i++;}
        temp2="(sec("+temp1+"))^(2)";
        temp1=termdiff(temp1);
        ans=termmult(ans,temp1);
        ans=termmult(ans,temp2);
        return ans;
    }
    if(s[i]=='c' && s[i+2]=='t'){
        i+=4;
        while(i!=s.length()-1) {temp1.push_back(s[i]);i++;}
        temp2="-(csc("+temp1+"))^(2)";
        temp1=termdiff(temp1);
        ans=termmult(ans,temp1);
        ans=termmult(ans,temp2);
        return ans;
    }
    return "";
}

string specialdiff(string s1,string s2,string s3)
{
    string temp1="",temp2="",ans1,c="",finalans;
    int i=0,lb=1,rb=0;
    i++;
    while(1){
        if(s1[i]=='(') lb++;
        else if(s1[i]==')') rb++;
        if(lb!=rb) temp1+=s1[i];
        else break;
        i++;
    }
    i++;
    if(i<s1.length() && s1[i]=='^'){
        i+=2;lb=1;rb=0;
        while(1){
            if(s1[i]=='(') lb++;
            else if(s1[i]==')') rb++;
            if(lb!=rb) c+=s1[i];
            else break;
            i++;
        }
        if(diff(temp1)=="0"){
            temp2="("+temp1+")^("+c+")ln("+temp1+")";
            ans1=termmult(diff(c),temp2);
        }
        else{
            int temp=ctn(c);
            ans1=termmult(c,diff(temp1));
            temp--;
            if(temp<0){
                temp*=-1;c='-'+cts(temp);
            }
            else c=cts(temp);
            if(c!="1") temp2="("+temp1+")^("+c+")";
            else temp2=temp1;
            ans1=termmult(ans1,temp2);
        }
    }
    else{
        ans1=diff(temp1);
    }
    if(s3==""){
        if(s2==""){
            return ans1;
        }
        temp1=termmult(ans1,s2);
        if(temp1!="0") finalans=temp1;
        temp2=termmult(s1,diff(s2));
        if(finalans=="") finalans=temp2;
        else if(temp2[0]=='-') finalans+=temp2;
        else if(temp2!="0") finalans+="+"+temp2;
        return finalans;
    }
    else{
        ans1=diff(s1+s2);
        temp1=termmult(ans1,s3);
        temp2=termmult(s1+s2,diff(s3));
        finalans='('+temp1+"-"+temp2+")/(("+s3+")^(2))";
        return finalans;
    }

}

string diff(string s)
{
    string c="",ans="",tempans="",temp1,temp2,temp3;
    int i=0,temp,lb=0,rb=0;

    while(i<s.length())
    {
        tempans="1";c="";
        if(s[i]=='-') {tempans="-1";i++;}
        else if(s[i]=='+') i++;
        while(i<s.length() && s[i]>='0' && s[i]<='9') {c.push_back(s[i]);i++;}
        if(c!="") tempans=termmult(tempans,c);
        if(s[i]=='('){
            lb=0;rb=0;temp1="";temp2="",temp3="";
            while(1){
                if(s[i]=='(') lb++;
                else if(s[i]==')') rb++;
                if(lb!=rb) temp1+=s[i];
                else break;
                i++;
            }
            temp1+=')';i++;
            if(i<s.length() && s[i]=='^'){
                temp1+="^(";i+=2;
                lb=1;rb=0;
                while(1){
                    if(s[i]=='(') lb++;
                    else if(s[i]==')') rb++;
                    if(lb!=rb) temp1+=s[i];
                    else break;
                    i++;
                }
                temp1+=')';i++;
            }
            while(i<s.length() && s[i]=='('){
                lb=0;rb=0;
                while(1){
                    if(s[i]=='(') lb++;
                    else if(s[i]==')') rb++;
                    if(lb!=rb) temp2+=s[i];
                    else break;
                    i++;
                }
                temp2+=')';i++;
                if(i<s.length() && s[i]=='^') {temp2+='^';i++;}
            }
            if(i<s.length() && s[i]=='/'){
                i++;lb=0;rb=0;
                while(1){
                    if(s[i]=='(') lb++;
                    else if(s[i]==')') rb++;
                    if(lb!=rb) temp3+=s[i];
                    else break;
                    i++;
                }
                temp3+=')';i++;
            }
            tempans=termmult(tempans,specialdiff(temp1,temp2,temp3));
            if((ans=="" || tempans[0]=='-') && tempans!="0") ans+=tempans;
            else if(tempans!="0") ans+="+"+tempans;
        }
        else{
            if(i==s.length() || s[i]=='+' || s[i]=='-'){
            }
            else{
            temp1="";
            while(i<s.length() && s[i]!='(') {temp1+=s[i];i++;}
            lb=0;rb=0;
            while(1){
                if(s[i]=='(') lb++;
                else if(s[i]==')') rb++;
                if(lb!=rb) temp1+=s[i];
                else break;
                i++;
            }
            temp1+=')';i++;
            tempans=termmult(tempans,termdiff(temp1));
            if((ans=="" || tempans[0]=='-') && tempans!="0") ans+=tempans;
            else if(tempans!="0") ans+='+'+tempans;
            }
        }
    }
    if(ans=="") return "0";
    if(ans[0]!='(') ans='('+ans+')';
    return ans;
}

int main()
{
    fstream myfile;
    myfile.open("input.txt");
    string s;
    myfile >> s;

    cout<<diff(s)<<endl;
    myfile.close();
    return 0;
}