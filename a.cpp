#include <bits/stdc++.h>
using namespace std;

float a[10001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t,n,m,t1=1;
    float s,s1;
    cin>>t;
    while(t--){
        cin>>n>>m;s=0;
        cout<<"Case #"<<t1<<": ";t1++;
        for(int i=1;i<=n;i++){
            cin>>a[i];s+=a[i];
        }
        if(n-m>1){
            sort(a+1,a+n+1);
            s=0;
            for(int i=n,j=1;j<m;j++,i--){
                s+=a[i];
            }
            s1=0;
            if((n-m+1)%2) s1=a[(n-m+2)/2];
            else s1=(a[(n-m+1)/2]+a[(n-m+1)/2+1])/2;
            s1*=1.0;
            cout<<s+s1<<endl;
            continue;
        }
        if(n==m){
            cout<<s<<endl;continue;
        }
        sort(a+1,a+n+1);
        s-=a[1]+a[2];
        s+=(a[1]+a[2])/2;
        cout<<s<<endl;
    }
    return 0;
}