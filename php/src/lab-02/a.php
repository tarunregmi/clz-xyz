<?php
  echo "<pre>";
  echo "PHP program to check Armstrong number:<br><br>";


  $number = 153;

  function isArmstrong($n) {
    global $number;
    $sum = 0;

    while($n > 0) {
      $digit = $n % 10;
      $sum += ($digit * $digit * $digit);
      $n = (int)($n / 10);
    }

    if ($number !== $sum) {
      echo "$number is not a Armstrong number.";
    } else {
      echo "$number is a Armstrong number.";
    }
  }

  isArmstrong($number);
  echo "<br>";
  $number = 370;
  isArmstrong($number);
  echo "<br>";
  $number = 120;
  isArmstrong($number);


  echo "</pre>";
?>
