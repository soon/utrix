/*
 *  pth_struct.h
 *  Utrix
 *
 *  Created by Matteo Casenove on 11/07/08.
 *  Copyright 2008 Utrix. All rights reserved.
 *
 */

#include "pthread_lib.h"
#include "pth_context.h"
#define ESECUTION_TID thread_exec->tid
#define DETACH 0
#define JOIN 1

/*Qui ci saranno solo le dichiarazioni e strutture necessarie per lavorare con i thread*/

/* Thread Control Block */
typedef struct tcb{
	pthread_t tid_f;
	pthread_t tid;
	void** result;/*Salvo l'informazione l'utilizzo varia a seconda se faccio prima la exit o la join*/
	struct tcb* thread_join;/*Al massimo solo un thread può fare la join sullo stesso thread, mettendolo nel tcb semplifico di molto il codice*/
	int prior;
	context_t ctx;
	int state;
	clock_t time;
	char save;
} tcb_s;

typedef tcb_s* tcb_t;

/* Thread table field */
typedef struct tbl_field{
    tcb_t tcb;
    struct tbl_field* next; 
} tbl_field_s;

typedef tbl_field_s* tbl_field_t;


int tcb_n;
/*numero dei thread creati*/
int  thread_n;
tcb_t thread_exec;/*Thread attualmente in esecuzione*/
/*liste di thread*/
/*thread appena creati e non schedulati*/
tbl_field_t thread_new;




