// Monk recently taught Fredo about sorting. Now, he wants to check whether he understood the concept or not. 
// So, he gave him the following algorithm and asked to implement it:

// Assumptions:
// We consider the rightmost digit of each number to be at index 1, second last at index 2 and so on till the leftmost digit of the number.
// Meaning of  chunk: This chunk consists of digits from position 5*i to 5*(i-1)+1 in the given number.
// If there is no digit at some position in the number, take the digit to be 0.

// Initially, i is 1.

// Construct the  chunk, for all of the integers in the array. Let's call the value of this chunk to be the 
// weight of respective integer in the array.
// If weight of all the integers of the array is 0, then STOP
// Sort the array according to the weights of integers. If two integers have same weight, then the one which 
// appeared earlier should be positioned earlier after the sorting is done. The array changes to this sorted array.
// Increment i by 1 and repeat from STEP 1
// See the sample explanation for a better understanding.
// So, Fredo understood the concept and coded it. Now, Monk asks you to write the code for the algorithm to verify Fredo's answer.

// Input:
// The first line of the input contains N denoting the number of elements in the array to be sorted.
// The next line contains N single space separated integers denoting the array elements.

// Output:
// You need to print the new array in each step of the algorithm.

// Constraints:
// ; A[] is the input array
// Size of integers (number of digits in integer) in A may not be same.
// Note

// Use Fast I/O

// SAMPLE INPUT 
// 3
// 213456789 167890 123456789

// SAMPLE OUTPUT 
// 213456789 123456789 167890 
// 167890 123456789 213456789 

// Explanation
// Each line of output is the array after each transformation.
// Here goes the explanation:
// 1st chunk of respective integers= 56789, 67890, 56789
// weight of respective integers= 56789, 67890, 56789 
// So, sorted array according to weights is [213456789, 123456789, 167890] because 56789< 67890.
// Note that the weight of 213456789 and 123456789 are the same, so we need to keep the given order.This becomes the new array.

// The array now is [213456789, 123456789, 167890]
// 2nd chunk of respective integers in the array= 02134, 01234, 00001
// weight of respective integers= 2134, 1234, 1
// So, sorted array according to weights is [167890, 123456789, 213456789] because 1<1234<2134.
// This becomes the new array.

// The array now is [167890, 123456789, 213456789].
// So, as the 3rd chunk would have no digits for any integer, so weights of all integers will be 0 and the algorithm would stop.



import java.io.*;
import java.util.*;

class Writer{
	final private static PrintStream w=System.out;
	final private static int SIZE = 1 << 16;
	final private static byte[] buff=new byte[SIZE];
	private static int curr=0;

	public Writer(){

	}

	public static void write(String str){
		byte[] strbytes=str.getBytes();

		for(int i=0;i<strbytes.length;i++){
			if(curr==SIZE){
				System.out.write(buff,0,SIZE);
				curr=0;
			}

			buff[curr++]=strbytes[i];
		}

	}

	public static void flush(){

		System.out.write(buff,0,curr);
	}
}
class TestClass {
    public static int[] count=new int[100000];
    

        public static long[] sort(long[] arr,long exp){
            
            long[] out=new long[arr.length];
            
            Arrays.fill(count,0);

            for(int i=0;i<arr.length;i++){
                count[(int)(arr[i]/exp)%100000]++;
            }

            for(int i=1;i<count.length;i++){
                count[i]=count[i]+count[i-1];
            }

            for(int i=arr.length-1;i>=0;i--){
                out[count[(int)(arr[i]/exp)%100000]-1]=arr[i];
                count[(int)(arr[i]/exp)%100000]--;
            }
            
            
            
            return out;
        }  


    
    
    public static void main(String args[] ) throws Exception {
        
        //BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        BufferedReader br=new BufferedReader(new FileReader(new File("tests.txt")));
        BufferedWriter bw=new BufferedWriter(new OutputStreamWriter(System.out));

        int N=Integer.parseInt(br.readLine());
        
        long[] arr=new long[N];
        
        String str=null;
        String[] arg=null;
        
        str=br.readLine();
        arg=str.split(" ");
        
        for(int i=0;i<N;i++){
            arr[i]=Long.parseLong(arg[i]);
        }
        
        long largest=Long.MIN_VALUE;
        for(int i=0;i<N;i++){
            largest=Math.max(largest,arr[i]);
        }
        
        long[] res=null;
        long start=System.currentTimeMillis();

        for(long exp=1;largest/exp>0;exp*=100000){
            arr=sort(arr,exp);
            for(int j=0;j<arr.length;j++){
            	str=""+arr[j]+" ";
                //System.out.print(arr[j]+" ");
                //bw.write(str,0,str.length());
                Writer.write(str);
            }

            Writer.write("\n");
            //System.out.println();
            //arr=res;
        }

        Writer.flush();
        long end=System.currentTimeMillis();

        System.out.println((end-start)/1000);
    }
}
