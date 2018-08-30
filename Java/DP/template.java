import java.io.*;
import java.util.*;

class Writer{
	private PrintStream w;
	final private static int SIZE = 1 << 16;
	final private byte[] buff=new byte[SIZE];
	private int curr=0;

	public Writer(){
        this.w=System.out;
	}

    public Writer(File file) throws Exception{
        this.w=new PrintStream(file);
    }

	public void write(String str){
		byte[] strbytes=str.getBytes();

		for(int i=0;i<strbytes.length;i++){
			if(curr==SIZE){
				w.write(buff,0,SIZE);
				curr=0;
			}

			buff[curr++]=strbytes[i];
		}

	}

	public void flush(){

		w.write(buff,0,curr);
        w.close();
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
	public static Writer w;
	public static InputReader r;

    static {
        try{
            r=new InputReader(System.in);
            //r=new InputReader(new FileInputStream(new File("tests.txt")));

            w=new Writer();
            //w=new Writer(new File("output.txt"));
        }catch(Exception e){

        }
    }
	

	public static void main(String[] args)throws Exception{

		int T=r.nextInt();

        String str=null;


	}
}