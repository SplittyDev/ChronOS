#ifndef _SYS_STAT_H
#define _SYS_STAT_H 1

#include <sys/types.h>

#ifdef __cplusplus
extern "C" {
#endif

struct stat {
  mode_t st_mode;
};

#define	__S_IFMT	0170000	/* These bits determine file type.  */

/* File types.  */
#define	__S_IFDIR	0040000	/* Directory.  */
#define	__S_IFCHR	0020000	/* Character device.  */
#define	__S_IFBLK	0060000	/* Block device.  */
#define	__S_IFREG	0100000	/* Regular file.  */
#define	__S_IFIFO	0010000	/* FIFO.  */
#define	__S_IFLNK	0120000	/* Symbolic link.  */
#define	__S_IFSOCK	0140000	/* Socket.  */

#define	__S_ISTYPE(mode, mask)	(((mode) & __S_IFMT) == (mask))

#define	S_ISDIR(mode)	 __S_ISTYPE((mode), __S_IFDIR)
#define	S_ISCHR(mode)	 __S_ISTYPE((mode), __S_IFCHR)
#define	S_ISBLK(mode)	 __S_ISTYPE((mode), __S_IFBLK)
#define	S_ISREG(mode)	 __S_ISTYPE((mode), __S_IFREG)
#define S_ISFIFO(mode)	 __S_ISTYPE((mode), __S_IFIFO)
#define S_ISLNK(mode)	 __S_ISTYPE((mode), __S_IFLNK)

int stat (const char *__restrict path, struct stat *__restrict buf);

#ifdef __cplusplus
}
#endif

#endif
