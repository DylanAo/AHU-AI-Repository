public class BankOfDalian extends Bank {
    double year;

    public double computerInterest() {
        super.year = (int) year;
        double r = year - (int) year;
        int day = (int) (r * 1000);

        double yearInterest = super.computerInterest(); // 调用父类的隐藏方法
        double dayInterest = day * 0.00012 * savedMoney;
        interest = yearInterest + dayInterest;

        System.out.printf("%d元存在大连银行%d年零%d天的利息：%f元\n", savedMoney, super.year, day, interest);
        return interest;
    }
}
