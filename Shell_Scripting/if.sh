echo "Value"
read x
if ["${x}" -gt "0"]; then
	echo "$x is greater than zero"
else
	echo "$x is lesser than zero"
fi