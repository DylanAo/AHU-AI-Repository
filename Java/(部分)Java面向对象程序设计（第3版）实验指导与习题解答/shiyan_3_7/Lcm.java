class Lcm extends T {
    private Gcd gcd = new Gcd();  // Lcm类中包含Gcd类的实例

    public int f(int a, int b) {
        int g = gcd.f(a, b);  // 调用Gcd类的f()方法获得最大公约数
        return (a * b) / g;   // 计算最小公倍数
    }
}
