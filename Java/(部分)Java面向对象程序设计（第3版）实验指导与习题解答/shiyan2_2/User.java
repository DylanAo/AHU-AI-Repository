public class User {
    public static void main(String args[]) {
        CD dataCD = new CD();
        int b[] = {1, 2, 3, 4, 5, 6, 7, 8};
        dataCD.setSize(b.length);
        dataCD.setContent(b);
        int a[] = dataCD.getContent();
        System.out.println("dataCD上的内容:");
        for (int i = 0; i < a.length; i++)
            System.out.printf("%8d", a[i]);

        Computer computerIMB = new Computer();
        computerIMB.putCD(dataCD);

        System.out.println("\n将dataCD的数据复制到计算机: computerIMB.");
        computerIMB.copyToComputer();

        System.out.println("computerIMB上的内容:");
        computerIMB.showData();

        int m = 12;
        System.out.println("\ncomputerIMB将每个数据增加" + m);
        computerIMB.addData(m);
        System.out.println("computerIMB将增值后的数据复制到CD: dataCD");
        computerIMB.copyToCD();

        System.out.println("dataCD上的内容:");
        a = dataCD.getContent();
        for (int i = 0; i < a.length; i++)
            System.out.printf("%3d", a[i]);
    }
}
