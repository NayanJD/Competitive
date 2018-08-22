// Pradyumn is tired of using auto - correct feature in his smartphone. He needs to correct his 
//  - correct more times than the auto - correct corrects him. Pradyumn is thinking to make his 
//  own app for mobile which will restrict auto - correct feature, instead it will provide auto
//   - completion. Whenever Pradyumn types factorial, auto - correct changes it to fact. Pradyumn's 
//   App will show options such as fact, factorial, factory. Now, he can chose from any of these options. 
//   As Pradyumn is busy with his front - end work of his App. He asks you to help him. He said "You will 
//   be given set of words(say a dictionary of words in uppercase and lowercase letters both, 
//     words may repeat too). Now, as user starts the app, he will make queries(in lowercase 
//     letters only). So, you have to print all the words of dictionary which have the prefix 
//     same as given by user as input(in lowercase only). And if no such words are available, 
//     add this word to your dictionary." As you know, Pradyumn want this app to be as smart as 
//     him :P So, implement a program for him such that he can release it on Fun Store.

// INPUT CONSTRAINTS





// INPUT FORMAT
// Single integer N which denotes the size of words which are input as dictionary
// N lines of input, where each line is a string of consisting lowercase/uppercase letter
// Single integer Q which denotes the number of queries.
// Q number of lines describing the query string on each line given by user

// OUTPUT FORMAT

// If auto - completions exists, output all of them in lexicographical order(lowercase) else 
// output "No suggestions" without quotes

// NOTE Auto - completion feature never consider the lowercase/uppercase for suggestions. Query 
// strings are lowercase. Dictionary of words contains both types of cases(Uppercase & Lowercase).
//  Multiple occurrences of word is possible.

// SAMPLE INPUT 
// 3
// fact
// factorial
// factory
// 2
// fact
// pradyumn
// SAMPLE OUTPUT 
// fact
// factorial
// factory
// No suggestions
// Explanation
// Already explained above.

// The solution uses Trie data structure.




import java.io.*;
import java.util.*;

class Reader{
	final private InputStream r;
	final private int SIZE=1<<16;
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
		int bytesread=r.read(buff,0,SIZE);

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

class TestClass {
    
    static class Node{
        public Node[] next;
        public int pos;
        public char c;
        public String str;

        public Node(int pos,char c){
            next=new Node[52];
            this.pos=pos;
            this.c=c;
            this.str=null;
        }
    }
    
    static void insert(Node root,String str){
        Node curr=root;
        
        if(root.pos==str.length()-1){
            curr.str=str;
            return;
        }
            
        char c=str.charAt(root.pos+1);
        //System.out.println(c);
        
        int index=0;
        
        if(Character.isUpperCase(c))
            index=65+26;
        else
            index=97;
        
        try{
        if(curr.next[(int)c-index]!=null){
            insert(curr.next[(int)c-index],str);
        }else{
            curr.next[(int)c-index]=new Node(curr.pos+1,c);
            insert(curr.next[(int)c-index],str);
        }
        }catch(Exception e){
            //System.out.println((int)c+" "+index);
        }
        
    }
    
    static List<String> search(Node root,String str){
        Node curr=root;
        
        List<String> ans=new LinkedList<>();
        List<String> aux=new LinkedList<>();
        
        if(curr.pos+1==str.length()){
            dfs(curr,ans,str);
            return ans;
        }
            
            
        char c=str.charAt(curr.pos+1);
        
        if(Character.isUpperCase(c))
            c=Character.toLowerCase(c);

        if(curr.next[(int)c-97]!=null){
            aux=search(curr.next[(int)c-97],str);
            if(aux.size()!=0)
                ans.addAll(aux);
        }
        

        if(Character.isLowerCase(c))
            c=Character.toUpperCase(c);

        if(curr.next[(int)c-65+26]!=null){
            aux=search(curr.next[(int)c-65+26],str);
            if(aux.size()!=0)
                ans.addAll(aux);
        }
        
        // ans.forEach(System.out::print);
        // System.out.println();

        return ans;
            
    }
    
    public static void dfs(Node root,List<String> ans,String str){
        
        boolean flag=false;
        if(root.str!=null)
            ans.add(root.str);
        //System.out.print(root.c+" ");
        for(int i=0;i<52;i++){
            if(root.next[i]!=null){
                if(i>25)
                    dfs(root.next[i],ans,str+(char)(i+65));
                else
                    dfs(root.next[i],ans,str+(char)(i+97));

                flag=true;
            }
        }
        
        if(!flag){
            //ans.add(str);
            //ans.forEach(System.out::print);
            //System.out.println();
        }
    }
    
    
    public static void main(String args[] ) throws Exception {
        
        //BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        //BufferedReader br=new BufferedReader(new FileReader(new File("tests.txt")));
        //BufferedWriter bw=new BufferedWriter(new OutputStreamWriter(System.out));
        //BufferedWriter bw=new BufferedWriter(new FileWriter(new File()))
        
        long start=System.currentTimeMillis();
        Writer w=new Writer(new File("output.txt"));
        Reader r=new Reader(new File("tests.txt"),w);

        int N=Integer.parseInt(r.nxtString());
        System.out.println(N);
        String str=null;
        String[] arg=null;
        
        Node root=new Node(-1,'a');	
        
        int i=0;
        while(i<N){
            str=r.nxtString();
            w.write(i+" "+str+"\n");
            insert(root,str);
            //System.out.println(i+" eol");
            i++;
        }
        w.flush();
        System.out.println("finished");
        int Q=Integer.parseInt(r.nxtString());
        
        i=0;
        List<String> ans=null;
        
        ans=new LinkedList<String>();
        //dfs(root,ans,"");

        while(i<Q){
            str=r.nxtString();
            ans=new LinkedList<>();
            
            ans=search(root,str);
            
            if(ans.size()==0){
                insert(root,str);
                w.write("No suggestions\n");
            }else{
                // ans.forEach(bw::write);

                for(String e:ans){
                    w.write(e+"\n");
                }
            }
            
            i++;
        }

        w.flush();

        long end=System.currentTimeMillis();
        //w.write((end-start)+"\n");
        //w.flush();
        
    }
}
