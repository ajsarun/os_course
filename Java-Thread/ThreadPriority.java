public class ThreadPriority {
    public static void main(String[] args) {
        Thread lowPriorityThread = new Thread(() -> {
            int sum = 0;
            for (int i = 0; i < 1000000; i++) {
                sum += i;
                //System.out.println("Low priority thread: " + i);
            }
            System.out.println("Low priority thread sum: " + sum);
        });
        lowPriorityThread.setPriority(Thread.MIN_PRIORITY);
        lowPriorityThread.start();
        Thread highPriorityThread = new Thread(() -> {
            int sum = 0;
            for (int i = 0; i < 1000000; i++) {
                sum += i;
                //System.out.println("High priority thread: " + i);
            }
            System.out.println("High priority thread sum: " + sum);
        });
        highPriorityThread.setPriority(Thread.MAX_PRIORITY);
        highPriorityThread.start();
        
    }
}
