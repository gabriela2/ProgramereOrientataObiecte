#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

///clasa persoana

class Persoana
{
protected:
    int id;
    string nume;
public:
    virtual void citire();
    virtual void afisare();

    ///constructor initializare
    Persoana()
    {
        id=0;
        nume=" ";
    }

    ///CONSTRUCTOR PARAMETRIZAT
    Persoana(string n,int idd)
    {
        nume=n;
        id=idd;
    }

    ///constructor de copiere
    Persoana(const Persoana& p)
    {
        id=p.id;
        nume=p.nume;
    }

    ///destructor
    ~Persoana()
    {
        //cout<<"acesta este un destructor pentru clasa persoana\n";
    }

    ///fct de setare si obtinere a numelui si a id-ului
    int get_id();
    string get_nume();
    void set_id(int );
    void set_nume(string);

    ///operatorii>> << =
    friend istream& operator>>(istream&,Persoana &);
    friend ostream& operator<<(ostream&,Persoana &);
    //Persoana& operator=(Persoana&);
};

///fct citire clasa persoana
void Persoana::citire()
{
    cout<<"ID=";    cin>>id;
    cout<<"Nume=";  cin>>nume;

}

///fct afisare clasa persoana
void Persoana::afisare()
{
    cout<<"Id: "<<id<<endl;
    cout<<"Nume: "<<nume<<endl;
}

///fct setare/returnare
int Persoana :: get_id(){return id;}
string Persoana :: get_nume(){return nume;}
void Persoana :: set_id(int idd){id=idd;}
void Persoana :: set_nume(string p){nume=p;}

///operatorii de citire, scriere si atribuiere
istream& operator>>(istream &in, Persoana& p)
{
    in>>p.id>>p.nume;
    return in;
}

ostream& operator<<(ostream& out, Persoana& p)
{
    out<<p.id<<p.nume;
    return out;
}
/*
Persoana &Persoana::operator=( Persoana& p)
{
    id=p.id;
    nume=p.nume;
    return *this;
}
*/



///clasa abonat

class Abonat:virtual public Persoana
{
protected:
    string nr_telefon;
public:

    virtual void citire();
    virtual void afisare();

    ///constructor initializare
    Abonat()
    {
        id=0;
        nume=" ";
        nr_telefon=" ";
    }

    ///CONSTRUCTOR PARAMETRIZAT
    Abonat(string n,int idd,string nr_tel)
    {
        nume=n;
        id=idd;
        nr_telefon=nr_tel;
    }

    ///constructor de copiere
    Abonat(const Abonat& a)
    {
        id=a.id;
        nume=a.nume;
        nr_telefon=a.nr_telefon;
    }

    ///destructor
    ~Abonat()
    {
        //cout<<"acesta este un destructor pt clasa abonat\n";
    }

    ///fct de setare si obtinere a nr de telefon
    string get_nr_telefon();
    void set_nr_telefon(string a);

    ///operatorii>> << =
    friend istream& operator>>(istream&,Abonat &);
    friend ostream& operator<<(ostream&,Abonat &);
    Abonat& operator=( Abonat&);

};

///fct de citire a clasei abonat
void Abonat :: citire()
{
    Persoana::citire();
    cout<<"Telefon=";  cin>>nr_telefon;
}

///fct de afisare a clasei abonat
void Abonat :: afisare()
{
    Persoana::afisare();
    cout<<"Numar telefon: "<<nr_telefon<<endl;
}

///fct de setare si obtinere a nr de telefon
string Abonat :: get_nr_telefon(){return nr_telefon;}
void Abonat :: set_nr_telefon(string a){nr_telefon=a;}


///operatorii de citire, scriere si atribuiere
istream& operator>>(istream &in, Abonat& a)
{
    in>>a.id>>a.nume>>a.nr_telefon;
    return in;
}

ostream& operator<<(ostream& out, Abonat& a)
{
    out<<a.id<<a.nume<<a.nr_telefon;
    return out;
}

Abonat &Abonat::operator=(Abonat& a)
{
    id=a.id;
    nume=a.nume;
    nr_telefon=a.nr_telefon;
    return *this;
}



///clasa abonat skype

class Abonat_Skype:virtual public Abonat
{
protected:
    int id_skype;
public:
    virtual void citire();
    virtual void afisare();

    ///constructor initializare
    Abonat_Skype()
    {
        id=0;
        nume=" ";
        nr_telefon=" ";
        id_skype=0;
    }

