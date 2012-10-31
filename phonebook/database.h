#ifndef DATABASE_H
#define DATABASE_H

#define DBFILE "db.bin"
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "main.h"

/* Entity structure */
typedef struct {
	int id;
	char name[64], number[32], occptn[32], email[256];
} Contact;

/* Global db file handler */
FILE* db;

/* Initializing the database api */
int db_construct();
/* Saving a new entity */
int db_save(Contact * cntct);
/* Updating an existing entity */
int db_update(Contact * cntct);
/* Deleting an entity */
int db_delete(Contact * cntct);
/* Getting an entity from the db */
int db_get(int id);
/* Searching for entities */
int db_search(char needle[], Contact *results);
/* Destroying the database api */
void db_destroy();

#endif