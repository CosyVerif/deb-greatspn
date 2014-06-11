#!/bin/sh
. great_package.sh
#PATH=$PATH:$GSPN2HOME
UIDPATH=$GSPN2HOME2/%U
export UIDPATH
export GSPN2HOME
export GSPN2HOME2
echo $GSPN2HOME
echo $GSPN2HOME2

STATUS=0

if [ ! -f $HOME/.greatspn ]
	then
		echo INSTALLING
		$GSPN2HOME2/first
		STATUS=$?
		if [ $STATUS -eq 1 ]
			then
				echo status 1
				exit $STATUS
		elif [ $STATUS -eq 2 ]
			then
				echo 
				exit $STATUS
		elif [ $STATUS -eq 3 ] 
			then
				echo
				exit $STATUS
		elif [ $STATUS -ne 0 ]
			then
				echo ERROR
				exit $STATUS
		fi
	else
		echo NOT INSTALLING
fi


unset GSPN_DEFAULT_PRINTER 
unset GSPN_NET_DIRECTORY 
unset GSPN_PS_DIRECTORY 
unset GSPN_EPS_DIRECTORY 
. $HOME/.greatspn
export GSPN_DEFAULT_PRINTER 
export GSPN_NET_DIRECTORY 
export GSPN_PS_DIRECTORY 
export GSPN_EPS_DIRECTORY 

echo ""
echo "# SETTING GSPN'S ENVIRONMENT VARIABLES TO :"
echo ""
echo GSPN2HOME=$GSPN2HOME 
echo GSPN_DEFAULT_PRINTER=$GSPN_DEFAULT_PRINTER 
echo GSPN_NET_DIRECTORY=$GSPN_NET_DIRECTORY
echo GSPN_EPS_DIRECTORY=$GSPN_EPS_DIRECTORY
echo GSPN_PS_DIRECTORY= $GSPN_PS_DIRECTORY



 
$GSPN2HOME2/GreatSPN2.0.2
exit $STATUS

