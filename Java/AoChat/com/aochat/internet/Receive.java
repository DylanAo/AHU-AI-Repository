package com.aochat.internet;

import com.aochat.ui.module.MessageArea;
import java.net.DatagramPacket;
import java.net.DatagramSocket;

public class Receive implements Runnable{
    DatagramSocket socket = null;
    private int receivePort;

    MessageArea messageArea;

    String sourceIP = null;

    public Receive(int receivePort, MessageArea messageArea) {
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
                sourceIP = packet.getAddress().toString().split("/")[1];
                String receiveData = new String(data,0, packet.getLength());
                messageArea.message.setText(messageArea.message.getText() +"\n接收来自于" + sourceIP + "的消息:" + receiveData);
            } catch (Exception e) {
                throw new RuntimeException(e);
            }
        }
    }
}
