/* Praf Andrei Alexandru Grupa 211
GNU GCC COMPILER
Eduard Gabriel Szmeteanca*/

#include <iostream>
#include <string.h>
#include <vector>
#include <fstream>
#include <exception>
#include <stdexcept>
#include<list>
#include <map>
#include <iterator>
#include <set>
#include<typeinfo>
using std::runtime_error;

using namespace std;

class Vaccin
{
protected:
    float pret;
    float tempdepo;
    string Substante;
    string ProdVaccin;
    string NumeVaccin;
    //vector<string> listasubst;
public:
    //constr fara parametrii
    Vaccin()
    {
        pret=0;
        Substante="Necunoscute";
        NumeVaccin="Necunoscut";
        ProdVaccin="Necunoscut";
        tempdepo=0;
    }

    //virtualizare clasa
    virtual void afisareSchemaVaccinare()=0;
    //citire fisier
    friend ofstream& operator<<(ofstream &fout,const Vaccin &v)
    {
        v.fwrite(fout);
        return fout;
        //din proiect
    }
    virtual ofstream& fwrite(ofstream &fout)const
    {

        fout<<NumeVaccin<<" de la producatorul:"<<ProdVaccin<<" si contine substantele:"<<Substante
            <<".\nAcesta trebuie pastrat la o temperatura de "<< tempdepo<< " grade "<<
            "si pretul acestuia este: "<<pret;
    }

    //afisare in fisier ->din proiect
    friend ifstream& operator>>(ifstream&fin, Vaccin &v)
    {
        v.fread(fin);
        return fin;
    }
    virtual void fread(ifstream &fin)
    {
        fin>>NumeVaccin;
        fin>>ProdVaccin;
        fin>>pret;
        fin>>tempdepo;
        fin>>Substante;
    }

    //operator << cu virtualizare
    friend ostream&operator <<(ostream&out, const Vaccin &vac)
    {
        vac.Afisare(out);
        return out;
    }
    virtual ostream& Afisare(ostream&out)const
    {
        out<<NumeVaccin<<" de la producatorul:"<<ProdVaccin<<" si contine substantele:"<<Substante
           <<".\nAcesta trebuie pastrat la o temperatura de "<< tempdepo<< " grade "<<
           "si pretul acestuia este: "<<pret;
    }
    friend istream&operator>>(istream &in, Vaccin &vac)
    {
        vac.read(in);
        return in;
    }
    virtual void read(istream &in)
    {
        cout<<"\nNume vaccin:";
        in>>NumeVaccin;
        cout<<"Producator vaccin:";
        in>>ProdVaccin;
        cout<<"Pret vaccin:";
        in>>pret;
        cout<<"Temperatura depozitare:";
        in>>tempdepo;
        cout<<" Substantele din vaccin(date prin virgula):";
        in>>Substante;

    }
    ~Vaccin()
    {

    }
};
//vaccinm sars cov2
class VaccinAntiSarsCov2:public Vaccin
{
private:
    string reactiiadverse;
    string medicamenteinterzise;
    int rataef;
public:
    VaccinAntiSarsCov2():Vaccin()
    {
        reactiiadverse="Necunoscute";
        medicamenteinterzise="Necunoscute";
        rataef=0;
    }
    virtual void fread(ifstream &fin)
    {
        Vaccin::fread(fin);
        fin>>reactiiadverse;
        fin>>medicamenteinterzise;
        fin>>rataef;
    }
    virtual ofstream& fwrite(ofstream &fout)const override
    {
        Vaccin::Afisare(fout);
        fout<<".Acest vaccin este anti Sars-Cov2 si poate avea urmatoarele reactii advere:"<<reactiiadverse;
        fout<<".Vaccinul nu va putea fi folosit pentru 6 luni cu urmatoarele medicamente:"<<medicamenteinterzise;
        fout<<".Rata eficienta este de :"<<rataef<<" %.";
        fout<<endl<<endl;
    }
    virtual ostream& Afisare(ostream &out)const override
    {
        Vaccin::Afisare(out);
        cout<<".Acest vaccin este anti Sars-Cov2 si poate avea urmatoarele reactii advere:"<<reactiiadverse;
        cout<<".Vaccinul nu va putea fi folosit pentru 6 luni cu urmatoarele medicamente:"<<medicamenteinterzise;
        cout<<".Rata eficienta este de :"<<rataef<<" %.";
        cout<<endl<<endl;
    }
    virtual void read(istream &in)
    {
        Vaccin::read(in);
        cout<<"Reactii adverse(separate prin virgula):";
        in>>reactiiadverse;
        cout<<"Medicamente contraindicate pe o perioada de 6 luni";
        in>>medicamenteinterzise;
        cout<<"Rata de eficienta:";
        in>>rataef;
    }
    virtual void afisareSchemaVaccinare()
    {
        cout<<"Vaccinul Sars-Cov2 se administreaza persoanleor cu varsta de peste 16 ani";
        cout<<" ,2 doze la o perioada de 21 de zile\n";
    }
    ~VaccinAntiSarsCov2()
    {

    }
};

