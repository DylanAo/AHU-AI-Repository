public class Parent {
    public int f(int a, int b) {
        int r =1 ;
        int aa = a;
        int bb = b;
        while (r!=0){    r = aa % bb;  aa = bb;  bb = r; }
        return aa;
    }
}

