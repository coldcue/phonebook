#ifndef DATABASE_H
#define DATABASE_H

#define DBFILE "db.bin"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

/**
The Contact entity structure
*/
typedef struct {
	unsigned id;
	char name[64], number[32], occptn[32], email[256];
} Contact;

/**
A list of contacts
*/
struct ContactList {
	Contact *cntct;
	struct ContactList *next;
};

typedef struct ContactList ContactList;

#include "list.h"

/**
Initialize the database
*/
int db_construct();

/**
Save a Contact to the database
@param cntct A pointer of a Contact
*/
int db_save(Contact *cntct);

/**
Updates a Contact in the database
@param cntct A pointer of a Contact
*/
int db_update(Contact *cntct);

/**
Deletes a Contact in the database
@param cntct A pointer of a Contact
*/
int db_delete(unsigned id);

/**
Gets a Contact from the database
@param id The ID of the Contact
@param cntct A pointer of a Contact
*/
int db_get(unsigned id, Contact *cntct);

/**
Gets a Contact from the database
@param id The ID of the Contact
@return A ContactVector (if the size is 0, there are no Contacts found)
*/
ContactList* db_search(const char * needle);

/**
Destroys the database
*/
void db_destroy();

#endif