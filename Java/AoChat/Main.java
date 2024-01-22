import com.aochat.internet.Receive;
import com.aochat.ui.Frame;

public class Main {
    public static void main(String[] args) {
        Frame frame = new Frame();
        new Thread(new Receive(8888, frame.messageArea)).start();// 默认接收端口8888
    }
}
