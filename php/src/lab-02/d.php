<?php
  echo "<pre>";
  echo "PHP program remove specific element by value from an array:<br><br>";


  function removeElementByValue(&$array, $value) {
    foreach($array as $key => $item) {
      if ($item === $value) {
        unset($array[$key]);
      }
    }

    $array = array_values($array);
  }

  $originalArray = [1, 2, 3, 4, 2, 5];
  $valueToRemove = 2;

  removeElementByValue($originalArray, $valueToRemove);

  echo "Array after removing value $valueToRemove: " . implode(", ", $originalArray);


  echo "</pre>";
?>
