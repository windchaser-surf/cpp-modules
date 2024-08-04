#!/bin/bash

numbers=33
for x in $(seq 1 $numbers); do
    comparisons_sum=0
    worst_case=0
    best_case=1000000
    iterations=100
    for i in $(seq 1 $iterations); do
        output_number=$(./PmergeMe `shuf -i 1-100000 -n $x | tr "\n" " "`)
        if ((output_number < best_case)); then
            best_case=($output_number)
        fi
        if ((output_number > worst_case)); then
            worst_case=($output_number)
        fi
        # echo "round $i: $output_number"
        comparisons_sum=$((comparisons_sum + output_number))
        # echo "comparisons_sum: $comparisons_sum"
    done
    echo "|-----------------------|"
    echo "| Der ultimative Tester |"
    echo "|-----------------------|"
    echo " > numbers: $x"
    echo " > iterations: $iterations"
    echo "$(tput setaf 1) > worst_case: $worst_case$(tput sgr0)"
    echo " > best_case: $best_case"
    echo " > average: $((comparisons_sum / iterations))"
    echo "|-----------------------|"
done