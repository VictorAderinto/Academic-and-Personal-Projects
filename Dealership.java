public class Dealership{
  
  //instance variable
  private Car[] myCar;
  private String name;
  private int numCars;
  private int actualNumCars;

  public static final int NOT_FOUND = 50;
  
  //returns dealership's name
  public String getName(){
  return name;
}

  //constructor defining a new dealership
public Dealership(String name, int maxCarNum){
  this.name = name;
  numCars = maxCarNum;
  myCar = new Car[maxCarNum];
  actualNumCars = 0;
}

//creates and adds a new car to the list
public void newAcquisition(CarType aCar){
  Car actualCar = new Car(aCar);
  myCar[actualNumCars] = actualCar;
  actualNumCars++;
  aCar.addDealership(this);
}

//returns information about the dealership
public String toString(){
  String s = name + "\n";
  for (int i = 0; i < actualNumCars; i++){
    s = s + myCar[i].toString() + "\n";
  }
  return s;
}

//returns the first car in the array that is of a given type
private Car getAvailable(CarType carType){
  Car similarCarType = null;
  int count = 0;
  while (similarCarType == null){ 
     if (myCar[count].getType().equals(carType) && myCar[count].isAvailable())
         similarCarType = myCar[count];
         count++;
  }
  return similarCarType;
}

//returns the position of the first car in the array that is of a given type
private int findCar(int firstCar){
  int position = NOT_FOUND;
  for (int i = 0; i < actualNumCars; i++){
     if (myCar[i].getInt() == firstCar)
         position = i;
  }
  return position;
}

//finds the first car in the array and marks it as checked out
public int rentType(CarType carName){
  int numAvailableId = 0;
  Car similarCar = getAvailable(carName);
  if (similarCar == null)
    numAvailableId = NOT_FOUND;
  else 
    similarCar.rentCar();
    numAvailableId = similarCar.getInt();
  return numAvailableId;
}

//finds the car that matches the given ID number and marks it as available
public boolean returnCar(int numId){
  int carWithId = findCar(numId);
  myCar[carWithId].returnCar();
  boolean checkAvailability = true;
  
  if (carWithId == NOT_FOUND)
    checkAvailability = false;
  return checkAvailability;
}

//returns the number of available instances of a particular cartype
public int getNumberAvailable(CarType myCar2){
  int numAvailable = 0;
  for (int i = 0; i < actualNumCars; i++){
     if (myCar[i].getType().equals(myCar2) && myCar[i].isAvailable())
         numAvailable++;
  }
  return numAvailable;
}

}

