#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
class Angajat
{
protected:
    const int ID;
    bool working;
    int varsta;
    char gen;
    char *nume;
    char prenume[100];
    int nrVoturi;
    float *rating;
    double salariu;

public:
    static int no_of_ang;
    static void initnoang(int x)
    {
        no_of_ang=x;
    }
    static void mesaj()
    {
        cout<<"AXP PIESE AUTO va ofera cele mai bune servicii alaturi de angajatii sai";
    }

    //constructor fara param
    Angajat():ID(00000)
    {
        working=0;
        varsta=0;
        gen='N';
        salariu=0;
        nume=new char[strlen("Necunoscut")+1];
        strcpy(this->nume,"Necunoscut");
        strcpy(this->prenume,"Necun");
        nrVoturi=0;
        rating=NULL;

    }
    //constructor cu param
    Angajat(int id,int varsta,bool Manager,char *nume,char prenume[100],int nrVoturi,
            float *rating,double salariu,char gen):ID(id)
    {
        this->varsta=varsta;
        this->working=working;
        this->gen=gen;
        this->nume=new char[strlen(nume)+1];
        strcpy(this->nume,nume);
        strcpy(this->prenume,prenume);
        this->nrVoturi=nrVoturi;
        this->rating=new float[nrVoturi];
        for(int i=0; i<nrVoturi; i++)
            this->rating[i]=rating[i];
    }
    // getteri
    int getVarsta()
    {
        return this->varsta;
    }
    char *getNume()
    {
        return this->nume;
    }
    char*getPrenume()
    {
        return this->prenume;
    }
    float *getRating()
    {
        return this->rating;
    }
    bool getWorking()
    {
        return this->working;
    }
    int getNrVoturi()
    {
        return this->nrVoturi;
    }
    double getSalariu()
    {
        return this->salariu;
    }
    char getGen()
    {
        return this->gen;
    }
    bool getLucreaza()
    {
        return this->working;
    }

    //setteri
    void setVarsta(int a)
    {
        this->varsta=a;
    }
    void setNume(char *a)
    {
        if(this->nume!=nullptr)
            delete[] this->nume;
        this->nume=new char[strlen(a)+1];
        strcpy(this->nume,a);
    }
    void setRating(float *a, int b)
    {
        if(this->rating!=nullptr)
            delete [] this->rating;
        this->nrVoturi=b;
        this->rating=new float [b];
        for(int i=0; i<b; i++)
            this->rating[i]=a[i];
    }
    void setPrenume(char a[100])
    {
        if(this->prenume!=nullptr)
            memset(this->prenume,0,101);
        strcpy(this->prenume,a);
    }
    void setSalariu(double salariu)
    {
        this->salariu=salariu;
    }
    void setGen(char gen)
    {
        this->gen=gen;
    }
    //copy
    Angajat(const Angajat &ang):ID(ang.ID)
    {
        this->varsta=ang.varsta;
        this->gen=ang.gen;
        this->working=ang.working;
        this->nrVoturi=ang.nrVoturi;
        this->salariu=ang.salariu;
        this->nume=new char[strlen(ang.nume)+1];
        strcpy(this->nume,ang.nume);
        strcpy(this->prenume,ang.prenume);
        this->rating=new float[ang.nrVoturi];
        for(int i=0; i<ang.nrVoturi; i++)
            this->rating[i]=ang.rating[i];
    }
    // operator =
    Angajat& operator=(const Angajat& ang)
    {
        if(this!=&ang)
        {
            this->working=ang.working;
            this->gen=ang.gen;
            this->varsta=ang.varsta;
            this->nrVoturi=ang.nrVoturi;
            this->salariu=ang.salariu;
            if(this->nume!=nullptr)
                delete []this->nume;
            this->nume=new char[strlen(ang.nume)+1];
            strcpy(this->nume,ang.nume);
            if(this->prenume!=nullptr)
                memset(this->prenume,0,101);
            strcpy(this->prenume,ang.prenume);
            if(this->rating!=nullptr)
                delete[ ]this->rating;
            this->rating=new float[ang.nrVoturi];
            for(int i=0; i<ang.nrVoturi; i++)
                this->rating[i]=ang.rating[i];
        }
    }
    //operator <<
    friend ostream&operator<<(ostream& out,const Angajat ang)
    {
        out<<"\nAngajatul  "<<ang.nume<<" "<<ang.prenume<<" are "<<ang.varsta<<" ani, salariu: "<<
           ang.salariu<<" lei si ratingul ";
        for(int i=0; i<ang.nrVoturi; i++)
            out<<ang.rating[i]<<" ";
        out<<" si este: "<<ang.gen<<".";
        //if(ang.working!=0)
        //   out<<"Acesta lucreaza";

        return out;
    }

