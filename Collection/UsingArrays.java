package Collection;

public class UsingArrays {
    private int intArray[]={1,2,3,4,5,6,7,8,9,10};
    private int intarrcopy[];
    public UsingArrays(){
        intarrcopy=new int[8];
        System.arraycopy(intArray,2,intarrcopy,0,intArray.length-2);
        for(int x : intarrcopy) System.out.print(x+" ");
    }

    public static void main(String[] args) {
        new UsingArrays();
    }
}
