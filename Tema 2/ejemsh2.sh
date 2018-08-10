Cont=0
while [ $Cont -le 60 ]
do
    date
    Cont=$(($Cont+1))
    
    echo $Cont
    sleep 1
done