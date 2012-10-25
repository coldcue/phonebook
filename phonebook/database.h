#ifndef DATABASE_H
#define DATABASE_H

#define DBFILE "database.csv"
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Entity structures */
typedef struct {
	int id;
	char *name, *number, *occptn
} Contact;

int db_save(Contact * cntct);
int db_update(Contact * cntct);
int db_delete(Contact * cntct);
int db_get(int id);
int db_search(char needle[], Contact *results);
char* db_convertToCsv(Contact *cntct);

#endif