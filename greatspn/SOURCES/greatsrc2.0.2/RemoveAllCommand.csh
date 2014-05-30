#!/bin/csh -f

if ($1 != '' ) then
  foreach x ( $1.* )
    echo Removing $x ...
    /bin/rm -f $x
  end
endif
