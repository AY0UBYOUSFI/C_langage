#include<studio.h> 
#include<stdlib.h>
FILE *ptr=NULL
void main(){
printf("hi\n");
Ptr=fopen("file.txt","w");
if(ptr==NULL){ 
printf("Ereur...");}
else{
char texte[100];
printf("entrez phrase : ");
gets(texte);
fprintf (ptr,"%s",texte);
}
printf ("fin.");
remove ("file.c");
}
