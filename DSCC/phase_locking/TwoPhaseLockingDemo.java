import java.util.*;
import java.util.concurrent.*;

class LockManager {
    private final Map<String, Integer> lockTable = new ConcurrentHashMap<>();
    private final Object lock = new Object();

    public boolean acquireLock(int transactionId, String resource) {
        synchronized (lock) {
            if (!lockTable.containsKey(resource)) {
                lockTable.put(resource, transactionId);
                System.out.println("Transaction " + transactionId + " acquired lock on " + resource);
                return true;
            } else {
                System.out.println("Transaction " + transactionId + " waiting for lock on " + resource);
                return false;
            }
        }
    }

    public void releaseLock(int transactionId, String resource) {
        synchronized (lock) {
            if (lockTable.containsKey(resource) && lockTable.get(resource) == transactionId) {
                lockTable.remove(resource);
                System.out.println("Transaction " + transactionId + " released lock on " + resource);
            }
        }
    }
}

class Transaction implements Runnable {
    private final int id;
    private final LockManager lockManager;
    private final List<String> resources;
    private final List<String> acquiredLocks = new ArrayList<>();
    private boolean shrinking = false;

    public Transaction(int id, LockManager lockManager, List<String> resources) {
        this.id = id;
        this.lockManager = lockManager;
        this.resources = resources;
    }

    @Override
    public void run() {
        // Growing phase
        for (String resource : resources) {
            while (!lockManager.acquireLock(id, resource)) {
                try {
                    Thread.sleep(1000); // wait before retrying
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
            acquiredLocks.add(resource);
            try {
                Thread.sleep(2000); // simulate work
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }

        // Shrinking phase
        shrinking = true;
        for (String resource : acquiredLocks) {
            lockManager.releaseLock(id, resource);
        }
        System.out.println("Transaction " + id + " completed.");
    }
}

public class TwoPhaseLockingDemo {
    public static void main(String[] args) {
        LockManager lockManager = new LockManager();

        // Define transactions and resources
        Transaction t1 = new Transaction(1, lockManager, Arrays.asList("A", "B"));
        Transaction t2 = new Transaction(2, lockManager, Arrays.asList("B", "C"));

        // Start both transactions in parallel
        Thread thread1 = new Thread(t1);
        Thread thread2 = new Thread(t2);

        thread1.start();
        thread2.start();
    }
}