    ///CONSTRUCTOR PARAMETRIZAT
    Abonat_Skype(string n,int idd,string nr_tel,int id_skp)
    {
        nume=n;
        id=idd;
        nr_telefon=nr_tel;
        id_skype=id_skp;
    }

    ///constructor de copiere
    Abonat_Skype(const Abonat_Skype& as)
    {
        id=as.id;
        nume=as.nume;
        nr_telefon=as.nr_telefon;
        id_skype=as.id_skype;
    }

    ///destructor
    ~Abonat_Skype()
    {
        //cout<<"acesta este un destructor pt clasa abonat_skype\n";
    }

    ///fct de setare si obtinere a id_skype
    int get_id_skype();
    void set_id_skype(int );

    ///operatorii>> << =
    friend istream& operator>>(istream&,Abonat_Skype &);
    friend ostream& operator<<(ostream&,Abonat_Skype &);
    Abonat_Skype& operator=( Abonat_Skype&);
};

///fct de citire a clasei abonat skype
void Abonat_Skype :: citire()
{
    Abonat::citire();
    cout<<"ID skype=";   cin>>id_skype;
}

///fct de afisare a clasei abonat_skype
void Abonat_Skype :: afisare()
{
    Abonat::afisare();
    cout<<"ID Skype: "<<id_skype<<endl;
}

///fct de setare si obtinere a id_skype
int Abonat_Skype :: get_id_skype(){return id_skype;}
void Abonat_Skype :: set_id_skype(int idd_skp){id_skype=idd_skp;}

///operatorii de citire, scriere si atribuiere
istream& operator>>(istream &in, Abonat_Skype& as)
{
    in>>as.id>>as.nume>>as.nr_telefon>>as.id_skype;
    return in;
}

ostream& operator<<(ostream& out,Abonat_Skype& as)
{
    out<<as.id<<as.nume<<as.nr_telefon<<as.id_skype;
    return out;
}

Abonat_Skype &Abonat_Skype::operator=( Abonat_Skype& as)
{
    id=as.id;
    nume=as.nume;
    nr_telefon=as.nr_telefon;
    id_skype=as.id_skype;
    return *this;
}


///clasa abonat skype Romania

class Abonat_Skype_Romania:virtual public Abonat_Skype
{
    int nr;
    Abonat_Skype *agendaRo;
    string adresa_mail;
public:
     virtual void citire();
     virtual void afisare();

    ///constructor initializare
    Abonat_Skype_Romania()
    {
        id=0;
        nume=" ";
        nr_telefon=" ";
        id_skype=0;
        adresa_mail=" ";
    }

    ///CONSTRUCTOR PARAMETRIZAT
    Abonat_Skype_Romania(string n,int idd,string nr_tel,int idd_skp,string mail)
    {
        nume=n;
        id=idd;
        nr_telefon=nr_tel;
        id_skype=idd_skp;
        adresa_mail=mail;
         cout<<"nr abonati ro=";cin>>nr;
        agendaRo=new Abonat_Skype[nr];
        for(int i=0;i<nr;i++)
        {
            agendaRo[i].citire();
        }
    }

    ///constructor de copiere
    Abonat_Skype_Romania(const Abonat_Skype_Romania& asr)
    {
        id=asr.id;
        nume=asr.nume;
        nr_telefon=asr.nr_telefon;
        id_skype=asr.id_skype;
        adresa_mail=asr.adresa_mail;
    }

    ///destructor
    ~Abonat_Skype_Romania()
    {
        //cout<<"acesta este un destructor pt clasa abonat skype romania\n";
        delete []agendaRo;

    }

    ///fct de setare si obtinere a nr de telefon
    string get_adresa_mail();
    void set_adresa_mail(string asr);

    ///operatorii>> << =
    friend istream& operator>>(istream&,Abonat_Skype_Romania &);
    friend ostream& operator<<(ostream&,Abonat_Skype_Romania &);
    Abonat_Skype_Romania& operator=( Abonat_Skype_Romania&);

        ///supraincarcarea operatorului de indexare
     Abonat_Skype *operator[] (string);
};
/*
Abonat_Skype *Abonat_Skype_Romania::operator[ ] (string nume)
{
    for(int i=0; i<nr; i++)
        if(agendaRo[i].nume== nume)
            return &agendaRo[i];
    return NULL;
}
*/
///fct de citire a clasei abonat skype Romania
void Abonat_Skype_Romania :: citire()
{
    Abonat_Skype::citire();
    cout<<"E-mail=";   cin>>adresa_mail;
}

