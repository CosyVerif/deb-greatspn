#!/bin/bash

PATH=/home/marco/C++/MDWN/src
PATH1=/home/marco/Smart
i=1
j=0



while [ $i -lt 50 ]
do
	j=0	
	while [ $j -lt 10 ];
		do
		$PATH/GDTMC $1 -H
		$PATH1/smart-1.1-linux $1.sm > $1.step
		let j=j+1
	done
	$PATH1/smart-1.1-linux $1.sm > $1.rs$i
	echo "****************"
	echo "Step " $i
	echo "****************"
	let i=i+1
done


