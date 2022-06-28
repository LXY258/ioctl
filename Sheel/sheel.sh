#!/bin/bash
#filename sheel

sheel() {
	echo $1
	$1
	if [ $? -eq 0 ]
	then
		echo "Success to "$1
	else
		echo "Fail to "$1
		i=1
		while(( $i<=5 ))
		do
			echo "---------------------"
			echo $i" try: "$1
			$1
			if [ $? -eq 0 ]
			then
				echo "Success to "$1
				echo "---------------------"
				break
			else
				echo "Fail to "$1
				echo "---------------------"
				i=`expr $i + 1`
			fi
		done
		if [ $i == 6 ]
		then
			echo "---------------------"
			echo "---------------------" >> log
			echo $1 | tee -a log
			$1 2>&1 | tee -a log
			echo "---------------------" >> log
			echo "Write this to file log"
			exit 0
		fi
	fi
}

echo "#######################"
sheel "touch yuye"
echo "#######################"
sheel "ls"
echo "#######################"
sheel "abcdefg"
echo "#######################"
sheel "touch ysyuye"
echo "#######################"

