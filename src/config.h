/* config.h - generado para mpg123 en Android ARM64 */
#ifndef CONFIG_H
#define CONFIG_H

/* Sistema */
#define HAVE_STDLIB_H 1
#define HAVE_SYS_TYPES_H 1
#define HAVE_SYS_STAT_H 1
#define HAVE_DIRENT_H 1
#define HAVE_STRERROR 1
#define HAVE_STRING_H 1
#define HAVE_INTTYPES_H 1
#define HAVE_STDINT_H 1
#define HAVE_UNISTD_H 1
#define HAVE_SIGNAL_H 1
#define HAVE_STDIO_H 1
#define HAVE_LIMITS_H 1
#define HAVE_FCNTL_H 1
#define HAVE_ERRNO_H 1

/* Funciones */
#define HAVE_STRERROR 1
#define HAVE_ATOLL 1
#define HAVE_MEMMOVE 1
#define HAVE_SETLOCALE 1

/* Large File Support */
#define SIZEOF_OFF_T 8
#define SIZEOF_LONG 8
#define SIZEOF_SIZE_T 8
#define _FILE_OFFSET_BITS 64
#define LFS_LARGEFILE_64 1

/* Decoder settings */
#define REAL_IS_FLOAT 1
#define ACCURATE_ROUNDING 1

/* NEON64 support for ARM64 */
#define OPT_MULTI 1
#define OPT_GENERIC 1
#define OPT_GENERIC_DITHER 1
#define OPT_NEON64 1

/* Assembler alignment directive for clang/gas */
#define ASMALIGN_BALIGN 1

/* Gapless */
#define GAPLESS 1

/* No debug */
/* #undef DEBUG */

/* Network timeouts not supported */
#define NO_NET 1

/* Feature flags */
#define INDEX_SIZE 1000
#define FRAME_INDEX 1

#endif /* CONFIG_H */