///fct afisare clasa abonat_skype_Romania
void Abonat_Skype_Romania :: afisare()
{
    Abonat_Skype::afisare();
    cout<<"Adresa e-mail: "<<adresa_mail<<endl;
}

///fct de setare si obtinere a nr de telefon
string Abonat_Skype_Romania :: get_adresa_mail(){return adresa_mail;}
void Abonat_Skype_Romania ::  set_adresa_mail(string asr){adresa_mail=asr;}

///operatorii de citire, scriere si atribuiere
istream& operator>>(istream &in, Abonat_Skype_Romania& asr)
{
    in>>asr.id>>asr.nume>>asr.nr_telefon>>asr.id_skype>>asr.adresa_mail;
    return in;
}

ostream& operator<<(ostream& out,Abonat_Skype_Romania& asr)
{
    out<<asr.id<<asr.nume<<asr.nr_telefon<<asr.id_skype<<asr.adresa_mail;
    return out;
}

Abonat_Skype_Romania &Abonat_Skype_Romania::operator=( Abonat_Skype_Romania& asr)
{
    id=asr.id;
    nume=asr.nume;
    nr_telefon=asr.nr_telefon;
    id_skype=asr.id_skype;
    adresa_mail=asr.adresa_mail;
    return *this;
}



///clasa abonat skype extern

class Abonat_Skype_extern:virtual public Abonat_Skype
{
    int ext;
    Abonat_Skype *agendaExt;
    string tara;
public:
   virtual void citire();
   virtual void afisare();

    ///constructor initializare
    Abonat_Skype_extern()
    {
        id=0;
        nume=" ";
        nr_telefon=" ";
        id_skype=0;
        tara=" ";

    }

    ///CONSTRUCTOR PARAMETRIZAT
    Abonat_Skype_extern(string n,int idd,string nr_tel,int id_skp,string origine)
    {
        nume=n;
        id=idd;
        nr_telefon=nr_tel;
        id_skype=id_skp;
        tara=origine;
         cout<<"nr abonati ext=";cin>>ext;
        agendaExt=new Abonat_Skype[ext];
        for(int i=0;i<ext;i++)
        {
            agendaExt[i].citire();
        }
    }

    ///constructor de copiere
    Abonat_Skype_extern(const Abonat_Skype_extern& ase)
    {
        id=ase.id;
        nume=ase.nume;
        nr_telefon=ase.nr_telefon;
        id_skype=ase.id_skype;
        tara=ase.tara;
    }

    ///destructor
    ~Abonat_Skype_extern()
    {
        //cout<<"acesta este un destructor pt clasa abonat skype extern\n";
    }

    ///fct de setare si obtinere a nr de telefon
    string get_tara();
    void set_tara(string ase);

    ///operatorii>> << =
    friend istream& operator>>(istream&,Abonat_Skype_extern &);
    friend ostream& operator<<(ostream&,Abonat_Skype_extern &);
    Abonat_Skype_extern& operator=(Abonat_Skype_extern&);

        ///supraincarcarea operatorului de indexare
     Abonat_Skype *operator[] (string);
};
/*
Abonat_Skype *Abonat_Skype_extern::operator[ ] (string nume)
{
    for(int i=0; i<ext; i++)
        if(agendaExt[i].nume== nume)
            return &agendaExt[i];
    return NULL;
}

*/

///fct de citire a clasei abonat skype extern
void Abonat_Skype_extern :: citire()
{
    Abonat_Skype::citire();
    cout<<"Tara=";  cin>>tara;
}

///fct de afisare a clasei abonat skype extern
void Abonat_Skype_extern :: afisare()
{
    Abonat_Skype::afisare();
    cout<<"Tara: "<<tara<<endl;
}

///fct de setare si obtinere a nr de telefon
string Abonat_Skype_extern :: get_tara(){return tara;}
void Abonat_Skype_extern :: set_tara(string ase){tara=ase;}

///operatorii de citire, scriere si atribuiere
istream& operator>>(istream &in, Abonat_Skype_extern& ase)
{
    in>>ase.id>>ase.nume>>ase.nr_telefon>>ase.id_skype>>ase.tara;
    return in;
}

ostream& operator<<(ostream& out,Abonat_Skype_extern& ase)
{
    out<<ase.id<<ase.nume<<ase.nr_telefon<<ase.id_skype<<ase.tara;
    return out;
}

