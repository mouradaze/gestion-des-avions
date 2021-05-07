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
    vo v1;
    v1 = malloc(sizeof(vo));
        // avion
    strcpy(v1->av.code,"5050");
    strcpy(v1->av.pilote,"hamada");
    v1->av.modele = 1515;
    v1->av.capacite = 5000;
    v1->av.nbrVol = 15;
    v1->av.date.j = 18;
    v1->av.date.m = 5;
    v1->av.date.a = 2000;
        // passager
    strcpy(v1->pas.id,"karim");
    strcpy(v1->pas.nom,"karim");
    strcpy(v1->pas.prenom,"karim");
    strcpy(v1->pas.adresse,"karim");
    strcpy(v1->pas.tel,"karim");
    v1->pas.age = 21;
        // vol
    v1->dateDep.j = 15;
    v1->dateDep.m = 15;
    v1->dateDep.a = 15;
    v1->dateArv.j = 20;
    v1->dateArv.m = 20;
    v1->dateArv.a = 20;
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

void affich(vo v){
   /* while(v!=NULL){
        //printf("%s\t%s",v->av.pilote,v->pas.adresse);
        v = v->next;
    }*/
}
int main(){
    vo vol;
    vol = init(vol);
    vol = ajoutVol(vol);
    //affich(vol);
}