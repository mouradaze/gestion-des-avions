#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct date{
    int j,m,a;
}date;

typedef struct passager {
    char id[10],nom[20],prenom[20],adresse[20],tel[12];
    int age;
}passager;

typedef struct avion{
    char code[10],pilote[25];
    int modele,capacite,nbrVol;
    struct date date;
}avion;

typedef struct vol{
    struct avion av;
    struct passager pas;
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
    printf("Donner Le Code D'avion : ");scanf("%s",code);
    strcpy(v1->av.code,code);
    printf("Donner Le Pilote : ");scanf("%s",pilote);
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
    printf("Donnez L'id Du Passager : ");scanf("%s",id);
    strcpy(v1->pas.id,id);
    printf("Donnez Le Nom Du Passager : ");scanf("%s",nom);fflush(stdin);
    strcpy(v1->pas.nom,nom);
    printf("Donnez Le Prenom Du Passager : ");scanf("%s",prenom);
    strcpy(v1->pas.prenom,prenom);
    printf("Donnez L'aadresse Du Passager : ");scanf("%s",adresse);fflush(stdin);
    strcpy(v1->pas.adresse,adresse);
    printf("Donnez Le Numero De Telephone Du Passager : ");scanf("%s",tel);
    strcpy(v1->pas.tel,tel);
    printf("Donnez Age Du passager : ");scanf("%d",&age);
    v1->pas.age = age;
        // vol
    printf("Date De Depart :\n");
    printf("Le Jour : ");scanf("%d",&j);
    v1->dateDep.j = j;
    printf("Le Mois : ");scanf("%d",&m);
    v1->dateDep.m = m;
    printf("L'Annee : ");scanf("%d",&a);
    v1->dateDep.a = a;
    printf("Date De Depart :\n");
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

/*vo ajoutPass (vo v){
    vo v1 = v;
    while(v1!=NULL){
        if()
    }
}*/
void affich(vo v){
    if(v == NULL)
        printf("Rien a afficher");
    while(v!=NULL){
        printf("%s\t%s",v->av.pilote,v->pas.adresse);
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
    /*vo vol;
    vol = init(vol);
    vol = ajoutVol(vol);
    affich(vol);*/
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

                    break;
                case 4 :

                    break;
                case 5 :

                    break;
                case 6 :

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