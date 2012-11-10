#ifndef CLIAPI_H
#define CLIAPI_H

#include <stdio.h>
#include "database.h"

void cliapi_printHeader();
char * cliapi_waitForCommand();
void cliapi_printContact(Contact * cntct);

#endif