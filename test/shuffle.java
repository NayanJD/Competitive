import java.util.*;
import java.io.*;

class Permutation{
	
	public static int perm(int length){

		if(length==0)
			return 1;

		//System.out.println(length);
		return length*perm(length-1);


	}



	private final int[] arr;
	private final int[][] aux;
	private int count;
	private int max_count;
	private int curr=0;

	public Permutation(int[] arr){
		this.arr=arr;

		this.count=0;
		this.max_count=Permutation.perm(arr.length);
		this.aux=new int[max_count][];

		permutation(arr,arr.length);
		curr=0;
		//System.out.println(arr.getClass());
	}

	public void permutation(int[] arr,int length){
		int temp=0;
		int index=arr.length-length;

		if(length==1){
			aux[curr++]=Arrays.copyOf(arr,arr.length);

			// for(int i=0;i<arr.length;i++){
			// 	System.out.print(arr[i]+" ");
			// }
			// System.out.println();
			return;
		}

		for(int i=index;i<arr.length;i++){
			temp=arr[index];
			arr[index]=arr[i];
			arr[i]=temp;

			permutation(Arrays.copyOf(arr,arr.length),length-1);
		}
	}

	public int[] next(){
		if(curr>=max_count){
			System.out.println("No Sequence left");
			return new int[0];
		}else{
			return aux[curr++];
		}
	}

	public void reset(){
		this.curr=0;
	}


}

class TestClass{

	public static int[][] map=new int[][]{{1,2,3},
											{1,3,2},
											{2,1,3},
											{2,3,1},
											{3,1,2},
											{3,2,1}};

	public static int[] mapper(int[] arr,int i){
		int[] aux=new int[3];

		aux[0]=arr[map[i][0]-1];
		aux[1]=arr[map[i][1]-1];
		aux[2]=arr[map[i][2]-1];

		return aux;
	} 

	public static int colsum(int[][] arr){
		int largest=arr[0][0];
		int smallest=arr[1][0];

		int temp=0;
		if(smallest>largest){
			temp=largest;
			largest=smallest;
			smallest=temp;
		}

		if(arr[2][0]>largest){
			temp=largest;
			largest=arr[2][0];
			smallest=temp;
		}else{
			if(arr[2][0]>smallest)
				smallest=arr[2][0];
		}

		return largest+smallest;


	}


	public static void main(String[] args) throws Exception{
		
	//BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
	BufferedReader br=new BufferedReader(new FileReader(new File("tests2.txt")));
	BufferedWriter bw=new BufferedWriter(new FileWriter(new File("output.txt")));


	int N=Integer.parseInt(br.readLine());

	int[][] arr=null;

	String str=null;
	//String[] args=null;

	arr=new int[3][N];

	for(int i=0;i<3;i++){
		str=br.readLine();
		args=str.split(" ");

		for(int j=0;j<N;j++){
			arr[i][j]=Integer.parseInt(args[j]);
		}
	}

	int[][] aux1=new int[N][3];
	for(int i=0;i<N;i++){
		for(int j=0;j<3;j++){
			aux1[i][j]=arr[j][i];
		}
	}

	arr=aux1;


	int[][][] aux=new int[6][3][N];

	for(int i=0;i<aux.length;i++){
		for(int j=0;j<aux[i].length;j++){
			for(int k=0;k<aux[i][j].length;k++){
				aux[i][j][k]=1;
			}
		}
	}

	int[] com=null;
	int[] comaux=null;
	int[][] sumaux=new int[3][1];

	int value=0;
	for(int i=0;i<N;i++){

		for(int j=0;j<6;j++){

			com=mapper(arr[i],j);

			for(int k=0;k<6;k++){

				value=colsum(new int[][]{{aux[j][0][i]},
									{aux[j][1][i]},
									{aux[j][2][i]}});

				for(int m=i-1;m>=0;m--){
					comaux=mapper(arr[m],k);
					
					for(int n=0;n<3;n++){

						if(com[n]>=comaux[n]){

							value=aux[k][n][m]+1;

							if(value>aux[j][n][i]){
								//aux[j][n][i]=value;
								sumaux[n][0]=value;
							}

						}
					}


					
					aux[j][0][i]=sumaux[0][0];
					aux[j][1][i]=sumaux[1][0];
					aux[j][2][i]=sumaux[2][0];

					
				}
			}
		}
	}

	int largest=Integer.MIN_VALUE;

	for(int i=0;i<aux.length;i++){
		for(int j=0;j<N;j++){
			// for(int k=0;k<aux[i][j].length;k++){
			// 	if(largest<aux[i][j][k])
			// 		largest=aux[i][j][k];
			// }

			value=colsum(new int[][]{{aux[i][0][j]},
									{aux[i][1][j]},
									{aux[i][2][j]}});

			if(largest<value)
				largest=value;
		}
	}

	for(int i=0;i<aux.length;i++){

		for(int j=0;j<aux[i].length;j++){
			for(int k=0;k<aux[i][j].length;k++){
				bw.write(aux[i][j][k]+"\t");
			}
			bw.write("\n");
		}

		bw.write("---------------------\n");
	}

	bw.write(largest+"\n");
	System.out.println(largest);

	bw.close();
	
	}
	
}
