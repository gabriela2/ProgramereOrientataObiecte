#include <iostream>
#include <string.h>
#include <typeinfo>
using namespace std;

class Regnul_Animal{
protected:
    string denumire ;
    string subregn ;
    string specie ;
    int id ;
public:
    virtual void citire() ;
    virtual void afisare() ;
    ///constructor initializare
    Regnul_Animal()
    {
        id = 0 ;
        denumire = " " ;
        subregn = " " ;
        specie = " " ;
    }
    ///CONSTRUCTOR PARAMETRIZAT
    Regnul_Animal(string den, string subr, string spc, int idd)
    {
        denumire = den ;
        subregn = subr ;
        specie = spc ;
        id = idd ;
    }
    ///constructor de copiere
    Regnul_Animal(const Regnul_Animal& r)
    {
        denumire = r.denumire ;
        subregn = r.subregn ;
        specie = r.specie;
        id = r.id ;
    }
     ///destructor
    ~Regnul_Animal()
    {
        //cout<<"acesta este un destructor pentru clasa regnul animal\n";
    }

    ///fct de setare si obtinere a denumirii/subregnului/speciei/id
    int get_id();
    string get_denumire() ;
    string get_subregn() ;
    string get_specie() ;
    void set_id(int ) ;
    void set_denumire(string) ;
    void set_subregn(string) ;
    void set_specie(string) ;

    ///operatorii>> <<
    friend istream& operator>>(istream&,Regnul_Animal &);
    friend ostream& operator<<(ostream&,Regnul_Animal &);

};

///fct citire clasa regn animal
void Regnul_Animal::citire()
{
    cout<<"ID=";        cin>>id;
    try{
        for(int i='a';i<='z';i++)
            if(id==i)
            throw id;
    }
    catch (...){cout<<"Nu se poate alege o lite"<<endl;}
    cout<<"Denumire=";  cin>>denumire;
    cout<<"Subregn=";   cin>>subregn;
    cout<<"Specie=" ;   cin>>specie;

}

///fct afisare clasa regn animal
void Regnul_Animal::afisare()
{
    cout<<"ID="<<id<<endl;
    cout<<"Denumire="<<denumire<<endl;
    cout<<"Subregn="<<subregn<<endl;
    cout<<"Specie="<<specie<<endl;
}

///fct setare/returnare
int Regnul_Animal :: get_id(){return id;}
string Regnul_Animal :: get_denumire(){return denumire;}
string Regnul_Animal :: get_subregn(){return subregn;}
string Regnul_Animal :: get_specie(){return specie;}
void Regnul_Animal :: set_id(int idd){id=idd;}
void Regnul_Animal :: set_denumire(string den){denumire=den;}
void Regnul_Animal :: set_subregn(string subr){subregn=subr;}
void Regnul_Animal :: set_specie(string spc){specie=spc;}


///operatorii de citire, scriere si atribuiere
istream& operator>>(istream &in, Regnul_Animal& p)
{
    in>>p.id>>p.denumire>>p.subregn>>p.specie;
    return in;
}

ostream& operator<<(ostream& out, Regnul_Animal& p)
{
    out<<p.id<<" "<<p.denumire<<" "<<p.subregn<<" "<<p.specie<<endl;
    return out;
}




class Nevertebrate :public Regnul_Animal{
protected:
    string nume;
    string clasa;
public:

    virtual void citire();
    virtual void afisare();

    ///constructor initializare
    Nevertebrate()
    {
        id=0;
        denumire=" ";
        subregn=" ";
        specie=" ";
        nume=" ";
        clasa=" ";
    }

    ///CONSTRUCTOR PARAMETRIZAT
    Nevertebrate(int idd, string den, string subr, string spc, string num, string cls)
    {
        id=idd;
        denumire=den;
        subregn=subr;
        specie=spc;
        nume=num;
        clasa=cls;
    }

    ///constructor de copiere
    Nevertebrate(const Nevertebrate& n)
    {
        id=n.id;
        denumire=n.denumire;
        subregn=n.subregn;
        specie=n.specie;
        nume=n.nume;
        clasa=n.clasa;
    }

    ///destructor
    ~Nevertebrate()
    {
//        cout<<"acesta este un destructor pt clasa nevertebrate\n";
    }

    ///fct de setare si obtinere
    string get_nume();
    string get_clasa();
    void set_nume(string);
    void set_clasa(string);

