<?php
  echo "<pre>";
  echo "PHP program to write your information using function:<br><br>";


  function displayName($firstName, $lastName) {
    echo "Name: " . $firstName . " " . $lastName . "\n";
  }

  function displayAge($age) {
    echo "Age: " . $age . "\n";
  }

  function displayAddress($street, $city, $state, $zip) {
    echo "Address: " . $street . ", " . $city . ", " . $state . " " . $zip . "\n";
  }

  function displayPersonInfo($firstName, $lastName, $age, $street, $city, $state, $zip) {
    displayName($firstName, $lastName);
    displayAge($age);
    displayAddress($street, $city, $state, $zip);
  }

  $firstName = "Kush";
  $lastName = "Nepal";
  $age = 22;
  $street = "Araniko Highway";
  $city = "Lokanthali";
  $province = "Bagmati";
  $zip = "44600";

  displayPersonInfo($firstName, $lastName, $age, $street, $city, $province, $zip);


  echo "</pre>";
?>
