#!/bin/bash
	count=0
	temp1=0
	temp2=0

	for (( j=1; j<=10; j=j+1));
	
	do
		#arquivo executável .x
		./exP.x

		echo "10000 10000"
		
		count=$[count+1] #count para média

		
	done
