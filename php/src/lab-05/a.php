<?php
  echo "<pre>";
  echo "PHP program to insert 5 customers record in database:<br><br>";


  $MYSQL_USER = 'user';
  $MYSQL_PASSWORD = 'password';
  $MYSQL_DATABASE = 'my_database';
  $MYSQL_SERVER = 'db';
  $TABLE = 'customers';

  // create and check database connection 
  $DB_CONNECTION = new mysqli($MYSQL_SERVER, $MYSQL_USER, $MYSQL_PASSWORD, $MYSQL_DATABASE);
  if ($DB_CONNECTION->connect_error) die("Database connection failed: " . $DB_CONNECTION->connect_error);
  echo "Database connected successfully!<br>";

  // create table
  $tableCreationQuery = "
    CREATE TABLE IF NOT EXISTS $TABLE (
      id INT AUTO_INCREMENT PRIMARY KEY,
      name VARCHAR(100),
      email VARCHAR(100),
      city VARCHAR(100)
    );
  ";
  if ($DB_CONNECTION->query($tableCreationQuery) === TRUE) echo "Table '$TABLE' is ready.<br>";
  else die("Error creating table: " . $DB_CONNECTION->error);

  // data
  $customerInsertQuery = "
    INSERT INTO $TABLE (name, email, city) VALUES
    ('Khadga Prasad Oli', 'kpo@gmail.com', 'Jhapa'),
    ('Sher Bahadur Deuba', 'sbd@gmail.com', 'Dhangadhi'),
    ('Pushpa Kamal Dahal', 'pkd@gmail.com', 'Pokhara'),
    ('Baburam Bhattarai', 'bb@gmail.com', 'Kathmandu'),
    ('Madhav Kumar Nepal', 'mkn@gmail.com', 'Pokhara')
  ";
  if ($DB_CONNECTION->query($customerInsertQuery) === TRUE) echo "Data inserted successfully";
  else echo "Error: " . $conn->error;

  $DB_CONNECTION->close();


  echo "</pre>";
?>
