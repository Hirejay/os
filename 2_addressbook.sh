#!/bin/sh

create()
{
echo "\nEnter Address Book Name: "
read fname
if [ ! -e "$fname" ]; then
touch "$fname"
echo  "Address Book Created....\n"
echo  "ID\tNAME\tADD\tMOB_NO\tSALARY" >> "$fname"
else
echo  "Address Book '$fname' already exists.\n"
fi
}
view(){

cat "$fname"

}
insert(){
echo "enter the of id employee"
read eid

echo "enter the of name employee"
read ename

echo "enter the of address employee"
read eadd

echo "enter the of mobile no employee"
read emob

echo "enter the of salary employee"
read esal

echo "$eid\t$ename\t$eadd\t$emob\t$esal" >> "$fname"

}
delete(){

echo  "Enter Employee ID to be Deleted: "
read eid
if grep -qw "$eid" "$fname"; then
grep -wv "$eid" "$fname" > temp
mv temp "$fname"
echo "Record Deleted"
else
echo "Error: Record does not exist!"
fi


}
modify(){
echo  "Enter Employee ID to be Modified: "
read eid
if grep -qw "$eid" "$fname"; then
grep -wv "$eid" "$fname" > temp
mv temp "$fname"
echo  "Enter Modified Record"
echo "enter the of id employee"
read eid

echo "enter the of name employee"
read ename

echo "enter the of address employee"
read eadd

echo "enter the of mobile no employee"
read emob

echo "enter the of salary employee"
read esal

echo "$eid\t$ename\t$eadd\t$emob\t$esal" >> "$fname"
else
echo "Error: Record does not exist!"
fi
}
search(){
echo  "Enter Employee ID to be Searched: "
read eid
if grep -qw "$eid" "$fname"; then
grep -w "$eid" "$fname"
echo "Record Found"
else
echo "Error: Record does not exist!"
fi
}

while true
do

echo "-----Address book-----"
echo "1.create address book"
echo "2.view address book"
echo "3.insert record"
echo "4.delete record"
echo "5.modify record"
echo "6.search reord"
echo "7.exit"
echo "enter your choice : "
read ch


case $ch in

1) create ;;

2) view ;;

3) insert ;;

4) delete ;;

5) modify ;;

6) search ;;

7) exit ;;

*) echo "enter the valid choice " ;;



esac
done
