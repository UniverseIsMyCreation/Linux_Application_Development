AC_PREREQ([2.69])
AC_INIT([rhasher], [1.0-1.0], [])
AM_INIT_AUTOMAKE([foreign subdir-objects])
AC_CONFIG_SRCDIR([rhasher.c])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CC

# Checks for libraries.
AC_CHECK_HEADER([rhash.h], [], [AC_MSG_ERROR([Unable to find aux rhash.h])])
AC_CHECK_HEADER([stdio.h], [], [AC_MSG_ERROR([Unable to find aux stdio.h])])
AC_CHECK_HEADER([string.h], [], [AC_MSG_ERROR([Unable to find aux string.h])],])
AC_CHECK_HEADER([ctype.h], [], [AC_MSG_ERROR([Unable to find aux ctype.h])])
AC_CHECK_LIB([rhash], [rhash_msg], [], [AC_MSG_ERROR([rhash_msg is needed])])
AC_CHECK_LIB([rhash], [rhash_library_init], [], [AC_MSG_ERROR([rhash_library_init is needed])])
AC_CHECK_LIB([rhash], [rhash_file], [], [AC_MSG_ERROR([rhash_file is needed])])
AC_CHECK_LIB([rhash], [rhash_print_bytes], [], [AC_MSG_ERROR([rhash_print_bytes is needed])])

# Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_SIZE_T

AC_ARG_ENABLE([readline],
	[AS_HELP_STRING([--with-readline], [enable support for readline])],
	[with_readline=yes], []
	)

AS_IF([test "x$with_readline" != xno], [
 	AC_CHECK_HEADERS([readline/readline.h readline/history.h])
 	AC_CHECK_LIB([readline], [readline])])

AC_CONFIG_FILES([Makefile])
AC_OUTPUT