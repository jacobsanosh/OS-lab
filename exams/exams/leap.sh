echo "enter the year"
read year
if(($year%4==0))
then
	if(($year%100==0))
	then
		if(($year%400==0))
		then
			echo "leap year"
		else
			echo "not an leap year"
		fi
	else
		echo "leap year"
	fi
else
	echo "not an leap year"
fi
