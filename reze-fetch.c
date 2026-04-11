#include<stdio.h>
#include <sys/sysctl.h>

int main () {

	printf(" .✦ ݁˖ REZE--FETCH .✦ ݁˖\n");
	printf("\n");
	size_t len_osversion;
	size_t len_hostname;
	
	char *osversion_ptr;
	char *hostname_ptr;
	if (sysctlbyname("kern.osrelease", NULL, &len_osversion, NULL, 0) == 0){
		
		osversion_ptr = malloc(len_osversion);
		if (osversion_ptr != NULL){
			if (sysctlbyname("kern.osrelease", osversion_ptr, &len_osversion, NULL, 0) == -1){ 
				perror("sysctl kern.osrelease");
    				return 1;
			}
		}else{return 1;} 

	}else{return 1;}
	if (sysctlbyname("kern.hostname", NULL, &len_hostname, NULL, 0) == 0){
                
                hostname_ptr = malloc(len_hostname);
                if (hostname_ptr != NULL){
                        if (sysctlbyname("kern.hostname", hostname_ptr, &len_hostname, NULL, 0) == -1){
                                perror("sysctl kern.hostname");
                                return 1;
                        }
                }else{return 1;}
                
        }else{return 1;}
	printf("\tOS: %s\n", osversion_ptr);
	printf("\tHostname: %s\n", hostname_ptr);
	free(osversion_ptr);
	free(hostname_ptr);
	return 0;

}