    ///operatorii>> <<
    friend istream& operator>>(istream&,Nevertebrate &);
    friend ostream& operator<<(ostream&,Nevertebrate &);

};

///fct de citire a clasei nevertebrate
void Nevertebrate :: citire()
{
    cout<<"Nevertebrat"<<endl;
    Regnul_Animal::citire();
    cout<<"Nume=";  cin>>nume;
    cout<<"Clasa="; cin>>clasa;
    cout<<endl;
}

///fct de afisare a clasei nevertebrate
void Nevertebrate :: afisare()
{
    Regnul_Animal::afisare();
    cout<<"Nume="<<nume<<endl;
    cout<<"Clasa="<<clasa<<endl;
}

///fct de setare si obtinere
string Nevertebrate :: get_nume(){return nume;}
string Nevertebrate :: get_clasa(){return clasa;}
void Nevertebrate :: set_nume(string n){nume=n;}
void Nevertebrate :: set_clasa(string c){clasa=c;}


///operatorii de citire, scriere
istream& operator>>(istream &in, Nevertebrate& p)
{
    in>>p.id>>p.denumire>>p.subregn>>p.specie>>p.nume>>p.clasa;
    return in;
}

ostream& operator<<(ostream& out, Nevertebrate& p)
{
    out<<p.id<<" "<<p.denumire<<" "<<p.subregn<<" "<<p.specie<<" "<<p.nume<<" "<<p.clasa<<endl;
    return out;
}



class Vertebrate : virtual public Regnul_Animal{
protected:
    string infraincrengatura;
    string clasa;
public:

    virtual void citire();
    virtual void afisare();

    ///constructor initializare
    Vertebrate()
    {
        id=0;
        denumire=" ";
        subregn=" ";
        specie=" ";
        infraincrengatura=" ";
        clasa=" ";
    }

    ///CONSTRUCTOR PARAMETRIZAT
    Vertebrate(int idd, string den, string subr, string spc, string infra, string cls)
    {
        id=idd;
        denumire=den;
        subregn=subr;
        specie=spc;
        infraincrengatura=infra;
        clasa=cls;
    }

    ///constructor de copiere
    Vertebrate(const Vertebrate& n)
    {
        id=n.id;
        denumire=n.denumire;
        subregn=n.subregn;
        specie=n.specie;
        infraincrengatura=n.infraincrengatura;
        clasa=n.clasa;
    }

    ///destructor
    ~Vertebrate()
    {
  //      cout<<"acesta este un destructor pt clasa vertebrate\n";
    }

    ///fct de setare si obtinere
    string get_infraincrengatura();
    string get_clasa();
    void set_infraincrengatura(string);
    void set_clasa(string);

    ///operatorii>> <<
    friend istream& operator>>(istream&,Vertebrate &);
    friend ostream& operator<<(ostream&,Vertebrate &);

};

///fct de citire a clasei vertebrate
void Vertebrate :: citire()
{
    Regnul_Animal::citire();
    cout<<"Infraincrengatura=";  cin>>infraincrengatura;
    cout<<"Clasa="; cin>>clasa;
}

///fct de afisare a clasei vertebrate
void Vertebrate :: afisare()
{
    Regnul_Animal::afisare();
    cout<<"Infraincrengatura="<<infraincrengatura<<endl;
    cout<<"Clasa="<<clasa<<endl;
}

///fct de setare si obtinere
string Vertebrate :: get_infraincrengatura(){return infraincrengatura;}
string Vertebrate :: get_clasa(){return clasa;}
void Vertebrate :: set_infraincrengatura(string n){infraincrengatura=n;}
void Vertebrate :: set_clasa(string c){clasa=c;}


///operatorii de citire, scriere
istream& operator>>(istream &in, Vertebrate& p)
{
    in>>p.id>>p.denumire>>p.subregn>>p.specie>>p.infraincrengatura>>p.clasa;
    return in;
}

ostream& operator<<(ostream& out, Vertebrate& p)
{
    out<<p.id<<" "<<p.denumire<<" "<<p.subregn<<" "<<p.specie<<" "<<p.infraincrengatura<<" "<<p.clasa<<endl;
    return out;
}



class Pesti: public Vertebrate{
protected:
    float greutate_ma;
    string nume;
    string apa;
public:
    virtual void citire();
    virtual void afisare();
    ///constructor de initializare
    Pesti()
    {
        id=0;
        denumire=" ";
        subregn=" ";
        specie=" ";
        infraincrengatura=" ";
        clasa=" ";
        greutate_ma=0;

        nume=" ";
        apa=" ";
    }

