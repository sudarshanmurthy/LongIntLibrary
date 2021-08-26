#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int greater(const char *r,const char *s)
{
    int counter=0;
    while(counter<strlen(s))
    {
        if(r[counter]>s[counter])
            return 1;
        else if(r[counter]<s[counter])
            return 0;
        counter++;
    }
    return 1;
}

static char** createArray(int m)
{
    char ** x=malloc(sizeof(char *)*m);
    return x;
}

static int equality(const char *r,const char *s)
{
    if(strlen(r)!=strlen(s))
        return 0;
    int length=strlen(s);
    int p=0;
    while(p<length)
    {
        if(r[p]!=s[p])
            return 0;
        p++;
    }
    return 1;
}

static char *duplicate(const char * str)
{
    int length_str=strlen(str);
    char *x=malloc(sizeof(char)*(length_str+1));
    for(int i=0;i<=length_str;i++)
        x[i]=str[i];
    return x;
}

static char* ctostr(int unsigned x)
{
    char *result;
    int c=0;
    int k=x;
    while(k)
    {
        c++;
        k/=10;
    }
    result=malloc(sizeof(char)*(c+1));
    result[c--]='\0';
    while(x)
    {
        result[c--]=48 + x%10;
        x/=10;
    }
    return result;
   
}

static void strRev(char * str)
{
    int len_str = strlen(str);
    int var=0;
    while(var < len_str / 2)
    {
        char ch = str[var];
        str[var]=str[len_str-var-1];
        str[len_str-var-1]=ch;
        var++;
    }
}


int intal_compare(const char* intal1, const char* intal2){
if(strlen(intal1)>strlen(intal2)){
return 1;}
else if(strlen(intal1)<strlen(intal2)){
return -1;}
else{
for(int i=0;i<strlen(intal1);i++){
if(intal1[i]>intal2[i]){return 1;}
else if(intal1[i]<intal2[i]){return -1;}
}
return 0;
}
}

char* intal_diff(const char* intal1, const char* intal2){
char *intal11=duplicate(intal1);
char *intal22=duplicate(intal2);
int com=intal_compare(intal22,intal11);
if(com==0){
char *res=malloc(sizeof(char)*2);
res[0]=48;
res[1]='\0';
return res;}
if(com==1){
char *l=intal11;
intal11=intal22;
intal22=l;}
int a=strlen(intal11);
int b=strlen(intal22);
char *res;

int n=a>b?a:b;

int min=(n==a)?b:a;
res=(char *)malloc(sizeof(char)*(n+2));
strRev(intal11);
strRev(intal22);
int carry=0;
int m=0;
for (int i=0; i<min; i++)
    {
        int sum = (intal11[i]-'0')-(intal22[i]-'0')-carry;
if(sum<0){
sum+=10;
carry=1;}
   
else{
carry=0;}
res[m++]=48+sum;
    }
 
    for (int i=min; i<n; i++)
    {
     int sum = (intal11[i]-'0')-carry;
if(sum<0){
sum+=10;
carry=1;}
else{
carry=0;}
        res[m++]=48+sum;  
    }
m--;
while(res[m]==48){
m--;}
m++;
res[m]='\0';
 
    strRev(res);
free(intal11);
free(intal22);
   
    return res;
}
char* intal_mod(const char *a,const char *b){
if(intal_compare(a,b)==-1){char *l=duplicate(a);return l;}
int diffbits=strlen(a)-strlen(b);
int remobit=(greater(a,b)==1)?0:1;
diffbits-=remobit;
if(diffbits>0){
char *extended=malloc(sizeof(char)*(strlen(b)+diffbits+1));
for(int i=0;i<strlen(b);i++){
extended[i]=b[i];}
int m=strlen(b);
for(int i=0;i<diffbits;i++){
extended[i+m]=48;}
extended[diffbits+m]='\0';
extended=intal_diff(a,extended);
return intal_mod(extended,b);}
return intal_mod(intal_diff(a,b),b);
}


