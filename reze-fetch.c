#include<stdio.h>
#include <sys/sysctl.h>

int main () {
	char osversion[256];	
	char hostname[256];

	printf(" .✦ ݁˖ REZE--FETCH .✦ ݁˖\n");
	printf("\n");
	size_t len_osversion = sizeof(osversion);
	size_t len_hostname = sizeof(hostname);
	sysctlbyname("kern.osrelease", NULL, &len_osversion, NULL, 0);
	if(sysctlbyname("kern.osrelease", osversion, &len_osversion, NULL, 0) == -1) {
		perror("sysctl kern.osrelease");
    		return 1;	
	}
	sysctlbyname("kern.hostname", NULL, &len_hostname, NULL, 0);
	
	if(sysctlbyname("kern.hostname", hostname, &len_hostname, NULL, 0) == -1) {
		perror("sysctl kern.hostname");
		return 1;
	}	

	printf("\tOS: %s\n", osversion);
	printf("\tHostname: %s\n", hostname);
	return 0;

}
