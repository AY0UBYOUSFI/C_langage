#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
struct Transition{
    char symbole;
    int destination;
};
struct Etat{
bool estFinal;
vector<Transition> transitions;
};
struct Automate{
int numEtatInitial;
vector<Etat> etats;
};
Automate A;
string delta;
//****************prototype*******************
Automate creer_Automate();
bool det(Automate AEF);
void AFF_AEF(Automate automate);
bool mot_accepteur(Automate AEF, string mot);
//********************************************
Automate creer_Automate(){
Automate automate;
int numEtat,numTransition;
cout<<"NBR d ETATS : ";
cin>>numEtat;
cout<<"ETAT INTIALE : ";
cin>>automate.numEtatInitial;
for(int i=0;i<numEtat;i++){
Etat etat;
cout<<"ETAT " <<i<< " EST FINALE [1/0]!: ";
cin>>etat.estFinal;
cout<<"NBR DE TRANTION DETAT "<<i<<" : ";
cin>>numTransition;
for(int j=0;j<numTransition;j++){
Transition transition;
cout<<"SYMBOLE DE TRANTION DE L'ETAT ["<<i<< "] : ";
cin>>transition.symbole;
cout<<"ETAT DE DESTINATION DE L'ETAT ["<<i<<"] : ";
cin>>transition.destination;
etat.transitions.push_back(transition);
}
automate.etats.push_back(etat);
}
return automate;
}

bool det(Automate AEF){
    char ptr;
    for (int i=0;i<AEF.etats.size();i++) {
        for (int j = 0; j<AEF.etats[i].transitions.size();j++){
            for(int z = 0; z<AEF.etats[i].transitions.size();z++){
                ptr=AEF.etats[i].transitions[j].symbole;
                if((AEF.etats[i].transitions[z].symbole==ptr)&&(z!=j))
                   return false;
            }
        if(AEF.etats[i].transitions[j].symbole=='&')
        return false;
        }
    }
return true;
}



void AFF_AEF(Automate automate){
    cout<<"\n##### AUTOMATE [AEF] ##### :"<< endl;
    if(automate.etats.size()>0){
        cout<<"->";
        for(int i=0;i<automate.etats.size();i++){
            for(int j=0;j<automate.etats[i].transitions.size();j++){
                if(i==0&&j==0){
                cout<<"ETAT ["<<i<<"] -> ["<<automate.etats[i].transitions[j].symbole;
                cout<<"] -> ["<<automate.etats[i].transitions[j].destination<<"] "<<endl;
                }
                else{
                cout<<"  ETAT ["<<i<<"] -> ["<<automate.etats[i].transitions[j].symbole;
                cout<<"] -> ["<<automate.etats[i].transitions[j].destination<<"] "<<endl;
                }
            }
        }
    }
    else{
        cout<<"AUTOMATE VIDE ..!";
    }
}

bool mot_accepteur(Automate AEF, string mot) {
    int temp = AEF.numEtatInitial;
    bool SMBT = true;
    delta="";
    for (int i=0;i<mot.size();i++) {
        SMBT = false;
        for (int j = 0; j<AEF.etats[temp].transitions.size(); j++){
            if (AEF.etats[temp].transitions[j].symbole==mot[i]){
                temp = AEF.etats[temp].transitions[j].destination;
                SMBT = true;
                delta+=mot[i];
                break;
            }
        }
    }

    if (!SMBT||!AEF.etats[temp].estFinal||(delta!=mot))
    return false;
    return true;
}

int menu(){
system("color a");
int choix;
cout<<"\nMENUE DE CHOIX :\n";
cout<<"\n#########################\n";
cout<<"1: CREE AEF []->[]\n";
cout<<"2: AFFICHER AEF [AEF]\n";
cout<<"3: AEF DETERMINISTE [OUI/NON]\n";
cout<<"4: MOT ACSEPTE OU NON [OUI/NON]\n";
cout<<"5: EXITE [FIN]\n";
cout<<"\n#########################\n";
cout<<"\n ENTRE VOTRE CHOIX : ";
cin>>choix;
return choix;
}
int main(){
    int choix;
    do {
        choix = menu();
        switch (choix){
            case 1:{
                A=creer_Automate();
                break;
            }
            case 2:{
                AFF_AEF(A);
                break;
            }
            case 3:{
                   if(det(A))
                    cout<<"\nAEF DETERMINISTE\n";
                   else
                    cout<<"\nAEF NE PAS DETERMINISTE...!";
                    break;
            }
            case 4:{
                string s;
                cout<<"\nENTREZ MOT : "; cin >> s;
                if (mot_accepteur(A,s)){
                    cout<<"\nMOT ACCEPTE"<<endl;
                }
                else{
                    cout<<"\nMOT NON ACCEPTE" << endl;

                }
                break;
            }
            case 5:{
                cout<<"FIN\n";
                break;
            }
            default:{
                cout<<"ERREUR DE CHOIX !\n";
                break;
            }
        }
    } while(choix!=5);
    return 0;
}
