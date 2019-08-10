#include<bits/stdc++.h>
#include<string.h>
#define ae(t,ch) add_empty(&temp,str[i])
#define a(t,ch) add(&temp,str[i])
#define i(t) insert(&temp)
using namespace std;
// Program to convert string array to integer array
int arr[100];
int k=0;
void add_empty(string *str,char ch){
    *str="";
    *str+=ch;}
void add(string *str,char ch){
    *str+=ch;}
void insert(string *temp){
    arr[k]=stoi(*temp);
    k++;
    *temp="";
}
    
int main(){
    string str;
    string temp="";
    int i=0;
    getline(cin,str);
    do{
        do{
            if(str[i]==' '){
            i++;}
            if(i==0)
            ae(t,ch);
            else if(str[i-1]==' ')
                ae(t,ch);
            else
                a(t,ch);
            i++;
        }while(str[i]!='\0'&&str[i]!=' ');
        
        i(t);}while(str[i]!='\0');
        
    for(int j=0;j<k;j++)
    cout<<arr[j]<<" ";
    return 0;}
