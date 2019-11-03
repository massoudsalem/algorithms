import java.util.Arrays;

public class ShellSort {
    public static void shellSort(int array[]){
        int h = 1;

        while(h <= array.length/3)
            h = h * 3 + 1;

        while (h > 0){

            for(int i = 0; i < array.length; i++){

                int j=i, temp=array[i];

                while(j >= h && temp <= array[j - h]){
                    array[j] = array[j - h];
                    j -= h;
                }

                array[j] = temp;
            }

            h = (h-1)/3;
        }
    }

    public static void main(String [] args){
        int array[] = {1,5,6,7,2,3,4,9,1};
        shellSort(array);
        System.out.println(Arrays.toString(array));
    }
}
