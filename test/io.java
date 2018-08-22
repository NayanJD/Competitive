import java.io.*;
import java.util.*;

class Reader{
	final private InputStream r;
	final private int SIZE=8192;
	final private byte[] buff=new byte[SIZE];
	private Writer w;
	private StringTokenizer st;
	private boolean eof;
	private int end=SIZE;
	public Reader(){
		r=System.in;
	}

	public Reader(File file) throws Exception{
		r=new FileInputStream(file);
	}

	public Reader(File file,Writer w)throws Exception{
		this(file);
		this.w=w;
	}

	public void read()throws Exception{
		int bytesread=r.read(buff);

		if(bytesread==-1)
			throw new Exception("End of File");

		st=new StringTokenizer(new String(buff,0,bytesread));
	}


	public String nxtString()throws Exception{

		if(st==null)
			read();

		if(st.hasMoreTokens())
			return st.nextToken();
		else{
			read();
			return nxtString();
		}
	}
}

class Writer{
    final private PrintStream w;
    final private int SIZE = 1<<16;
    final private byte[] buff=new byte[SIZE];
    private int curr=0;

    public Writer(){
        w=System.out;
    }

    public Writer(File file) throws Exception{
        w=new PrintStream(file);
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
    }
}

class TestClass{
	public static void main(String[] args) throws Exception{
		Writer w=new Writer(new File("ouput.txt"));
		Reader r=new Reader(new File("tests.txt"));

		String str=null;

		try{
			while(true){
				str=r.nxtString();
				w.write(str+"\n");
			}
		}catch(Exception e){}
		finally{
			w.flush();
		}

		byte[] buff=new byte[10];
		StringTokenizer st=new StringTokenizer("kkkk");

		System.out.println(st.hasMoreTokens());
	}
}