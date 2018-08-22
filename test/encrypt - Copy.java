import java.io.*;

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

	public static int heapsize=0;

	public static int parent(int key){
		return (int)(key/2-0.5);
	}

	public static void insertkey(char[] arr,char key){

		heapsize++;
		arr[heapsize]=key;

		int temp=0;
		int i=heapsize;

		while(i!=0 && arr[parent(i)]>arr[i]){
			temp=arr[parent(i)];
			arr[parent(i)]=arr[i];
			arr[i]=temp;
		}

	}	

	public static void minheapify(char[] arr,int idx){

		int left=2*idx+1;
		int right=2*idx+2;

		if(left>=heapsize || right>=heapsize)
			return;

		int smallest=idx;

		if(arr[left]<arr[smallest])
			smallest=left;

		if(arr[smallest]>arr[right])
			smallest=right;

		int temp=0;

		if(smallest!=idx){
			temp=arr[smallest];
			arr[smallest]=arr[idx];
			arr[idx]=temp;

			minheapify(arr,smallest);
		}
	}

	public static void heapsort(char[] arr){
		char[] aux=Arrays.copyOf(arr);

		for(int i=0;i<aux.length;i++){
			insertKey(arr,aux[i]);
		}

		int temp=0;
		for(int i=arr.length-1;i>=0;i--){
			temp=arr[i];
			arr[i]=arr[0];
			arr[0]=temp;

			heapsize--;
			maxheapify(arr,0);
		}



	}
    public static void main(String args[] ) throws Exception {
        
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        
        int T=Integer.parseInt(br.readLine());

        int i=0;

        String estr=null;
        String str=null;
        String[] arg=null;
        int pos=0;
        char[] arr=null;
        int[] alpha=new int[26];
        int[][] dp=null;

        while(i<T){
        	str=br.readLine();

        	arg=str.split(" ");

        	estr=Integer.parseInt(arg[0]);
        	pos=Integer.parseInt(arg[1]);

        	estr.getChars(0,estr.length,arr,0);

        	heapsize=0;
        	heapsort(arr);

        	



        }
        
    }
}
