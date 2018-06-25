/* print square roots in Java language.  R. Brown, 9/2010 */

class Sqrts {
  public static void main(String args[]) {
    System.out.println("sqrt(n)");
    System.out.println("--------");
    int n;
    int max;
    max = Integer.parstInt(args[0])
    for (n=0;  n<=max;  n++)
      System.out.println(Math.sqrt(n));
    return;

  }
}
