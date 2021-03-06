/* Copyright (c) 2016, Michael Zuo. ISC License. */

#include <errno.h>
#include <unistd.h>
#include <sys/procctl.h>
#include <err.h>

int main(int const argc, char **argv) {
	if (argc < 2)
		errx(2, "usage: %s prog...", *argv);

	if (procctl(P_PID, getpid(), PROC_REAP_ACQUIRE, NULL) == -1) {
		if (errno != EBUSY)
			err(1, "procctl");
	}

	execvp(argv[1], argv+1);
	err(1, "%s", argv[1]);
}
