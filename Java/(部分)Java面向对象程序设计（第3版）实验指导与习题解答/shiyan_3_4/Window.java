public abstract class Window{
        double width;
        double height;
        public abstract String getMaterial();

        public void  setWidth(double w){
            width=w;
        }
        public void  setHeight(double h){
            height=h;
        }
        public double  getWidth(){
            return width;
        }
        public double  getHeight(){
            return height;
        }
}
