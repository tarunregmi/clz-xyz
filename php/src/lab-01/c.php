<?php
  echo "<pre>";
  echo "PHP program to check prime number:<br><br>";


  $number = 67;
  $number = abs($number);

  if ($number < 2) {
    echo "Number must be >= 2";
  } else {
    for ($i=2; $i<$number; $i++) {
      if (($number % $i) === 0) break;
    }
    
    if ($i === $number) {
      echo "$number is prime number.";
    } else {
      echo "$number is not prime number";
    }
  }
  


  echo "</pre>";
?>
