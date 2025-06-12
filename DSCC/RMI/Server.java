import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

public class Server {
    public static void main(String[] args) {
        try {
            ArithmeticImpl obj = new ArithmeticImpl();
            Registry registry = LocateRegistry.createRegistry(1099);
            registry.rebind("Arithmetic Service", obj);
            System.out.println("Server is Ready.");
        } catch (RemoteException e) {
        }
    }
}
