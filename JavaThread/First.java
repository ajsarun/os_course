
// First.java 

class Worker1 extends Thread
{
   public void run() {
      System.out.println("I Am a Worker Thread");
   }
}

public class First
{
   public static void main(String args[]) {
      Worker1 runner = new Worker1();
      
      runner.start();

	System.out.println("I Am The Main Thread");
   }
}



