<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Simple Interest Calculator</title>
</head>
<body>
  <h2>Simple Interest Calculator</h2>

  <form method="post" action="">
    <label for="principal">Principal (P): </label>
    <input type="number" name="principal" id="principal" required><br><br>

    <label for="rate">Rate of Interest (R): </label>
    <input type="number" name="rate" id="rate" required><br><br>

    <label for="time">Time (T in years): </label>
    <input type="number" name="time" id="time" required><br><br>

    <input type="submit" name="calculate" value="Calculate Interest"><br><br>

    <label for="simple_interest">Simple Interest (SI): </label>
    <input type="text" name="simple_interest" id="simple_interest" value="<?php 
      if (isset($_POST['calculate'])) {
        $principal = $_POST['principal'];
        $rate = $_POST['rate'];
        $time = $_POST['time'];        
        $simple_interest = ($principal * $rate * $time) / 100;
        echo $simple_interest;
      }
    ?>" readonly><br><br>
  </form>
</body>
</html>
