#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct date{
    int j,m,a;
}date;

typedef struct passager {
    char id[10],nom[20],prenom[20],adresse[20],tel[12];
    int age;
    struct passager *next,*before;
}passager,*pa;

typedef struct avion{
    char code[10],pilote[25];
    int modele,capacite,nbrVol;
    struct date date;
}avion;

typedef struct vol{
    char codeVol;
    struct avion av;
    pa pas;
    struct date dateDep,dateArv;
    struct vol *next,*before;
}vol,*vo;

vo init(vo v){
    return NULL;
}

vo ajoutVol(vo v){
    char code[25],pilote[25],id[10],nom[25],prenom[25],adresse[25],tel[12];
    int modele,capacite,j,m,a,nbrVol,age;
    vo v1;
    v1 = malloc(sizeof(vo));
        // avion
    printf("Donner Le Code D'avion : ");scanf("%s",code);fflush(stdin);
    strcpy(v1->av.code,code);
    printf("Donner Le Pilote : ");scanf("%s",pilote);fflush(stdin);
    strcpy(v1->av.pilote,pilote);
    printf("Donner Le Modele De Avion : ");scanf("%d",&modele);fflush(stdin);
    v1->av.modele = modele;
    printf("Donner La Capacite De Stockage : ");scanf("%d",&capacite);
    v1->av.capacite = capacite;
    printf("Donner Le Nombre De Vols Assures : ");scanf("%d",&nbrVol);
    v1->av.nbrVol = nbrVol;
    printf("Donner La Date De Fabrication :\n");
    printf("Le Jour : ");scanf("%d",&j);
    v1->av.date.j = j;
    printf("Le Mois : ");scanf("%d",&m);
    v1->av.date.m = m;
    printf("L'Annee : ");scanf("%d",&a);
    v1->av.date.a = a;
        // passager
        
    printf("Donnez L'id Du Passager : ");scanf("%s",id);fflush(stdin);
    strcpy(v1->pas->id,id);
    printf("Donnez Le Nom Du Passager : ");scanf("%s",nom);fflush(stdin);
    strcpy(v1->pas->nom,nom);
    printf("Donnez Le Prenom Du Passager : ");scanf("%s",prenom);fflush(stdin);
    strcpy(v1->pas->prenom,prenom);
    printf("Donnez L'aadresse Du Passager : ");scanf("%s",adresse);fflush(stdin);
    strcpy(v1->pas->adresse,adresse);
    printf("Donnez Le Numero De Telephone Du Passager : ");scanf("%s",tel);fflush(stdin);
    strcpy(v1->pas->tel,tel);
    printf("Donnez Age Du passager : ");scanf("%d",&age);
    v1->pas->age = age;
    if(v1->pas == NULL){
    v1->pas->next = NULL;
    v1->pas->before = NULL;
        }
        else{
            v1->pas->next = v->pas;
            v->pas->before = v1->pas;
            v1->pas->before = NULL;
        }
        // vol
    printf("Donnez Le Code Du Vol : ");scanf("%s",code);fflush(stdin);
    strcpy(v1->codeVol,code);
    printf("Date De Depart :\n");
    printf("Le Jour : ");scanf("%d",&j);
    v1->dateDep.j = j;
    printf("Le Mois : ");scanf("%d",&m);
    v1->dateDep.m = m;
    printf("L'Annee : ");scanf("%d",&a);
    v1->dateDep.a = a;
    printf("Date D'Arriver :\n");
    printf("Le Jour : ");scanf("%d",&j);
    v1->dateArv.j = j;
    printf("Le Mois : ");scanf("%d",&m);
    v1->dateArv.m = m;
    printf("L'Annee : ");scanf("%d",&a);
    v1->dateArv.a = a;
    if(v == NULL){
        v1->next = NULL;
        v1->before = NULL;
        
        return v1;
    }
    else{
        v1->next = v;
        v->before = v1;
        v1->before = NULL;
        return v;
    }
}


void recherche (vo v){
    vo v1 = v;
    int tmp = 0;char id[10];
    printf("Donner L'id Du Passager : ");scanf("%s",id);
    while(v1!=NULL){
        if(strcmp(v1->pas->id,id) == 0)
            tmp = 1;
        v1 = v1->next;
    }
    if(tmp == 1)
        printf("Le Passager Existe !\n");
    else
        printf("Le Passager N'existe Pas !\n");
}

