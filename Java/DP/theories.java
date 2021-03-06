// Scientists, researchers, mathematicians and thinkers propose theories for a number of things. 
// For explaining a single thing, a number of theories are proposed. A number of theories are 
// rendered invalid after a new and more relevant theory surfaces, giving a better and a more 
// valid explanation for the subject of the theory. For this problem, we are only concerned with 
// one field of study, lets say, A. In the field A, a number of theories were proposed for a number of domains in the field. 

// For a particular theory, the time at which it was proposed be T1 and the time at which it 
// becomes invalid be T2. We define the theory period for this particular theory as [T1, T2). 
// Both T1 and T2 are recorded in seconds from some reference point, B. We are given the theory 
// periods for a number of theories. It is possible that more than one theory in the field A might 
// be valid at some second, T (Recorded with reference to B ). Let us call the value of the number 
// of valid theories at the second T as popularity of the field at second T. The popularity of 
// the field would be maximum at some point in time. Your task is simple, that is calculate this 
// maximum value of popularity for the field A. 

// INPUT:
// The first line of the input contains the integer t , the number of test cases.
// For each test case first line contains a positive integer n , that is, the number of theories.
// Then, n lines follow, one for each theory(1 to n ). Each line contains, 2 integers T1[i] and T2[i]. 
// T1[i] is the lower bound of the theory period for the theory i. (1 <= i <= n )
// T2[i] is the upper bound of the theory period for the theory i. (1 <= i <= n )


// OUTPUT:
// The output contains t lines, one for each test case. Each line contains a positive integer, 
// the required answer for that test case. 

// CONSTRAINTS:
// 1 <= t <= 10
// 1 <= n <= 104
// 1 <= T1[i] , T2[i] <= 109
// T1[i] < T2[i] 

// SAMPLE INPUT 
// 1
// 5
// 1 10
// 2 4
// 3 5
// 11 12
// 12 13
// SAMPLE OUTPUT 
// 3
// Explanation
// In the sample input, the number of test cases is 1.

// For test case 1, the value of n = 5, that is, the number of theories.
// The start time and the end time for each theory is measured from the same reference point.
// 1. The first theory is valid from 1s to 9s (Both Included)
// 2. Theory 2: It is valid from 2s to 3s (Both Included) 
// 3. Theory 3: It is valid from 3s to 4s (Both Included)
// 4. Theory 4: It is valid from 11s to 11s (Both Included)
// 5. Theory 5: It is valid from 12s to 12s (Both Included)

// It can be clearly seen at the time T = 3, a total of 3 theories are valid simultaneously. 
// From time T = 1 to T = 12, the maximum number of simultaneously valid theories is 3. And 
// this event occurs at T = 3 from the common reference.

// The solution used the interval problem algorithm. O(nlogn)






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

class InputReader {
		 
    private InputStream stream;
    private byte[] buf = new byte[8192];
    private int curChar, snumChars;
    private SpaceCharFilter filter;

    public InputReader(InputStream stream) {
        this.stream = stream;
    }

    public int snext() {
        if (snumChars == -1)
            throw new InputMismatchException();
        if (curChar >= snumChars) {
            curChar = 0;
            try {
                snumChars = stream.read(buf);
            } catch (IOException e) {
                throw new InputMismatchException();
            }
            if (snumChars <= 0)
                return -1;
        }
        return buf[curChar++];
    }

    public int nextInt() {
        int c = snext();
        while (isSpaceChar(c))
            c = snext();
        int sgn = 1;
        if (c == '-') {
            sgn = -1;
            c = snext();
        }
        int res = 0;
        do {
            if (c < '0' || c > '9')
                throw new InputMismatchException();
            res *= 10;
            res += c - '0';
            c = snext();
        } while (!isSpaceChar(c));
        return res * sgn;
    }

    public long nextLong() {
        int c = snext();
        while (isSpaceChar(c))
            c = snext();
        int sgn = 1;
        if (c == '-') {
            sgn = -1;
            c = snext();
        }
        long res = 0;
        do {
            if (c < '0' || c > '9')
                throw new InputMismatchException();
            res *= 10;
            res += c - '0';
            c = snext();
        } while (!isSpaceChar(c));
        return res * sgn;
    }

    public int[] nextIntArray(int n) {
        int a[] = new int[n];
        for (int i = 0; i < n; i++)
            a[i] = nextInt();
        return a;
    }

    public String readString() {
        int c = snext();
        while (isSpaceChar(c))
            c = snext();
        StringBuilder res = new StringBuilder();
        do {
            res.appendCodePoint(c);
            c = snext();
        } while (!isSpaceChar(c));
        return res.toString();
    }

    public int[] readCharCount() {
        int c = snext();
        while (isSpaceChar(c))
            c = snext();
        int[] map = new int[256];
        do {
            int val = c ;
            map[val]++;
            c = snext();
        } while (!isSpaceChar(c));
        return map;
    }

    public boolean isSpaceChar(int c) {
        if (filter != null)
            return filter.isSpaceChar(c);
        return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
    }

    public interface SpaceCharFilter {
        public boolean isSpaceChar(int ch);
    }
}

class TestClass{
	public static Writer w=new Writer();
	public static InputReader r=new InputReader(System.in);

	public static int solver(int[] start,int[] end){
		int count=0;
		int maxcount=Integer.MIN_VALUE;

		Arrays.sort(start);
		Arrays.sort(end);

		int i=0;
		int j=0;

		while(i<start.length){

			if(end[j]<=start[i]){
				count--;
				j++;
			}else{
				count++;
				if(maxcount<count)
					maxcount=count;

				i++;
			}
		}

		return maxcount;

	}

	public static void main(String[] args)throws Exception{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));


		//int T=Integer.parseInt(br.readLine());

		int T=r.nextInt();

		int[] start=null;
		int[] end=null;
		int N=0;
		String str=null;
		int ans=0;
		for(int i=0;i<T;i++){
			//N=Integer.parseInt(br.readLine());
			N=r.nextInt();

			start=new int[N];
			end=new int[N];

			for(int j=0;j<N;j++){
				//str=br.readLine();
				//args=str.split(" ");

				//start[j]=Integer.parseInt(args[0]);
				//end[j]=Integer.parseInt(args[1]);
				start[j]=r.nextInt();
				end[j]=r.nextInt();
			}

			ans=solver(start,end);

			w.write(ans+"\n");
		}

		w.flush();
	}
}
