#include <iostream>
#include <math.h>
#include "nrComplex.h"
using namespace std;


/*void nrComplex::citire()
{
    cout<<"real=";
    cin>>pReal;
    cout<<"imag=";
    cin>>pImag;
}
*/

void nrComplex::afisare()
{
    if(pReal==0 && pImag==0)
        cout<<0<<"\n";
    if(pReal!=0 && pImag==0)
        cout<<pReal<<"\n";
    if(pReal==0 && pImag!=0)
        cout<<pImag<<"*i\n";
    if(pReal>0 && pImag>0)
        cout<<pReal<<"+"<<pImag<<"*i\n";
    if(pReal<0 && pImag<0)
        cout<<pReal<<"-"<<-pImag<<"*i\n";
    if(pReal>0 && pImag<0)
        cout<<pReal<<"-"<<-pImag<<"*i\n";
    if(pReal<0 && pImag>0)
        cout<<pReal<<"+"<<pImag<<"*i\n";


}


double nrComplex::get_real(){return pReal;}
double nrComplex::get_imag(){return pImag;}
void nrComplex::set_real(double r){pReal=r;}
void nrComplex::set_imag(double i){pImag=i;}



nrComplex operator+(const nrComplex& first,const nrComplex& second)
{
    nrComplex suma;
    suma.pReal=first.pReal+second.pReal;
    suma.pImag=first.pImag+second.pImag;
    return suma;
}


nrComplex operator+(double smth,const nrComplex& nr)
{
    nrComplex suma;
    suma.pReal=smth+nr.pReal;
    suma.pImag=nr.pImag;
    return suma;
}


nrComplex operator+(const nrComplex& nr,const double smth)
{
    nrComplex suma;
    suma.pReal=nr.pReal+smth;
    suma.pImag=nr.pImag;
    return suma;
}




nrComplex operator-(const nrComplex& first,const nrComplex& second)
{
    nrComplex diferenta;
    diferenta.pReal=first.pReal-second.pReal;
    diferenta.pImag=first.pImag-second.pImag;
    return diferenta;
}


nrComplex operator-(double smth,const nrComplex& nr)
{
    nrComplex diferenta;
    diferenta.pReal=smth-nr.pReal;
    diferenta.pImag=-nr.pImag;
    return diferenta;
}


nrComplex operator-(const nrComplex& nr,double smth)
{
    nrComplex diferenta;
    diferenta.pReal=nr.pReal-smth;
    diferenta.pImag=nr.pImag;
    return diferenta;
}




nrComplex operator+(const nrComplex& nr)
{
    nrComplex semn;
    semn.pReal=nr.pReal;
    semn.pImag=nr.pImag;
    return semn;
}


nrComplex operator-(const nrComplex& nr)
{
    nrComplex semn;
    semn.pReal=-nr.pReal;
    semn.pImag=-nr.pImag;
    return semn;
}



nrComplex operator*(const nrComplex& first,const nrComplex& second)
{
    nrComplex inmultire;
    inmultire.pReal=first.pReal*second.pReal-first.pImag*second.pImag;
    inmultire.pImag=first.pReal*second.pImag+second.pReal*first.pImag;
    return inmultire;
}


nrComplex operator*(double smth,const nrComplex& nr)
{

    nrComplex inmultire;
    inmultire.pReal=smth*nr.pReal;
    inmultire.pImag=smth*nr.pImag;
    return inmultire;
}


nrComplex operator*(const nrComplex& nr,double smth)
{
    nrComplex inmultire;
    inmultire.pReal=nr.pReal*smth;
    inmultire.pImag=nr.pImag*smth;
    return inmultire;
}



nrComplex operator/(const nrComplex& first,const nrComplex& second)
{
    nrComplex impartire;
    impartire.pReal=(first.pReal*second.pReal+first.pImag*second.pImag)/(second.pReal*second.pReal+second.pImag*second.pImag);
    impartire.pImag=(second.pReal*first.pImag-first.pReal*second.pImag)/(second.pReal*second.pReal+second.pImag*second.pImag);
    return impartire;
}


nrComplex operator/(double smth,const nrComplex& nr)
{
    nrComplex impartire;
    impartire.pReal=smth*nr.pReal/(nr.pReal*nr.pReal+nr.pImag*nr.pImag);
    impartire.pImag=-smth*nr.pImag/(nr.pReal*nr.pReal+nr.pImag*nr.pImag);
    return impartire;

}


nrComplex operator/(const nrComplex& nr,double smth)
{
    nrComplex impartire;
    impartire.pReal=nr.pReal/smth;
    impartire.pImag=nr.pImag/smth;
    return impartire;
}



int operator==(const nrComplex& first,const nrComplex& second)
{
    if(first.pReal==second.pReal && first.pImag==second.pImag)
        return 1;
    else
        return 0;
}


int operator==(double smth,const nrComplex& nr)
{
    if (smth==nr.pReal && nr.pImag==0)
        return 1;
    else
        return 0;
}


int operator==(const nrComplex& nr,double smth)
{
    if (nr.pReal==smth && nr.pImag==0)
        return 1;
    else
        return 0;

}



nrComplex& operator+=(nrComplex& first,const nrComplex& second)
{
    first.pReal=first.pReal+second.pReal;
    first.pImag=first.pImag+second.pImag;
    return first;

}


