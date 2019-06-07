#include <iostream>
#include <memory>
#include <iterator>

using namespace std;

namespace sn {

    struct list_entry
    {
	explicit list_entry(int i) : value{i}, next{} {}
	    
        int value;
        unique_ptr<list_entry> next;
    };

    struct list_iterator
    {
	list_iterator(list_entry* p) : p{p} {}

	int& operator*() { return p->value; }
	const int& operator*() const { return p->value; }

	bool operator!=(list_iterator that) const { return p != that.p; }

	list_iterator& operator++() { p= p->next.get(); return *this; }
	
	list_entry* p;
    };

    struct list
    {
	void insert(int i) {
	    if (head == nullptr) {
		head= make_unique<list_entry>(i);
		tail= head.get();
	    } else {
		tail->next= make_unique<list_entry>(i);
		tail= tail->next.get();
	    }
	}

	list_iterator begin() { return list_iterator{head.get()}; }
	list_iterator end() { return list_iterator{nullptr}; }
	
	unique_ptr<list_entry> head;
	list_entry*            tail{};
    };

    template <typename Iterator, typename Init>
    Init sum(Iterator b, Iterator e, Init init)
    {
	for (; b != e; ++b)
	    init+= *b;
	return init;
    }
    
}

int main (int argc, char* argv[]) 
{
    using namespace sn;

    list l;
    l.insert(3);
    l.insert(8);
    l.insert(2);

    int sl= 0;
    for (list_entry* p= l.head.get(); p != nullptr; p= p->next.get())
	sl+= p->value;

    cout << "Die Summe ist " << sl << endl;

    int array[]= {3, 8, 2};
    int sa= 0;
    for (int i= 0, e= sizeof(array) / sizeof(array[0]); i < e; ++i)
	sa+= array[i]; 
    cout << "Die Summe ist " << sa << endl;
    
    cout << "Summe Liste = " << sum(begin(l), end(l), 0) << endl;
    cout << "Summe Array = " << sum(begin(array), end(array), 0) << endl;

    cout << "Der Array ist ";
    copy(begin(array), end(array), ostream_iterator<int>(cout, ", ")); cout << endl;

    
    return 0;
}
  
 
