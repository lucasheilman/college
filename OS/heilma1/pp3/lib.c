/* library source for new system calls */

#define _GNU_SOURCE
#include <unistd.h>
#include <sys/syscall.h>
#include <stdio.h>
#include <sys/types.h>

extern int errno;

#define __NR_dub2		 63
#define __NR_lh_mycall           385
#define __NR_lh_putval           386
#define __NR_lh_getval           387

int dub2(int fd, int fd2) {
  return syscall(__NR_dub2, fd, fd2);
}

int lh_mycall(){
  return syscall(__NR_lh_mycall);
}

int lh_putval(int val){
  return syscall(__NR_lh_putval, val);
}

int lh_getval(){
  return syscall(__NR_lh_getval);
}

/* The following would appear in the caller's program...

main()
{
  dub2(1, 5);
}


*/