nrComplex& operator+=(nrComplex& nr,double smth)
{
    nr.pReal=nr.pReal+smth;
    return nr;
}



nrComplex& operator-=(nrComplex& first,const nrComplex& second)
{
    first.pReal-=second.pReal;
    first.pImag-=second.pImag;
    return first;

}


nrComplex& operator-=(nrComplex& nr,double smth)
{
    nr.pReal-=smth;
    return nr;
}



nrComplex& operator*=(nrComplex& first,const nrComplex& second)
{
    nrComplex inmultire;
    inmultire.pReal=first.pReal*second.pReal-first.pImag*second.pImag;
    inmultire.pImag=first.pReal*second.pImag+second.pReal*first.pImag;
    first.pReal=inmultire.pReal;
    first.pImag=inmultire.pImag;
    return first;
}


nrComplex& operator*=(nrComplex& nr,double smth)
{
    nr.pReal*=smth;
    nr.pImag*=smth;
    return nr;
}



nrComplex& operator/=(nrComplex& first,const nrComplex& second)
{
    nrComplex impartire;
    impartire.pReal=(first.pReal*second.pReal+first.pImag*second.pImag)/(second.pReal*second.pReal+second.pImag*second.pImag);
    impartire.pImag=(second.pReal*first.pImag-first.pReal*second.pImag)/(second.pReal*second.pReal+second.pImag*second.pImag);
    first.pReal=impartire.pReal;
    first.pImag=impartire.pImag;
    return first;
}


nrComplex& operator/=(nrComplex& nr,double smth)
{
    nr.pReal/=smth;
    nr.pImag/=smth;
    return nr;
}




nrComplex& operator^(const nrComplex& nr,int expo)
{
    nrComplex rezultat;
    rezultat.pReal=nr.pReal;
    rezultat.pImag=nr.pImag;
    double real,imag;
    if(expo==0)
    {
        rezultat.pReal=1;
        rezultat.pImag=0;
        return rezultat;
    }
    if(expo==1)
        return rezultat;

    for(int i=2; i<=expo; i++)
    {

        real=rezultat.pReal*nr.pReal-rezultat.pImag*nr.pImag;
        imag=nr.pReal*rezultat.pImag+rezultat.pReal*nr.pImag;
        rezultat.pReal=real;
        rezultat.pImag=imag;
    }


    return rezultat;


}



/*double abs(const nrComplex &z)
{

    double x,y;
    x=z.pImag;
    y=z.pReal;
    return sqrt(x*x+y*y);
}*/



nrComplex sqrt(const nrComplex& nr)
{
    nrComplex radPatratica;
    radPatratica.pReal=sqrt((nr.pReal+sqrt(nr.pImag*nr.pImag+nr.pReal*nr.pReal))/2);
    if(radPatratica.pReal!=0)
        radPatratica.pImag = nr.pImag/(2*radPatratica.pReal);
    else
    {
        radPatratica.pImag = sqrt(-nr.pReal);
        radPatratica.pReal=0;
    }
    return radPatratica;
}










///operatori citire / scriere

istream& operator>>(istream &in,const nrComplex& nr)
{
    in>>nr.pReal>>nr.pImag;
    return in;
}

ostream& operator<<(ostream& out,const nrComplex & nr)
{
    out<<nr.pReal<<nr.pImag;
}
ostream& operator<<(ostream& out,const nrComplex & first,const nrComplex & second)
{
    out<<first.pReal+second.pReal<<"+"<<first.pImag+second.pImag<<"\n";
}


///fct friend -> fct membra
double nrComplex::abs(const nrComplex &z)
{
    double x,y;
    x=z.pImag;
    y=z.pReal;
    return sqrt(x*x+y*y);
}


///fct membra -> fct friend
void citire(nrComplex &z)
{
    cout<<"real=";
    cin>>z.pReal;
    cout<<"imag=";
    cin>>z.pImag;
}

///operator postfixat si prefixat
nrComplex nrComplex::operator++()// prefixat ++obiect
{
    pReal++;
    pImag++;
    return *this;
}

nrComplex nrComplex::operator++(int pReal)//postfixat obiect++
{
    pReal++;
    return *this;
}
///operator de atribuiere
nrComplex &nrComplex::operator=(const nrComplex& nr)
{
    pReal=nr.pReal;
    pImag=nr.pImag;
    return *this;
}



int main()
{
    nrComplex a,b,c,x,y,delta;
    cout<<"a:\n";
    a.citire();
    cout<<"b:\n";
    b.citire();
    cout<<"c:\n";
    c.citire();
    if (a==0)
        if(b==0)
            if(c==0)
                cout<<"O infinitate de solutii\n";
            else
                cout<<"Multimea vida\n";
        else
        {

            x=-c/b;
            cout<<"x=";
            x.afisare();
        }
    else
    {
        delta=b*b-4*a*c;
        cout<<"delta=";
        delta.afisare();
        x=(b+sqrt(delta))/(-2*a);
        y=(sqrt(delta)-b)/(2*a);
        cout<<"x1=";
        x.afisare();
        cout<<"\nx2=";
        y.afisare();
    }
    return 0;
}