    //operator >>
    friend istream& operator >>(istream& in, Angajat& ang)
    {
        char aux[100];
        cout<<"\nIntroduceti numele:";
        in>>aux;
        if(ang.nume!=NULL)
            delete[]ang.nume;
        ang.nume=new char [strlen(aux)+1];
        strcpy(ang.nume,aux);
        cout<<"\nIntroduceti prenumele:";
        if(ang.prenume!=nullptr)
            memset(ang.prenume,0,101);
        char aux2[100];
        in>>aux2;
        strcpy(ang.prenume,aux2);
        cout<<"\nIntroduceti varsta: ";
        in>>ang.varsta;
        cout<<"\nIntroduceti salariul: ";
        in>>ang.salariu;
        cout<<"\nIntroduceti genul:(M/F)";
        in>>ang.gen;
        cout<<"Lucreaza(1/0):";
        in>>ang.working;
        cout<<"\nIntroduceti numarul de voturi primite:";
        in>>ang.nrVoturi;
        if(ang.rating!=nullptr)
            delete[]ang.rating;
        ang.rating=new float[ang.nrVoturi];
        cout<<"\nIntroduceti ratingul primit:";
        for(int i=0; i<ang.nrVoturi; i++)
            in>>ang.rating[i];
        return in;

    }


    Angajat operator *(int a)
    {
        this->salariu=this->salariu*a;
        return *this;
    }
    Angajat operator+(int a)
    {
        int rating2[100];
        if(this->rating!=NULL)
        {
            for(int i=0; i<this->nrVoturi; i++)
                rating2[i]=this->rating[i];
            delete[]this->rating;
        }
        this->nrVoturi++;
        this->rating=new float[this->nrVoturi+1];
        for(int i=0; i<this->nrVoturi; i++)
            this->rating[i]=rating2[i];
        this->rating[this->nrVoturi-1]=a;
        return *this;
    }
    // pre increment & post increment
    const Angajat operator++()
    {
        this->salariu=this->salariu+100;
        return *this;
    }
    const Angajat operator++(int)
    {
        Angajat aux(*this);
        this->salariu=this->salariu+100;
        return aux;
    }
    // index operator
    float &operator[](int i)
    {
        if(i>this->nrVoturi)
        {
            cout<<"Index invalid"<<endl;
            return this->rating[0];
        }
        return this->rating[i];
    }

    // operator cond.
    bool  operator >(Angajat ang)
    {
        if(this->ratingtot()>ang.ratingtot())
            return 1;
        else
            return 0;
    }
    bool operator ==(Angajat ang)
    {
        if(strcmp(this->nume,ang.nume)==0)
            return true;
        else
            return false;
    }

    //rating total
    float ratingtot()
    {
        float medierating;
        for(int i=0; i<this->nrVoturi; i++)
            medierating=medierating+this->rating[i];
        medierating=medierating/this->nrVoturi;
        return medierating;
    }
    //destructor
    ~Angajat()
    {
        if(this->nume!=nullptr)
            delete[]this->nume;
        if(this->rating!=nullptr)
            delete[]this->rating;
    }

};
int Angajat::no_of_ang;

class Produs
{

protected:
    const long ID_Produs;
    int nrbucati;
    char *nume;
    char numeproducator[100];
    char locdepozit;// raion notat de la A la Z;0-9;
    double pret;
    float multiplicatorpret;//fiecare tip de produs are un multiplicator de pret pentru vanzare;
    bool instock;
    int no_of_cars;
    int *for_car;//fiecare cod(luat ca un int) se potriveste unei masini;


public:
    static int nr_loc_depozit;
    static void init_nr_loc_depozit(int x)
    {
        nr_loc_depozit=x;
    }

    Produs():ID_Produs(00000)
    {
        nrbucati=0;
        nume=new char[strlen("Produs necunoscut")+1];
        strcpy(nume,"Produs necunoscut");
        strcpy(numeproducator,"Producator necunoscut");
        locdepozit='0';
        pret=0.0;
        instock=0;
        no_of_cars=0;
        for_car=NULL;
        multiplicatorpret=0.0;
    }

    Produs(long id, int nrbucati, char*nume,char numeproducator[100], char locdepozit,
           double pret,float multiplicatorpret,bool instock,int no_of_cars,int *for_car):ID_Produs(id)
    {
        this->nrbucati=nrbucati;
        this->multiplicatorpret=multiplicatorpret;
        this->nume=new char[strlen(nume)+1];
        strcpy(this->nume,nume);
        strcpy(this->numeproducator,numeproducator);
        this->locdepozit=locdepozit;
        this->pret=pret;
        this->instock=instock;
        this->no_of_cars=no_of_cars;
        this->for_car=new int[no_of_cars];
        for(int i=0; i<no_of_cars; i++)
            this->for_car[i]=for_car[i];

    }
    //gettereri
    float getMultPr()
    {
        return this->multiplicatorpret;
    }
    int getNrBucati()
    {
        return this->nrbucati;
    }
    char*getNume()
    {
        return this->nume;
    }
    char *getProducator()
    {
        return this->numeproducator;
    }
    char getLocDep()
    {
        return this->locdepozit;
    }
    double getPret()
    {
        return this->pret;
    }

