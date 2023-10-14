import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class AoChatFrame {
    JPanel rootPanel = new JPanel();  // 新建根窗口

    JFrame frame = new JFrame("AoChat"); // 初始化窗口，并命名
    AoChatMenu menuBar = new AoChatMenu(rootPanel, frame);  // 新建菜单栏


    AoChatEnterTextArea textArea = new AoChatEnterTextArea(rootPanel); // 新建聊天输入框

    AoChatButton buttons = new AoChatButton(rootPanel, textArea);  // 新建按钮组

    AoChatIPText ipText = new AoChatIPText(rootPanel); // 新建IP地址输入框

    AoChatLabel labels = new AoChatLabel(rootPanel);  //新建标签组

    AoChatMessageArea messageArea = new AoChatMessageArea(rootPanel);



    public AoChatFrame(){
        panelInit(); // 窗口初始化
        setPosition();  // 设置每个组件位置
    }

    private void panelInit(){
        // 窗口初始化
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);  // 关闭窗口时关闭进程
        frame.setContentPane(rootPanel);  // 面板给容器里面
        frame.setResizable(false);  // 不准改大小

        frame.setSize(800, 600);  // 设置窗口大小
        frame.setVisible(true); // 显示窗口
    }


    private void setPosition(){
        // 设置每个组件位置
        rootPanel.setLayout(null);// 禁用布局器
        menuBar.setPosition();
        buttons.setPosition();
        textArea.setPosition();
        ipText.setPosition();
        labels.setPosition();
        messageArea.setPosition();
    }
}




class AoChatMenu implements AoChatComponentBasic {

    JFrame frame;
    JMenuBar bar = new JMenuBar();
    JMenu settingMenuBar = new JMenu("设置");


    JMenuItem abut = new JMenuItem("关于AoChat");
    JMenu color = new JMenu("主题");
    JMenuItem exit = new JMenuItem("退出");

    JMenuItem orange = new JMenuItem("橙色");
    JMenuItem lightGray = new JMenuItem("亮灰色");

    JMenuItem gray = new JMenuItem("灰色");

    public AoChatMenu(JPanel panel,JFrame frame){
        this.frame = frame;
        add2Panel(panel);
    }

    @Override
    public void add2Panel(JPanel panel) {
        add2panel(panel);
        addActionListener();
        settingMenuBar.add(abut);
    }

    public void setPosition(){

        bar.setBounds(0,0,800,20);
    }
    void add2panel(JPanel panel){
        panel.add(bar);
        bar.add(settingMenuBar);
        settingMenuBar.add(abut);
        settingMenuBar.add(color);
        settingMenuBar.add(exit);
        color.add(lightGray);
        color.add(gray);
        color.add(orange);


    }
    void addActionListener(){

        abut.addActionListener(new aboutActionListener());
        exit.addActionListener(new exitActionListener());
        orange.addActionListener(new orangeActionListener(frame));
        lightGray.addActionListener(new lightGrayActionListener(frame));
        gray.addActionListener(new grayActionListener(frame));
    }

    class aboutActionListener implements ActionListener{

        @Override
        public void actionPerformed(ActionEvent e) {
            JOptionPane.showMessageDialog(null,"Written by ChenAo\n版本:DEV 0.1","关于AoChat",JOptionPane.OK_OPTION);
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


class AoChatButton implements AoChatComponentBasic {

    JButton sendButton = new JButton("发送");

    JButton newIPButton = new JButton("新建");

    JButton clearButton = new JButton("清空");

    public AoChatButton(JPanel panel, AoChatEnterTextArea enterTextArea){
        add2Panel(panel);
        addActionListener(enterTextArea);
        setPosition();
    }

    public void setPosition(){
        sendButton.setBounds(720, 520, 60, 30);
        newIPButton.setBounds(94,70,60,30);
        clearButton.setBounds(650, 520, 60, 30);
    }

    public void add2Panel(JPanel panel){
        panel.add(sendButton);
        panel.add(newIPButton);
        panel.add(clearButton);
    }

    private void addActionListener(AoChatEnterTextArea enterTextArea){
        sendButtonActionListener(enterTextArea);
    }


    private void sendButtonActionListener(AoChatEnterTextArea enterTextArea){
        sendButton.addActionListener(new sendButtonMenuActionListener(enterTextArea));
        newIPButton.addActionListener(new newIPActionListener());
        clearButton.addActionListener(new clearButtonActionListener(enterTextArea));
    }

    class sendButtonMenuActionListener implements ActionListener{

        AoChatEnterTextArea enterTextArea;

        public sendButtonMenuActionListener(AoChatEnterTextArea enterTextArea) {
            this.enterTextArea = enterTextArea;
        }

        @Override
        public void actionPerformed(ActionEvent e) {

            System.out.println("hi");
        }
    }
    class newIPActionListener implements ActionListener{

        @Override
        public void actionPerformed(ActionEvent e) {
            System.out.println("new");
        }
    }

    class clearButtonActionListener implements ActionListener{
        AoChatEnterTextArea enterTextArea;

        public clearButtonActionListener(AoChatEnterTextArea enterTextArea) {
            this.enterTextArea = enterTextArea;
        }

        @Override
        public void actionPerformed(ActionEvent e) {
            enterTextArea.text.setText("");
        }
    }
}

class AoChatEnterTextArea implements AoChatComponentBasic {

    JTextArea text = new JTextArea();

    AoChatEnterTextArea(JPanel panel){
        add2Panel(panel);
    }

    public void add2Panel(JPanel panel){
        panel.add(text);
    }

    public void setPosition(){
        text.setBounds(180, 400, 600, 100);
    }
}

class AoChatIPText implements AoChatComponentBasic {

    JTextField text = new JTextField();

    AoChatIPText(JPanel panel){

        add2Panel(panel);
    }

    public void add2Panel(JPanel panel){

        panel.add(text);
    }

    public void setPosition(){

        text.setBounds(5, 40, 150, 30);
    }
}

class AoChatLabel implements AoChatComponentBasic {

    JLabel ipLabel = new JLabel("新建与目标IP对话");

    AoChatLabel(JPanel panel){

        add2Panel(panel);
    }

    @Override
    public void add2Panel(JPanel panel) {

        panel.add(ipLabel);
    }

    @Override
    public void setPosition() {

        ipLabel.setBounds(5, 18, 100, 30);
    }
}

class AoChatMessageArea implements AoChatComponentBasic{

    JTextArea messageArea = new JTextArea();

    public AoChatMessageArea(JPanel panel) {
        add2Panel(panel);
    }

    @Override
    public void add2Panel(JPanel panel) {
       panel.add(messageArea);
    }

    @Override
    public void setPosition() {
        messageArea.setBounds(180, 25, 600, 350);
    }
}

