public class Building {
    int windowNumber=100;
    double width=109.98;
    double height=156.88;
    Window [] window;
    Building(){
        window=new Window[windowNumber];
    }
    Building(int n){
        windowNumber = n;
        window=new Window[windowNumber];
    }
    public void use(Window[]w){
        for(int i=0;i<window.length;i++){
            boolean boo=
            Math.abs(w[i].getWidth()-width)<=1E-2&&
            Math.abs(w[i].getHeight()-height)<=1E-1;
            if (boo){window[i]=w[i];}
        }
    }
    public  void  showWindow(){
        for(int i=0;i<window.length;i++){
            if(window[i]!=null){
                System.out.println("第"+(i+1)+"扇窗户是："+window[i].getMaterial());
            }
            else{
                System.out.println("该窗户未安装");
            }
        }
    }
}
