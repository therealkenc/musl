#include "stdio_impl.h"
#include <fcntl.h>
#include <string.h>
#include <errno.h>

#ifndef _WSLTUB
// nevermind
#else
	int close(int fd);
#endif

FILE *fopen(const char *restrict filename, const char *restrict mode)
{
	FILE *f;
	int fd;
	int flags;

	/* Check for valid initial mode character */
	if (!strchr("rwa", *mode)) {
		errno = EINVAL;
		return 0;
	}

	/* Compute the flags to pass to open() */
	flags = __fmodeflags(mode);

	fd = sys_open(filename, flags, 0666);
	if (fd < 0) return 0;
	if (flags & O_CLOEXEC)
#ifndef _WSLTUB
		__syscall(SYS_fcntl, fd, F_SETFD, FD_CLOEXEC);
#else
		fcntl(fd, F_SETFD, FD_CLOEXEC);
#endif
	f = __fdopen(fd, mode);
	if (f) return f;

#ifndef _WSLTUB
	__syscall(SYS_close, fd);
#else
	close(fd);
#endif
	return 0;
}

weak_alias(fopen, fopen64);
