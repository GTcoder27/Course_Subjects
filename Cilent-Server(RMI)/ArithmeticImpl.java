import java.rmi.server.UnicastRemoteObject;
import java.rmi.RemoteException;

public class ArithmeticImpl extends UnicastRemoteObject implements Arithmetic {

    protected ArithmeticImpl() throws RemoteException {
        super();
    }

    public String performOperation(String operation, double num1, double num2) throws RemoteException {
        double result;
        switch (operation.toLowerCase()) {
            case "add":
                result = num1 + num2;
                break;
            case "subtract":
                result = num1 - num2;
                break;
            case "multiply":
                result = num1 * num2;
                break;
            case "divide":
                if (num2 == 0) return "Error: Division by zero";
                result = num1 / num2;
                break;
            default:
                return "Error: Invalid operation";
        }
        return "Result: " + result;
    }
}
