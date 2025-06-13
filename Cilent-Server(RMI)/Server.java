import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

public class Server {
  public static void main(String[] args) {
    try {
      ArithmeticImpl obj = new ArithmeticImpl();
      Registry registry = LocateRegistry.createRegistry(1091);
      registry.rebind("ArithmeticService", obj);
      System.out.println("Server is ready...");
    } catch (Exception e) {
      System.err.println("Server exception: " + e);
    }
  }
}
