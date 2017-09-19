#include <iostream>

#include "cekla.h"

using namespace std;

int convert(const int S, const int A)
{
    if (S == 0)
    {
        return 0;
    }
    else
    {
        return (S % A + 10 * convert(S / A, A));
    }
}

list convertx(const list l, const int base)
{
    if (l.head() == 0)
    {
        return cons(0, nil);
    }
    else
    {
        write(l.head());
        write(l);
        cout<<endl;
        return cons(l.head(), convertx(
                             cons(l.head()/base,
                             cons(
                                  l.head()%base, l.tail()
                                  ))
                             , base)
                    );
    }
}

/*int atrendezett(const int S, const int A)
{
    return convertx(cons(S, nil), A);
}*/

int main()
{
    //cout<<atrendezett(100, 2);
    //write(convertx(cons(100, nil), 2));
    convertx(cons(100, nil), 2);
    return 0;
}

