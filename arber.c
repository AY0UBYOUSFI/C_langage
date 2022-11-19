#include <iostream>
#include <stdlib.h>
using namespace std;
struct noeud{
int x;
noeud *G,*D;
};
typedef noeud* arbre;
arbre creenoeud ( int x ) {
arbre k = new noeud ;
k->x=x ;
k->G=NULL;
k->D=NULL;
}
void infixe (arbre a) {

if (a!=NULL) {
infixe (a->G) ;
cout <<a->x<<" " ;
infixe (a->D) ;}
}
void prefixe ( arbre a) {


if (a!=NULL) {
cout <<a->x<<" " ;
prefixe (a->G) ;
prefixe (a->D) ;}}
void postfixe ( arbre a) {


if (a!=NULL) {
postfixe (a->G) ;
postfixe (a->D) ;
cout <<a->x<<" " ;
}
}
arbre recherche ( arbre a,int x ) {

if(a==NULL) return NULL;
else if (a->x==x ) return a;
else if (a->x>x ) return recherche (   a->G, x ) ;
else return recherche (a->D, x ) ;
}

arbre min( arbre  a) {
if (a==NULL) return NULL;
else if (a->G==NULL) return a;
else return min(a->G) ;
}
arbre max ( arbre a) {
if (a==NULL) return NULL;
else if (a->D==NULL) return a;
else return min(a->D) ;
}
arbre succ( arbre  a) {
if (a==NULL) return NULL;
else if (a->D==NULL) return NULL;
else return min(a->D) ;
}
arbre prec(arbre  a) {
if (a==NULL) return NULL;
else if(a->G==NULL) return NULL;
else return max(a->G) ;
}
arbre ajout ( arbre a, int x ) {
arbre k= new noeud ;
k->x=x ;
k->D=NULL;
k->G=NULL;
if (a==NULL) a=k ;
else {
arbre p=NULL;
arbre A1=a;
while (A1!=NULL) {
p=A1 ;
if (A1->x>x )A1=A1->G;
else A1=A1->D;
}
if ( p->x>x ) p->G=k ;
else p->D=k ;
}
return a;
}
arbre supp( arbre a, int x ) {
if (a==NULL) return NULL;
else {
arbre p=NULL;
arbre A1=a;
while (A1!=NULL)
if (A1->x==x ) {
if ((A1->G==NULL) && (A1->D==NULL)) {
if ( p==NULL) return NULL;
else if ( p->G==A1 ) p->G=NULL;
else p->D=NULL;
delete (A1 ) ;
break ;
}
else if ((A1->G==NULL) || (A1->D==NULL)) {
arbre f ;
if (A1->D==NULL) f =A1->G;
else f =A1->D;
if ( p==NULL)a=f ;
else if ( p->D==A1 ) p->D= f ;
else p->G= f ;
delete (A1 ) ;
break ;
}
else {
arbre pr = prec (A1 ) ;
A1->x=pr->x ;
x=pr->x ;
p=A1 ;
A1=A1->G;
continue ;
}
}
else {
p=A1 ;
if (A1->x>x) A1=A1->G;
else A1=A1->D;
}
}
return a;
}



void menu ( ) {
system ( " c l s " ) ;
cout<<"\n1.cree noeud " ;
cout<<"\n2.recherche " ;
cout<<"\n3.max " ;
cout<<"\n4.min " ;
cout<<"\n5.suucceur  " ;
cout<<"\n6.predsecceur " ;
cout<<"\n7.insersition" ;
cout<<"\n8.sppresion";
cout<<"\n9.affiche";
}
int main()
{
arbre a=NULL;
int ch;
char ri;
do{system("cls");system("color a");
menu () ;
cout <<" \nDonner votre choix  " ; cin >>ch ;
switch (ch) {
case 1:{int s;
cout<<" donnes s ";
cin>>s;
a=ajout(a,s);
cout<<"\n prefix ";
prefixe(a);
cout<<"\n infixe ";
infixe(a);
cout<<"\n postefixe ";
postfixe(a);
}
break ;
case 2 :{
int y;
cout<<"  donnes y";
cin>>y;
arbre m;
m=recherche(a,y);
if(m!=NULL)cout<<" existe ";
else cout<<"ne pas existe ";
}
break ;
case 3 :{
arbre f=max(a);
infixe(f);
prefixe(f);
postfixe(f);
}
break ;
case 4 :{
arbre c=min(a);
infixe(c);
}
break ;
case 5 :{
arbre t=succ(a) ;
infixe(t);
}
break ;
case 6 :{
arbre i =prec(a) ;
infixe(i);
}
break ;
case 7 :{int s;
cout<<" donnes s";
cin>>s;
a=ajout(a,s);
cout<<"\n prefix";
prefixe(a);
cout<<"\n infixe";
infixe(a);
cout<<"\n postefixe";
postfixe(a);
}
break ;
case 8 :{int b;
cout<<" donnes b";
cin>>b;
a=supp(a,b);
}
break ;
case 9 :{cout<<"\n prefix ";
if(a==0)cout<<"vide ";
prefixe(a);
cout<<"\n infixe ";
if(a==0)cout<<"vide ";
infixe(a);
cout<<"\n postefixe ";
if(a==0)cout<<" vide ";
postfixe(a);
}break;
default:cout<<"error";
}cout<<"\n continut o/n \n";
cin>>ri;
}while(ri!='n');return 0;}
