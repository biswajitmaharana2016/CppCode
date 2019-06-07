#include <iostream>
#include <memory>
#include <exception>
#include <cassert>
#include <initializer_list>
#include <iomanip>

// Stack-Implementierung mit unique_ptr
// mit Move-Operationen
// und Kopie
// mit Initializer-Liste

/*
Schreiben Sie eine Stack-Implementierung für eine generische Wertart. 
Die maximale Größe des Stacks wird Konstruktor übergeben. 

Stellen Sie die folgenden Funktionen zur Verfügung:
* Konstruktoren;
* Destruktor wenn nötig;
* Zuweisungsoperatoren;
* top: zeige letztes Element (ohne es zu entfernen);
* pop: entferne letztes Element (ohne es zurückzugeben); 
* push: füge neues Element ein;
* clear: lösche alle Einträge;
* size: Anzahl der Elemente im Stack;
* full: ob der Stack voll ist;
* empty: ob der Stack leer ist;
* capacity: Anzahl der verfügbaren Einträge;
* reserve: Platz für n Einträge reservieren, Daten ggf. kopieren 
* operator<< und
* operator==: zwei Stacks haben die gleiche Größe und gleiche
  Einträge.
Stacküber- und -underlauf sollen eine Ausnahme werfen.

Die Move-Operationen sollen in der Quelle einen leeren Stack hinterlassen,
wobei die Kapazität erhalten bleiben oder auf 0 reduziert werden kann.

Die Implementierung soll für die internen Daten einen
Unique-Pointer verwenden.



 */



namespace sn {

    // Immer gut, von std::exception abzuleiten
    struct underflow
      : std::exception
    {
	virtual const char* what() const noexcept override {return "Stack underflow!\n";}
    };

    struct overflow
      : std::exception
    {
	virtual const char* what() const noexcept override {return "Stack overflow!\n";}
    };

    class stack
    {
	void check_empty() const
	{
	    if (empty())
		throw underflow{};
	}
	void check_full() const
	{
	    if (full())
		throw overflow{};
	}

	void give_me(const stack& that, size_t s)
	{
	    std::copy(&that.data[0], &that.data[s], &data[0]);
	}
	void clear(stack&& that) const
	{
	    that.pos= 0;
	    that.cap= 0;
	}
      public:
	stack(size_t c) : cap{c}, pos{0}, data{new int[cap]} {}

	stack(std::initializer_list<int> il)
	  : stack(il.size())
	{
	    std::copy(begin(il), end(il), &data[0]);
	    pos= cap;
	}

	stack(const stack& that)
	  : stack(that.capacity())
	{
	    pos= that.pos;
	    give_me(that, pos);
	}

	~stack() { delete[] data; }

	stack& operator=(const stack& that) &
	{
	    if (that.size() > cap)
		throw overflow{};
	    give_me(that, that.size());
	    pos= that.size();
	    return *this;
	}

	void reserve(unsigned new_cap)
	{
	    if (new_cap <= cap)
		return;
	    int* tmp{ new int[new_cap] };
	    std::copy(&data[0], &data[pos], &tmp[0]);
	    std::swap(tmp, data);
	    cap= new_cap;
	    delete[] tmp;
	}
	
	size_t capacity() const { return cap; }
	size_t size() const { return pos; }

	bool empty() const { return pos == 0u; }
	bool full() const { return pos == cap; }
	
	int top() const { check_empty(); return data[pos-1]; }
	void pop() { check_empty(); --pos; }

	void push(const int& v) { check_full(); data[pos++]= v; }

	friend std::ostream& operator<<(std::ostream&, const stack&);

	bool operator==(const stack& that)
	{
	    if (pos != that.pos)
		return false;
	    for (unsigned i= 0; i < pos; ++i)
		if (data[i] != that.data[i])
		    return false;
	    return true;
	}
      private:
	size_t                   cap, pos;
	int*                     data;	
    };
   
    std::ostream& operator<<(std::ostream& os, const stack& s)
    {
    	for (unsigned p= s.size(); p-- != 0; )
    	    os << '[' << std::setw(5) << s.data[p] << " ]\n";
    	return os;
    }
}


int main (int argc, char* argv[]) 
{
    using namespace std;
    using namespace sn;

    stack   si(100);

    assert(si.empty());
    assert(!si.full());
    assert(si.size() == 0);
    assert(si.capacity() == 100);
    
    for (size_t i= 0; i < si.capacity(); ++i)
	si.push(i);

    assert(!si.empty());
    assert(si.full());
    assert(si.size() == 100);
    assert(si.top() == 99);
    
    si.pop();
    assert(!si.empty());
    assert(!si.full());
    assert(si.size() == 99);
    assert(si.top() == 98);

    stack   si2= {3, 9, 4, 8};
    cout << "si2 initial =\n" << si2 << endl;

    assert(!si2.empty());
    assert(si2.full());
    assert(si2.size() == 4);
    assert(si2.top() == 8);

    stack   si2ref(4);
    si2ref.push(3);
    si2ref.push(9);
    si2ref.push(4);
    si2ref.push(8);

    assert(si2 == si2ref);
    
    stack si3(si2);
    cout << "si3 nach Copy-Konstruktor =\n" << si3 << endl;
    assert(si3 == si2ref);

    si3.reserve(200);
    assert(si3.capacity() == 200);
    
    stack si5(4);
    si5= si2;
    cout << "si5 nach Copy-Zuweisung =\n" << si5 << endl;
    assert(si5 == si2ref);

    stack   si7= {3, 2, 1, 0};
    try {
	si7.push(-1);
	throw "Fehlende Ausnahme";
    } catch (overflow) {
	cout << "Overflow erfolgreich gefangen.\n";
    }

    stack   si8(10);
    try {
	si8.pop();
	throw "Fehlende Ausnahme";
    } catch (underflow) {
	cout << "Underflow erfolgreich gefangen.\n";
    }
    
    
    return 0;
}

