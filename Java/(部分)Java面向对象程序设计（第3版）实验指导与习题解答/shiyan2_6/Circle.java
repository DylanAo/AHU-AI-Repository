public class Circle extends Geometry {
    double r;

    public Circle(double r) {
        this.r = r;
    }

    @Override
    public double getArea() {
        return 3.14* r * r; // 计算圆的面积
    }
}
