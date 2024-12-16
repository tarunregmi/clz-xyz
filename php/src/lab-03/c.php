<?php
  echo "<pre>";
  echo "PHP program to print factorial of a number:<br><br>";


  $number = 7;

  function factorial($n) {
    if ($n <= 1) return 1;
    else return ($n * factorial($n - 1));
  }

  echo "Factorial of $number is " . factorial($number) . ".";


  echo "</pre>";
?>
