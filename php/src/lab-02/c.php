<?php
  echo "<pre>";
  echo "PHP program to count the words in the string:<br><br>";


  function countWords($string) {
    $words = explode(' ', trim($string));

    $words = array_filter($words, function($word) {
      return !empty($word);
    });

    return count($words);
  }

  $inputString = "Hello, world! This is a test string.";
  $wordCount = countWords($inputString);

  echo "Original string: $inputString\n";
  echo "The number of words in the string is: $wordCount";


  echo "</pre>";
?>
