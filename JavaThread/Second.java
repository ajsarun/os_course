
 //Second.java
 
 
public class Second
{
   public static void main(String args[]) {
      Runnable runner = new Worker2();
      
      Thread thrd = new Thread(runner);
      
      thrd.start();

	System.out.println("I Am The Main Thread");
   }
}
