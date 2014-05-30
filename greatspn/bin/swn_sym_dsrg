#!/bin/sh 
. great_package.sh

echo ""
echo "Start SWN Dinamic Symbolic Reachability Graph construction"
#time

$GSPN2HOME2/WNDSRG $1 $2

if [ $? -ne 0 ] 
then
	exit 22
fi

if [ "$2" = "-m" ]
then 
$GSPN2HOME2/WNDSRGSOLVER $1 -p
fi

exit 0
