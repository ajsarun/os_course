import java.util.Random;
class Decrementer extends Thread {
	Random rand = new Random();	
	private Counter counter; 	
	public Decrementer(Counter c) {
		counter = c;
	}
	public void run() {
		counter.decrement();
	}
}
