class SharedData {
    private int sum;
    public int getSum() {
        return sum;
    }
    public void calculateSum(int num) {
        sum = num * (num+1) /2;
    }
}
class Child extends Thread {
    private SharedData data;
    int num;
    public Child(SharedData data, int num) {
        this.data = data;
        this.num = num;
    }
    public void run() {
        System.out.println("I am calculating");
        data.calculateSum(num);
    }
}
public class Main {
    public static void main(String[] args) {
        int num = Integer.parseInt(args[0]);
        SharedData data = new SharedData();
        Child child = new Child(data, num);
        child.start();
        try {
            child.join();
        }
        catch (InterruptedException ie) {}
        System.out.println(data.getSum());
        System.out.println("Goodbye");
    }
}
