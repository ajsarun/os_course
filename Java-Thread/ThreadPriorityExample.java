public class ThreadPriorityExample {

    public static void main(String[] args) {
        Thread[] t = new Thread[10];
        for (int i = 0; i < t.length; i++) {
            t[i] = new Thread(new Task("Task " + i));
            t[i].setPriority(i+1);
            
        }
        for (int i = t.length-1; i >= 0; i--) {
            t[i].start();
        }
        /*for (int i = 0; i < t.length; i++) {
            t[i].start();
        }*/
        for (int i = 0; i < t.length; i++) {
            try {
                t[i].join();
            }
            catch (InterruptedException e) { 

            }
        }
        System.out.println("Goodbye");
    }
}

