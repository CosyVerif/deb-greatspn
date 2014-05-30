#
############ GreatSPN2.0 ######################
if ( ! $?GSPN2VERSION ) then
	set path1 = $0;
	set path2 = $path1:h
	set path1 = $path2:h
        setenv GSPN2VERSION $path1/install/version.csh
	unset path1
	unset path2
endif
if ( ! $?GSPNBINS ) then
        setenv GSPNBINS `$GSPN2VERSION`
endif
if ( ! $?GSPNHOME ) then
        source ~/.GreatSPN_$GSPNBINS
endif


echo ""
echo "Start SWN Ordinary Simulation ..."
time $GSPNHOME/2bin/WNSIM $1 $2 $3 $4 $5 $6 $7 $8 $9
if( $status != 0) exit(21)
exit(0)
