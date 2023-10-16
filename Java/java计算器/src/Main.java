import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;//事件监视器，检测按钮点击
import java.awt.event.ActionListener;//监视器，检测按钮点击

public class Main {
    public static void main(String[] args) {
        JS win=new JS();
    }
}
class JS extends JFrame implements ActionListener{
    private StringBuilder sBuilder = new StringBuilder();  //利用StringBuilder类来显示，以及区分两个操作数
    JTextArea text=new JTextArea();//文本框
    double a,b;//将输入运算符前的数据作为第一个操作数a,将输入运算符后的数据作为第二个操作数b
    Double sum;
    int i;//用i记录运算符类型以便进行运算
    public JS()
    {
        setBounds(100,100,400,400);//设定计算器窗口大小
        setTitle("计算器");//设定窗口标签
        JPanel p1=new JPanel();//创建面板p1,p1是显示窗口，用于显示输入的数字、符号以及运算结果
        JPanel p2=new JPanel();//创建面板p2,p2是按钮面板，用于显示可输入的数组、运算符和运算按钮
        text.setPreferredSize(new Dimension (370,60));//设置显示窗口大小(height设置为60)
        p1.add(text);//将text窗口放入p1中
        this.add(p1,BorderLayout.NORTH);

        {
            p2.setLayout(new GridLayout(5, 4));//将p2分割成5*4的20个部分
            JButton button[] = new JButton[20];//创建20个按钮
            button[0] = new JButton("C");//清空
            button[1] = new JButton("CE");//清除之前输入的一个数据
            button[2] = new JButton("%");//取余
            button[3] = new JButton("÷");//除法
            button[4] = new JButton("7");//7
            button[5] = new JButton("8");//8
            button[6] = new JButton("9");//9
            button[7] = new JButton("x");//乘号
            button[8] = new JButton("4");//4
            button[9] = new JButton("5");//5
            button[10] = new JButton("6");//6
            button[11] = new JButton("—");//减号
            button[12] = new JButton("1");//1
            button[13] = new JButton("2");//2
            button[14] = new JButton("3");//3
            button[15] = new JButton("+");//加号
            button[16] = new JButton("^");//乘方
            button[17] = new JButton("0");//0
            button[18] = new JButton(".");//小数点
            button[19] = new JButton("=");//等于

            for (int i = 0; i < button.length; i++)//将按钮放入p2中
                p2.add(button[i]);
            add(p2, BorderLayout.CENTER);

            for (int i = 0; i < button.length; i++)    //为每一个事件(按钮)添加监视器
                button[i].addActionListener(this);
            this.setVisible(true);//让窗口可见，若删除此段代码，运行时不会显示窗口
            this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); //点击X号可以关闭程序
        }//创建按钮
    }

    public void actionPerformed(ActionEvent e) //事件处理
    {
        String lab=e.getActionCommand();//按下按钮时选定当前按钮的字符

        if(lab.equals("0"))//处理按钮 0~9
        {
            sBuilder.append("0");//利用StringBuilder类的对象调用方法，将数据存起来
            text.setText(sBuilder.toString());//显示之前所有输入的数据
        }
        else if(lab.equals("1"))
        {
            sBuilder.append("1");
            text.setText(sBuilder.toString());
        }
        else if(lab.equals("2"))
        {
            sBuilder.append("2");
            text.setText(sBuilder.toString());
        }
        else if(lab.equals("3"))
        {
            sBuilder.append("3");
            text.setText(sBuilder.toString());
        }
        else if(lab.equals("4"))
        {
            sBuilder.append("4");
            text.setText(sBuilder.toString());
        }
        else if(lab.equals("5"))
        {
            sBuilder.append("5");
            text.setText(sBuilder.toString());
        }
        else if(lab.equals("6"))
        {
            sBuilder.append("6");
            text.setText(sBuilder.toString());
        }
        else if(lab.equals("7"))
        {
            sBuilder.append("7");
            text.setText(sBuilder.toString());
        }

        else if(lab.equals("8"))
        {
            sBuilder.append("8");
            text.setText(sBuilder.toString());
        }
        else if(lab.equals("9"))
        {
            sBuilder.append("9");
            text.setText(sBuilder.toString());
        }

        else if(lab.equals("CE"))//处理"CE"按钮事件   即清除当前的输入的数据
        {
            sBuilder.deleteCharAt(sBuilder.length() - 1);//StringBuilder的实例化对象调用方法下标减1即可
            text.setText(sBuilder.toString());
        }
        else if(lab.equals("C")) //处理"CE"按钮事件   即清除之前的输入所有的数据
        {
            sBuilder = new StringBuilder();//重新创建即可清除之前的输入所有的数据
            text.setText(sBuilder.toString());
        }
        else if(lab.equals("."))// 处理按钮 "." 事件
        {
            sBuilder.append(".");//利用StringBuilder类的对象调用方法，将数据存起来
            text.setText(sBuilder.toString());//显示之前输入的数据
        }

        else if(lab.equals("+"))//处理+"按钮乘法
        {
            a = Double.parseDouble(sBuilder.toString());//将输入运算符前的数据作为第一个操作数a
            i=0;
            sBuilder = new StringBuilder();//将数组清空
            text.setText("+");
        }
        else if(lab.equals("—"))//处理"—"按钮乘法
        {
            a = Double.parseDouble(sBuilder.toString());//将输入运算符前的数据作为第一个操作数a
            i=1;//标记运算类型  即"÷"之前的数据即将作为因数
            sBuilder = new StringBuilder();//将数组清空来存储第二个操作数 b
            text.setText("—");
        }
        else if(lab.equals("x"))//处理"x"按钮乘法
        {
            a = Double.parseDouble(sBuilder.toString());//将输入运算符前的数据作为第一个操作数a
            i=2;//标记运算类型  即"÷"之前的数据即将作为因数
            sBuilder = new StringBuilder();//将数组清空来存储第二个操作数 b
            text.setText("x");
        }
        else if(lab.equals("÷"))//处理"÷"按钮事件
        {
            a = Double.parseDouble(sBuilder.toString());//将输入运算符前的数据作为第一个操作数a
            i=3;//标记运算类型  即"÷"之前的数据即将作为被除数
            sBuilder = new StringBuilder();//将数组清空来存储第二个操作数 b
            text.setText("÷");
        }

        else if(lab.equals("%"))//处理取余运算
        {
            a = Double.parseDouble(sBuilder.toString());//将输入运算符前的数据作为第一个操作数a
            i=4;//标记取余运算
            sBuilder = new StringBuilder();//将数组清空来存储第二个操作数 b
            text.setText("%");
        }
        else if(lab.equals("^"))//处理取余运算
        {
            a = Double.parseDouble(sBuilder.toString());//将输入运算符前的数据作为第一个操作数a
            i=5;//标记取余运算
            sBuilder = new StringBuilder();//将数组清空来存储第二个操作数 b
            text.setText("^");
        }
        else if(lab.equals("="))
        {
            b = Double.parseDouble(sBuilder.toString());//遇到等号时记录第二个操作数b
            if (i == 0)//加法 a+b
            {
                sum=a+b;
                text.setText(sum.toString());//输出第二个操作数已经输入的数据
                sBuilder = new StringBuilder();//清空数据，为后面的操作数留空间
                sBuilder.append(sum);
            }
            else if (i == 1)//加法a-b
            {
                sum = a - b;
                text.setText(sum.toString());
                sBuilder = new StringBuilder();//清空数据，为后面的操作数留空间
                sBuilder.append(sum);
            }
            else if (i == 2)//乘法a*b
            {
                sum = a * b;
                text.setText(sum.toString());
                sBuilder = new StringBuilder();
                sBuilder.append(sum);
            }
            else if (i == 3)//除法a÷b
            {
                sum = a / b;
                text.setText(sum.toString());
                sBuilder = new StringBuilder();
                sBuilder.append(sum);
            }
            else if (i == 4)//取余a%b
            {
                sum=a % b;
                int m=(int)a;
                int n=(int)b;
                sum=(double)m % n;
                text.setText(sum.toString());
                sBuilder = new StringBuilder();
                sBuilder.append(sum);
            }
            else if (i == 5)//a是底数b是指数
            {
                sum=1.0;
                if(b==0)
                    sum=1.0;
                else
                    for(int i=1;i<=b;i++)
                        sum=sum*a;
                text.setText(sum.toString());
                sBuilder = new StringBuilder();
                sBuilder.append(sum);
            }
            else
                text.setText(sBuilder.toString());
        }
    }
}





