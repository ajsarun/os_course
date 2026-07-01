public class Task implements Runnable {
//public class Task extends Thread {
	private final String taskName;
    
	public Task(String taskName) {
        this.taskName = taskName;
    }
	public void run() {
		System.out.println(Thread.currentThread().getName() + " is executing " + taskName);
        try {
            Thread.sleep(1000); // Simulate work with sleep
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
        }
        System.out.println(Thread.currentThread().getName() + " finished " + taskName);
	}
}