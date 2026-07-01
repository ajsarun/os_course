public class Main {
    public static void main (String[] args) throws InterruptedException {
        Counter counter = new Counter(5);
        Incrementer incThread = new Incrementer(counter);
        Decrementer decThread = new Decrementer(counter);
        incThread.start();
        decThread.start();
        incThread.join();
        decThread.join();
        System.out.println(counter.getCount());
    }
}
