echo "enter an number"
read n
fact=1
i=1
while((i<=n))
do 
	fact=$((fact*i))
	((i++))
done
echo "fact=$fact"
