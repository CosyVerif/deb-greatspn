#
. great_package.sh
#if ( ! $?GSPN2VERSION ) then
#	set path1 = $0;
#	set path2 = $path1:h
#	set path1 = $path2:h
#        setenv GSPN2VERSION $path1/install/version.csh
#	unset path1
#	unset path2
#endif
#if ( ! $?GSPN2BINS ) then
#        setenv GSPN2BINS `$GSPN2VERSION`
#endif
#if ( ! $?GSPN2HOME2 ) then
#        source ~/.GreatSPN2_$GSPN2BINS
#endif
if ( ! -e $1.grg ) then
    if ( ! -e $1.ecs ) then
	if ( ! -e $1.pin ) then
		${GSPN2HOME2}/2bin/pinvar $1 > /dev/null
	endif
	${GSPN2HOME2}/2bin/struct $1 > /dev/null
    endif
    ${GSPN2HOME2}/2bin/grg_prep $1 > /dev/null
endif
if ( ! -e $1.gmt ) then
    ${GSPN2HOME2}/2bin/gmt_prep $1 > /dev/null
endif
if ( ! -e $1.gst ) then
    ${GSPN2HOME2}/2bin/gst_prep $1 > /dev/null
endif
/bin/rm -f $1.sta $1.mpd
#
# use the following option not to trace the firing instances
${GSPN2HOME2}/simbin2/engine $* | ${GSPN2HOME2}/simbin2/measure $1 &
#
# use the following option to trace the firing instances
# ${GSPN2HOME2}/simbin2/engine $* -r | ${GSPN2HOME2}/simbin2/measure $1 &
exit(0)
