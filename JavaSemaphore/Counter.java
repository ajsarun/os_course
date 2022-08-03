import java.util.concurrent.Semaphore;
import java.util.Random;
public class Counter {
	private int count = 0;
   private Semaphore sem;
   public Counter() {
      this(0);
   }
   public Counter(int val) {
      count = val;
      sem = new Semaphore(1);
   }
	public int increment() {
      Random rand = new Random();
		int temp = 0;
		try {		
			sem.acquire();
			temp = count;
			temp++;
			Thread.sleep(rand.nextInt(3000));
		}
		catch(InterruptedException e) {
		}
		count = temp;
		sem.release();
		return count;
	}
	public int decrement() {
		Random rand = new Random();
		int temp = 0;
		try {		
			sem.acquire();
			temp = count;
			temp--;
			Thread.sleep(rand.nextInt(3000));
		}
		catch(InterruptedException e) {
		}
		count = temp;
		sem.release();
		return count;
	}
	public int getCount() {
		return count;	
	}
}