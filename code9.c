import java.util.*;
import java.util.Scanner;
class RSA{
 public static void main(String arg[]){
 Scanner in=new Scanner(System.in);
 long p,q,d,z,e,n,c;
 int choice;
 System.out.println("Enter two distinct prime numbers");
 p=in.nextLong();
 q=in.nextLong();
 n=p*q;
 z=(p-1)*(q-1);
 System.out.println("Enter a value for d which is less than and relatively 
prime to "+z);
 d=in.nextLong();
 
 for(e=1;e<z;++e)
 {
 if(((e*d)%z)==1)
 break;
 }
 
System.out.println("p="+p+"\nq="+q+"\nn="+n+"\nz="+z+"\nd="+d+"\ne="+e);
 do{
 System.out.println("1.Encription \n2.Decription\n3.Exit");
 System.out.println("choose an option");
 choice = in.nextInt();
 switch(choice){
 case 1:System.out.println("Enter a plain text");
 String s = in.next();
 
 System.out.println("Plain Text" +"\t" + "Cipher Text");
 for(int i = 0; i < s.length(); i++){
 long pl = (int) s.charAt(i);
 c = modexp(pl,e,n);
 System.out.println(s.charAt(i)+"\t\t" + c);
 }
 break;
 case 2: System.out.println("Enter a cipher text (0 to stop input)");
 long [] ci = new long[50];
 int j =0;
 do{
 ci[j] = in.nextLong();
 }while(ci[j++] != 0);