    ///CONSTRUCTOR PARAMETRIZAT
    Pesti(int idd, string den, string subr, string spc, string infra, string cls, float grm, string num, string h2o )
    {
        id=idd;
        denumire=den;
        subregn=subr;
        specie=spc;
        infraincrengatura=infra;
        clasa=cls;
        greutate_ma=grm;
        nume=num;
        apa=h2o;
    }

    ///constructor de copiere
    Pesti(const Pesti& n)
    {
        id=n.id;
        denumire=n.denumire;
        subregn=n.subregn;
        specie=n.specie;
        infraincrengatura=n.infraincrengatura;
        clasa=n.clasa;
        greutate_ma=n.greutate_ma;
        nume=n.nume;
        apa=n.apa;
    }

    ///destructor
    ~Pesti()
    {
    //    cout<<"acesta este un destructor pt clasa pesti\n";
    }

    ///fct de setare si obtinere
    string get_nume();
    string get_apa();
    float get_greutate_ma();
    void set_nume(string);
    void set_apa(string);
    void set_greutate_ma(float);

    ///operatorii>> <<
    friend istream& operator>>(istream&,Pesti &);
    friend ostream& operator<<(ostream&,Pesti &);

};

///fct de citire a clasei pesti
void Pesti::citire()
{
    cout<<"Pesti"<<endl;
    Vertebrate::citire();
    cout<<"Nume=";             cin>>nume;
    cout<<"Apa (dulce/sarata)= ";              cin>>apa;
   /* try{
        if(strcmp(apa,"dulce")!=0 ||strcmp(apa,"sarata")!=0)
            throw apa;
    }
    catch(...)
    {
        cout<<"alegerea facuta nu corespunde campului"<<endl;
    }
*/
    cout<<"Greutate medie=";   cin>>greutate_ma;
    cout<<endl;
}

///fct de afisare a clasei pesti
void Pesti::afisare()
{
    Vertebrate::afisare();
    cout<<"Nume="<<nume<<endl;
    cout<<"Apa="<<apa<<endl;
    cout<<"Greutate medie="<<greutate_ma<<endl;

}

///fct de obtinere /setare
string Pesti :: get_nume(){return nume;}
string Pesti :: get_apa(){return apa;}
float  Pesti :: get_greutate_ma(){return greutate_ma;}
void Pesti :: set_nume(string n){nume=n;}
void Pesti :: set_apa(string a){apa=a;}
void Pesti :: set_greutate_ma(float gr){greutate_ma=gr;}

///operatorii de citire, scriere
istream& operator>>(istream &in, Pesti& p)
{
    in>>p.id>>p.denumire>>p.subregn>>p.specie>>p.infraincrengatura>>p.clasa>>p.nume>>p.apa>>p.greutate_ma;
    return in;
}

ostream& operator<<(ostream& out, Pesti& p)
{
    out<<p.id<<" "<<p.denumire<<" "<<p.subregn<<" "<<p.specie<<" "<<p.infraincrengatura<<" "<<p.clasa<<" "<<p.nume<<" "<<p.apa<<" "<<p.greutate_ma<<endl;
    return out;
}




class Pasari: public Vertebrate{
string nume;
string zona;
public:
    virtual void citire();
    virtual void afisare();

    ///constructor de initializare
    Pasari()
    {
        id=0;
        denumire=" ";
        subregn=" ";
        specie=" ";
        infraincrengatura=" ";
        clasa=" ";
        nume=" ";
        zona=" ";
    }

    ///constructor paramentrizat
    Pasari(int idd, string den, string subr, string spc, string infra, string cls, string num,string site)
    {
        id=idd;
        denumire=den;
        subregn=subr;
        specie=spc;
        infraincrengatura=infra;
        clasa=cls;
        nume=num;
        zona=site;
    }
    ///constructor de copiere
    Pasari(const Pasari& p )
    {
        id=p.id;
        denumire=p.denumire;
        subregn=p.subregn;
        specie=p.specie;
        infraincrengatura=p.infraincrengatura;
        clasa=p.clasa;
        nume=p.nume;
        zona=p.zona;

    }
    ///destructor
    ~Pasari()
    {
      //  cout<<"Destructor pentru clasa pasari"<<endl;
    }