void volappart (vo v){
    vo v1 = v;
    char code[25];int tmp = 0;
    printf("Donnez Le Code Du Vol : ");scanf("%s",code);
    while(v1 !=NULL){
        if(strcmp(v1->codeVol,code) == 0)
            tmp = 1;
        v1 = v1->next;
    }
    if(tmp == 1)
        printf("Le Vol Existe !\n");
    else
        printf("Le Vol N'existe Pas !\n");
}

vo modifdate (vo v){
    vo v1 = v;int j,m,a;char code[25];
    printf("Donnez Le Code Du Vol : ");scanf("%s",code);
    while(v1 != NULL){
        if(strcmp(v1->codeVol,code) == 0){
            printf("Donnez Une Date Superieure A La Date Actuelle\n");
            printf("Date De Depart :\n");
            do{
            printf("Le Jour : ");scanf("%d",&j);
            }while(j>v1->dateDep.j);
            v1->dateDep.j = j;
            

            do{
            printf("Le Mois : ");scanf("%d",&m);
            }while(m>v1->dateDep.m);
            v1->dateDep.m = m;
            

            do{
            printf("L'Annee : ");scanf("%d",&a);
            }while(a>v1->dateDep.a);
            v1->dateDep.a = a;
            


            printf("Date D'Arriver :\n");
            do{
            printf("Le Jour : ");scanf("%d",&j);
            }while(j>v1->dateDep.j);
            v1->dateArv.j = j;
            

            do{
            printf("Le Mois : ");scanf("%d",&m);
            }while(m>v1->dateDep.m);
            v1->dateArv.m = m;
            

            do{
            printf("L'Annee : ");scanf("%d",&a);
            }while(a>v1->dateDep.a);
            v1->dateArv.a = a;
            
        }
    }
    return v;
}
void affichtt(vo v){
    if(v == NULL)
        printf("Rien a afficher");
    while(v!=NULL){
        printf("Le Vol %s : \n",v->codeVol);
        printf("Date De Depart :\n");
        printf("Le Jour : %d",v->dateDep.j);
        printf("Le Mois : %d",v->dateDep.m);
        printf("L'Annee : %d",v->dateDep.a);
        printf("Date D'Arriver :\n");
        printf("Le Jour : %d",v->dateArv.j);
        printf("Le Mois : %d",v->dateArv.m);
        printf("L'Annee : %d",v->dateArv.a);

        printf("Infos D'avion :\n");
        printf("Le Code D'avion : %s\n");
        printf("Le Pilote : %s\n");
        printf("Le Modele De Avion : %d\n");
        printf("La Capacite De Stockage : %d\n");
        printf("Le Nombre De Vols Assures : %d\n");
        printf("La Date De Fabrication : %d\n");
        printf("Le Jour : %d\n");
        printf("Le Mois : %d\n");
        printf("L'Annee : %d\n");
        printf("Infos Des Passager : \n");
        v = v->next;
    }
}
void menuPrincipal(){
    printf("************ Menu Principal **************\n");
    printf("1- Ajouter un vol\n");
    printf("2- Ajouter Un Passager A Un Vol\n");
    printf("3- Recherche D'un Passager\n");
    printf("4- Appartenance D'un Vol\n");
    printf("5- Modifier La Date D'un Vol\n");
    printf("6- Afficher Tous Les Vols");
    printf("7- Afficher Les Passager De Moins De 10 Ans\n");
    printf("8- Afficher Les Vols De Demain\n");
    printf("9- Supprimer Le Dernier Vol\n");
    printf("10- Supprimer Un Passager\n");
    printf("11- Fermer Le Programme\n");
}
int main(){
    int choix;
    vo vol;
    vol = init(vol);
    do{
        menuPrincipal();
        printf("Votre Choix : ");scanf("%d",&choix);
            switch(choix){
                case 1 :
                    vol = ajoutVol(vol);
                    break;
                case 2 :
                    
                    break;
                case 3 :
                    recherche(vol);
                    break;
                case 4 :
                    volappart(vol);
                    break;
                case 5 :
                    vol = modifdate(vol);
                    break;
                case 6 :
                    affichtt(vol);
                    break;
                case 7 :

                    break;
                case 8 :

                    break;
                case 9 :

                    break;
                case 10 :

                    break;
                case 11 :
                    exit(1);
                    break;
                default :
                    printf("Ce Choix N'est Pas Disponible, Ressayer !!\n");
                    break;
            }
    }while(choix != 11);
}