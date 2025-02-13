#! /bin/bash

worker_age=25
child=16

#applying conditionals in shell
if [ $worker_age -le $child ]
then
     echo "Not eligible to work in the factory"
else
     echo "Is appropriate age for factory work"
fi
