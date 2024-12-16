<?php
  echo "<pre>";
  echo "Create a class named \"Bird\". Also, create two objects pigeon and crow. Display their colors, habitats and what they eat.:<br><br>";


  class Bird {
    public $color;
    public $habitat;
    public $food;

    public function __construct($color, $habitat, $food) {
      $this->color = $color;
      $this->habitat = $habitat;
      $this->food = $food;
    }

    public function displayDetails() {
      echo "Color: " . $this->color . "<br>";
      echo "Habitat: " . $this->habitat . "<br>";
      echo "Food: " . $this->food . "<br><br>";
    }
  }

  // Create objects for Pigeon and Crow
  $pigeon = new Bird("Gray", "Urban areas, forests", "Seeds, fruits");
  $crow = new Bird("Black", "Forests, urban areas", "Insects, small animals, food scraps");

  // Display the details of Pigeon and Crow
  echo "Pigeon Details:<br>";
  $pigeon->displayDetails();

  echo "Crow Details:<br>";
  $crow->displayDetails();


  echo "</pre>";
?>
