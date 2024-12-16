<?php
  echo "<pre>";


  $MYSQL_USER = 'user';
  $MYSQL_PASSWORD = 'password';
  $MYSQL_DATABASE = 'my_database';
  $MYSQL_SERVER = 'db';
  $TABLE = 'customers';

  $DB_CONNECTION = new mysqli($MYSQL_SERVER, $MYSQL_USER, $MYSQL_PASSWORD, $MYSQL_DATABASE);
  if ($DB_CONNECTION->connect_error) die("Database connection failed: " . $DB_CONNECTION->connect_error);

  // Fetch data
  $sql = "SELECT * FROM $TABLE WHERE city = 'Pokhara'";
  $result = $DB_CONNECTION->query($sql);
  if ($result->num_rows > 0) {
    echo "Customers from 'Pokhara' city:<br/>";
    while($row = $result->fetch_assoc()) {
      echo "id: " . $row["id"] . " - Name: " . $row["name"] . " - Email: " . $row["email"] . " - City: " . $row["city"] . "<br/>";
    }
  } else echo "0 results";

  $DB_CONNECTION->close();


  echo "</pre>";
?>
