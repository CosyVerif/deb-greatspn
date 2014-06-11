#!/bin/sh 

. great_package.sh

echo ""
echo "Start SWN Extended Symbolic Reachability Graph construction"
#time
$GSPN2HOME2/WNESRG $1 $2 
if [ $? -ne 0 ] 
then
	exit 22
fi
if [ "$2" = "-m" ]
then 
$GSPN2HOME2/ESRG_CTMC $1 $3 -d
$GSPN2HOME2/WNESRGSOLVER $1 -p
fi

exit 0
