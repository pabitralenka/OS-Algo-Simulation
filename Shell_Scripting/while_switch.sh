while read f 
do
	case $f in
		hello)		echo "English" ;;
		howdy)		echo "American" ;;
		"guten tag")	echo "German"  ;;
		*) 			echo "Unknown : $f" ;;
	esac
done < me.txt