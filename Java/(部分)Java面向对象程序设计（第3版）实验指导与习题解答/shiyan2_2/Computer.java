public class Computer {
    int data[ ];
    CD includeCD;
    public void putCD( CD cd){
        includeCD = cd;
        int size = includeCD. getsize( );
        data = new int[ size];}
    void copyToComputer( ){
        int []b = includeCD. getContent( );
        int min = Math. min( data.length, b. length);for( int i = 0; i<min;i++) {
            data[ i] =b[i];}}
    public void addData( int m){
        for( int i= 0;i<data. length; i++){data[ i] = data[i]+m;}}
    void copyToCD( ){
        includeCD.setContent ( data) ;
    }
    void showData() {
        for( int i= 0; i<data.length;i++){
            System. out. printf(" % 3d", data[ i]);
        }
    }}
