
    auto sum(First f, Rest ...r)
    {
	// potentiell verschiedene Typen in return -> Fehler bei auto
	if (f == 0)
	    return sum(r...);
	else
	    return f + sum(r...);
    }
#endif

    // C++17: Faltung

    // wie sum: rechts-assoziativ, ohne Einheitselement
    template <typename ...Args>
    auto sumr(Args ...a)
    {
	return (a + ...);
    }
    
    // rechts-assoziativ, mit Einheitselement
    template <typename ...Args>
    auto sumr0(Args ...a)
    {
	return (a + ... + 0);
    }
    
    // links-assoziativ, ohne Einheitselement
    template <typename ...Args>
    auto suml(Args ...a)
    {
	return (... + a);
    }
    
    // links-assoziativ, mit Einheitselement
    template <typename ...Args>
    auto suml0(Args ...a)
    {
	return (0 + ... + a);
    }
}

int main (int argc, char* argv[]) 
{
    using namespace sn;

    cout << "sum(9u, -2.6) = " << sum(9u, -2.6) << endl;
    cout << "sum(3.7f, 9u, -2.6) = " << sum(3.7f, 9u, -2.6) << endl;
    cout << "sum(-7, 3.7f, 9u, -2.6) = " << sum(-7, 3.7f, 9u, -2.6) << endl;
    cout << "sum(-7, 3.7f, 9u, -42.6) = " << sum(-7, 3.7f, 9u, -42.6) << endl;

    // cout << "sum(9u, -42) = " << sum(9u, -42) << endl;
    
    cout << "sumr(-7, 3.7f, 9u, -42.6) = " << sumr(-7, 3.7f, 9u, -42.6) << endl;
    cout << "sumr0(-7, 3.7f, 9u, -42.6) = " << sumr0(-7, 3.7f, 9u, -42.6) << endl;
    cout << "sumr0() = " << sumr0() << endl;

    cout << "suml(-7, 3.7f, 9u, -42.6) = " << suml(-7, 3.7f, 9u, -42.6) << endl;
    cout << "suml0(-7, 3.7f, 9u, -42.6) = " << suml0(-7, 3.7f, 9u, -42.6) << endl;
    cout << "suml0() = " << suml0() << endl;

    cout << "sumr(1.0, -1.0, 1e-20) = " << sumr(1.0, -1.0, 1e-20) << endl;
    cout << "suml(1.0, -1.0, 1e-20) = " << suml(1.0, -1.0, 1e-20) << endl;

    return 0;
}
  
 
