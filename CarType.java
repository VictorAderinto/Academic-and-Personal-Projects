public class CarType{
  
  //instance variables
  private String make; 
  private String model;
  private int yearManufacture;
  private String color;
  private Dealership[] myDealer; //partilly full array of dealerships 
  private int num; //number of items in dealership array
  
  //constructor defining cartype class
  public CarType(String a, String b, int c, String d){
  
    make = a;
    model = b;
    yearManufacture = c;
    color = d;
    myDealer =  new Dealership[10];//defining an array of dealership with size 10
    num = 0; //initiliazing number of items in array as 0
  }
  
  //instance method that aads a dealership to the list and makes sure there are no duplicates
  public void addDealership(Dealership listDealership){
  int count = 0;
  for (int i = 0; i < 10; i++){
    if (myDealer[i] == listDealership)
      count++;
  }
  if (count == 0){
    myDealer[num] = listDealership;
    num++;
  }
  }
  
  //finds available instances of a particular cartype and prints dealerships where its available
  public void findInstances(){
    String s = this + " is available at:" + "\n";
    for (int i = 0; i < num; i++){
    if (myDealer[i].getNumberAvailable(this) > 0)
      s+= myDealer[i].getName() + ": " + myDealer[i].getNumberAvailable(this) + " instance(s)" + "\n";
    else 
      s+= "No instances are currently available." + "\n";
    }
    System.out.print(s);
  }
  
  //prints cartype
  public String toString(){
    return make + ", " + model + ", " + yearManufacture + ", " + color;
  }
  
  //checks if two carTypes are equal
  public boolean equals(CarType car){
    return make.equals(car.make) && model.equals(car.model) && yearManufacture == car.yearManufacture && color.equals(car.color);
  }
  
}
  