//vaccin antigripal
class VaccinAntigripal:public Vaccin
{
private:
    string tulpiniv;
    bool OMS;
public:
    VaccinAntigripal():Vaccin()
    {
        tulpiniv="Necunoscute";
        OMS=0;
    }
    virtual void fread(ifstream &fin)
    {
        Vaccin::fread(fin);
        fin>>tulpiniv;
        fin>>OMS;
    }
    virtual ofstream& fwrite(ofstream &fout)const override
    {
       Vaccin::Afisare(fout);
        fout<<".Acest vaccin este antigripal si este pentru tulpinile"<<tulpiniv;
        if(OMS==0)
            fout<<".Acesta nu este recomandat de OMS.";
        else
            fout<<".Acesta este recomandat de OMS";
        fout<<endl<<endl;
    }
    virtual void read(istream &in)
    {
        Vaccin::read(in);
        cout<<"Tulpini virus:(separate prin virgula fara spatii):";
        in>>tulpiniv;
        cout<<"Recomandat de OMS( 0 pentru nu, 1 pentru da)";
        in>>OMS;
    }
    virtual ostream& Afisare(ostream &out)const override
    {
        Vaccin::Afisare(out);
        cout<<".Acest vaccin este antigripal si este pentru tulpinile"<<tulpiniv;
        if(OMS==0)
            cout<<".Acesta nu este recomandat de OMS.";
        else
            cout<<".Acesta este recomandat de OMS";
        cout<<endl<<endl;
    }
    virtual void afisareSchemaVaccinare()
    {
        cout<<"Vaccinul anti gripal se administreaza la adulti o doza de 0.5 ml, iar la copii si adolescenti";
        cout<<" 0.3 ml, repetandu-se din 2 in 2 ani\n";
    }
    ~VaccinAntigripal()
    {

    }
};

//vaccin anti hepatic
class VaccinAntihepatic:public  Vaccin
{
private:
    char heptype;
    string modvac;
public:
    VaccinAntihepatic():Vaccin()
    {
        heptype='A';
        modvac="Necunoscut";
    }
    virtual void fread(ifstream &fin)
    {
        Vaccin::fread(fin);
        fin>>heptype;
        fin>>modvac;
    }
    virtual ofstream& fwrite(ofstream &fout)const override
    {
       Vaccin::Afisare(fout);
        fout<<".Acest vaccin este anti hepatic pentru urmatorul tip de hepatita:"<<heptype;
        fout<<".Modul de vaccinare este:"<<modvac;
        fout<<endl<<endl;
    }
    virtual void read(istream &in)
    {
        Vaccin::read(in);
        cout<<"Tipul hepatitei pentru care este facut vaccinul(A,B sau C):";

        in>>heptype;
        cout<<"Modul de vaccinare:";
        in>>modvac;
    }
    virtual ostream& Afisare(ostream &out)const override
    {
        Vaccin::Afisare(out);
        cout<<".Acest vaccin este anti hepatic pentru urmatorul tip de hepatita:"<<heptype;
        cout<<".Modul de vaccinare este:"<<modvac;
        cout<<endl<<endl;
    }
    virtual void afisareSchemaVaccinare()
    {
        if(heptype=='A' || heptype=='B')
        {
            cout<<"La copii cu varsta mai mica de 1 an se administreaza 2 injectari";
            cout<<" la un interval de o luna, a treia injectare dupa 6 luni de la prima injectare";
            cout<<"\nLa adulti conform schemei de imunizare recomandata de medic\n";
        }
        if(heptype=='C')
            cout<<"Vaccinul poate fi administrat doar la recomandarea medicului.\n";
    }
    ~VaccinAntihepatic()
    {

    }
};
class Comanda
{
private:
    static int contid;//laborator 12
    string numeClient;
    string data;
    int cantitate;
    const int id;//lab 12
    string NumeVaccin;
    vector<Vaccin*> listavac;

public:
    Comanda():id(contid++)
    {
        numeClient="Necun";
        data="0/0/0";
        cantitate=0;
    }

    Comanda(string data,string numeClient,string NumeVaccin,int cantitate):id(contid++)
    {
        this->data=data;
        this->numeClient=numeClient;
        this->cantitate=cantitate;

    }
    ~Comanda()
    {

    }
};

class ListaComenzi
{
private:
    vector<Comanda>LC;
public:
    ListaComenzi operator+(Comanda A)
    {
        LC.push_back(A);
        return *this;
    }
    Comanda &operator[](int i)
    {
        return this->LC[i];
    }

};

int main()
{

    VaccinAntigripal a;
    VaccinAntihepatic b;
    VaccinAntiSarsCov2 c;
    //cin>>c;
    cin>>a>>b>>c;
    cout<<a<<b<<c;
    Vaccin* list[3];
    list[0]=new VaccinAntigripal();
    list[1]=new VaccinAntihepatic();
    list[2]=new VaccinAntiSarsCov2();
    for(int i=0; i<3; i++)
    {
        cout<<i<<endl;
        list[i]-> afisareSchemaVaccinare();
    }
    //Comanda com1(string("20-12-2020"),string("SpitalX"),string("AntiSarsCov2"),20);
//ListaComenzi lista;
    //lista=lista+com1;
   // cout<<lista[0];




    //a.afisareSchemaVaccinare();
    return 0;
}
