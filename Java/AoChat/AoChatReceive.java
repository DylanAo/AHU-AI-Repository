import java.net.DatagramPacket;
import java.net.DatagramSocket;

public class AoChatReceive implements Runnable{
    DatagramSocket socket = null;
    private int receivePort;

    AoChatMessageArea messageArea;

    public AoChatReceive(int receivePort, AoChatMessageArea messageArea) {
        this.receivePort = receivePort;
        this.messageArea = messageArea;
        try {
            socket = new DatagramSocket(this.receivePort);
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }

    @Override
    public void run() {
        while (true){
            try {
                byte[] container = new byte[1024];
                DatagramPacket packet = new DatagramPacket(container, 0, container.length);
                socket.receive(packet);
                byte[] data = packet.getData();
                String receiveData = new String(data,0, packet.getLength());
                messageArea.messageArea.setText(messageArea.messageArea.getText() +"\n接收:" +packet.getAddress().toString() + ":" + receiveData);
                //System.out.println(packet.getAddress().toString() + ":" + receiveData);
            } catch (Exception e) {
                throw new RuntimeException(e);
            }
        }
    }
}
