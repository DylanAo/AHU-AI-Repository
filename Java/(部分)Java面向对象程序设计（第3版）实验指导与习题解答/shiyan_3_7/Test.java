public class Test {
    public static void main(String[] args) {
        T obj1 = new Gcd();  // T类的上转型对象，指向Gcd类的实例
        int a = 12, b = 18;
        int g = obj1.f(a, b);
        System.out.printf("a=%d, b=%d, GCD=%d\n", a, b, g);

        T obj2 = new Lcm();  // T类的上转型对象，指向Lcm类的实例
        int l = obj2.f(a, b);
        System.out.printf("a=%d, b=%d, LCM=%d", a, b, l);
    }
}
