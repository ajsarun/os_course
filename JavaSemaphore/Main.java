public class Main {
	public static void main(String[] args) {
		Counter counter = new Counter(5);
		Incrementer incrementer = new Incrementer(counter);
		Decrementer decrementer = new Decrementer(counter);
		incrementer.start();
		decrementer.start();
		try {
			incrementer.join();
			decrementer.join();
		}
		catch (InterruptedException e) {
		}
		System.out.println("Count = " + counter.getCount());
	}
}
