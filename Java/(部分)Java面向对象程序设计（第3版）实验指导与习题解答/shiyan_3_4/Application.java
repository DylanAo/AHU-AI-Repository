public class Application {
    public  static void main(String args[]){
        Building schoolBuilding;
        int m=7;
        schoolBuilding=new Building(m);
        Window[]w=new Window[m];
        for(int i=0;i<m;i++){
            if(i%2==0){
                w[i]=new WoodWindow();
                w[i].setWidth(109.98);
                w[i].setHeight(156.89);
            } else if (i%2==1) {
                w[i]=new AluminumWindow();
                w[i].setWidth(109.98);
                w[i].setHeight(156.89);
            }
        }
        schoolBuilding.use(w);
        schoolBuilding.showWindow();
    }
}
