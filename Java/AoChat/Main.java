public class Main {
    public static void main(String[] args) {
        AoChatFrame frame = new AoChatFrame();// 默认发送端口8889
        new Thread(new AoChatReceive(8888, frame.messageArea)).start();// 默认接收端口8888
    }
}
