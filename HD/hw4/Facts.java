/* print square roots in Java language.  R. Brown, 9/2010 */

class Facts {
  public static void main(String args[]) {
    System.out.println("n\tn!");
    System.out.println("----------------");
    int n;
    for (n=0;  n<=5;  n++)
	System.out.println(n + "\t" + Facts.factorial(n));
    return;

  }
}
