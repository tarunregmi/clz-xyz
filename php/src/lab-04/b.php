<?php
  echo "<pre>";
  echo "PHP program to give an example of parameterized constructor in PHP.:<br><br>";


  class Car {
    public $make;
    public $model;
    public $year;

    public function __construct($make, $model, $year) {
      $this->make = $make;
      $this->model = $model;
      $this->year = $year;
    }

    public function displayDetails() {
      echo "Car Make: " . $this->make . "<br>";
      echo "Car Model: " . $this->model . "<br>";
      echo "Car Year: " . $this->year . "<br>";
    }
  }

  $car1 = new Car("Toyota", "Corolla", 2020);
  $car1->displayDetails();


  echo "</pre>";
?>
