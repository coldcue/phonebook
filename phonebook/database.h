#ifndef DATABASE_H
#define DATABASE_H

#define DBFILE "db.bin"
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Entity structures */
typedef struct {
	int id;
	char name[64], number[32], occptn[32];
} Contact;

FILE* db;

int db_construct();
int db_save(Contact * cntct);
int db_update(Contact * cntct);
int db_delete(Contact * cntct);
int db_get(int id);
int db_search(char needle[], Contact *results);
void db_destroy();

#endif