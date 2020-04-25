#ifndef _RESOLVER_H_
#define _RESOLVER_H_

#include <stdio.h>
#include <netdb.h>

#define HOSTNAME_MAX NI_MAXHOST

int resolve_name_by_addr(char address[], char host[]);

#endif
