<?php
  echo "<pre>";
  echo "PHP program to print sum of digits:<br><br>";


  $number = 437;
  $digits = abs($number);
  $sum = 0;

  echo "Number: $number<br>";
  while ($digits > 0) {
    $reminder = $digits % 10;
    $sum += $reminder;
    $digits = (int)($digits / 10);
  }
  echo "Sum of digits: $sum";


  echo "</pre>";
?>