Abonat_Skype_extern &Abonat_Skype_extern::operator=( Abonat_Skype_extern& ase)
{
    id=ase.id;
    nume=ase.nume;
    nr_telefon=ase.nr_telefon;
    id_skype=ase.id_skype;
    tara=ase.tara;
    return *this;
}



///clasa agenda

class Agenda:virtual public Abonat_Skype_Romania,virtual public Abonat_Skype_extern
{
    int op;
public:
    void citire();
    void afisare();

    ///supraincarcarea operatorului de indexare
    string operator[](string);
};

void Agenda::citire()
{
    cout<<"optiune (1-Romania,altceva-inrest) =";
    cin>>op;
    if(op==1)
       Abonat_Skype_Romania::citire();
    else
        Abonat_Skype_extern::citire();
}
void Agenda::afisare()
{
    if(op==1)
        Abonat_Skype_Romania::afisare();
    else
        Abonat_Skype_extern::afisare();
}



/// subiect clasa
/*         persoana
           /       \
        fizica      juridica
            \       /
              pachet

*/



class persFizica:virtual public Persoana
{
protected:
    string cnp;
public:
    virtual void citire();
    virtual void afisare();

    ///constructor initializare
    persFizica()
    {
        id=0;
        nume=" ";
        cnp=" ";
    }

    ///CONSTRUCTOR PARAMETRIZAT
    persFizica(string n,int idd,string identif)
    {
        nume=n;
        id=idd;
        cnp=identif;
    }

    ///constructor de copiere
    persFizica(const persFizica& p)
    {
        id=p.id;
        nume=p.nume;
        cnp=p.cnp;
    }

    ///destructor
    ~persFizica()
    {
        //cout<<"acesta este un destructor pentru clasa persoanaFizica\n";
    }

    ///fct de setare si obtinere a numelui si a id-ului
    string get_cnp();
    void set_cnp(string );

    ///operatorii>> << =
    friend istream& operator>>(istream&,persFizica &);
    friend ostream& operator<<(ostream&,persFizica&);


};

///fct de citire a clasei persfizica
void persFizica :: citire()
{
    Persoana::citire();
    cout<<"cnp=";  cin>>cnp;
}

///fct de afisare a clasei persfizica
void persFizica :: afisare()
{
    Persoana::afisare();
    cout<<"CNP: "<<cnp<<endl;
}

///fct de setare si obtinere a cnp
string persFizica :: get_cnp(){return cnp;}
void persFizica :: set_cnp(string a){cnp=a;}


///operatorii de citire, scriere si atribuiere
istream& operator>>(istream &in, persFizica& a)
{
    in>>a.id>>a.nume>>a.cnp;
    return in;
}

ostream& operator<<(ostream& out, persFizica& a)
{
    out<<a.id<<a.nume<<a.cnp;
    return out;
}




class persJuridica:virtual public Persoana
{
protected:
    string CUI;
public:
    virtual void citire();
    virtual void afisare();

    ///constructor initializare
    persJuridica()
    {
        id=0;
        nume=" ";
        CUI=" ";
    }

    ///CONSTRUCTOR PARAMETRIZAT
    persJuridica(string n,int idd,string identif)
    {
        nume=n;
        id=idd;
        CUI=identif;
    }

    ///constructor de copiere
    persJuridica(const persJuridica& p)
    {
        id=p.id;
        nume=p.nume;
        CUI=p.CUI;
    }

    ///destructor
    ~persJuridica()
    {
        //cout<<"acesta este un destructor pentru clasa persoanaJURIICA\n";
    }

    ///fct de setare si obtinere a numelui si a cui
    string get_CUI();
    void set_CUI(string );

    ///operatorii>> << =
    friend istream& operator>>(istream&,persJuridica &);
    friend ostream& operator<<(ostream&,persJuridica&);

};

///fct de citire a clasei persJURIDICA
void persJuridica :: citire()
{
    Persoana::citire();
    cout<<"CUI=";  cin>>CUI;
}

///fct de afisare a clasei persJURIDICA
void persJuridica :: afisare()
{
    Persoana::afisare();
    cout<<"C.U.I: "<<CUI<<endl;
}

///fct de setare si obtinere a CUI
string persJuridica :: get_CUI(){return CUI;}
void persJuridica :: set_CUI(string a){CUI=a;}


