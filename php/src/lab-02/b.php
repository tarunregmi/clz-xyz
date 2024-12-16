<?php
  echo "<pre>";
  echo "PHP program to reverse the string:<br><br>";


  function reverseString($string) {
    $reversed = "";
    $length = strlen($string);

    for ($i = $length - 1; $i >= 0; $i--) {
      $reversed .= $string[$i];
    }

    return $reversed;
  }

  $inputString = "Hello, World!";
  $reversedString = reverseString($inputString);

  echo "Original string: $inputString\n";
  echo "Reversed string: $reversedString";


  echo "</pre>";
?>
