#include <iostream>

using namespace std;

namespace le {

    struct dummy{};
    struct alignas(64) dummy64 {};
    struct alignas(dummy64) another_dummy {};

    struct alignas(32)  alignas(16*alignof(int))   last_dummy 
    {
	int i alignas(64);
    };

    struct  alignas(8)  gepackt
    {

	int i, j;
	double d; 
	char c;
    } __attribute__((__packed__));

    // static_assert(sizeof(gepackt) % 4 == 0,
    // 		  "Groesse von gepackt muss Vielfaches von 32 sein!");
    
    template <typename ...T>
    struct alignas((4*alignof(T))...) variadic_dummy {};
}

int main (int argc, char* argv[]) 
{
    using namespace le;
    cout << "sizeof(gepackt) = " << sizeof(gepackt) << endl;
    cout << "alignof(gepackt) = " << alignof(gepackt) << endl;   

    cout << "Alignment von int ist " << alignof(int) << endl;
    cout << "Alignment von dummy ist " << alignof(dummy) << endl;
    cout << "Alignment von dummy64 ist " << alignof(dummy64) << endl;
    cout << "Alignment von another_dummy ist " << alignof(another_dummy) << endl;
    cout << "Alignment von last_dummy ist " << alignof(last_dummy) << endl;
    cout << "Alignment ist " << alignof(variadic_dummy<int, dummy64>) << endl;

    // Ab C++17
    dummy64* p = new(align_val_t{4096}) dummy64;
    cout << hex << "p = " << p << endl;
    
    return 0;
}
  
 
