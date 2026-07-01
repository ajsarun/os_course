import java.util.concurrent.*;

public class TPExample {
	public static void main(String[] args) {
		int numTasks = 10000;
		long startTime = System.currentTimeMillis();
		ExecutorService pool = Executors.newCachedThreadPool();
    	//ExecutorService pool = Executors.newSingleThreadExecutor();
      	//ExecutorService pool = Executors.newFixedThreadPool(numTasks);
	  	//ExecutorService pool = Executors.newFixedThreadPool(5000);
	  	
		for(int i =0; i < numTasks; i++) {
			pool.execute(new Task("Task " + i));
		}
		pool.shutdown();
		try {
			//this main thread wait for all tasks to finish or
			// 1 minute timeout
            if (!pool.awaitTermination(60, TimeUnit.SECONDS)) {
                pool.shutdownNow(); //force shutdown if not finish in time
            }
        } catch (InterruptedException e) {
            pool.shutdownNow();
        }
		long endTime = System.currentTimeMillis();
        System.out.println("Total execution time with thread pool: " + (endTime - startTime) + " milliseconds");
	}
}