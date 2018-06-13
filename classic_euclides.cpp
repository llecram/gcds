#include<iostream>
#include<NTL/ZZ.h>
#include<time.h>
#include<stdio.h>
using namespace NTL;
using namespace std;
ZZ euclides(ZZ m, ZZ n){
     unsigned t0, t1;
      t0=clock();
    long long counter=0;
    ZZ memo(0);
     ZZ temp(0);
     memo+=NumBits(m);
     memo+=NumBits(n);
        if(m < n)
        {
                temp = m;
                memo+=NumBits(temp);
                m = n;
                memo+=NumBits(m);
                n = temp;
                memo+=NumBits(n);
        }
        while(n != 0)
        {
                counter++;
                temp = m % n;
                memo+=NumBits(temp);
                m = n;
                memo+=NumBits(m);
                n = temp;
                memo+=NumBits(n);
        }
        t1 = clock();
        double time = (double(t1-t0)/CLOCKS_PER_SEC);
        cout <<"Memory use: "<<memo<<endl;
        cout << "Execution Time: " << time << endl;
        cout << "Number of iterations: " << counter << endl;
        return m;
}
int main(){
    ZZ a;
    ZZ b;
    a=GenPrime_ZZ(800);
    b=GenPrime_ZZ(800);
    ZZ c(euclides(a,b));
    cout<<c<<endl;

}
