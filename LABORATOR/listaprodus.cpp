#include <iostream>

using namespace std;

class Produs
{
protected:
    string nume;
    float pretBrut;
public:

    virtual float calculeazaPret()
    {
        pretBrut=0;
    };
    void afisareBrand()  //? exitsa final in c++?
    {

        cout<<"Este un produs din gama EDI.SRL";

    }

    friend  ostream& operator<<(ostream& out,const Produs& p)
    {

        out<<p.nume;
        return out;

    }
    friend istream& operator >>(istream& in, Produs&p)
    {

        cout<<"Numele este: ";
        in>>p.nume;
        cout<<"Pretul brut este: ";
        in>>p.pretBrut;
        return in;

    }

};

class ProdusPersibail:public Produs
{
private:
    string dataExpirare;
public:

    float calculeazaPret()
    {

        return this->pretBrut+(45*this->pretBrut)/100;

    }
    friend ostream& operator<<(ostream& out,const ProdusPersibail& p)
    {
        out<<(Produs&)p;
        out<<" "<<p.dataExpirare;
        return out;

    }
    friend istream& operator >>(istream& in, ProdusPersibail&p)
    {

        in>>(Produs&)p;
        cout<<"Dati data: ";
        in>>p.dataExpirare;
        return in;
    }

};
class ProdusNePerisbalil:public Produs
{
private:
    int garantie;
public:

    float calculeazaPret()
    {

        return this->pretBrut+(10*this->pretBrut)/100;

    }

    friend ostream& operator<<(ostream& out,const ProdusNePerisbalil& p)
    {
        out<<(Produs&)p;
        out<<" "<<p.garantie;
        return out;

    }
    friend istream& operator >>(istream& in, ProdusNePerisbalil&p)
    {

        in>>(Produs&)p;
        cout<<"ani garantie: ";
        in>>p.garantie;
        return in;
    }


};

class listaProduse
{
private:
    Produs *p[100];

public:
    int cont;
    listaProduse()
    {
        cont=0;
    }

    void add()
    {
        int n;
        cout<<"Cate produse doriti sa adaugati?\n";
        cin>>n;
        int ch;

        for( int i=0 ; i<n; i++)
        {
            cout<<"Produsul este perisabil(1) sau neperisabil(0)";
            cin>>ch;
            if(ch==0)
            {
                ProdusNePerisbalil np;
                p[this->cont]=new ProdusNePerisbalil();
                cin>>np;
                p[this->cont]=&np;
                this->cont ++;
            }
            else if(ch==1)
            {
                ProdusPersibail l;
                p[this->cont]=new ProdusPersibail();
                cin>>l;
                p[this->cont]=&l;
                this->cont++;

            }

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
        }
    }
    void afis()
    {
        cout<<"Contor: "<<cont<<endl;
        int n=this->cont;
        for(int i=0; i<n; i++){
            int q;
            q=this->p[i]->calculeazaPret();
            cout<<q;
            }
    }

};

int main()
{

    listaProduse a;
    a.afis();
    a.add();
    a.afis();
    return 0;
}
