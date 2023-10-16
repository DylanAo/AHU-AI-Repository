//MainClass.java
interface Area {
    double computerArea( double r);}
class Circle{
    double r;
    void setRadius( double r){
        this.r = r;
    }
    void showArea( Area area){
        double result = area.computerArea(r);
        System. out. println( "result = " + result);}}
public class MainClass {

    public static void main( String args[ ]){
        Area area = new Area() {
            //匿名类的实例
            public double computerArea( double r) {
                return Math.PI *r* r;}
        };
        System.out.println( area. computerArea(5));
        area=(double r)->{return Math.PI*r*r;};
//使用Lambda表达式代替匿名类的实例
        System. out. println( area.computerArea(2)) ;
        Circle circle = new Circle();
        circle.setRadius(12.8);
        circle.showArea( new Area( ) {
            //匿名类的实例
            public double computerArea( double r){
                return Math.PI*r* r;
            } } ) ;
        circle.setRadius( 100) ;
        circle.showArea((double r)->{return Math.PI*r*r;});
//!使用 Lambda表达式代替匿名类的实例
    }
}
