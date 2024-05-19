#include <iostream>

class A {
  private:
    int a_;
  public:
    A(int x = 10) : a_(x) {}
    int f(int x) { return g(x * x); }
    virtual int g(int x) const { return x % a_;}
};

class B: public A {
  private:
    int b_;
  public:
    B(int x): b_(x) {}
    virtual int f (int x) const { return g(x + x); }
    int g(int x) const { return x % b_; }
};

class C: public B {
  private:
    int c_;
  public:
    C(int x = 5): B(x), c_(x) {}
    int f(int x) { return g(x * c_); }
};

int main() {
  A *a = new A;
  std::cout << a->f(5) << std::endl;
  // 5 

  A *b = new B(7);
  std::cout << b->f(4) << std::endl;
  // B(7) -> b_ = 7
  // g(4 * 4) -> g(16) -> 16 % 7 = 2

  B *c = new C;
  std::cout << c->f(3) << std::endl;
  // c_ = 5 y b_ = 5
  // f(3) -> g(3 * 5) = g(15) -> 
}