<?php
  // start the session
  session_start();

  if (!isset($_SESSION['username'])) {
    $_SESSION['username'] = 'JohnDoe';
    $_SESSION['email'] = 'johndoe@example.com';
    echo "Session variables are set.<br>";
  } else {
    echo "Session already started. Here are the details:<br>";
    echo "Username: " . $_SESSION['username'] . "<br>";
    echo "Email: " . $_SESSION['email'] . "<br>";
  }

  // end the session
  if (isset($_GET['end_session']) && $_GET['end_session'] == 'true') {
    session_unset();
    session_destroy();
    echo "Session has been destroyed and all session variables are cleared.<br>";
  } else {
    echo '<br><a href="?end_session=true">Click here to end the session</a>';
  }
?>
