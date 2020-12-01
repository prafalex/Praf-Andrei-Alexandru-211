#include <iostream>
#include <vector>
#include <list>
#include <iterator>
using namespace std;
class automobil
{
    // marca,model,use,detaliu specific
protected:
    string marca;
    string model;
    string use;
    bool combustibil;// 0 pentru motorina, 1 pentru benzina
public:
    automobil()
    {
        marca="Anonim";
        model="Anonim";
        use="necunoscut";
        combustibil=0;
    }
    friend ostream&operator <<(ostream &out,const automobil &a)
    {
        a.Afisare(out);
        return out;
    }

    virtual ostream& Afisare(ostream &out) const
    {

        out<<"\n\nMarca:"<<marca<<";Model:"<<model<<";scop:"<<use;
        if(combustibil)
            out<<" si este pe benzina";
        else
            out<<" si este pe motorina";
        return out;

    }
    friend istream& operator>>(istream &in, automobil &a)
    {
        a.read(in);
        return in;
    }
    virtual void read(istream &in)
    {
        cout<<"\nMarca:";
        in>>marca;
        cout<<"Model:";
        in>>model;
        cout<<"Scop:";
        in>>use;
        cout<<"Este pe benzina sau motorina(0 pentru motorina, 1 pentru benzina):";
        in>>combustibil;

    }
    virtual void afis(){}



};

class masiniundercover: public automobil
{
    //viteza, nr gloate rezistenta;
    float speed;
    int no_of_res;
public:
    masiniundercover():automobil()
    {
        speed=0;
        no_of_res=0;
    }
    //
    virtual ostream& Afisare(ostream &out) const override
    {
        automobil::Afisare(out);
        out<<" .Acesta prinde viteza:"<<speed<<" si rezista la "<<no_of_res<<" gloante.";
        return out;

    }
    virtual void read(istream &in)
    {
        automobil::read(in);
        cout<<"Viteza:";
        in>>speed;
        cout<<"Nr.gloante la care rezista:";
        in>>no_of_res;
    }

};

class masiniinterventie:public automobil
{
    int no_of_pers;
    bool arma;
public:
    masiniinterventie():automobil()
    {
        no_of_pers=0;
        arma=0;
    }

    virtual ostream& Afisare(ostream &out) const override
    {
        automobil::Afisare(out);
        out<<". Acesta poate transporta: "<<no_of_pers<<" persoane. ";
        if(arma)
            cout<<"Acesta este dotat cu TR-85.";
        else
            cout<<"Acesta nu este dotat cu TR-85.";
        return out;

    }
    virtual void read(istream &in)
    {
        automobil::read(in);
        cout<<"Nr. de persoane care pot fi transportate:";
        in>>no_of_pers;
        cout<<"Este dotat cu TR-85(0/1):";
        in>>arma;

    }
};

class masiniemisiereceptie:public automobil
{
    //distanta de interceptie audio,dist de interceptie video
    float dist_audio;
    float dist_video;
public:
    masiniemisiereceptie():automobil()
    {
        dist_audio=0;
        dist_video=0;
    }
    virtual ostream& Afisare(ostream &out) const override
    {
        automobil::Afisare(out);
        out<<". Distanta de interceptie audio este:"<<dist_audio<<" ,iar distanta pentru interceptie video este: "
           <<dist_video;
        return out;

    }

    virtual void read(istream &in)
    {
        automobil::read(in);
        cout<<"Distanta de interceptie audio:";
        in>>dist_audio;
        cout<<"Distanta pentru interceptie video:";
        in>>dist_video;

    }
};

class listaautomobile
{
    vector <automobil*> v;
    int n;
public:
    listaautomobile()
    {
        n=0;
    }
    listaautomobile(vector<automobil*>v, int n)
    {
        this->n=n;
        this->v=v;
    }
    listaautomobile& operator+(masiniemisiereceptie& a)
    {
        v.push_back(&a);
        n++;
        return *this;
    }
    listaautomobile& operator+(masiniundercover& a)
    {
        v.push_back(&a);
        n++;
        return *this;
    }
    listaautomobile& operator+(masiniinterventie& a)
    {
        v.push_back(&a);
        n++;
        return *this;
    }
    listaautomobile& operator+(automobil& a)
    {
        v.push_back(&a);
        n++;
        return *this;
    }

    void afis()
    {
        for(int i=0; i<v.size(); i++)
            cout<<*v[i];
    }


};
int main()
{
    listaautomobile a;
    masiniundercover b;
    masiniemisiereceptie c;
    masiniinterventie d;
    cin>>b;
    cin>>c;
    cin>>d;
    a=a+b;
    a=a+c;
    a=a+d;
    a.afis();

    return 0;
}
