#include <iostream>
#include<fstream>>
#include<string.h>
using namespace std;
ifstream f("Date2.txt");

struct lista_circulara
{
    int val;
    struct lista_circulara *next, *prev;


};


void add_dreapta( struct lista_circulara *&prim,  struct lista_circulara *&ultim, struct lista_circulara *&marcaj)
{  struct lista_circulara *l=new lista_circulara;

    int x;
    f>>x;
     l->val=x;

    if(prim==NULL)
    {   prim=ultim=l;
         l->next=marcaj;
       l->prev=marcaj;
        marcaj->next=l;
        marcaj->prev=l;

    }
    else
    {   l->next=prim;
        l->prev=marcaj;
        prim->prev=l;
        marcaj->next=l;
        prim=l;

    }

cout<<"S-a adaugat elem in dreapta nodului marcaj\n";
}

void add_interior(struct lista_circulara *&prim, struct lista_circulara *&ultim, struct lista_circulara *&marcaj)
{ struct lista_circulara *l=new lista_circulara, *p=prim;
  int x,k,n=1;
  f>>x>>k;
   cout<<"Vom introduce elemntul "<<x<<" pe pozitia "<<k<<"\n";

   l->val=x;
   if(prim==NULL)
    {    prim=ultim=l;
        l->next=l->prev=marcaj;
        marcaj->next=l;
        marcaj->prev=l;

    }
    else
        if(k==1)
      { l->prev=marcaj;
        l->next=prim;
         prim->prev=l;
         marcaj->next=l;
         prim=l;

      }
      else
     {

   while(p!=marcaj&&n<k-1)
   {   n++;
       p=p->next;

   }

   if(p==marcaj||p->next==marcaj)
    cout<<"Pozitia nu exista\n";
    else
   {
        l->next=p->next;
        p->next->prev=l;
       l->prev=p;
       p->next=l;
   }

    }
}

void sterge_elem_dupa_val (struct lista_circulara *&prim, struct lista_circulara *&ultim, struct lista_circulara *&marcaj)
{
    struct lista_circulara *l=prim, *aux;
    int x;
    f>>x;
    cout<< "Vom sterge elemntul "<<x<<" din lista\n";
    if(prim==NULL)
        cout<<"Elementul nu exista in lista, lista vida \n";
        else
       if(prim->val==ultim->val==x)
       {
           delete l;
           prim=ultim=NULL;
           marcaj->next=marcaj->prev=marcaj;
       }
    else
        if(prim->val==x)
     {  aux=prim;
        prim=prim->next;
        prim->prev=marcaj;
        marcaj->next=prim;
        delete aux;
    }
    else
        if(ultim->val==x)
    {   aux=ultim;
        ultim=ultim->prev;
        ultim->next=marcaj;
        marcaj->prev=ultim;
        delete aux;
    }
    else
  {
    while(l!=marcaj&&l->val!=x)
        l=l->next;
    if(l==marcaj)
     cout<<"Elementul nu exista in lista \n";
     else
      {aux=l;
       l->prev->next=l->next;
       l->next->prev=l->prev;
     delete l;}

  }
}

void sterge_stanga(struct lista_circulara *&prim,struct lista_circulara *&ultim,struct lista_circulara *&marcaj)
{
    struct lista_circulara *aux;
    if(prim==NULL)
      cout<<"Lista vida\n";
    else
    if(ultim==prim)
    { aux=prim;
      delete aux;
      prim=ultim=NULL;
      marcaj->next=marcaj;
      marcaj->prev=marcaj;
      cout<<"S-a sters elem din stanga nodului marcaj\n";
    }
    else
    {
    aux=ultim;
    ultim=ultim->prev;
    delete aux;
    ultim->next=marcaj;
    marcaj->prev=ultim;

    cout<<"S-a sters elem din stanga nodului marcaj\n";
     }
}

void afisare (struct lista_circulara *prim, struct lista_circulara *marcaj)
{
    struct lista_circulara *l=prim;
    if(prim==NULL)
        cout<<"Lista vida\n";
    else
    {cout<<"Lista: ";
    while(l!=marcaj)
    {   cout<<l->val<<"  ";
        l=l->next;
    }
    cout<<"\n\n"; }

}

int main()
{
    struct lista_circulara *prim=NULL, *ultim=NULL, *marcaj=new struct lista_circulara;
     marcaj->next=marcaj;
     marcaj->prev=marcaj;
     char s[50];

     while(f>>s)
     {
         if(strcmp(s,"add_dreapta")==0)
            add_dreapta(prim,ultim,marcaj);
           else
              if(strcmp(s,"sterge_stanga")==0)
                sterge_stanga(prim,ultim,marcaj);
           else
              if(strcmp(s,"add_interior")==0)
               add_interior(prim,ultim,marcaj);
           else
              if(strcmp(s,"sterge_elem_dupa_val")==0)
                sterge_elem_dupa_val(prim,ultim,marcaj);
               else
                if(strcmp(s,"afisare")==0)
                      afisare(prim,marcaj);
     }


    return 0;
}
