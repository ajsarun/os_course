//public class Task implements Runnable {
public class Task extends Thread {
	public void run() {
		System.out.println("I am working on task");
	}
}