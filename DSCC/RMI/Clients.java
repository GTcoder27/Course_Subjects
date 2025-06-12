import java.rmi.NotBoundException;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.util.Scanner;

public class Clients {
    public static void main(String[] args) {
        try {
            Registry registry = LocateRegistry.getRegistry("localhost", 1099);
            Arithmetic stub = (Arithmetic) registry.lookup("Arithmetic Service");

            // Example Queries
            System.out.println(stub.performOperation("add", 10, 5));
            System.out.println(stub.performOperation("subtract", 15, 3));
            System.out.println(stub.performOperation("multiply", 4, 6));
            System.out.println(stub.performOperation("division",10, 5));
            System.out.println(stub.performOperation("division", 20, 0)); // Division by Zero test

            //User Input
            int a,b;
            System.err.println("Enter the Value of a and b");
            try (Scanner sc = new Scanner(System.in)) {
                a = sc.nextInt();
                b = sc.nextInt();
                System.out.println(stub.performOperation("add", a, b));
                System.out.println(stub.performOperation("subtract", a, b));
                System.out.println(stub.performOperation("multiply", a, b));
                System.out.println(stub.performOperation("division", a, b));
            }

        } catch (NotBoundException | RemoteException e) {
        }
    }
}