    bool getStock()
    {
        return this->instock;
    }
    int getNoCars()
    {
        return this->no_of_cars;
    }
    int * getCars()
    {
        return this->for_car;
    }
    //setters
    void setNrBucati(int a)
    {
        this->nrbucati=a;
    }
    void setNume(char *a)
    {
        if(this->nume!=nullptr)
            delete[]this->nume;
        this->nume=new char[strlen(a)+1];
        strcpy(this->nume,a);
    }
    void setProducator(char a[100])
    {
        if(this->numeproducator!=nullptr)
            memset(this->numeproducator, 0, 100);
        strcpy(this->numeproducator,a);
    }
    void setLocDep(char a)
    {
        this->locdepozit=a;
    }
    void setPret(double a)
    {
        this->pret=a;
    }
    void setMultPret(float a)
    {
        this->multiplicatorpret=a;
    }
    void setStock(bool a)
    {
        this->instock=a;
    }
    void setNoCars(int a)
    {
        this->no_of_cars=a;
    }
    void setCars(int *a,int b)
    {
        if(this->for_car!=nullptr)
        {
            delete[]this->for_car;
        }
        this->no_of_cars=b;
        this->for_car=new int[b];
        for(int i=0; i<b; i++)
            this->for_car[i]=a[i];
    }

    //copy constr
    Produs(const Produs &prod):ID_Produs(prod.ID_Produs)
    {
        this->nrbucati=prod.nrbucati;
        this->nume=new char[strlen(prod.nume)+1];
        strcpy(this->nume,prod.nume);
        strcpy(this->numeproducator,prod.numeproducator);
        this->locdepozit=prod.locdepozit;
        this->pret=prod.pret;
        this->instock=prod.instock;
        this->no_of_cars=prod.no_of_cars;
        this->for_car=new int [prod.no_of_cars];
        for(int i=0; i<prod.no_of_cars; i++)
            this->for_car[i]=prod.for_car[i];
    }
    // operator =
    Produs &operator =(const Produs&prod)
    {
        if(this!=&prod)
        {
            this->nrbucati=prod.nrbucati;
            if(this->nume!=nullptr)
                delete[]this->nume;
            this->nume=new char[strlen(prod.nume)+1];
            strcpy(this->nume,prod.nume);
            if(this->numeproducator!=nullptr)
                memset(this->numeproducator, 0, 101);
            strcpy(this->numeproducator,prod.numeproducator);
            this->locdepozit=prod.locdepozit;
            this->pret=prod.pret;
            this->no_of_cars=prod.no_of_cars;
            if(this->for_car!=nullptr)
                delete[]this->for_car;
            this->for_car=new int[prod.no_of_cars];
            for(int i=0; i<prod.no_of_cars; i++)
                this->for_car[i]=prod.for_car[i];
            return *this;
        }
    }

    //ETAPA 2- virtualizare afisare
    friend ostream&operator <<(ostream&out, const Produs &prod)
    {
        prod.Afisare(out);
        return out;
    }

    virtual ostream& Afisare(ostream&out)const
    {
        out<<nume<<" provine de la "<<numeproducator<<" si avem "<<nrbucati<< " in stock"
           <<",iar pretul este:"<<pret*multiplicatorpret<<".\nAcesta este disponibil pentru masinile cu codul:";
        for(int i=0; i<no_of_cars; i++)
            out<<for_car[i]<<" ";
        out<<".\n";
        return out;
    }

    //ETAPA 2 - virtualizare citire
    friend istream&operator>>(istream &in, Produs &prod)
    {
        prod.read(in);
        return in;
    }
    virtual void read(istream &in)
    {

        char aux[100];
        cout<<"\nIntroduceti numele produsului :";
        in>>aux;
        if(nume!=NULL)
            delete []nume;
        nume=new char[strlen(aux)+1];
        strcpy(nume,aux);
        cout<<"\nIntroduceti numele producatorului:";
        char aux2[100];
        if(numeproducator!=nullptr)
            memset(numeproducator, 0, 101);
        in>>aux2;
        strcpy(numeproducator,aux2);
        cout<<"\nNumarul de bucati:";
        in>>nrbucati;
        cout<<"\nLocul in depozit:";
        in>>locdepozit;
        cout<<"\nPretul:";
        in>>pret;
        cout<<"\nMultiplicatorul pentru pretul de vanzare:";
        in>>multiplicatorpret;
        cout<<"\nEste in stock(1/0):";
        in>>instock;
        cout<<"\nNumarul de masini cu care este compatibil:";
        in>>no_of_cars;
        if(no_of_cars>0)
        {
            if(for_car!=nullptr)
                delete[]for_car;
            for_car=new int[no_of_cars];
            cout<<"\nIntroduceti codurile masinilor:";
            for(int i=0; i<no_of_cars; i++)
                in>>for_car[i];
        }
    }


