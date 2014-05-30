#!/bin/csh -f

foreach x ( $1.* )
if ( $x != $1.net  &&  $x != $1.def ) then
	echo Removing $x ... 
	/bin/rm -f $x
endif
end
