#!/bin/bash
read -p "Enter first Number: " num1
read -p "Enter second Number: " num2

read -p  "Choose operation: 
 1. Addition 
 2. Subtraction  
 3. Multiplication 
 4. Division 
 5. Power 
 " choice


case "$choice" in 
1)
  echo "Result: $(echo "$num1 + $num2" | bc)";;
2) echo "Result: $(echo "$num1 - $num2" | bc)" ;;
3) echo "Result: $(echo "$num1 * $num2" | bc)" ;;
4)
   if [ "$num2" -eq 0 ] ; then
      echo "ERROR Division by zero" 
   else
      echo "Result: $(echo "scale=2; $num1 / $num2" | bc)"
    fi
   ;;

  5)
    echo "Result: $(echo "$num1 ^ $num2" | bc)"
    ;;
  *)
    echo "Invalid choice!"
    ;;
esac