class Test {
private:
	int a;
public: 
	Test() = default;
	Test(int a) : a(a) {};
	void print() const;
};