    Produs operator /(float a)
    {
        this->pret=this->pret/a;
        return *this;
    }
    Produs operator +(int a) // adaugare cod masina compatibila
    {
        int aux[100];
        if(this->for_car!=NULL)
        {
            for(int i=0; i<this->no_of_cars; i++)
                aux[i]=this->for_car[i];
            delete[]this->for_car;
        }
        this->no_of_cars++;
        this->for_car=new int[this->no_of_cars+1];
        for(int i=0; i<this->no_of_cars; i++)
            this->for_car[i]=aux[i];
        this->for_car[this->no_of_cars-1]=a;
        return *this;
    }
    //operator --;++
    const Produs operator --()
    {
        this->nrbucati=this->nrbucati-1;
        return *this;
    }
    const Produs operator++(int)
    {
        Produs aux(*this);
        this->nrbucati=this->nrbucati+1;
        return aux;
    }

    //index operator
    int &operator[](int i)
    {
        if(i>this->no_of_cars)
        {
            cout<<"Index invalid"<<endl;
            return this->for_car[0];
        }
        return this->for_car[i];
    }

    //operator cond
    bool operator >(Produs prod)
    {
        if(this->nrbucati>prod.nrbucati)
            return 1;
        else
            return 0;
    }
    bool operator==(Produs prod)
    {
        if(strcmp(this->nume,prod.nume)==0)
            return 1;
        else
            return 0;
    }
    bool checkstock()
    {
        if(this->instock)
            return 1;
        else
            return 0;
    }
    virtual double profitprodus()
    {
        double profit;
        profit=this->pret*this->multiplicatorpret-this->pret;
        profit=profit*this->nrbucati;
        return profit;
    }
    bool checkcomp(int a)
    {
        for(int i=0; i<this->no_of_cars; i++)
            if(a==for_car[i])
                return 1;
        return 0;
    }

    virtual void afis() {};

    //destructor
    ~Produs()
    {
        if(this->nume!=nullptr)
            delete[]this->nume;
        if(this->for_car!=nullptr)
            delete[]this->for_car;
    }
};
int Produs::nr_loc_depozit;

//clasa IS A
class ProdusIntretinere:public Produs
{
    string use;// interior, exterior, curatare pete, etc.
    string dataexpirare;
    bool toxic;
public:
    ProdusIntretinere():Produs()
    {
        use="Necunoscut";
        dataexpirare="0/0/0";
        toxic=0;
    }
    ProdusIntretinere(const ProdusIntretinere& prod):Produs(prod)
    {
        this->use=prod.use;
        this->dataexpirare=prod.dataexpirare;
        this->toxic=prod.toxic;
    }
    //operator =
    ProdusIntretinere &operator=(const ProdusIntretinere &prod)
    {
        Produs::operator=(prod);
        if(this!=&prod)
            this->use=prod.use;
            this->dataexpirare=prod.dataexpirare;
            this->toxic=prod.toxic;
    }
    virtual void read(istream &in)
    {
        char aux[100];
        cout<<"\nIntroduceti numele produsului :";
        in>>aux;
        if(nume!=NULL)
            delete []nume;
        nume=new char[strlen(aux)+1];
        strcpy(nume,aux);
        cout<<"\nIntroduceti numele producatorului:";
        char aux2[100];
        if(numeproducator!=nullptr)
            memset(numeproducator, 0, 101);
        in>>aux2;
        strcpy(numeproducator,aux2);
        cout<<"\nNumarul de bucati:";
        in>>nrbucati;
        cout<<"\nLocul in depozit:";
        in>>locdepozit;
        cout<<"\nPretul :";
        in>>pret;
        cout<<"\nMultiplicatorul pentru pretul de vanzare:";
        in>>multiplicatorpret;
        cout<<"\nEste in stock(1/0):";
        in>>instock;
        //produsele de acest tip sunt compatibile pt orice autoturism;
        cout<<"\nScopul:";
        in>>use;
        cout<<"\nData de expirare:";
        in>>dataexpirare;
        cout<<"\nEste toxic(1/0):";
        in>>toxic;
    }

    virtual ostream& Afisare(ostream&out)const override
    {
        out<<nume<<" provine de la "<<numeproducator<<" si avem "<<nrbucati<< " in stock"
           <<",iar pretul de vanzare este:"<<pret*multiplicatorpret<<" .Scopul acestuia este:"<<use
           <<" .Data de expirare: "<<dataexpirare;
        if(toxic)
            out<<".Acesta este toxic.";
        else
        {
            out<<" .Acesta nu este toxic.";
        }
        out<<endl;
        return out;
    }

