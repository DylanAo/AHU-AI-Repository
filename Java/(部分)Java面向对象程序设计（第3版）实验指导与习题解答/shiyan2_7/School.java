public class School implements computerAverage{
    @Override
    public double average(double x[]) {
        double sum = 0;
        for (double num : x) {
            sum += num;
        }
        double average = sum / x.length;
        return average;
    }
}
