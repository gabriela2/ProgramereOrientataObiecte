using namespace std;
class nrComplex
{
    double pReal,pImag;

public:
    nrComplex()/// constructor initializare
    {
        pReal=0;
        pImag=0;
    }
    nrComplex(double pReal,double pImag)  ///constructor parametrizare
    {
        pReal=pReal;
        pImag=pImag;
    }
     nrComplex(const nrComplex& z)    ///constructor de copiere
    {
        pReal=z.pReal;
        pImag=z.pImag;
    }
    ///metoda publica pentru citire;
   /* void citire();*/

    ///metoda publica de afisare (sub forma "a", "i*a", "-i*a", "a+i*b","a-i*b", dupa caz);
    void afisare();

     ///metode publice pentru setat/furnizat partea reala si partea imaginara;
    double get_real();
    double get_imag();
    void set_real(double r);
    void set_imag(double i);


    ///operatori friend

    ///  operatorii binari +, -, *, /, ==, != se scriu in cate trei variante, pentru a putea lucra cu operanzi complex-complex, double-complex, complex-double;

    /// + (adunare)
    friend nrComplex operator+(const nrComplex&,const nrComplex&);
    friend nrComplex operator+(double ,const nrComplex&);
    friend nrComplex operator+(const nrComplex&,double);

    ///  - (scadere),
    friend nrComplex operator-(const nrComplex&,const nrComplex&);
    friend nrComplex operator-(double ,const nrComplex&);
    friend nrComplex operator-(const nrComplex&,double);

     ///  +(numarul insusi),
    friend nrComplex operator+(const nrComplex&);
    ///  - (opus),
    friend nrComplex operator-(const nrComplex&);

     ///  * (inmultire),
    friend nrComplex operator*(const nrComplex&,const nrComplex&);
    friend nrComplex operator*(double ,const nrComplex&);
    friend nrComplex operator*(const nrComplex&,double);


    ///  / (impartire),
    friend nrComplex operator/(const nrComplex&,const nrComplex&);
    friend nrComplex operator/(double ,const nrComplex&);
    friend nrComplex operator/(const nrComplex&,double);

     ///  == (test de egalitate),
    friend int operator==(const nrComplex&,const nrComplex&);
    friend int operator==(double,const nrComplex&);
    friend int operator==(const nrComplex&,double);

    ///  != (test de neegalitate);
    friend int operator!=(const nrComplex&,const nrComplex&);
    friend int operator!=(double,const nrComplex&);
    friend int operator!=(const nrComplex&,double);



    ///  operatorii +=, -=,*=, /= se scriu in doua variante, pentru a putea lucra cu operanzi complex-complex, complex-double.

    ///  +=
    friend nrComplex& operator+=(nrComplex&,const nrComplex &);
    friend nrComplex& operator+=(nrComplex&,double);

    ///  -=
    friend nrComplex& operator-=(nrComplex&,const nrComplex &);
    friend nrComplex& operator-=(nrComplex&,double);

    /// *=
    friend nrComplex& operator*=(nrComplex&,const nrComplex &);
    friend nrComplex& operator*=(nrComplex&,double);

    /// /=
    friend nrComplex& operator/=(nrComplex&,const nrComplex &);
    friend nrComplex& operator/=(nrComplex&,double);

     ///   ^ (ridicare la putere naturala),
    friend nrComplex& operator^(const nrComplex&,int);

    ///functii friend
   // friend double abs(const nrComplex &z);
    friend nrComplex sqrt(const nrComplex& c);





    ///constructorii sunt la inceputul clasei

    ///operatori  citire/scriere
    friend istream& operator>>(istream&,nrComplex &);
    friend ostream& operator<<(ostream&,const nrComplex &);
    //friend ostream& operator<<(ostream&,const nrComplex &, const nrComplex &);


    ///fct friend -> fct membra
    double abs(const nrComplex &z);
    ///fct membra -> fct friend
    friend void citire(nrComplex&);


    ///operator prefixat si postfixat
    nrComplex operator++(); // prefixat ++obiect
    nrComplex operator++(int); //postfixat obiect++

    ///operator de atribuire
    nrComplex& operator=(const nrComplex&);



    ///destructor
    ~nrComplex(){cout<<"destructor";}




};