    void afis()
    {
        cout<<"Produs intretinere";
    }
};

//class IS A
class UnelteAuto:public Produs
{
    string use;// interior, exterior, curatare pete, etc.
    char calitate;// A-  cea  mai buna calitate, D- cea mai proasta
    string material;

public:
    UnelteAuto():Produs()
    {
        use="Necunoscut";
        calitate='D';
        material="Necunoscut";
    }
    //copy constr;
    UnelteAuto(const UnelteAuto& prod):Produs(prod)
    {
        this->use=prod.use;
        this->calitate=prod.calitate;
        this->material=prod.material;
    }
    //operator =
    UnelteAuto &operator=(const UnelteAuto &prod)
    {
        Produs::operator=(prod);
        if(this!=&prod)
            this->use=prod.use;
            this->calitate=prod.calitate;
            this->material=prod.material;
    }
    virtual void read(istream &in)
    {
        char aux[100];
        cout<<"\nIntroduceti numele produsului :";
        in>>aux;
        if(nume!=NULL)
            delete []nume;
        nume=new char[strlen(aux)+1];
        strcpy(nume,aux);
        cout<<"\nIntroduceti numele producatorului:";
        char aux2[100];
        if(numeproducator!=nullptr)
            memset(numeproducator, 0, 101);
        in>>aux2;
        strcpy(numeproducator,aux2);
        cout<<"\nNumarul de bucati:";
        in>>nrbucati;
        cout<<"\nLocul in depozit:";
        in>>locdepozit;
        cout<<"\nPretul :";
        in>>pret;
        cout<<"\nEste in stock(1/0):";
        in>>instock;
        //produsele de acest tip sunt compatibile pt orice autoturism;
        cout<<"\nScopul:";
        in>>use;
        cout<<"\nCalitatea:";
        in>>calitate;
        cout<<"\nMaterialul:";
        in>>material;
    }

    virtual ostream& Afisare(ostream&out)const override
    {
        out<<nume<<" provine de la "<<numeproducator<<" si avem "<<nrbucati<< " in stock"
           <<",iar pretul  este:"<<pret<<" .Scopul acestuia este:"<<use
           <<" ,este fabricat din:"<<material<<" si calitatea acestuia este:"<<calitate;
        out<<endl;
        return out;
    }
    double profitprodus()
    {
        double profit=0.0;

        switch(calitate)
        {
        case 'A':
            profit=this->pret*1.5-this->pret;

            break;
        case 'B':
            profit=this->pret*1.4-this->pret;
            break;
        case 'C':
            profit=this->pret*1.3-this->pret;
            break;
        case 'D':
            profit=this->pret*1.2-this->pret;
            break;
        }
        profit=profit*double(this->nrbucati);
        return profit;
    }
    void afis()
    {
        cout<<"Unealta auto";
    }
};

//class HAS A, vom crea o lista de produse care contine un vector de produse;
class listaProduse
{
    Produs **p;
public:
    int cont=0;
    void add()
    {
        int n;
        cout<<"\nCate produse doriti sa adaugati?\n";
        cin>>n;
        p=new Produs *[n+cont];

        int ch;

        for( int i=0 ; i<n; i++)
        {
            cout<<"Produsul este din categoria unelte auto(0), categoria produse pentru intretinere(1) sau produs normal(2):";
            cin>>ch;
            if(ch==1)
            {

                p[this->cont]=new ProdusIntretinere;
                cin>>*p[this->cont];

            }
            else if(ch==0)
            {
                p[this->cont]=new UnelteAuto;
                cin>>*p[this->cont];


            }
            else if(ch==2)
            {
                p[this->cont]=new Produs;
                cin>>*p[this->cont];
            }
            this->cont++;
        }
    }
    void remove(int x)
    {
        if(x<0 || x>=this->cont)
            cout<<"Index invalid";
        else
        {
            for(int i=x; i<=this->cont-1; i++)
            {
                p[i]=p[i+1];
            }
            p[this->cont-1]= {};
            this->cont--;
        }
    }
    void afis()
    {
        for(int i=0; i<this->cont; i++)
        {
            cout<<*p[i]<<endl;
        }
    }

    double getProfitLista()
    {
        double profit=0;
        for(int i=0; i<this->cont; i++)
            profit=this->p[i]->profitprodus();
        return profit;
    }

};


