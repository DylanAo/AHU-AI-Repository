package com.aochat.ui.module;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.LinkedHashSet;

public class Menu implements ComponentBasic {
    JFrame frame;

    int ipHistorySetSize = 0;

    public LinkedHashSet<String> ipHistorySet = new LinkedHashSet<>();
    JMenuBar bar = new JMenuBar();
    JMenu settingMenuBar = new JMenu("设置");
    JMenu ipHistoryMenuBar = new JMenu("切换历史聊天对象");

    JMenuItem about = new JMenuItem("关于AoChat");
    JMenu color = new JMenu("主题");
    JMenuItem exit = new JMenuItem("退出");

    JMenuItem orange = new JMenuItem("橙色");
    JMenuItem lightGray = new JMenuItem("亮灰色");

    JMenuItem gray = new JMenuItem("灰色");

    public Menu(JPanel panel,JFrame frame){
        this.frame = frame;
        //ipHistorySet.add("无历史对话记录");
        add2Panel(panel);

    }

    @Override
    public void add2Panel(JPanel panel) {
        add2panel(panel);
    }

    public void setPosition(){

        bar.setBounds(0,0,800,20);
    }
    void add2panel(JPanel panel){
        panel.add(bar);
        bar.add(settingMenuBar);
        bar.add(ipHistoryMenuBar);
        settingMenuBar.add(about);
        settingMenuBar.add(about);
        settingMenuBar.add(color);
        settingMenuBar.add(exit);
        color.add(lightGray);
        color.add(gray);
        color.add(orange);
        ipHistoryMenuBar.add(new JMenuItem("无历史对话记录"));
    }


    public void refreshIpHistoryMenu(){
        if (ipHistorySet.size() != ipHistorySetSize){
            if (ipHistorySetSize == 0){
                ipHistoryMenuBar.remove(0);
            }
            String[] ipHistoryArr = new String[ipHistorySet.size()];
            ipHistorySet.toArray(ipHistoryArr);
            String currentIp = ipHistoryArr[ipHistorySetSize];
            JMenuItem newIpItem = new JMenuItem(currentIp);
            newIpItem.addActionListener(new ActionListener() {
                @Override
                public void actionPerformed(ActionEvent e) {
                    Buttons.setIpAndPort(currentIp);
                    JOptionPane.showMessageDialog(null,"已切换至" + currentIp,"提示",JOptionPane.PLAIN_MESSAGE);
                    Labels.setText("发送至:" + currentIp);
                }
            });
            ipHistoryMenuBar.add(newIpItem);
            ipHistorySetSize ++;
        }

    }
    public void addActionListener(){
        about.addActionListener(new aboutActionListener());
        exit.addActionListener(new exitActionListener());
        orange.addActionListener(new orangeActionListener(frame));
        lightGray.addActionListener(new lightGrayActionListener(frame));
        gray.addActionListener(new grayActionListener(frame));
    }

    class aboutActionListener implements ActionListener {

        @Override
        public void actionPerformed(ActionEvent e) {
            ImageIcon icon = new ImageIcon("src/img/icon.png");
            JOptionPane.showMessageDialog(null,"作者:陈傲\n版本:V 1.0","关于AoChat",JOptionPane.OK_OPTION, icon);
        }
    }
    class exitActionListener implements ActionListener{

        @Override
        public void actionPerformed(ActionEvent e) {
            System.exit(0);
        }
    }

    class orangeActionListener implements ActionListener{
        JFrame frame;

        orangeActionListener(JFrame frame){
            this.frame = frame;
        }
        @Override
        public void actionPerformed(ActionEvent e) {
            frame.getContentPane().setBackground(Color.ORANGE);
        }
    }

    class lightGrayActionListener implements ActionListener{
        JFrame frame;

        lightGrayActionListener(JFrame frame){
            this.frame = frame;
        }
        @Override
        public void actionPerformed(ActionEvent e) {
            frame.getContentPane().setBackground(Color.lightGray);
        }
    }

    class grayActionListener implements ActionListener{
        JFrame frame;

        grayActionListener(JFrame frame){
            this.frame = frame;
        }
        @Override
        public void actionPerformed(ActionEvent e) {
            frame.getContentPane().setBackground(Color.gray);
        }
    }
}
