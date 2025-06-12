import java.util.Scanner;

public class RingElection {

    static int[] processIds;
    static boolean[] isActive;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Step 1: Input
        System.out.print("Enter number of processes: ");
        int n = scanner.nextInt();

        processIds = new int[n];
        isActive = new boolean[n];

        System.out.println("Enter process IDs: ");
        for (int i = 0; i < n; i++) {
            processIds[i] = scanner.nextInt();
            isActive[i] = true;
        }

        System.out.print("Enter process ID to fail: ");
        int failedId = scanner.nextInt();
        int failedIndex = findProcessIndex(failedId);
        if (failedIndex != -1) {
            isActive[failedIndex] = false;
        }

        System.out.print("Enter process ID to initiate election: ");
        int initiatorId = scanner.nextInt();
        int initiatorIndex = findProcessIndex(initiatorId);

        if (initiatorIndex == -1 || !isActive[initiatorIndex]) {
            System.out.println("Invalid initiator.");
            return;
            
        }

        // Step 2: Start election
        int newCoordinator = startElection(initiatorIndex);
        System.out.println("New coordinator is Process " + newCoordinator);
        
    }

    static int startElection(int initiatorIndex) {
        int n = processIds.length;
        int maxId = processIds[initiatorIndex];
        int current = (initiatorIndex + 1) % n;

        System.out.println("\nElection started by Process " + processIds[initiatorIndex]);

        while (current != initiatorIndex) {
            if (isActive[current]) {
                System.out.println("Process " + processIds[current] + " received election message.");
                if (processIds[current] > maxId) {
                    maxId = processIds[current];
                }
            }
            current = (current + 1) % n;
        }

        return maxId;
    }

    static int findProcessIndex(int id) {
        for (int i = 0; i < processIds.length; i++) {
            if (processIds[i] == id) {
                return i;
            }
        }
        return -1;
    }
}