class distribuitor
{
private:
    const int ID_Distribuitor;
    int nr_produse;
    char nume_produs[100][100];
    float *pret_produs;
    char *nume_firma;
    char nume_reprezentant[100];
    bool distribuitor_piese_oem;
    double rata_reducere;
    char rating;// A-E, unde A inseamna cel mai bun rating, iar E cel mai prost.

public:
    static char tara[10];
    static void inittara(char a[10])
    {
        strcpy(tara,a);
    }
    distribuitor():ID_Distribuitor(00000),distribuitor_piese_oem(0)
    {
        nr_produse=0;
        strcpy(nume_produs[0],"Produs Necunoscut!");
        pret_produs=NULL;
        nume_firma=new char[strlen("Firma Necunoscuta!")+1];
        strcpy(nume_firma,"Firma Necunoscuta!");
        strcpy(nume_reprezentant,"Reprezentant necunoscut");
        rata_reducere=0;
        rating='0';
    }
    distribuitor(int id,bool dist_oem,int nr_produse,char nume_produs[100][100],
                 float *pret_produs,char*nume_firma,char nume_reprezentant[100],double rata_reducere,char rating)
        :ID_Distribuitor(id),distribuitor_piese_oem(dist_oem)
    {
        this->nr_produse=nr_produse;
        this->pret_produs=new float[nr_produse];
        for(int i=0; i<nr_produse; i++)
            this->pret_produs[i]=pret_produs[i];
        for(int i=0; i<nr_produse; i++)
            strcpy(this->nume_produs[i],nume_produs[i]);
        strcpy(this->nume_reprezentant,nume_reprezentant);
        this->nume_firma=new char[strlen(nume_firma)+1];
        strcpy(this->nume_firma,nume_firma);
        this->rata_reducere=rata_reducere;
        this->rating=rating;
    }
    distribuitor(int id,bool dist_oem,int nr_produse,char nume_produs[100][100],float *pret_produs)
        :ID_Distribuitor(id),distribuitor_piese_oem(dist_oem)
    {
        this->nr_produse=nr_produse;
        this->pret_produs=new float[nr_produse];
        for(int i=0; i<nr_produse; i++)
            this->pret_produs[i]=pret_produs[i];
        for(int i=0; i<nr_produse; i++)
            strcpy(this->nume_produs[i],nume_produs[i]);
    }
    distribuitor(const distribuitor &dist):ID_Distribuitor(dist.ID_Distribuitor),distribuitor_piese_oem(
            dist.distribuitor_piese_oem)
    {
        this->nr_produse=dist.nr_produse;
        this->pret_produs=new float[dist.nr_produse];
        for(int i=0; i<dist.nr_produse; i++)
            this->pret_produs[i]=dist.pret_produs[i];
        for(int i=0; i<dist.nr_produse; i++)
            strcpy(this->nume_produs[i],dist.nume_produs[i]);
        strcpy(this->nume_reprezentant,dist.nume_reprezentant);
        this->nume_firma=new char[strlen(dist.nume_firma)+1];
        strcpy(this->nume_firma,dist.nume_firma);
        this->rata_reducere=dist.rata_reducere;
        this->rating=dist.rating;
    }

    distribuitor &operator =(const distribuitor& dist)
    {
        if(this!=&dist)
        {
            this->nr_produse=dist.nr_produse;
            if(this->pret_produs!=nullptr)
                delete[]this->pret_produs;
            this->pret_produs=new float[dist.nr_produse];
            for(int i=0; i<dist.nr_produse; i++)
                this->pret_produs[i]=dist.pret_produs[i];
            if(this->nume_produs!=nullptr)
                memset(nume_produs,0,101);
            for(int i=0; i<dist.nr_produse; i++)
                strcpy(this->nume_produs[i],dist.nume_produs[i]);
            if(this->nume_reprezentant!=nullptr)
                memset(nume_produs,0,101);
            strcpy(this->nume_reprezentant,dist.nume_reprezentant);
            if(this->nume_firma!=nullptr)
                delete[]this->nume_firma;
            this->nume_firma=new char[strlen(dist.nume_firma)+1];
            strcpy(this->nume_firma,dist.nume_firma);
            this->rata_reducere=dist.rata_reducere;
            this->rating=dist.rating;
        }
    }
    friend ostream&operator <<(ostream&out,const distribuitor dist)
    {
        out<<"Firma "<<dist.nume_firma<<", prin reprezentantul ei "<<dist.nume_reprezentant<<" si cu  ratingul "
           <<dist.rating<<" , va ofera urmatoarele produse spre comanda ";
        for(int i=0; i<dist.nr_produse; i++)
        {
            out<<" "<<dist.nume_produs[i]<<" cu pretul "<<dist.pret_produs[i];
            if(i<dist.nr_produse-1)
                cout<<",";
        }
        out<<"."<<endl<<"Fiecare produs are o reducere de "<<dist.rata_reducere<<"%.";
        return out;
    }
    friend istream&operator >>(istream&in, distribuitor& dist)
    {
        char aux[100];
        cout<<"Introduceti numele distributuitorului:\n";
        in>>aux;
        if(dist.nume_firma!=NULL)
            delete[]dist.nume_firma;
        dist.nume_firma=new char[strlen(aux)+1];
        strcpy(dist.nume_firma,aux);
        cout<<"Introduceti numele reprezentantului:\n";
        char aux2[100];
        if(dist.nume_reprezentant!=nullptr)
            memset(dist.nume_reprezentant, 0, 101);
        in>>aux2;
        strcpy(dist.nume_reprezentant,aux2);
        cout<<"Introduceti numarul de produse disponibile:\n";
        in>>dist.nr_produse;
        if(dist.pret_produs!=nullptr)
            delete[]dist.pret_produs;
        if(dist.nume_produs!=nullptr)
            memset(dist.nume_produs,0,101);
        dist.pret_produs=new float[dist.nr_produse];
        cout<<"Introduceti numele produsele si pretul acestora:\n";
        for(int i=0; i<dist.nr_produse; i++)
        {
            in>>dist.nume_produs[i];
            in>>dist.pret_produs[i];
        }
        cout<<"Firma este distrbuitoare de piese OEM(1/0):\n";
        in>>dist.distribuitor_piese_oem;
        cout<<"Introduceti procentul de reducere:\n";
        in>>dist.rata_reducere;
        cout<<"Introduceti ratingul firmei:\n";
        in>>dist.rating;
        return in;
    }
    ~distribuitor()
    {
        if(this->pret_produs!=nullptr)
            delete[]this->pret_produs;
        if(this->nume_firma!=nullptr)
            delete[]this->nume_firma;
    }


};
char distribuitor::tara[10];

