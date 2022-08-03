
class Incrementer extends Thread {
	private Counter counter; 	
	public Incrementer(Counter c) {
		counter = c;
	}
	public void run() {
		counter.increment();
	}
}
