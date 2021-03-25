#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
struct Bint{
    int Blength;
    int num[1024];
    Bint(){
        memset(num,0,sizeof(num));
        Blength=0;
    }
};

Bint Change(string a){
    Bint x;
    int alen=a.size();
    for(int i=1;i<=alen;++i){
        x.num[i-1]=a[alen-i]-'0';
    }
    x.Blength=alen;
    return x;
}
int compare(Bint a ,Bint b){
    if(a.Blength>b.Blength){
        return 1;
    }else if(a.Blength<b.Blength){
        return -1;
    }else{
        int len=a.Blength;
        for(int i=1;i<=len;++i){
            if(a.num[len-i]>b.num[len-i]){
                return 1;
            }else if(a.num[len-i]<b.num[len-i]){
                return -1;
            }
        }
        return 0;
    }
}


Bint Badd(Bint a,Bint b){
    Bint c;
    int m=a.Blength;
    int n=b.Blength;
    for(int i=0;i<m||i<n;++i){
        c.num[c.Blength++]=a.num[i]+b.num[i];
    }
    int p=c.Blength;
    for(int i=0;i<p;++i){
        if(c.num[i]>=10){
        	if(i==p-1){
			c.Blength++;
			}
            c.num[i+1]=c.num[i+1]+c.num[i]/10;
            c.num[i]=c.num[i]%10;
        }
    }
    return c;
}

Bint BSub(Bint a,Bint b){
    Bint c;
    int m=a.Blength;
    int n=b.Blength;
    if(compare(a,b)==-1){
        c=BSub(b,a);
        cout<<"-";
        return c;
    }else if(compare(a,b)==0){
        return Change("0");
    }else{
        for(int i=0;i<m||i<n;++i){
            if(a.num[i]>=b.num[i]){
                c.num[c.Blength++]=a.num[i]-b.num[i];
            }else{
                int pos=i+1;
                while(a.num[pos]==0&&pos<a.Blength) 
                {
                    a.num[pos]=9;
                    pos++;
                }
                a.num[pos]--;
                c.num[c.Blength++]=a.num[i]-b.num[i]+10;
            }
    }
    while(c.num[c.Blength-1]==0){
        c.Blength--;
    }
    return c;
    }
}
Bint BMul(Bint a,Bint b){
    if(compare(a,Change("0"))==0||compare(b,Change("0"))==0){
        return Change("0");
    }
    Bint c;
    int m=a.Blength;
    int n=b.Blength;
    for(int i=0;i<m;++i){
        for(int j=0;j<n;++j){
            c.num[i+j]+=a.num[i]*b.num[j];
        }
    }
    for(int i=0;i<=1023;++i){
        if(c.num[i]>=10){
            c.num[i+1]=c.num[i+1]+c.num[i]/10;
            c.num[i]=c.num[i]%10;
        }
    }
    for(int i=1023;i>=0;--i){
        if(c.num[i]!=0){
            c.Blength=i+1;
            break;
        }
    }
    
    return c;
}
void Append(Bint& a,Bint& b){
    int m=a.Blength;
    int n=b.Blength;
    a.Blength=m+n;
    for(int i=0;i<n;++i){
        a.num[m+i]=b.num[i];
    }
}
Bint Append(Bint a,int b){
    int m=a.Blength;
    a.Blength=m+1;
    for(int i=m;i>0;--i){
        a.num[i]=a.num[i-1];
    }
    a.num[0]=b;
    return a;
}
Bint BDiv(Bint a,Bint b,Bint& r){
    Bint c;
    int m=a.Blength;
    int n=b.Blength;
    if(compare(a,b)==1){
        if(m==n){
            int count=0;
            while (compare(a,Change("0"))==1);
            {
                a=BSub(a,b);
                r=a;
                count++;
            }
            return c=Change(count+"0");
        }else{
            Bint tempa;
            for(int i=a.Blength;i>=0;--i){
                tempa=Append(tempa,a.num[i]);
                while(tempa.Blength-1>=1&&tempa.num[tempa.Blength-1]==0){
                    tempa.Blength--;
                }
                int count=0;
                while(compare(tempa,b)>=0&&compare(BSub(tempa,b),Change("0"))){
                    count++;
                    tempa=BSub(tempa,b);
                }
                c.num[i]=count;
                c.Blength+=1;
            }
            r=tempa;
            while(c.num[c.Blength-1]==0){c.Blength--;}    
            return c;
        }
    }else if(compare(a,b)==0){
        r=Change("0");
        return Change("1");
    }else{
        r=a;
        return Change("0");
    }
}
void PrintBInt(Bint num){
    int len=num.Blength;
    for(int i=len-1;i>=0;--i){
        
        cout<<num.num[i];
    }
    cout<<endl;
}
int main(){
    string s1="9999";
    string s2="100001";
    Bint r;
    Bint num1=Change(s1);
    Bint num2=Change(s2);
    PrintBInt(num1);
    PrintBInt(num2);
    Bint num3=BDiv(num2,num1,r);
    PrintBInt(num3);
    PrintBInt(r);

    return 0;
}