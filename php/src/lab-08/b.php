<?php
  $jsonFile = 'data.json';

  if (file_exists($jsonFile)) {
    $jsonData = file_get_contents($jsonFile);

    $data = json_decode($jsonData, true);

    if ($data !== null) {
      echo "<table border='1' cellpadding='5' cellspacing='0'>";
      
      echo "<tr>";
      foreach ($data[0] as $key => $value) echo "<th>" . htmlspecialchars($key) . "</th>";
      echo "</tr>";

      foreach ($data as $item) {
        echo "<tr>";
        foreach ($item as $value) echo "<td>" . htmlspecialchars($value) . "</td>";
        echo "</tr>";
      }

      echo "</table>";
    } else echo "Error: Failed to decode JSON.";
  } else echo "Error: JSON file not found.";
?>
