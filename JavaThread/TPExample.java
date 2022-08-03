import java.util.concurrent.*;

public class TPExample {
	public static void main(String[] args) {
		int numTasks = Integer.parseInt(args[0].trim());
		ExecutorService pool = Executors.newCachedThreadPool();
      //ExecutorService pool = Executors.newSingleThreadExecutor();
      //ExecutorService pool = Executors.newFixedThreadPool(numTasks);
		for(int i =0; i < numTasks; i++) {
			pool.execute(new Task());
		}
		pool.shutdown();
	}
}