//MainClass.java
public class MainClass{
    public static void main( String args[ ]){
        Geometry [ ] tuxing = new Geometry[29] ;//有29个Geometry对象
        for( int i = 0;i<tuxing.length; i++){//29个 Geometry对象分成两类
            if(i%2== 0)
            tuxing[i]= new Rect( 16+ i,68 ) ;
            else if(i%2==1) {
                tuxing[i] = new Circle( 10 + i);
            }
        }
        TotalArea computer = new TotalArea( );
        computer. setTuxing( tuxing ) ;
        System. out.printf("各种图形的面积之和:\n %f" , computer. computerTotalArea());
    }
}