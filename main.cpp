#include <iostream>

#include "cekla.h"

using namespace std;

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

//from slide
int sum(const list L) { // az L lista elemeinek összege
if (L == nil) return 0; // ha L üres, akkor 0,
else { // különben hd(L) + sum(tl(L))
const int X = hd(L); // segédváltozókat használhatunk,
const list T = tl(L); // de csak konstansokat
return X + sum(T); // rekurzió (ez nem jobbrekurzió!)
} // Fejtörõ: csak akkor lehet jobbrekurzióvá alakítani, ha
}

int power(int x, int n)
{
    if (n == 0) return 1;

    return x * power(x, n-1);
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

list atrendezo(const list konvertalt)
{
    return atrendezox(nrev(konvertalt), nil, nil);
}

int kiszamolox(const list revatrendezett, const int base, const int helyiertek)
{
    if(length(revatrendezett)==0) return 0;
    if(helyiertek==0&&revatrendezett.head()==0) return kiszamolox(revatrendezett.tail(), base, helyiertek+1);
    return power(revatrendezett.head()*base, helyiertek)+kiszamolox(revatrendezett.tail(), base, helyiertek+1);
}

int kiszamolo(const list atrendezett, const int base)
{
    return kiszamolox(nrev(atrendezett), base, 1)/base;
}

int atrendezett(const int S, const int A)
{
    write(convertx(cons(S, nil), A).tail());
    write(atrendezo(convertx(cons(S, nil), A).tail()));
    return kiszamolo(atrendezo(convertx(cons(S, nil), A).tail()), A);
}

int main()
{
    //cout<<atrendezett(100, 2);

    //convertx(cons(100, nil), 2);

    /*write(kiszamolo(atrendezo(
                    convertx(cons(100, nil), 2).tail())
          , 2));*/
    write(atrendezett(0, 2));

    return 0;
}

