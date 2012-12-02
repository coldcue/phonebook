#ifndef CLIAPI_H
#define CLIAPI_H

#include <stdio.h>
#include "database.h"

void cliapi_printHeader();
void cliapi_waitForCommand(char buf[]);
void cliapi_printContact(Contact * cntct);
Contact * cliapi_askNewDetails();
void cliapi_askModDetails(Contact * cntct);

#endif