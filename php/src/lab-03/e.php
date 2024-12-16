<?php
  echo "<pre>";
  echo "PHP program to show passing argument and returning value in php:<br><br>";


  function calculateArea($width, $height) {
    return $width * $height;
  }

  function getGreeting($name, $age) {
    return "Hello, $name! You are $age years old.";
  }

  $width = 7.5;
  $height = 10;
  $area = calculateArea($width, $height);

  $name = "Alice";
  $age = 30;
  $greeting = getGreeting($name, $age);

  echo "The area of the rectangle is $area square units.\n";
  echo $greeting;



  echo "</pre>";
?>
