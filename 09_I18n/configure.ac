AC_PREREQ([2.69])
AC_INIT([predict_number], [1.0], [ilyagr2012@gmail.com])
AM_INIT_AUTOMAKE([foreign])
AC_CONFIG_SRCDIR([src/predict_number.c])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CC

# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([libintl.h], [], [AC_MSG_ERROR([Unable to find aux libintl.h])])
AC_CHECK_HEADERS([locale.h], [], [AC_MSG_ERROR([Unable to find aux locale.h])])
AC_CHECK_HEADERS([stdlib.h], [], [AC_MSG_ERROR([Unable to find aux stdlib.h])])
AC_CHECK_HEADERS([string.h], [], [AC_MSG_ERROR([Unable to find aux string.h])])
AC_CHECK_HEADERS([stdio.h], [], [AC_MSG_ERROR([Unable to find main stdio.h])])
AC_CHECK_HEADERS([libgen.h], [], [AC_MSG_ERROR([Unable to find main libgen.h])])

# Checks for library functions.
AC_CHECK_FUNCS([setlocale])

#po/Makefile
AC_CONFIG_FILES([Makefile po/Makefile src/Makefile])
AC_OUTPUT
