#!/bin/sh
. great_package.sh
$GSPN2HOME2/swn-translator $1
if [ $? -ne 0 ]
then
	rm -f $1_unf.*
	exit 5
fi
