#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

class decoratiune
{
private:
    bool reciclabil;
    char *nume;
    float price;
public:
    decoratiune()
    {
        reciclabil=0;
        nume=new char[strlen("Necunoscut")+1];
        strcpy(nume,"Necunoscut");
        price=0.0f;
    }
    decoratiune(bool reciclabil,char*nume,float pret)
    {
        this->reciclabil=reciclabil;
        this->nume=new char[strlen(nume)+1];
        strcpy(this->nume,nume);
        this->price=pret;
    }
    decoratiune(const decoratiune &deco)
    {
        this->reciclabil=deco.reciclabil;
        this->nume=new char[strlen(deco.nume)+1];
        strcpy(this->nume,deco.nume);
        this->price=deco.price;
    }

    decoratiune &operator=(const decoratiune &deco)
    {
        if(this!=&deco)
        {
            this->reciclabil=deco.reciclabil;
            this->price=deco.price;
            if(this->nume!=nullptr)
                delete[]this->nume;
            strcpy(this->nume,deco.nume);
            this->price=deco.price;
        }

    }
    void setRecic(bool a)
    {
        this->reciclabil=a;
    }
    void setNume(char *a)
    {
        if(this->nume!=nullptr)
            delete[]this->nume;
        this->nume=new char[strlen(a)+1];
        strcpy(this->nume,a);
    }
    void setPrice(float a)
    {
        this->price=a;
    }
    bool getRecic()
    {
        return this->reciclabil;
    }
    char *getNume()
    {
        return this->nume;

    }
    float getpret()
    {
        return this->price;
    }
    float pret()
    {
        return this->price;
    }
    friend ostream&operator<<(ostream &out,const decoratiune deco)
    {
        out<<deco.nume<<" are pretul: "<<deco.price<<" lei.";
        if(deco.reciclabil)
        {
            cout<<"Acesta este reciclabil.\n";

        }
        else
            cout<<"Acesta nu este reciclabil.\n";
        return out;
    }
    friend istream&operator>>(istream &in,decoratiune &deco)
    {
        char aux[100];
        cout<<"Introduceti numele decoratiunii: \n";
        in>>aux;
        if(deco.nume!=NULL)
            delete[]deco.nume;
        deco.nume=new char[strlen(aux)+1];
        strcpy(deco.nume,aux);
        cout<<"Pretul produsului:\n";
        in>>deco.price;
        cout<<"Este reciclabil(1/0):\n";
        in>>deco.reciclabil;
        return in;
    }

};
class listaproduse:public decoratiune
{
public:
    vector<decoratiune> listadec;

    friend ostream&operator<<(ostream &out,  listaproduse b)
    {
        out<<"Pe lista avem:\n";
        for(int i=0; i<b.listadec.size(); i++)
        {
            out<<b.listadec[i].getNume()<< " cu pretul: "<< b.listadec[i].getpret()<<
                " si este reciclabil:"<<b.listadec[i].getRecic();
            out<<endl;
        }
    }
    float pret()
    {
        float total=0;
        for(int i=0; i<listadec.size(); i++)
            total=total+listadec[i].getpret();
        return total;
    }
    listaproduse operator+(decoratiune a)
    {
        listadec.push_back(a);
        return *this;
    }
    decoratiune &operator[](int i)
    {
        return this->listadec[i];
    }
    void remove(int i)
    {
        listadec.erase(listadec.begin()+i);
    }



};
int main()
{
    listaproduse b;
    decoratiune a;
    cin>>a;
    b=b+a;
    cout<<b[0]<<endl;
    cout<<b.pret()<<endl;
    cout<<b[0].pret()<<endl;
    //b.remove(0);
    cout<<b;
    return 0;
}
