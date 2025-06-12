import java.rmi.Remote;
import java.rmi.RemoteException;

public interface Arithmetic extends Remote {
    String performOperation(String operation, double num1, double num2) throws RemoteException;
}
