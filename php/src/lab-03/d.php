<?php
  echo "<pre>";
  echo "PHP program to print Fibonacci series with and without using recursion:<br><br>";


  $number = 10;

  // without recursion
  function fibonacciWithoutRecursion($n) {
    $a = 0;
    $b = 1;

    for ($i = 0; $i < $n; $i++) {
      echo $a . ", ";
      $next = $a + $b;
      $a = $b;
      $b = $next;
    }
  }

  // with recursion
  function fibonacci($n) {
    if ($n <= 1) {
      return $n;
    } else {
      return fibonacci($n -1) + fibonacci($n - 2);
    }
  }

  function fibonacciWithRecursion($n) {
    for ($i = 0; $i < $n; $i++) {
      echo fibonacci($i) . ", ";
    }
  }

  echo "Fibonacci series up to $number terms:\n\n";
  echo "Without recursion:\n";
  fibonacciWithoutRecursion($number);
  echo "\n\nWith recursion:\n";
  fibonacciWithRecursion($number);
  


  echo "</pre>";
?>
