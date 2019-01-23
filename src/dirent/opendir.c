#define _GNU_SOURCE
#include <dirent.h>
#include <fcntl.h>
#include <stdlib.h>
#include "__dirent.h"
#include "syscall.h"

#ifndef _WSLTUB
// nevermind
#else
	int close(int fd);
#endif

DIR *opendir(const char *name)
{
	int fd;
	DIR *dir;

	if ((fd = open(name, O_RDONLY|O_DIRECTORY|O_CLOEXEC)) < 0)
		return 0;
	if (!(dir = calloc(1, sizeof *dir))) {
#ifndef _WSLTUB
		__syscall(SYS_close, fd);
#else
		close(fd);
#endif
		return 0;
	}
	dir->fd = fd;
	return dir;
}
