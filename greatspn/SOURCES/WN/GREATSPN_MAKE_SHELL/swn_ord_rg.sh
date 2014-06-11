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
echo "Start SWN Ordinary Reachability Graph construction"
time $GSPNHOME/2bin/WNRG $1 $2 -mc
if( $status != 0) exit(23)

/bin/cat /dev/null >  $1.gst
$GSPNHOME/2bin/swn_stndrd $1
if( $status != 0) exit(24)
$GSPNHOME/2bin/swn_ggsc $1 -e0.000001 -i10000
if( $status != 0) exit(25)
/bin/cp $1.epd $1.mpd
if( $status != 0) exit(31)
$GSPNHOME/2bin/swn_gst_prep $1
if( $status != 0) exit(27)
$GSPNHOME/2bin/swn_gst_stndrd $1 > $1.temp
if( $status != 0) exit(26)
/bin/cat $1.trash $1.sta > $1.temp
if( $status != 0) exit(32)
/bin/mv $1.temp $1.sta
if( $status != 0) exit(33)
/bin/rm $1.trash
if( $status != 0) exit(30)
exit(0)
