#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include "pizza.h"


void *order(void *x){
	//thlefwniths
    int id = *(int *)x;
    int rc;
    struct timespec start,end1,end2,endf;
    
    rc = pthread_mutex_lock(&lock5);  
    while (Neisodos == 0) {  
        rc = pthread_cond_wait(&cond5, &lock5);
        
    }
	
    Neisodos--;
    randnum=(rand()%Torderhigh-Torderlow)+Torderlow;
    sleep(randnum); 
    Neisodos++;
    rc = pthread_cond_signal(&cond);
    rc = pthread_mutex_unlock(&lock5);
    
    clock_gettime(CLOCK_REALTIME,&start); //wra pou ksekinise h paraggelia
    
    printf("H paraggelia %d xekinhse\n",id);

    rc = pthread_mutex_lock(&lock);  //kleidwma tou mutex pou afora ton diathesimo thlefwnith otan dexetai klisi
    while (Ntel == 0) {  //an den yparxoun diathesimoi thlefwnites
        
        rc = pthread_cond_wait(&cond, &lock); //perimene to antistoixo sima
    }
	
    Ntel--; //meiwse ton arithmo twn diathesimwn thlefwnitwn
    rc = pthread_mutex_unlock(&lock);
    

    
    
    //arxikopoihsh metritwn gia kathe pitsa kai gia ta esoda
    int sunthr=0;
    int spethr=0;
    int marthr=0;
    int pepthr=0;
    int plth=(rand()%Norderhigh-Norderlow)+Norderlow;  //dhmioyrgeitai tyxaios arithmos apo pitses sto diasthma pou dinetai
    for(int j=0;j<plth;j++){
    int r=(rand()%100)+1;   //apofasizetai to eidos ths pizzas
    
    //analoga me to eidos ths pizzas prosarmozontai ta esoda
    if(r<=Pm){
    	sunthr=sunthr+Cm;
    	marthr++;
    	}
    else if(r<=Pm+Pp){
    	sunthr=sunthr+Cp;
    	pepthr++;
    	}
    else {
    	sunthr=sunthr+Cs;
    	spethr++;
    	}
    }
    int d=(rand()%Tpaymenthigh-Tpaymentlow)+Tpaymentlow;
    int ep=(rand()%100);
    if(ep<=Pfail){
    	rc = pthread_mutex_lock(&screen);  //mutex gia kleidwma othonis kata thn ektipwsi ths eksodou
    	printf("H paraggelia me arithmo %d apetuxe \n", id);
    	Ntel++;   //h paraggelia apetyxe ara yparxei pleon diathesimos o thlefwnitis
    	rc = pthread_mutex_unlock(&screen); 
    	apot++;   //auksanw arithmo apotyximenwn paraggeliwn
    	rc = pthread_cond_signal(&cond);
    	pthread_exit(NULL);
    	}
    	rc = pthread_mutex_lock(&screen);  
    	printf("H paraggelia me arithmo %d kataxwrithike \n", id);	
    	rc = pthread_mutex_unlock(&screen);
    epit++;  //auksanw arithmo epityximenwn paraggeliwn
    //edw prostetoume tis pizzes ths paragelias stis sunolikes pitses
    sun=sun+sunthr;
    mar=mar+marthr;
    pep=pep+pepthr;
    spe=spe+spethr;
    
    
    
    Ntel++;
	rc = pthread_cond_signal(&cond);
    
    
    
    //paraskevasths
    rc = pthread_mutex_lock(&lock2);  //otan arxizei na xrhsimopoieitai kapoios paraskevastis
    while (Ncook == 0) {   // synthiki anamonis oso den exoume diathesimo paraskevasti
    	
        rc = pthread_cond_wait(&cond2, &lock2);
    }
    
    Ncook--;
    rc = pthread_mutex_unlock(&lock2);
    sleep(Tprep*plth);  //gia na prosomoiwsw thn wra pou xreiazetai h paraskeyh
    
    
    
    
    //fournoi
    
    rc = pthread_mutex_lock(&lock3); //otan arxizei na xrhsimopoieitai kapoios fournos
    while (Noven < plth) {  //an oi fournoi einai ligoteroi apo tis pizzes pou prepei na psithoun tautoxrona
    	
        rc = pthread_cond_wait(&cond3, &lock3);
    }
    Noven=Noven-plth; //afairw tous fournous poy einai se xrhsh
    rc = pthread_mutex_unlock(&lock3);
    
    //Prosthetoume ton poro molis eleftherwthei fournos kai boume sthn diadikasia psisimatos
    Ncook++;
    
    rc = pthread_cond_signal(&cond2);
    
    
    sleep(Tbake); //prosomoiazei thn wra psisimatos
    
    
    
    //delivery
    
    rc = pthread_mutex_lock(&lock4);
    while (Ndeliver == 0) {
    	
        rc = pthread_cond_wait(&cond4, &lock4);
    }
    //kanoume akrivos to idio me ton fourno ,me to pou erthei delivery diathesimo dinoume pisw tous fournous
    Noven=Noven+plth;
    rc = pthread_cond_signal(&cond3);
    
    
    Ndeliver--; //otan enas dianomeas eksipiretei
    rc = pthread_mutex_unlock(&lock4);
    
    clock_gettime(CLOCK_REALTIME,&endf);
    
    sleep(Tpack*plth); //xronos pou xreiazetai gia paketarisma
    
    clock_gettime(CLOCK_REALTIME,&end1);
    
    long leptaet=end1.tv_sec-start.tv_sec; //xronos synolikhs proetoimasias
    
    rc = pthread_mutex_lock(&screen); //mutex gia kleidwma othonis otan typwnw eksodo
	printf("H paraggelia me arithmo %d etoimastike se %ld lepta.\n", id,leptaet);
	rc = pthread_mutex_unlock(&screen);
    
    
    
    int r2=(rand()%Tdelhigh-Tdellow)+Tdellow;  //tyxaios xronos pou xreiazetai gia thn dianomh
    
    sleep(r2);
    
    clock_gettime(CLOCK_REALTIME,&end2);
    long leptap=end2.tv_sec-start.tv_sec;  //ypologismos synolikou xronou
    if(leptap>megxrono){
    megxrono=leptap;  //update ton megisto xrono paradosis
    }
    sunxronos=sunxronos+leptap; //prosthesi ston synoliko xrono paradosis
    
    
    
    long leptakr=end2.tv_sec-endf.tv_sec;
    
    if(leptakr>megxronokr){
    megxronokr=leptakr;  //gia megisto xrono kryomatos paraggeliwn
    }
    sunxronoskr=sunxronoskr+leptakr;	
    
    rc = pthread_mutex_lock(&screen);
	printf("H paraggelia me arithmo %d paradothike se %ld lepta.\n", id,leptap);
	rc = pthread_mutex_unlock(&screen);
    
    sleep(r2);
    
    
    Ndeliver++;  //eleythervnetai enas dianomeas 
    rc = pthread_cond_signal(&cond4);
    
    
    pthread_exit(NULL); //exodos apo to nima
}


