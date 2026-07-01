public class Incrementer extends Thread {
    public Counter obj;
    public Incrementer(Counter c) {
        obj = c;
    }
    @Override
    public void run() {
        try {
            obj.increment();
        } catch (InterruptedException ex) {
            
        }
    }
}