    ///functii de obtinere/setare
    string get_nume();
    string get_zona();
    void set_nume(string);
    void set_zona(string);

    ///functii de citire/scriere
    friend istream& operator>>(istream&,Pasari &);
    friend ostream& operator<<(ostream&,Pasari &);

};


///functia de citire pentru clasa Pasari
void Pasari::citire()
{
    cout<<"Pasari"<<endl;
    Vertebrate::citire();
    cout<<"Nume=";  cin>>nume;
    cout<<"Zona";   cin>>zona;
    cout<<endl;
}

void Pasari::afisare()
{
    Vertebrate::afisare();
    cout<<"Nume="<<nume<<endl;
    cout<<"Zona="<<zona<<endl;
}

///functii de obtinere/setare
string  Pasari :: get_nume(){return nume;}
string  Pasari :: get_zona(){return zona;}
void  Pasari :: set_nume(string a){nume=a;}
void  Pasari :: set_zona(string b){zona=b;}


///operatorii de citire, scriere
istream& operator>>(istream &in, Pasari& p)
{
    in>>p.id>>p.denumire>>p.subregn>>p.specie>>p.infraincrengatura>>p.clasa>>p.nume>>p.zona;
    return in;
}

ostream& operator<<(ostream& out, Pasari& p)
{
    out<<p.id<<" "<<p.denumire<<" "<<p.subregn<<" "<<p.specie<<" "<<p.infraincrengatura<<" "<<p.clasa<<" "<<p.nume<<" "<<p.zona<<endl;
    return out;
}




class Mamifere:public Vertebrate{
string locomotie;
string nume;
public:
    virtual void citire();
    virtual void afisare();

    ///constructor de initializare
    Mamifere()
    {
        id=0;
        denumire=" ";
        subregn=" ";
        specie=" ";
        infraincrengatura=" ";
        clasa=" ";
        locomotie=" ";
        nume=" ";
    }
    ///cosntructor parametrizat
    Mamifere(int idd, string den, string subr, string spc, string infra, string cls, string miscare, string name)
    {
        id=idd;
        denumire=den;
        subregn=subr;
        specie=spc;
        infraincrengatura=infra;
        clasa=cls;
        locomotie=miscare;
        nume=name;
    }
    ///constructor de copiere
    Mamifere(const Mamifere& m)
    {
        id=m.id;
        denumire=m.denumire;
        subregn=m.subregn;
        specie=m.specie;
        infraincrengatura=m.infraincrengatura;
        clasa=m.clasa;
        locomotie=m.locomotie;
        nume=m.nume;
    }
    ///destructor
    ~Mamifere()
    {
        //cout<<"Destructor pentru clasa mamifere"<<endl;
    }

    ///fct de obtinere/setare
    string get_nume();
    string get_locomotie();
    void set_nume(string);
    void set_locomotie(string);

    ///fct scriere/citire
    friend istream& operator>>(istream&,Mamifere &);
    friend ostream& operator<<(ostream&,Mamifere &);


};

///fct citire
void Mamifere::citire()
{
    cout<<"Mamifere"<<endl;
    Vertebrate::citire();
    cout<<"Locomotie="; cin>>locomotie;
    cout<<"Nume=";cin>>nume;
    cout<<endl;

}
///fct afisare
void Mamifere::afisare()
{
    Vertebrate::afisare();
    cout<<"Locomotie="<<locomotie<<endl;
    cout<<"Nume="<<nume<<endl;

}
///fct setare si returnare
string Mamifere :: get_nume(){return nume;}
string Mamifere :: get_locomotie(){return locomotie;}
void  Mamifere :: set_nume(string p){nume=p;}
void  Mamifere :: set_locomotie(string i){nume=i;}

///operatorii de citire, scriere
istream& operator>>(istream &in, Mamifere& p)
{
    in>>p.id>>p.denumire>>p.subregn>>p.specie>>p.infraincrengatura>>p.clasa>>p.nume>>p.locomotie;
    return in;
}

ostream& operator<<(ostream& out, Mamifere& p)
{
    out<<p.id<<" "<<p.denumire<<" "<<p.subregn<<" "<<p.specie<<" "<<p.infraincrengatura<<" "<<p.clasa<<" "<<p.nume<<" "<<p.locomotie<<endl;
    return out;
}





