
import java.util.Random;

public class Counter {
    private int count;
    public Counter(int val) {
        count = val;
    }
    public synchronized void increment()throws InterruptedException {
        
        int temp = count;
        Random rand = new Random();
        int num = rand.nextInt(5);
        Thread.sleep(num*1000);
        temp++; 
        count = temp;  
        
    }
    public synchronized void decrement() throws InterruptedException{
        int temp = count;
        Random rand = new Random();
        int num = rand.nextInt(5);
        Thread.sleep(num*1000);
         temp--;
         count = temp;
        
                
    }
    public int getCount() {
        return count;
    }
}
