import java.util.Scanner;

public class BullyAlgorithm {

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

        System.out.print("Enter the process ID to fail: ");
        int failedId = scanner.nextInt();
        int failedIndex = findProcessIndex(failedId);
        if (failedIndex != -1) {
            isActive[failedIndex] = false;
        }

        System.out.print("Enter the process ID to initiate the election: ");
        int initiatorId = scanner.nextInt();
        int initiatorIndex = findProcessIndex(initiatorId);

        if (initiatorIndex == -1 || !isActive[initiatorIndex]) {
            System.out.println("Invalid initiator.");
            return;
        }

        // Step 2: Start Bully election
        int coordinator = startElection(initiatorIndex);
        System.out.println("New coordinator is Process " + coordinator);
    }

    static int startElection(int initiatorIndex) {
        int n = processIds.length;
        int initiatorId = processIds[initiatorIndex];
        boolean higherProcessResponded = false;

        System.out.println("\nElection started by Process " + initiatorId);

        for (int i = 0; i < n; i++) {
            if (i != initiatorIndex && processIds[i] > initiatorId && isActive[i]) {
                System.out.println("Process " + initiatorId + " sends election message to Process " + processIds[i]);
                System.out.println("Process " + processIds[i] + " responds.");
                higherProcessResponded = true;
            }
        }

        if (!higherProcessResponded) {
            // No higher ID active, initiator becomes coordinator
            return processIds[initiatorIndex];
        } else {
            // One of the higher ID processes will start election itself
            int maxActiveId = -1;
            for (int i = 0; i < n; i++) {
                if (isActive[i]) {
                    if (processIds[i] > maxActiveId) {
                        maxActiveId = processIds[i];
                    }
                }
            }
            return maxActiveId;
        }
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
