public class Test {
    public static void main(String[] args) {
        Parent obj = new Child();  // 父类的上转型对象，指向子类的实例
        int a = 12, b = 18;
        int lcm = obj.f(a, b);
        System.out.printf("a=%d, b=%d, LCM=%d", a, b, lcm);
    }
}