class Client
{
private:
    const int ID_Client;
    char *nume;
    char prenume[100];
    char gen;
    float  buget;
    bool client_asociat;
    int nrcomenzianterioare;
    int *id_comenzianterioare;

public:
    int cont=0;
    vector <Produs> comanda;
    Client():ID_Client(00000)
    {
        id_comenzianterioare=NULL;
        gen='0';
        nume=new char[strlen("Client necunoscut"+1)];
        strcpy(nume,"Client necunoscut");
        strcpy(prenume,"////");
        buget=0.0f;
        client_asociat=0;
        nrcomenzianterioare=0;
    }
    Client(int id,char *nume,char prenume[100],char gen,float buget,
           bool client_asociat,int nrcomenzianterioare,int *id_comenzianterioare):ID_Client(id)
    {
        this->nume=new char[strlen(nume)+1];
        strcpy(this->nume,nume);
        strcpy(this->prenume,prenume);
        this->gen=gen;
        this->buget=buget;
        this->client_asociat=client_asociat;
        this->nrcomenzianterioare=nrcomenzianterioare;
        this->id_comenzianterioare=new int[nrcomenzianterioare];
        for(int i=0; i<nrcomenzianterioare; i++)
            this->id_comenzianterioare[i]=id_comenzianterioare[i];
    }
    Client(int id,char *nume,char prenume[100]):ID_Client(id)
    {
        this->nume=new char[strlen(nume)+1];
        strcpy(this->nume,nume);
        strcpy(this->prenume,prenume);
    }
    Client(const Client &c):ID_Client(c.ID_Client)
    {
        this->nume=new char[strlen(c.nume)+1];
        strcpy(this->nume,c.nume);
        strcpy(this->prenume,c.prenume);
        this->gen=c.gen;
        this->buget=c.buget;
        this->client_asociat=c.client_asociat;
        this->nrcomenzianterioare=c.nrcomenzianterioare;
        this->id_comenzianterioare=new int[c.nrcomenzianterioare];
        for(int i=0; i<c.nrcomenzianterioare; i++)
            this->id_comenzianterioare[i]=c.id_comenzianterioare[i];
    }
    Client &operator=(const Client&c)
    {
        if(this->nume!=nullptr)
            delete[]this->nume;
        this->nume=new char[strlen(c.nume)+1];
        strcpy(this->nume,c.nume);
        strcpy(this->prenume,c.prenume);
        this->gen=c.gen;
        this->buget=c.buget;
        this->client_asociat=c.client_asociat;
        this->nrcomenzianterioare=c.nrcomenzianterioare;
        if(this->id_comenzianterioare!=nullptr)
            delete[]this->id_comenzianterioare;
        this->id_comenzianterioare=new int[c.nrcomenzianterioare];
        for(int i=0; i<c.nrcomenzianterioare; i++)
            this->id_comenzianterioare[i]=c.id_comenzianterioare[i];
        return *this;
    }
    friend ostream&operator<<(ostream&out,const Client c)
    {
        out<<"Clientul "<<c.nume<<" "<<c.prenume<<" are un buget de "<<c.buget<<" lei si este client asociat al firmei AXP AUTO PARTS:";
        if(c.client_asociat)
            out<<"DA.";
        else
            out<<"NU.";
        out<<"\nAcesta a mai avut "<<c.nrcomenzianterioare<<" comenzi anterioare.";
        out<<"\nComenzile au avut ID-ul:";
        for(int i=0; i<c.nrcomenzianterioare; i++)
        {
            out<<c.id_comenzianterioare[i]<<" ";
        }
        return out;

    }

