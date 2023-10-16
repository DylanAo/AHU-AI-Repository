public class Rect extends Geometry {
    double a, b;

    public Rect(double a, double b) {
        this.a = a;
        this.b = b;
    }

    @Override
    public double getArea() {
        return a * b; // 计算矩形的面积
    }
}
