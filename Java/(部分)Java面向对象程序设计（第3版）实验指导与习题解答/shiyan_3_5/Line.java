public class Line {
    InputScore one;
    DelScore two;
    ComputerAver three;
    Line(){
        three=new ComputerAver();
        two=new DelScore(three);
        one=new InputScore(two);
    }
    public void givePersonScore(){
        one.inputScore();
    }
}
