<?php
  echo "<pre>";
  echo "PHP program to reverse given number:<br><br>";


  $number = 8972;
  
  function reverseNumber($n) {
    $nStr = (string)$n;

    $reversedStr = strrev($nStr);
    $reversedNum = (int)$reversedStr;

    return $reversedNum;
  }

  echo "Original number: $number\n";
  echo "Reversed number: " . reverseNumber($number);


  echo "</pre>";
?>
