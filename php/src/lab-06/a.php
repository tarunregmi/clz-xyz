<?php
  // set a cookie
  if(!isset($_COOKIE['username'])) {
    setcookie("username", "JohnDoe", time() + 3600, "/");
    echo "Cookie 'username' is set. <br>";
  } else {
    echo "Cookie 'username' is already set.<br>";
  }

  // display cookie
  if (isset($_COOKIE['username'])) {
    echo "The value of 'username' cookie is: " . $_COOKIE['username'];
  } else {
    echo "Cookie 'username' is not set.";
  }
?>
