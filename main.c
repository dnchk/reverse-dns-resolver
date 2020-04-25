#include "resolver.h"

static int usage()
{
    printf("Invalid address, type as follows: dns_resolver <ip_addres>\n");
    return 1;
}

int main(int argc, char** argv)
{
    char host[HOSTNAME_MAX];

    if ((!*(argv+1)) || resolve_name_by_addr(*(argv+1), host))
	return usage();

    printf("Host: %s\n", host);

    return 0;
}
