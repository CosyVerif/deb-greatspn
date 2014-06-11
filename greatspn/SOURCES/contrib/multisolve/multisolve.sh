#!/bin/sh
. great_package.sh
#cd $GSPN2HOME/../multisolve
CLASSPATH=${CLASSPATH}$GSPN2HOME2/multisolve:
export CLASSPATH

unset GSPN_NET_DIRECTORY
unset GSPN_PS_DIRECTORY
unset GSPN_EPS_DIRECTORY

GSPN_NET_DIRECTORY=${HOME}

if [ -f $HOME/.greatspn ]
then
. $HOME/.greatspn
fi    
                     
echo ""
echo " Trying to Start MultiSolve"
echo "  (for proper use gnuplot 3.7 or higher is required)"
echo ""

export GSPN2HOME GSPN2HOME2

java MultiSolve "$GSPN_NET_DIRECTORY" "$GSPN2HOME2" &
exit
