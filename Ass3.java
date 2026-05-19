class EvenRunnable implements Runnable {
    public void run() {
        for (int i = 2; i <= 20; i += 2) {
            System.out.println("Even: " + i);
        }
    }
}

class OddThread extends Thread {
    public void run() {
        for (int i = 1; i <= 20; i += 2) {
            System.out.println("Odd: " + i);
        }
    }
}

public class Ass3 {
    public static void main(String[] args) {
        Thread t1 = new Thread(new EvenRunnable());
        OddThread t2 = new OddThread();

        t1.start();
        t2.start();
    }
}