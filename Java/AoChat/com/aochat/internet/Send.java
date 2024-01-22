package com.aochat.internet;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetSocketAddress;

public class Send implements Runnable{

    DatagramSocket socket = null;
    BufferedReader reader = null;

    String str;

    private int sourcePort;
    private String destinationIP = null;
    private int destinationPort;

    public Send(int sourcePort, String destinationIP, int destinationPort, String str) {
        this.sourcePort = sourcePort;
        this.destinationIP = destinationIP;
        this.destinationPort = destinationPort;
        this.str = str;

        try {
            socket = new DatagramSocket(sourcePort);
            reader = new BufferedReader(new InputStreamReader(System.in));
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }

    @Override
    public void run() {
        try {
            String data = str;
            byte[] datas = data.getBytes();
            DatagramPacket packet = new DatagramPacket(datas,datas.length,new InetSocketAddress(destinationIP, destinationPort));
            socket.send(packet);
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
        socket.close();
    }
}

