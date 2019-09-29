#include<iostream>  
#include<string>  
#include<algorithm>  
using namespace std;  
int n;  
bool judge(string s1,string s2,string s3)  
{  
    reverse(s1.begin(),s1.end());  
    bool flag=true;  
    for(int i=0;i<n;i++){  
        if(((s2[i]-'a'+s3[i]-'a')-2*(s1[i]-'a'))%26!=0){  
            flag=false;  
            break;  
        }  
    }  
    return flag;  
}  
int main()  
{  
    string s1,s2,s3;  
    cin>>n;  
    cin>>s1>>s2>>s3;  
    if(judge(s1,s2,s3)) reverse(s1.begin(),s1.end()),cout<<s1<<endl;  
    else if(judge(s2,s1,s3)) reverse(s2.begin(),s2.end()),cout<<s2<<endl;  
    else if(judge(s3,s2,s1))reverse(s3.begin(),s3.end()),cout<<s3<<endl;  
    return 0;  
}
