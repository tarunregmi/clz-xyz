<?php
  echo "<pre>";
  echo "Example of error handlers to print error:<br><br>";


  // custom error handler function
  function customError($errno, $errstr, $errfile, $errline) {
    echo "<b>Error occurred:</b><br>";
    echo "Error number: $errno<br>";
    echo "Error message: $errstr<br>";
    echo "File: $errfile<br>";
    echo "Line: $errline<br>";
  }
  
  // set the custom error handler
  set_error_handler("customError");
  
  // trigger errors
  echo $undefinedVar;
  $div = 1 / 0;
  nonExistentFunction();


  echo "</pre>";
?>
