#!/bin/sh

cd test

start=`date +%s%N`
valgrind ./ft_vector > ft_vector.out 2> ft_vector_err.log
end=`date +%s%N`
ft_execution=`expr $end - $start`

start=`date +%s%N`
valgrind ./std_vector > std_vector.out 2> std_vector_err.log
end=`date +%s%N`
std_execution=`expr $end - $start`

diff=`expr $ft_execution / $std_execution`
echo -n "Checking time execution : "
if [[ $diff > 20 ]]
then
	echo -e "\033[1;31mFailed ! The execution is more than $diff times slower.\033[m"
else
	echo -e "\033[1;32mSuccess ! The execution is $diff times slower.\033[m"
fi

echo -n "Checking outfile diff   : "
diff ft_vector.out std_vector.out

if [[ $? == 1 ]]
then
	echo -e "\033[1;31mFailed ! ft_vector.out and std_vector.out are different.\033[m"
else
	echo -e "\033[1;32mSuccess !\033[m"
fi
