#ifndef CLIAPI_H
#define CLIAPI_H

#include <stdio.h>
#include "database.h"

/** Prints out the header of the Phonebook */
void cliapi_printHeader();
/** Waits for a command */
void cliapi_waitForCommand(char buf[]);
/** Prints out a contact */
void cliapi_printContact(Contact * cntct);
/** Asks details for a new contact */
Contact * cliapi_askNewDetails();
/** Asks modification details for a new contact */
void cliapi_askModDetails(Contact * cntct);

#endif