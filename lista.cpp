#include <iostream>
#include<fstream>
#include<string.h>
using namespace std;
ifstream f("Date.txt");

struct start
{
    int val;
    struct start *next, *prev;


};


void add_inceput( struct start *&prim,  struct start *&ultim, struct start *&marcaj)
{  struct start *l=new start;
    int x;
    f>>x;
     l->val=x;

    if(prim==NULL)
    {   l->next=NULL;
       l->prev=marcaj;
       prim=ultim=l;

    }
    else
    {
        l->prev=marcaj;
        l->next=prim;
        prim->prev=l;
        prim=l;

    }


}

void add_final (struct start *&prim, struct start *&ultim, struct start *&marcaj)
{
  struct start *l=new start;
  int x;
  f>>x;
   l->val=x;

   if(prim==NULL)
   { l->next=NULL;
   l->prev=marcaj;
     prim=ultim=l;

   }
   else
   {   l->next=NULL;
       l->prev=ultim;
       ultim->next=l;
       ultim=l;
   }
}


void sterge_inceput(struct start *&prim,struct start *&ultim,struct start *&marcaj)
{
    struct start *aux;
    if(prim==NULL)
        cout<<"Lista vida";
    if(prim==ultim)
    {
     delete prim;
     marcaj->next=NULL;
    }
    else {
     aux=prim;
     prim=prim->next;
      prim->prev=marcaj;
      marcaj->next=prim;
      delete aux;
    }
}

void sterge_final(struct start *&prim,struct start *&ultim,struct start *&marcaj)
{
    struct start *aux;
    if(prim==NULL)
        cout<<"Lista vida";
    else
    if(ultim==prim)
    { delete prim;
      marcaj->next=NULL;
    }
    else
    {
    aux=ultim;
    ultim=ultim->prev;
    delete aux;
    ultim->next=NULL;
    }
}



void afisare (struct start *prim)
{
    struct start *l=prim;
    if(prim==NULL)
        cout<<"Lista vida\n";
    else
    while(l!=NULL)
    {   cout<<l->val<<"  ";
        l=l->next;
    }
    cout<<"\n\n";

}

int main()
{
    struct start *marcaj=new start,*prim=NULL, *ultim=NULL;
     marcaj->next=prim;
     marcaj->prev=NULL;
     char s[50];
   while(f>>s)
    {
        if(strcmp(s,"add_inceput")==0)
            add_inceput(prim, ultim, marcaj);
            else
         if(strcmp(s,"add_final")==0)
            add_final(prim,ultim, marcaj);
            else
         if(strcmp(s,"afisare")==0)
            afisare(prim);
            else
             if(strcmp(s,"sterge_final")==0)
               sterge_final(prim,ultim,marcaj);
              else
                if(strcmp(s,"sterge_inceput")==0)
               sterge_inceput(prim,ultim,marcaj);



    }

    return 0;
}
