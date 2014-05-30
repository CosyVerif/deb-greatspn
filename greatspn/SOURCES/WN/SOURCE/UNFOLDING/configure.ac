# AC_INIT (package, version, [bug-report], [tarname])
AC_INIT([SWN unfolder],[0.0d],[Davide Cerotti <dvdc@libero.it>])
# We use automake to build makefiles
AM_INIT_AUTOMAKE([-Wall -Werror foreign])

# programs used to build

#compile in C
# no special flags, this is default behavior
#use bison/flex parsers
AM_PROG_LEX
# force use of yacc instead of bison -y
# AC_PROG_YACC   <- this tests for bison then byacc then yacc
AC_SUBST(YACC,[yacc])

# automake :
# build these Makefile using the Makefile.am files in each directory
AC_CONFIG_FILES([
  Makefile
  src/Makefile
])
# Do it !! (mandatory)
AC_OUTPUT
