<?php
  echo "<pre>";
  echo "Example of error suppression:<br><br>";


  // Example
  $dividend = 10;
  $divisor = 0;
  $result = @($dividend / $divisor);

  if ($result === FALSE) echo "Error: Division by zero.<br>";
  else echo "Result: $result";


  echo "</pre>";
?>
