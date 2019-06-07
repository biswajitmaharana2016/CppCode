#include <iostream>
#include <vector>
#include <list>
#include <memory>
#include <type_traits>

constexpr size_t stack_limit= 1 << 14;

template <typename Value, unsigned Size, unsigned Id= 0>
class static_memory_block
{
    static Value* get_block(std::true_type)
    {
	static array_type block;
	return block;
    }

    static Value* get_block(std::false_type)
    {
	static std::unique_ptr<Value> block{new Value[Size]};
	return block.get();
    }
    
  public:
    using array_type= Value[Size];
    using on_stack= std::integral_constant<bool, (Size * sizeof(Value) <= stack_limit)>;
    
    static Value* get_block()
    {
	return get_block(on_stack{});
    }

    static_memory_block() = delete;
    static_memory_block(const static_memory_block&) = delete;
};

struct exaggerated_deallocate {};
struct not_last_chunk {};
struct out_of_memory {};

template <typename Value, unsigned Size>
class lifo_allocator
{
    using block_type= static_memory_block<Value, Size>;
  public:
    using value_type= Value;
    using pointer=    Value*;
    using size_type=  unsigned;

    template<typename U>
    struct rebind
    {
	using other= lifo_allocator<U, Size>;
    };

    static void deallocate(pointer p, size_type n)
    {
	if (n > pos)
	    throw exaggerated_deallocate{};
	if (p != &block[pos-n])
	    throw not_last_chunk{};
	pos-= n;
    }

    static pointer allocate(size_type n)
    {
	if (pos + n > Size)
	    throw out_of_memory{};
	pointer start= &block[pos];
	pos+= n;
	return start;
    }
  private:
    static size_type pos;
    static pointer   block;
};

template <typename Value, unsigned Size>
unsigned lifo_allocator<Value, Size>::pos{0};

template <typename Value, unsigned Size>
Value* lifo_allocator<Value, Size>::block{block_type::get_block()};

struct paar
{
    void* operator new(size_t size);
  
    void operator delete(void * p);

    int    i= 9;
    double d= 1.9;
};


void* paar::operator new(size_t size)
{
    std::cout << "Mein eigenes new!!!\n";
    using pal= lifo_allocator<paar, 100>;
    return pal::allocate(1);
}


void paar::operator delete(void* p)
{
    std::cout << "Mein eigenes delete!!!\n";
    using pal= lifo_allocator<paar, 100>;
    return pal::deallocate(static_cast<paar*>(p), 1);
}

struct undynamisch
{
    void* operator new(size_t size) = delete;

    int    i= 9;
    double d= 1.9;
};

int main(int argc, char** argv) 
{
    using namespace std;

    undynamisch u1;
    // undynamisch* pu1= new undynamisch; // Verboten!!!
    
    cout << "paar block starts at " << &static_memory_block<paar, 100>::get_block()[0]
	 << " and ends at " << &static_memory_block<paar, 100>::get_block()[100] << endl;
    
    paar *p1= new paar, *p2= new paar;
    cout << "p1 = " << p1 << endl;
    cout << "p2 = " << p2 << endl;

    delete p2;
    delete p1;
    
    cout << "block starts at " << &static_memory_block<int, 1000>::get_block()[0]
	 << " and ends at " << &static_memory_block<int, 1000>::get_block()[1000] << endl;

    using al= lifo_allocator<int, 1000>;
    
    vector<int, al> v{2, 3, 4, 9};
    cout << "&v[0] = " << &v[0] << endl;
    
    vector<int, al> w(99);
    cout << "&w[0] = " << &w[0] << endl;

    {
	vector<int, al> x(12);
	cout << "&x[0] = " << &x[0] << endl;
    }

    vector<int, al> y(12);
    cout << "&y[0] = " << &y[0] << endl;

    auto dv1= new vector<int, al>(10);
    auto dv2= new vector<int, al>(120);

    cout << "&dv1[0] = " << &(*dv1)[0] << endl;
    cout << "&dv2[0] = " << &(*dv2)[0] << endl;

    delete dv2;
    delete dv1;

    // mit push_back in falscher Reihenfolge freigegeben
    list<int, al> ll;
    ll.push_front(3); 
    ll.push_front(39); 
    ll.push_front(93);
    for (int i : ll)
	cout << "Eintrag ist " << i << endl;
    
    return 0;
}
