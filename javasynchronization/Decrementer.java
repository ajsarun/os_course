public class Decrementer extends Thread {
    public Counter obj;
    public Decrementer(Counter c) {
        obj = c;
    }
    @Override
    public void run() {
        try {
            obj.decrement();
        } catch (InterruptedException ex) {
            
        }
    }
}
