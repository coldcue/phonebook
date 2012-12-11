#ifndef DATABASE_H
#define DATABASE_H

/** The name of the database file */
#define DBFILE "db.bin"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

/**
The Contact structure
*/
typedef struct {
	/** The unique ID of the Contact */
	unsigned id;
	/** The name of the person */
	char name[64];
	/** The phone number of the person */
	char number[32];
	/** The occupation of the person */
	char occptn[32];
	/** The e-mail of the person */
	char email[256];
} Contact;

/**
A list for contacts
*/
typedef struct ContactList {
	Contact *cntct;
	struct ContactList *next;
} ContactList;

#include "list.h"

/**
Initialize the database file by creating a new one, if it's not found.
*/
int db_construct();

/**
Saves a Contact to end of the database file.
*/
int db_save(Contact *cntct);

/**
Updates a Contact in the database by replacing the old Contact in the file.
*/
int db_update(Contact *cntct);

/**
Deletes a Contact in the database by creating a new file where the
specified contact will be omitted, then replace the old file with the new.
*/
int db_delete(unsigned id);

/**
Gets a Contact from the database. It starts a binary searching by the ID, 
and if it found, the Contact will be read from that position. Very fast.
*/
int db_get(unsigned id, Contact *cntct);

/**
Searches the entire database for the given phrase. It's slow, but works well.
*/
ContactList* db_search(const char * needle);

#endif