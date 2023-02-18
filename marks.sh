#!/bin/bash

# Ask the user to provide their marks:
echo "Please enter your marks: "
# the user's marks are read into a variable named result.
read result

# The value the user has entered is checked with an if-else statement to see if it is more than 40.
if [ $result -gt 40 ]
then
    # If it is more than 40, echo prints PASS.
    echo "PASS"
else
    # If it is 40 or less, echo prints FAIL.
    echo "FAIL"
fi 
