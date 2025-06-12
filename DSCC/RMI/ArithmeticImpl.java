import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;

public class ArithmeticImpl extends UnicastRemoteObject implements Arithmetic {

    protected ArithmeticImpl() throws RemoteException {
        super();
    }

    @Override
    public String performOperation(String operation, double num1, double num2) throws RemoteException {
        double result;

        switch (operation) {
            case "add" -> result = num1 + num2;
            case "subtract" -> result = num1 - num2;
            case "multiply" -> result = num1 * num2;
            case "division" -> {
                if (num2 == 0) {
                    return "Error: Division by Zero";
                }
                result = num1 / num2;
            }
            default -> {
                return "Invalid operation. Use only add, subtract, multiply, or divide.";
            }
        }

        return "Result: " + result;
    }
}

