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
//from slide
list append(const list L1, const list L2)
{
    if (L1 == nil) return L2;
    return cons(hd(L1), append(tl(L1), L2));
}

//from slide
list nrev(const list L) {
    if (L == nil) return nil;
    return append(nrev(tl(L)), cons(hd(L), nil));
}

//returns a list with the head 0
list convertx(const list l, const int base)
{
    if (l.head() == 0)
    {
        return l;
    }
    return convertx(
                             cons(l.head()/base,
                             cons(
                                  l.head()%base, l.tail()
                                  ))
                             , base);
}

int length(const list l)
{
    if(l==nil) return 0;
    return 1+length(l.tail());
}

list atrendezox(const list l, const list plan, const list ps)
{
    if(length(l)==0) return append(plan, ps);
    if(length(l)%2==1) return atrendezox(l.tail(), cons(l.head(), plan), ps);
    return atrendezox(l.tail(), plan, cons(l.head(), ps));
}

list atrendezo(const list l)
{
    return atrendezox(nrev(l), nil, nil);
}

/*int atrendezett(const int S, const int A)
{
    return convertx(cons(S, nil), A);
}*/

int main()
{
    //cout<<atrendezett(100, 2);
    write(atrendezo(
                    convertx(cons(100, nil), 2).tail())
          );
    //convertx(cons(100, nil), 2);
    return 0;
}

