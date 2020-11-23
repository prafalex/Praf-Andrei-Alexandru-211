#include <iostream>

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
    friend ostream&operator <<(ostream &out,const automobil &a)
    {
        out<<"Marca:"<<a.marca<<";Model:"<<a.model<<";scop:"<<a.use;
        if(a.combustibil)
            cout<<".Acesta foloseste benzina";
        else
            cout<<".Acesta foloseste motorina";
        return out;

    }
    friend istream& operator>>(istream &in, automobil &a)
    {
        cout<<"Marca:";
        in>>a.marca;
        cout<<"Model:";
        in>>a.model;
        cout<<"Scop:";
        in>>a.use;
        cout<<"Este pe benzina sau motorina(0 pentru motorina, 1 pentru benzina):";
        in>>a.combustibil;
        return in;
    }


};

class masiniundercover: public automobil
{
    //viteza, nr gloate rezistenta;
    float speed;
    int no_of_res;
    friend ostream& operator<<(ostream &out,const masiniundercover& m)
    {
        out<<(automobil&)m;
        out<<"\nAcesta prinde viteza:"<<m.speed<<" si rezista la "<<m.no_of_res<<" gloante";
        return out;

    }
    friend istream&operator >>(istream &in, masiniundercover &m)
    {
        in>>(automobil&)m;
        cout<<"Viteza:";
        in>>m.speed;
        cout<<"Nr. de gloante la care rezista:";
        in>>m.no_of_res;
        return in;
    }

};

class masiniinterventie:public automobil
{
    int no_of_pers;
    bool arma;
    friend ostream& operator<<(ostream &out,const masiniinterventie& m)
    {
        out<<(automobil&)m;
        out<<"\nAcesta poate transporta: "<<m.no_of_pers<<" persoane";
        if(m.arma)
            cout<<"\nAcesta este dotat cu TR-85";
        else
            cout<<"\n Acesta nu este dotat cu TR-85";
        return out;

    }
    friend istream&operator >>(istream &in, masiniinterventie &m)
    {
        in>>(automobil&)m;
        cout<<"Nr. de persoane care pot fi transportate:";
        in>>m.no_of_pers;
        cout<<"Este dotat cu TR-85(0/1):";
        in>>m.arma;
        return in;
    }
};

class masiniemisiereceptie:public automobil
{
    //distanta de interceptie audio,dist de interceptie video
    float dist_audio;
    float dist_video;
    friend ostream& operator<<(ostream &out,const masiniemisiereceptie& m)
    {
        out<<(automobil&)m;
        out<<"\Distanta de interceptie audio este:"<<m.dist_audio<<" ,iar distanta pentru interceptie video este: "
           <<m.dist_video;
        return out;

    }
    friend istream&operator >>(istream &in, masiniemisiereceptie &m)
    {
        in>>(automobil&)m;
        cout<<"Distanta de interceptie audio:";
        in>>m.dist_audio;
        cout<<"Distanta pentru interceptie video:";
        in>>m.dist_video;
        return in;
    }
};

class listaautomobile
{
    automobil *a[100];
public:
    int cont=0;
    void add()
    {
        int n;
        cout<<"Cate produse doriti sa adaugati?\n";
        cin>>n;
        int ch;

        for( int i=0 ; i<n; i++)
        {
            cout<<"Automobil emisie(1),Automobil interventie(2),Automobil undercover(3)";
            cin>>ch;
            if(ch==1)
            {

                a[this->cont]=new masiniemisiereceptie;
                cin>>*a[this->cont];

            }else
             if(ch==2)
            {
                a[this->cont]=new masiniinterventie;
                cin>>*a[this->cont];


            }else
            if(ch==3){
                a[this->cont]=new masiniundercover;
                cin>>*a[this->cont];
            }
            this->cont++;
        }
    }

    void afis()
    {
        //cout<<"Contor: "<<cont<<endl;
        for(int i=0; i<this->cont; i++)
        {
            cout<<*a[i];
        }
    }

};
int main()
{
    listaautomobile a;
    masiniundercover m;
    masiniinterventie m1;
    masiniemisiereceptie m2;
    a.add();
    a.afis();
    return 0;
}
