 #include <iostream>
 #include <NTL/ZZ.h>
 #include <math.h>
 #include <ctime>
 #include "asd.h"
 using namespace NTL;
using namespace std;
ZZ gcdext(ZZ x, ZZ y){
    unsigned t0, t1;
    t0=clock();
    ZZ counter(0);
    ZZ memo(0);
    ZZ g(1);
    memo+=NumBits(g);
    while(ZZ(x&1)==ZZ(0) && ZZ(y&1)==ZZ(0)){
        x>>=1;
        memo+=NumBits(x);
        y>>=1;
        memo+=NumBits(y);
        g<<=1;
        memo+=NumBits(g);
    }
    ZZ u(x);
    memo+=NumBits(u);
    ZZ v(y);
    memo+=NumBits(v);
    ZZ A(1);
    memo+=NumBits(A);
    ZZ B(0);
    memo+=NumBits(B);
    ZZ C(0);
    memo+=NumBits(C);
    ZZ D(1);
    memo+=NumBits(D);
    //cout<<u<<" & "<<v<<" & "<<A<<" & "<<B<<" & "<<C<<" & "<<D<<" & "<<endl;
    while(true){
        counter++;
        while(ZZ(u&1)==ZZ(0)){
            counter++;
            u>>=1;
            memo+=NumBits(u);
            if(ZZ((A|B)&1)==ZZ(0)){
                A>>=1;
                memo+=NumBits(A);
                B>>=1;
                memo+=NumBits(B);
                //cout<<u<<" & "<<v<<" & "<<A<<" & "<<B<<" & "<<C<<" & "<<D<<" & "<<endl;
            }
            else{
                A=(A+y)>>1;
                memo+=NumBits(A);
                B=(B-x)>>1;
                memo+=NumBits(B);
                //cout<<u<<" & "<<v<<" & "<<A<<" & "<<B<<" & "<<C<<" & "<<D<<" & "<<endl;
            }
        }
        while(ZZ(v&1)==ZZ(0)){
            counter++;
            v>>=1;
            memo+=NumBits(v);
            if(ZZ((C|D)&1)==ZZ(0)){
                C>>=1;
                memo+=NumBits(C);
                D>>=1;
                memo+=NumBits(D);
                //cout<<u<<" & "<<v<<" & "<<A<<" & "<<B<<" & "<<C<<" & "<<D<<" & "<<endl;
            }
            else{
                C=(C+y)>>1;
                memo+=NumBits(C);
                D=(D-x)>>1;
                memo+=NumBits(D);
                //cout<<u<<" & "<<v<<" & "<<A<<" & "<<B<<" & "<<C<<" & "<<D<<" & "<<endl;
            }
        }
        if(u>=v){
            u=u-v;
            memo+=NumBits(u);
            A=A-C;
            memo+=NumBits(A);
            B=B-D;
            memo+=NumBits(B);
           //cout<<u<<" & "<<v<<" & "<<A<<" & "<<B<<" & "<<C<<" & "<<D<<" & "<<endl;
        }
        else{
            v=v-u;
            memo+=NumBits(v);
            C=C-A;
            memo+=NumBits(C);
            D=D-B;
            memo+=NumBits(D);
            //cout<<u<<" & "<<v<<" & "<<A<<" & "<<B<<" & "<<C<<" & "<<D<<" & "<<endl;
        }
        if(u==ZZ(0)){
            ZZ a(C);
            memo+=NumBits(a);
            ZZ b(D);
            memo+=NumBits(b);
            t1 = clock();
            double time = (double(t1-t0)/CLOCKS_PER_SEC);
            //cout<<u<<" & "<<v<<" & "<<A<<" & "<<B<<" & "<<C<<" & "<<D<<" & "<<endl;
            cout<<"Numero de iteraciones: "<<counter<<endl;
            cout<<"Cantidad de memoria usada: "<<memo*ZZ(8)<<endl;
            cout <<"Tiempo de Ejecucion: " << time << endl;
            return a;
        }
    }
}
int main(){
    ZZ a, b;
    a=123214125123512512531;
    b=1235125321412351251235;
    long long tmanhio=sizeof(gcdext(a,b));
    long long das=sizeof(b);
   // int g=mem_total();
   cout<<a<<" "<<b<<endl;
    cout<<gcdext(a,b)<<endl;
    cout<<tmanhio;
}
