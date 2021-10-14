public class Car{
 
  //instance variables
  private CarType motor;
  private boolean available;
  private int number;
  
  //keeps track of number of available cars
  private static int population = 0;
  
  //constructor that initializes a new car
  public Car(CarType vehicle){
    motor = vehicle;
    available = true;
    number = 20210001 + population;
    population++;
  }
  
  //returns cartype
  public CarType getType(){
    return motor;
  }
  
  //returns ID number
  public int getInt(){
    return number;
  }
  
  //returns true or false based on car availability
  public boolean isAvailable(){
    return available;
  }
  
  //changes availability to true once car is returned
  public void returnCar(){
    available = true;
  }
  //marks car as unavailable once car is rented
  public void rentCar(){
    available = false;
  }
  
  //returns true if car's ID matches the parameter
  public boolean matches(int num){
    return number == num;
  }
  
  //returns the car's information
  public String toString(){
    if (available)
      return motor + ", " + "ID-" + number + ", " + "Available";
    else
      return motor + ", " + "ID-" + number + ", " + "Rented";
  }
}
