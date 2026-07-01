public class NonTPExample {
	public static void main(String[] args) {
	    int numTasks = 10000;
	    long startTime = System.currentTimeMillis();
        Thread threads[] = new Thread[numTasks];
		for (int i = 0; i < numTasks; i++) {
            //Thread thread = new Thread(new Task("Task " + i));
            threads[i] = new Thread(new Task("Task " + i));
            threads[i].start();
            
        }
        for (int i = 0; i < numTasks; i++) {
            try {
                threads[i].join(); // Wait for the thread to finish
            } catch (InterruptedException e) {
                e.printStackTrace();
            }

        }
		long endTime = System.currentTimeMillis();
        System.out.println("Total execution time without thread pool: " + (endTime - startTime) + " milliseconds");
	}
}