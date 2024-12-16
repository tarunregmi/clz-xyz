<?php
  $csvFile = 'data.csv';

  if (file_exists($csvFile)) {
    if (($file = fopen($csvFile, 'r')) !== FALSE) {
      echo "<table border='1'>";
      echo "<tr>";

      $headers = fgetcsv($file, 0, ',', '"', '\\');
      foreach ($headers as $header) echo "<th>" . htmlspecialchars($header) . "</th>";
      echo "</tr>";

      while (($row = fgetcsv($file, 0, ',', '"', '\\')) !== FALSE) {
        echo "<tr>";
        foreach ($row as $column) echo "<td>" . htmlspecialchars($column) . "</td>";
        echo "</tr>";
      }

      echo "</table>";

      fclose($file);
    } else echo "Error: Unable to open the file.";
  } else echo "Error: File not found.";
?>