char* intal_multiply(const char* intal1, const char* intal2)
{
    if(intal1[0]==48||intal2[0]==48)
    {
        char *result = (char*)malloc(sizeof(char)*2);
        result[0] = 48;
        result[1] = '\0';
        return result;
    }
    int len_1 = strlen(intal1);
    int len_2 = strlen(intal2);
    char* result = malloc(sizeof(char)*(len_1+len_2+2));
    int value1 = 0;  
    int value2 = 0;  
    int i= 0;
    while(i < len_1 + len_2 + 2)
    {
        result[i]=48;
        i++;
    }
    i=len_1 -1;
    while(i >=0)
    {
        int val = 0;  
        int val1 = intal1[i] - '0';
        value2 = 0;
        int j = len_2 - 1;    
        while(j >= 0)  
        {  
            int val2 = intal2[j] - '0';  
 
            int s = val1 * val2 + (result[value1 + value2]- '0') + val;  
            val = s / 10;  
            result[value1 + value2] = 48+(s % 10);  
            value2++;  
            j--;
        }  
        if (val > 0)  
            result[value1 + value2] = 48+ result[value1+value2] -'0'+ val;  
        value1++;
        i--;
    }

    int value = value1 + value2 -1 ;
    while(result[value]==48)
        value--;
    result [ value + 1] = '\0';
    strRev(result);
    return result;
}

char* intal_add(const char* intal1, const char* intal2){
char *intal11=duplicate(intal1);
char *intal22=duplicate(intal2);
int a=strlen(intal11);
int b=strlen(intal22);
char *res;
int n=a>b?a:b;
if(intal_compare(intal22,intal11)==1){
char *l=intal11;
intal11=intal22;
intal22=l;}
int min=(n==a)?b:a;
res=(char *)malloc(sizeof(char)*(n+2));
strRev(intal11);
strRev(intal22);
int carry=0;
int m=0;
for (int i=0; i<min; i++)
    {
        int sum = (intal11[i]-'0')+(intal22[i]-'0')+carry;
        res[m++]=48+sum%10;
        carry = sum/10;
    }
 
    for (int i=min; i<n; i++)
    {
     int sum = (intal11[i]-'0')+carry;
        res[m++]=48+sum%10;
        carry = sum/10;  
    }
 
 
    if (carry){
        res[m++]=48+carry;}
res[m]='\0';
 
    strRev(res);
free(intal11);
free(intal22);
    return res;
}



char * intal_fibonacci(unsigned int n)
{
    char * arr1 = (char*)malloc(2 * sizeof(char));
    arr1[0]=48;
    arr1[1]='\0';
    char* arr2 = (char*)malloc(2* sizeof(char));
    arr2[0]=49;
    arr2[1]='\0';
    if(n==0){
        return arr1;}
    if(n==1){
        return arr2;}
    while(n-1)
    {
        char * a3 = intal_add(arr1, arr2);
        arr1=arr2;
        arr2=a3;
        n--;
    }
    return arr2;
}

char* intal_factorial(unsigned int n)
{
    if(n==1||n==0)
    {
        char * var = malloc(sizeof(char)*2);
        var[1]='\0';
        var[0]=49;
        return var;
    }
    return intal_multiply(ctostr(n),intal_factorial(n-1));
}

char* intal_bincoeff(unsigned int n, unsigned int k)
{
    char** dp_table = malloc(sizeof(char* ) * (k+1));
    for(int a=0; a<=k; a++)
        dp_table[a]="0";

    dp_table[0] = malloc(sizeof(char)*2);
    dp_table[0][0]=49;
    dp_table[0][1]='\0';
   
    int var = 1;
    while(var <=n)
    {
        int r = var>k ? k : var;
        int var1 = r;
        while(var1 > 0)
        {
            dp_table[var1] = intal_add(dp_table[var1], dp_table[var1-1]);
            var1--;
        }
        var++;
    }
    char * result = (char*)malloc(sizeof(char)* strlen(dp_table[k]));
    strcpy(result,dp_table[k]);
    for(int i=0;i<k+1;i++)
        free(dp_table[i]);
    free(dp_table);
    return result;
}

