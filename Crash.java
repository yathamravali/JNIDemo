public class Crash{
  public native void printHello();
  static {
    System.loadLibrary("Crash");
  }
  public static void main(String[] args){
    Crash obj = new Crash();
    obj.printHello();
  }
}

