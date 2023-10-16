public class TotalArea {
    Geometry[] tuxing;
    double totalArea = 0;

    public void setTuxing(Geometry[] t) {
        tuxing = t;
    }

    public double computerTotalArea() {
        for (int i = 0; i < tuxing.length; i++) {
            totalArea += tuxing[i].getArea(); // 让tuxing的元素调用getArea方法，并累加到totalArea
        }
        return totalArea;
    }
}