class Reptile:public Vertebrate{
string nume;
public:
    virtual void citire();
    virtual void afisare();
    ///constructor de initializare
    Reptile()
    {
        id=0;
        denumire=" ";
        subregn=" ";
        specie=" ";
        infraincrengatura=" ";
        clasa=" ";
        nume=" ";
    }
    ///cosntructor parametrizat
    Reptile(int idd, string den, string subr, string spc, string infra, string cls, string name)
    {
        id=idd;
        denumire=den;
        subregn=subr;
        specie=spc;
        infraincrengatura=infra;
        clasa=cls;
        nume=name;
    }
    ///constructor de copiere
    Reptile(const Reptile& m)
    {
        id=m.id;
        denumire=m.denumire;
        subregn=m.subregn;
        specie=m.specie;
        infraincrengatura=m.infraincrengatura;
        clasa=m.clasa;
        nume=m.nume;
    }
    ///destructor
    ~Reptile()
    {
        //cout<<"Destructor pentru clasa reptile"<<endl;
    }

    ///fct de obtinere/setare
    string get_nume();
    void set_nume(string);

    ///fct scriere/citire
    friend istream& operator>>(istream&,Reptile &);
    friend ostream& operator<<(ostream&,Reptile &);


};

///fct citire
void Reptile::citire()
{
    cout<<"Reptile"<<endl;
    Vertebrate::citire();
    cout<<"Nume=";cin>>nume;
    cout<<endl;

}
///fct afisare
void Reptile::afisare()
{
    Vertebrate::afisare();
    cout<<"Nume="<<nume<<endl;

}
///fct setare si returnare
string Reptile :: get_nume(){return nume;}
void  Reptile :: set_nume(string p){nume=p;}

///operatorii de citire, scriere
istream& operator>>(istream &in, Reptile& p)
{
    in>>p.id>>p.denumire>>p.subregn>>p.specie>>p.infraincrengatura>>p.clasa>>p.nume;
    return in;
}

ostream& operator<<(ostream& out, Reptile& p)
{
    out<<p.id<<" "<<p.denumire<<" "<<p.subregn<<" "<<p.specie<<" "<<p.infraincrengatura<<" "<<p.clasa<<" "<<p.nume<<endl;
    return out;
}

template <class tip>
class AtlasZoologic{
    tip v[100];
    int dim;
    static int nr;
public:
    AtlasZoologic()
    {
        dim=0;
        nr++;
    }
    void citire();
    void afis();
    void add(tip ob)
    {
        v[dim++]=ob;
    }
    int get_nr(){return nr;}
};
template <class tip>
void AtlasZoologic<tip>::citire()
{
    for (int i=0;i<dim;i++)
        v[i].citire();

}


template <class tip>
void AtlasZoologic<tip>::afis()
{
    for (int i=0;i<dim;i++)
        {v[i].afisare();
    cout<<endl;}
    cout<<endl;
}
template<class tip>
int AtlasZoologic<tip>::nr;


template <>
class AtlasZoologic<unsigned int>
{
    Nevertebrate vct[100];
    int n;
    static int nr;
public:
    AtlasZoologic()
    {
        n=0;
        nr++;
    }
    void citire()
    {
        for (int i=0;i<n;i++)
        vct[i].citire();
    }
    void afis()
    {
        for (int i=0; i<n; i++)
        {
            vct[i].afisare();
            cout<<endl;
        }
        cout<<endl;
    }
    void add(Nevertebrate ob)
    {
        vct[n++]=ob;
    }
    int get_nr(){return nr;}
};

template<>
int AtlasZoologic<unsigned int>::nr;


