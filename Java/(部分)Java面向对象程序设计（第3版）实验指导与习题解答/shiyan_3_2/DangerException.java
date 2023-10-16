// DangerException.java
public class DangerException extends Exception {
    String message;
    public DangerException(){
        message ="危险品!";
    }
    public void toShow( ){
        System.out.print(message +" ");
    }
}