int main(int argc,char *argv[] )  {
	
	if(argc != 3){
		printf("ERROR: Provide one argument. \n");
		return -1;
	}
	
	int N=atoi(argv[1]);  //arithmos paraggeliwn
	int seed=atoi(argv[2]); //tyxaio seed
	srand(seed);
	int id[N];
	
	
    int rc;
    pthread_t threads[N];

    pthread_mutex_init(&lock, NULL);
    pthread_cond_init(&cond, NULL);
	
    for (int i = 0; i < N; i++) {  //dhmiourgia nimatwn
        id[i] = i+1;
        printf("Main: dhmioyrgia nhmatos %d\n", i+1);
    	rc = pthread_create(&threads[i], NULL, order, &id[i]);
    	
    	
        
    }

    for (int i = 0; i < N; i++) {
        pthread_join(threads[i], NULL);
        
    }
    //ektipwsi twn statistikwn apotelesmatwn
	printf("To kerdos htan %d.\n", sun);
	printf("MARGARITES: %d.\n", mar);
	printf("PEPERONI: %d.\n", pep);
	printf("SPECIAL %d.\n", spe);
	printf("Eixame %d epitixumenes paragelies kai %d apotuximenes paragelies.\n", epit,apot);
	
	long mo=sunxronos/epit;
	printf("O megistos xronos paradwshs htan %ld lepta kai mesos xronos %ld lepta.\n", megxrono,mo);
	
	long mokr=sunxronoskr/epit;
	printf("O megistos xronos kruwmatos htan %ld lepta kai mesos xronos %ld lepta.\n", megxronokr,mokr);
	//katastrofi twn nhmatwn kai twn metavlhtwn synthikis
    pthread_mutex_destroy(&lock);
    pthread_cond_destroy(&cond);
    
    pthread_mutex_destroy(&lock2);
    pthread_cond_destroy(&cond2);
    
    pthread_mutex_destroy(&lock3);
    pthread_cond_destroy(&cond3);
    
    pthread_mutex_destroy(&lock4);
    pthread_cond_destroy(&cond4);

    return 0;
}