int main()
{
    AtlasZoologic<unsigned int>N;
    AtlasZoologic<Pesti>Pe;
    AtlasZoologic<Pasari>Pa;
    AtlasZoologic<Mamifere>M;
    AtlasZoologic<Reptile>R;
    int n,i;
    cout<<"Introduceti numarul de file pe care il va avea atlasul :";
    cin>>n;
    try
    {
        if(n<0)
            throw n;
    }
    catch(int n)
    {
        cout<<"Un atlas nu poate avea un numar negativ de file"<<endl;
    }
    if(n<0)
        return 0;

    for(i=0; i<n; i++)
    {

        int op;
        cout<<"optiunea dorita este (1)-nevertebrate; (2)-pesti; (3)-pasari; (4)-mamifere; (5)-reptile   :";
        cin>>op;
        try
        {
            if (op>5 || op<1)
                throw op;
        }
        catch(int op)
        {
            cout<<"Nu se poate realiza optiunea"<<endl;
        }
        switch (op)
        {
        case 1 :
        {
            Nevertebrate ob;
            ob.citire();
            N.add(ob);
            break;
        }
        case 2 :
        {
            Pesti ob;
            ob.citire();
            Pe.add(ob);
            break;
        }
        case 3 :
        {
            Pasari ob;
            ob.citire();
            Pa.add(ob);
            break;
        }
        case 4 :
        {
            Mamifere ob;
            ob.citire();
            M.add(ob);
            break;
        }
        case 5 :
        {
            Reptile ob;
            ob.citire();
            R.add(ob);
            break;
        }
        }

    }
    cout<<"AFISARE NEVERTEBRATE\n"<<endl;
    N.afis();
    cout<<"AFISARE PESTI\n"<<endl;
    Pe.afis();
    cout<<"AFISARE PASARI\n"<<endl;
    Pa.afis();
    cout<<"AFISARE MAMIFERE\n"<<endl;
    M.afis();
    cout<<"AFISARE REPTILE\n"<<endl;
    R.afis();

    Nevertebrate nev;
    Pesti pes;
    Pasari pa;
    Mamifere mam;
    Reptile rep;

    Regnul_Animal **p;
    p=new Regnul_Animal*[n];

    for(i=0; i<n; i++)
    {
        int op;
        cout<<"optiunea dorita este (1)-nevertebrate; (2)-pesti; (3)-pasari; (4)-mamifere; (5)-reptile   :";
        cin>>op;
        try
        {
            if (op>5 || op<1)
                throw op;
        }
        catch(int op)
        {
            cout<<"Nu se poate realiza optiunea";
        }
        switch (op)
        {
        case 1 :
        {
            p[i]=new Nevertebrate();
            break;
        }
        case 2 :
        {
            p[i]=new Pesti();
            break;
        }
        case 3 :
        {
            p[i]=new Pasari();
            break;
        }
        case 4 :
        {
            p[i]=new Mamifere();
            break;
        }
        case 5 :
        {
            p[i]=new Reptile();
            break;
        }
        }
        p[i]->citire();

    }

    for(i=0; i<n; i++)
        p[i]->afisare();


    cout<<"\n AFISARE NEVERTEBRATE DIN VECTORUL ALOCAT DINAMIC SPRE CLASA REGN ANIMAL"<<endl;
    for(i=0; i<n; i++)

        if(typeid(*p[i])==typeid(nev))
        {
            cout<<*(dynamic_cast<Nevertebrate*>(p[i]))<<endl;
        }
    cout<<"\n AFISARE pesti DIN VECTORUL ALOCAT DINAMIC SPRE CLASA REGN ANIMAL"<<endl;
    for(i=0; i<n; i++)
        if(typeid(*p[i])==typeid(pes))
        {
            cout<<*(dynamic_cast<Pesti*>(p[i]))<<endl;
        }
    cout<<"\n AFISARE pasari DIN VECTORUL ALOCAT DINAMIC SPRE CLASA REGN ANIMAL"<<endl;
    for(i=0; i<n; i++)
        if(typeid(*p[i])==typeid(pa))
        {
            cout<<*(dynamic_cast<Pasari*>(p[i]))<<endl;
        }
    cout<<"\n AFISARE mamifere DIN VECTORUL ALOCAT DINAMIC SPRE CLASA REGN ANIMAL"<<endl;
    for(i=0; i<n; i++)
        if(typeid(*p[i])==typeid(mam))
        {
            cout<<*(dynamic_cast<Mamifere*>(p[i]))<<endl;
        }
    cout<<"\n AFISARE reptile DIN VECTORUL ALOCAT DINAMIC SPRE CLASA REGN ANIMAL"<<endl;
    for(i=0; i<n; i++)
        if(typeid(*p[i])==typeid(rep))
        {
            cout<<*(dynamic_cast<Reptile*>(p[i]))<<endl;
        }


    AtlasZoologic<Pesti> ne;
    int nr=ne.get_nr();
    cout<<"\n Sunt "<<nr<<" file"<<endl;
    AtlasZoologic<unsigned int> pp;
    int nrpp=pp.get_nr();
    cout<<"\n Sunt  "<<nrpp<<" file pt nevertebrate"<<endl;




}


