//Bank.java
public class Bank {
    int savedMoney;int year;
    double interest;
    double interestRate = 0.29;
    public double computerInterest(){
        interest = year * interestRate * savedMoney;
        return interest;
    }
    public void setInterestRate( double rate){
       interestRate = rate;
    }
}
