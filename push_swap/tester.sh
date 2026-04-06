#!/bin/bash

ITERATIONS=100
LIMIT=500
TOTAL=0
MOVES_FILE="moves.txt"

# Clear previous results
> $MOVES_FILE

echo "Running $ITERATIONS tests for $LIMIT numbers..."

for i in $(seq 1 $ITERATIONS)
do
    # Generate 500 unique random numbers
    ARG=$(shuf -i 0-1000 -n $LIMIT | tr '\n' ' ')
    
    # Run push_swap and count lines
    RESULT=$(./push_swap $ARG | wc -l)
    
    # Check for sort integrity (Optional but recommended)
    CHECK=$(./push_swap $ARG | ./checker_linux $ARG)
    
    if [ "$CHECK" != "OK" ]; then
        echo "Error: Sort failed at iteration $i"
        exit 1
    fi

    echo $RESULT >> $MOVES_FILE
    echo -n "." # Progress bar
done

echo -e "\n\n--- RESULTS ---"

# Sort numbers to find the median
sort -n $MOVES_FILE > sorted_moves.txt
MEDIAN=$(sed -n '50p' sorted_moves.txt)
MAX=$(tail -n 1 sorted_moves.txt)
MIN=$(head -n 1 sorted_moves.txt)

echo "Minimum: $MIN"
echo "Maximum: $MAX"
echo "MEDIAN : $MEDIAN"

# Clean up
rm moves.txt sorted_moves.txt