char * intal_pow(const char *intal1,unsigned int n)
{
    if (n == 0){
               char *v=malloc(sizeof(char)*2);
v[1]='\0';
v[0]=49;
return v;}
    else if (n%2 == 0){
        return intal_multiply(intal_pow(intal1, n/2),intal_pow(intal1, n/2));}
    else{
        return intal_multiply(intal1,intal_multiply(intal_pow(intal1, n/2),intal_pow(intal1, n/2)));}
}



char* intal_gcd(const char *intal1, const char *intal2){
if(intal1[0]==48 && intal2[0]==48){char *res=malloc(sizeof(char)*2);
res[1]='\0';
res[0]=48;
return res;}

if(intal2[0]==48){ char *res=duplicate(intal1);return res;}

else{ return intal_gcd(intal2,intal_mod(intal1,intal2));}

}
int intal_max(char **arr, int n)
{
    char *result = arr[0];
    int pos=0;
    int i=0;
    while(i<n)
    {
        if(intal_compare(arr[i],result)==1)
        {
            pos=i;
            result=arr[i];
        }
        i++;
    }
    return pos;
}

int intal_min(char **arr, int n)
{
    char *result = arr[0];
    int pos=0;
    int i=0;
    while(i<n)
    {
        if(intal_compare(arr[i],result)== -1)
        {
            pos=i;
            result=arr[i];
        }
        i++;
    }
    return pos;
}

int intal_search(char **arr, int n, char* key)
{
    int search_res=-1;
    int i=0;
    while(i<n)
    {
        if(equality(arr[i],key)==1)
        {
            search_res=i;
            break;
        }
        i++;
    }
    return search_res;
}

static int binsearch1(char **arr, int l, int r, char *key)
{
    if (r >= l)
    {
        int middle = l + (r - l) / 2;
        if (intal_compare(arr[middle],key)==0)
            return middle;
        if (intal_compare(arr[middle],key)==1)
            return binsearch1(arr, l, middle - 1, key);
        return binsearch1(arr, middle + 1, r, key);
    }
    return -1;
}

int intal_binsearch(char **arr, int n, char* key)
{
    return binsearch1(arr,0,n-1,key);
}

static void merge(char** arr, int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
 
    char** L=createArray(n1);
    char** R=createArray(n2);
    for (i = 0; i < n1; i++){
        L[i] = duplicate(arr[l + i]);}
    for (j = 0; j < n2; j++){
        R[j] = duplicate(arr[m + 1+ j]);}
 
    i = 0;  
    j = 0;
    k = l;  
    while (i < n1 && j < n2)
    {
        if (intal_compare(L[i],R[j])<=0)
        {
            arr[k] = duplicate(L[i]);
            i++;
        }
        else
        {
            arr[k] = duplicate(R[j]);
            j++;
        }
        k++;
    }
 
    while (i < n1)
    {
        arr[k] = duplicate(L[i]);
        i++;
        k++;
    }
 
    while (j < n2)
    {
        arr[k] = duplicate(R[j]);
        j++;
        k++;
    }
for(int i=0;i<n1;i++){
free(L[i]);}
for(int i=0;i<n2;i++){
free(R[i]);}
free(L);
free(R);

}

static void mergeSort(char** arr, int l, int r)
{
    if (l < r)
    {
        int m = l+(r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }

}

void intal_sort(char **a, int n){

    mergeSort(a,0,n-1);
}

static char* max(const char *a,const char *b){
char *l=duplicate(a);
char *m=duplicate(b);
    if(intal_compare(l,m)==1){
        return l;
    }
    else{
        return m;
    }
}
static char* coin_row(char** arr,int index,int n)
{
    if (index==n)
        return "0";
    if (index==n-1)
        return arr[index];
    if (index==n-2)
        return max(arr[index],arr[index+1]);
    return max(intal_add(arr[index],coin_row(arr,index+2,n)),coin_row(arr,index+1,n));
}

char* coin_row_problem(char **arr, int n)
{
    return coin_row(arr,0,n);
}
