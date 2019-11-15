#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys.stat.h>
#include <time.h>
#include <string.h>

int main () {
        struct stat s;
        int f = stat ("Makefile", &s);
	if (f < 0) { 
		printf ("Error %d: %s\n", errno, strerror (errno)); 
	}
        printf ("File: Makefile\n\tSize: %d\n", f.st_size);
        printf ("Mode: %o\n", f.st_mode); //in octal numbers
        time_t tim = f.st_atime;
        printf ("Last accessed: %s", ctime (&f.st_atime));
  return 0;
}