    friend istream&operator>>(istream &in, Client &c)
    {
        char aux[100];
        cout<<"Introduceti numele clientului:\n";
        in>>aux;
        if(c.nume!=NULL)
            delete[]c.nume;
        c.nume=new char[strlen(aux)+1];
        strcpy(c.nume,aux);
        cout<<"Introduceti prenumele :\n";
        char aux2[100];
        if(c.prenume!=nullptr)
            memset(c.prenume, 0, 101);
        in>>aux2;
        strcpy(c.prenume,aux2);
        cout<<"Introduceti genul(M/F):\n";
        in>>c.gen;
        cout<<"Introduceti bugetul:\n";
        in>>c.buget;
        cout<<"Este client asociat firmei(1/0):\n";
        in>>c.client_asociat;
        cout<<"Numarul de comenzi anterioare:\n";
        in>>c.nrcomenzianterioare;
        if(c.id_comenzianterioare!=nullptr)
            delete[]c.id_comenzianterioare;

        c.id_comenzianterioare=new int[c.nrcomenzianterioare];
        cout<<"Introduceti ID-urile comenzilor anterioare:\n";
        for(int i=0; i<c.nrcomenzianterioare; i++)
        {
            in>>c.id_comenzianterioare[i];
        }

        return in;
    }

};


/*firma detine mai multe automobile dintre care unele pentru transport angajati, unele pentru transport
piese,
pentru acestea vom crea o inferfata/clasa abstracta
*/
class automobil
{
protected:
    string marca;
    string model;
    bool combustibil;//1 pentru benzina, 0 pentru motorina
public:
    automobil()
    {
        marca="anonim";
        model="anonim";
        combustibil=0;
        ;
    }
    friend istream& operator>>(istream &in, automobil &a)
    {
        a.read(in);
        return in;
    }
    virtual void read(istream &in){
        cout<<"Marca:";
        in>>marca;
        cout<<"Model:";
        in>>model;
        cout<<"Combustibil(1 pentru benzina, 0 pentru motorina):";
        in>>combustibil;
    }
    virtual void afis()
    {
        cout<<"Automobilul este marca:"<<marca<<" ,modelul:"<<model;
        if(combustibil)
            cout<<". Acesta este pe benzina ";
        else
            cout<<". Acesta este pe motorina ";

    }
    virtual float costuri()=0;
    /*
    Pentru costuri vom calcula in felul urmator:
        -pentru fiecare persoana transportata se va plati o taxa de 1,5lei lunar;
        -pentru fiecare tona pe care un automobil o poate transporta se vor plati 2 lei lunar;
        -daca masina este pe motorina se va aplica o taxa de 54 de lei, iar daca este pe benzina 43 de lei
    Acestea vor fi taxele lunare pentru automobilele firmei;
    */
    virtual ~automobil()
    {}
};

class autoPersoane: public automobil
{
    int nrpers;
public:
    autoPersoane():automobil()
    {
        nrpers=0;
    }
    virtual void read(istream &in)
    {
        automobil::read(in);
        cout<<"Numarul de persoane care pot fi transportate:";
        in>>nrpers;
    }
    float costuri()
    {
        float n=0.0;
        n=n+float(nrpers)*1.5;
        if(this->combustibil==1)
            n=n+43;
        else
            n=n+54;
        return n;
    }
    void afis()
    {
        automobil::afis();
        cout<<"si poate transporta: "<<nrpers<< " persoane.\n";
    }
};

class autoLivrare: public automobil
{
    float tonaj;
public:
    autoLivrare():automobil()
    {
        tonaj=0.0;
    }
    virtual void read(istream &in)
    {
        automobil::read(in);
        cout<<"Capacitatea maxima:";
        in>>tonaj;
    }
    float costuri()
    {
        float n=0.0;
        n=n+float(tonaj)*2;
        if(this->combustibil==1)
            n=n+43;
        else
            n=n+54;
        return n;
    }
    void afis()
    {
        automobil::afis();
        cout<<"si  poate transporta: "<<tonaj<< " tone.\n";
    }
};
int main()
{
    distribuitor::inittara("Romania");

    //test inferfata clasa abstracta
    automobil *a[2];
    a[1]=new autoLivrare;
    a[0]=new autoPersoane;
    cin>>*a[1];
    cin>>*a[0];
    a[1]->afis();
    cout<<endl;
    a[0]->afis();


    //test clase mostenite
    ProdusIntretinere c;
    cin>>c;
    ProdusIntretinere b;
    b=c;
    cout<<b;
    listaProduse p;
    p.add();
    p.afis();
    cout<<p.getProfitLista();


    return 0;
}
