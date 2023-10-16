import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;

class MyExtendsJFrame extends JFrame implements ActionListener {
    // 自定义窗口类，
    // 1.继承窗口类，用于设计窗体；
    // 2.实现ActionListener，用于响应按钮点击事件
    // 3.实现Runnable，重写run方法，用于执行接收线程

    JTextField textSend;
    JTextArea textRecv;
    JTextField textIP;
    JTextField textPort;
    JButton buttonSend;

    public MyExtendsJFrame() {
        setTitle("聊天软件");
        setBounds(160, 100, 320, 600);
        setLayout(null);
        init(); // 添加控件的操作封装成一个函数
        setVisible(true);// 放在添加组件后面执行
        setDefaultCloseOperation(EXIT_ON_CLOSE);
    }

    void init() {// 添加的控件

        textSend = new JTextField(20);
        textSend.setBounds(5, 425, 302, 30);
        add(textSend);

        textRecv = new JTextArea();
        textRecv.setBounds(5, 5, 302, 420);
        add(textRecv);

        textIP = new JTextField(20);
        textIP.setBounds(5, 470, 100, 30);
        add(textIP);

        textPort = new JTextField(20);
        textPort.setBounds(115, 470, 100, 30);
        add(textPort);

        buttonSend = new JButton("Send");
        buttonSend.setBounds(225, 470, 80, 30);
        buttonSend.addActionListener(this);// 添加关联
        add(buttonSend);
    }

    public void actionPerformed(ActionEvent e) { // 发送按钮响应
        byte data[] = textSend.getText().getBytes();// 获取发送文本框字符
        try {
            String ipAddress = textIP.getText();
            int port = Integer.parseInt(textPort.getText());
            InetAddress address = InetAddress.getByName(ipAddress);// 设置目的IP地址
            DatagramPacket SendPacket = new DatagramPacket(data, data.length, address, port);
            // 基于上一步的目标地址，创建UDP数据包，目标端口为对应的输入端口号

            DatagramSocket post = new DatagramSocket();// 创建UDP发送对象
            post.send(SendPacket); // 发送数据
        } catch (Exception e1) {
            e1.printStackTrace();
        }
    }

    public void run() { // 接收函数
        byte data[] = new byte[1024];
        try {
            DatagramSocket recv = new DatagramSocket(Integer.parseInt(textPort.getText()));// 创建UDP接收对象
            DatagramPacket pack = new DatagramPacket(data, data.length);// 创建UDP接收数据包

            while (true) {
                recv.receive(pack); // 接收一个数据包
                String s = new String(pack.getData(), 0, pack.getLength()); // 读取数据包
                textRecv.setText(textRecv.getText() + "recv" + s + '\n'); // 显示数据
            }
        } catch (Exception e1) {
            e1.printStackTrace();
        }
    }
}
