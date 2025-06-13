import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.util.Scanner;

public class Client {
    public static void main(String[] args) {
        try {
            Registry registry = LocateRegistry.getRegistry("localhost", 1091);
            Arithmetic stub = (Arithmetic) registry.lookup("ArithmeticService");

            Scanner sc = new Scanner(System.in);

            while (true) {
                System.out.print("\nEnter operation (add, subtract, multiply, divide or 'exit' to quit): ");
                String operation = sc.next();

                if (operation.equalsIgnoreCase("exit")) break;

                System.out.print("Enter first number: ");
                double num1 = sc.nextDouble();

                System.out.print("Enter second number: ");
                double num2 = sc.nextDouble();

                String result = stub.performOperation(operation, num1, num2);
                System.out.println(result);
            }

            sc.close();
        } catch (Exception e) {
            System.err.println("Client exception: " + e);
        }
    }
}
