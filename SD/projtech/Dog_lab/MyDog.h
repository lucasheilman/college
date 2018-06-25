
/** Represents a canine */
class MyDog {
protected:
  char *name;  /**< name for this Dog */
  int age;  /**< age of this Dog, in years */

public:
  /** 2-argument constructor
      @param n Name for this Dog, to copy to name using dynamic allocation
      @param a Age value for this Dog */
  Dog(const char *n, int a);

  /** obtain name state variable
      @return The value of the state variable name for this Dog */
  char *get_name();
};
