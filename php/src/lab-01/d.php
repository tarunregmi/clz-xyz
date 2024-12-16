<?php
  echo "<pre>";
  echo "PHP program to check palindrome number:<br><br>";


  $number = 12321;
  $number = (string)$number;
  $numberLen = strlen($number);
  $count = (int)($numberLen / 2);

  for ($i=0; $i<=$count; $i++) {
    if ($number[$i] !== $number[$numberLen - $i -1]) break;
  }

  if (($i-1) !== $count) {
    echo "$number is not palindrome number.";
  } else {
    echo "$number is palindrome number.";
  }


  echo "</pre>";
?>
