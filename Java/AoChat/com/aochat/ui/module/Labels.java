package com.aochat.ui.module;

import javax.swing.*;
import java.net.InetAddress;
import java.net.UnknownHostException;

public class Labels implements ComponentBasic {

    InetAddress myIpAddress = null;


    JLabel ipLabel = new JLabel("输入目标与IP端口");
    JLabel myIpLabel = null;
    static JLabel sourceIpLabel = new JLabel("暂无发送目标");

    public Labels(JPanel panel){
        try {
            myIpAddress = InetAddress.getLocalHost();
        } catch (UnknownHostException e) {
            throw new RuntimeException(e);
        }
        myIpLabel = new JLabel("本机IP:"+myIpAddress.getHostAddress());
        add2Panel(panel);
    }

    @Override
    public void add2Panel(JPanel panel) {

        panel.add(ipLabel);
        panel.add(myIpLabel);
        panel.add(sourceIpLabel);
    }

    @Override
    public void setPosition() {

        ipLabel.setBounds(5, 18, 150, 30);
        myIpLabel.setBounds(5,100,150, 30);
        sourceIpLabel.setBounds(5, 120, 180, 30);
    }

    public static void setText(String str){
        sourceIpLabel.setText(str);
    }
}
