#include <netdb.h>
#include <arpa/inet.h>
#include "resolver.h"

static int addr_str2bin(char address[], struct sockaddr_storage *sa)
{
    int res;
    struct sockaddr_in *sockaddr_ipv4;
    struct sockaddr_in6 *sockaddr_ipv6;

    sockaddr_ipv4 = (struct sockaddr_in *)sa;
    sockaddr_ipv4->sin_family = AF_INET;

    res = inet_pton(sockaddr_ipv4->sin_family, address,
	&sockaddr_ipv4->sin_addr);

    if (res == 1)
        return 0;

    sockaddr_ipv6 = (struct sockaddr_in6 *)sa;
    sockaddr_ipv6->sin6_family = AF_INET6;

    res = inet_pton(sockaddr_ipv6->sin6_family, address,
	&sockaddr_ipv6->sin6_addr);

    if (res != 1)
        return -1;

    return 0;
}

int resolve_name_by_addr(char address[], char host[])
{
    int res;
    struct sockaddr_storage sa_stor;

    if (addr_str2bin(address, &sa_stor))
        return -1;

    res = getnameinfo((struct sockaddr *)&sa_stor, sizeof(sa_stor), host,
	HOSTNAME_MAX, NULL, 0, 0);

    if (res)
    {
	printf("getnameinfo failed: %s\n", gai_strerror(res));
	return -1;
    }

    return 0;
}
