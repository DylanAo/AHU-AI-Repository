public class Child extends Parent {
    public int f(int a, int b) {
        int gcd = super.f(a, b);  // 调用父类的f()方法获得最大公约数
        int lcm = (a * b) / gcd;  // 计算最小公倍数
        return lcm;
    }
}