///operatorii de citire, scriere si atribuiere
istream& operator>>(istream &in, persJuridica& a)
{
    in>>a.id>>a.nume>>a.CUI;
    return in;
}

ostream& operator<<(ostream& out, persJuridica& a)
{
    out<<a.id<<a.nume<<a.CUI;
    return out;
}






class Abonament:public persFizica,public persJuridica
{
    string tip;
    float cost;
    int op;
public:
    void citire();
    void afisare();
    Abonament()
    {
        id=0;
        nume=" ";
        tip=" ";
        cost=0;
    }

    ///CONSTRUCTOR PARAMETRIZAT
    Abonament(string n,int idd,string tipul,float z)
    {
        nume=n;
        id=idd;
        tip=tipul;
        cost=z;
    }

    ///constructor de copiere
    Abonament(const Abonament& p)
    {
        id=p.id;
        nume=p.nume;
        tip=p.tip;
        cost=p.cost;

    }

    ///destructor
    ~Abonament()
    {
        //cout<<"acesta este un destructor pentru clasa abonament\n";
    }

    ///operatorii>> <<
    friend istream& operator>>(istream&,Abonament &);
    friend ostream& operator<<(ostream&,Abonament&);



};

void Abonament::citire()
{
    cout<<"tip=";cin>>tip;
    cout<<"cost=";cin>>cost;
    cout<<"optiune=";cin>>op;
    if(op==1)
        persFizica::citire();
    else
        persJuridica::afisare();

}
void Abonament::afisare()
{
    cout<<"tip="<<tip<<endl;
    cout<<"cost="<<cost<<endl;
    if(op==1)
        persFizica::afisare();
    else
        persJuridica::afisare();
}
///operatorii de citire, scriere si atribuiere
istream& operator>>(istream &in, Abonament& a)
{
    in>>a.id>>a.nume>>a.tip>>a.cost;
    return in;

}

ostream& operator<<(ostream& out, Abonament & a)
{
    out<<a.id<<a.nume<<a.tip<<a.cost;
    return out;
}







int main()
{
/*
    int n,i;
    cout<<"n=";
    cin>>n;
    Agenda *p;
    p=new Agenda[n];
    for(i=0;i<n;i++)
    {
        cout<<endl;
        p[i].citire();
    }
    cout<<"\nAfisarea utilizatorilor\n"<<endl;

     for(i=0;i<n;i++)
    {
        p[i].afisare();
        cout<<endl;
        cout<<endl;
    }
    int nr;
    cout<<"abonati externi"<<endl;
    cout<<"nr=";cin>>nr;
    Abonat_Skype_extern *v;
    v=new Abonat_Skype_extern [nr];
    for(i=0;i<nr;i++)
    {
        cout<<endl;
        v[i].citire();
    }
    string sir;
    cout<<"sir=";cin>>sir;
//    v[sir]->afisare();
*/

    ///subiecte clasa
    int n,j,i,op;
    cout<<"n=";
    cin>>n;
    Persoana **p;
    p=new Persoana*[n];
    persFizica fiz,pfiz[n];
    persJuridica jur,pjur[n];
    int k1=0,k2=0;
    for(i=0; i<n; i++)
    {
        cout<<"opt(1-fizica,2 juridic)=";
        cin>>op;
        if(op==1)
            p[i]=new persFizica();
        else if(op==2)
            p[i]=new persJuridica();
        p[i]->citire();
    }
    for(i=0; i<n; i++)
    {
        if(typeid(*p[i])==typeid(fiz))
        {
            pfiz[k1]=(*p[i]);
            k1++;
        }
        if(typeid(*p[i])==typeid(jur))
        {
            pfiz[k2]=*p[i];
            k2++;
        }
    }

///ordonari realizate dupa id
    for(i=0; i<k1-1; i++)
        for(j=i+1; j<k1; j++)
            if(pfiz[i].id<pfiz[j].id)
                swap(pfiz[i],pfiz[j]);

    for(i=0; i<k2-1; i++)
        for(j=i+1; j<k2; j++)
            if(pjur[i].id<pjur[j].id)
                swap(pjur[i],pjur[j]);


    cout<<"\npersoane fizice:\n";
    for(i=0; i<k1; i++)
    {
        pfiz[i].afisare();
        cout<<endl;
    }

    cout<<"persoane juridice:\n";
    for(i=0; i<k2; i++)
    {
        pjur[i].afisare();
        cout<<endl;
    }


    return 0;
}
