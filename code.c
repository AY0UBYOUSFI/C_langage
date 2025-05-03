#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>


struct List{
    int number;
    struct List *next;
};
typedef struct List *Tlist;


Tlist AddToList(Tlist L, int number){
    
    Tlist node = (Tlist) malloc(sizeof(struct List));
    node->number = number;


    if(L==NULL){
       L = node;
       L->next = NULL;
       return L;
    }
    else{

        Tlist T1 = L;
        while(T1->next!=NULL){
            T1=T1->next;
        }
        T1->next=node;
        node->next = NULL;
        return L;

    }
    return L;
}



void display(Tlist L){

   if(L==NULL)
     printf("empty list...");
    else{
        Tlist T = L;
        int i=0;
        while(T!=NULL){
            i++;
            printf("[%d:%d] -> ",i,T->number);
            if(T->next==NULL){
            printf("[NULL]");
            return;
            }
            else
            T=T->next;
        }
         

    }
return;

}


void CreatList(Tlist *p){

    int upperbound = rand()%100;
    int i=0,value=0;
    for(i=0;i<upperbound;i++){
        value = rand()%(i+1);
        *p=AddToList(*p,value);
        
    }

    display(*p);

}

void _ini_() {
    printf("\n");
    printf("  #############################################\n");
    printf("  #                                           #\n");
    printf("  #       ____  _        _                    #\n");
    printf("  #      |  _ \\(_)___ __| |_ ___  _ __        #\n");
    printf("  #      | | | | / -_) _|  _/ _ \\| '_ \\       #\n");
    printf("  #      |_| |_|_\\___\\__|\\__\\___/| .__/       #\n");
    printf("  #                                |_|        #\n");
    printf("  #                                           #\n");
    printf("  #       Dynamic Linked List Generator       #\n");
    printf("  #              Created by Peter             #\n");
    printf("  #############################################\n\n");

    Sleep(100);
}

int main(){




srand(time(NULL));
_ini_();

Tlist p= NULL;
int i =0;
for(i=0;i<5;i++){
    printf("\ntry [%d]\n",i);    
    CreatList(&p);
}

 

/*

 Tlist a = (Tlist) malloc(sizeof(struct List));
 a->number = 78;
 Tlist b = (Tlist) malloc(sizeof(struct List));
 b->number = 32;
 Tlist c = (Tlist) malloc(sizeof(struct List));
 c->number = 56;
 a->next=b;
 b->next=c;
 c->next= NULL;

 */





   // display(p);

     printf("\ncode running succesfuly ...");
    return 0;
}