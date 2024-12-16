<?php
  echo "<pre>";
  echo "PHP program find cube of given number using function:<br><br>";


  $number = 'a';

  function cube($n) {
    if (!is_numeric($n)) {
      throw new InvalidArgumentException("The input must be a number.");
    }

    return $n * $n * $n;
  }

  try {
    echo "The cube of $number is " . cube($number);
  } catch (InvalidArgumentException $err) {
    echo "Error: " . $err->getMessage();
  }


  echo "</pre>";
?>
