#include <iostream>
#include <list>

using namespace std;

list<pair <int, int> >::iterator it, he;

void print(list<pair<int, int> > l)
{
    for (it = l.begin(); it != l.end(); it++)
    {
        he = it;
        he++;
        if ((*it).second != 0)
        {
            if (((*it).second != 1) && ((*it).first != 0) && ((*it).first != 1))
                cout << (*it).second << "x^" << (*it).first;
            if (((*it).second != 1) && ((*it).first == 1))
                cout << (*it).second << "x";
            if (((*it).second != 1) && ((*it).first == 0))
                cout << (*it).second;
            if (((*it).second == 1) && ((*it).first != 0) && ((*it).first != 1))
                cout << "x^" << (*it).first;
            if (((*it).second == 1) && ((*it).first == 1))
                cout << "x";
            if (((*it).second == 1) && ((*it).first == 0))
                cout << "1";

            if ((*it).first > 2)
                cout << " + ";
        }
    }
}

pair<int, int> operator *(pair <int, int> a, int n)
{
    a.second *= n;
    return a;
}

list<pair<int, int> > operator *(list<pair<int, int> > l, int n)
{
    for (it = l.begin(); it != l.end(); it++)
        *it = (*it) * n  ;
    return l;
}

list<pair<int, int> > operator *(list<pair<int, int> > l, pair<int, int> p)
{
    for (it = l.begin(); it != l.end(); it++)
        (*it).first = (*it).first + p.first;
    l = l * p.second;
    return l;
}

list<pair<int, int> > operator +(list<pair<int, int> > p, list<pair<int, int> > s)
{
    list<pair<int, int> > t;
    it = p.begin();
    he = s.begin();
    while ((it != p.end()) && (he != s.end()))
    {
        if ((*it).first > (*he).first)
        {
            t.push_back(*it);
            it++;
        }
        if ((*it).first < (*he).first)
        {
            t.push_back(*he);
            he++;
        }
        if ((*it).first == (*he).first)
        {
            (*it).second = (*it).second + (*he).second;
            t.push_back(*it);
            it++;
            he++;
        }
    }
    while (it != p.end())
    {
        t.push_back(*it);
        it++;
    }
    while (he != s.end())
    {
        t.push_back(*he);
        he++;
    }
    return t;
}

int main()
{
    int j;
    list<pair<int, int> > D[11];
    cout << "Padovan polynomial number: ";

    pair<int, int> a;
    a.first = 0;
    a.second = 1;
    D[0].push_front(a);
    a.first = 0;
    a.second = 0;
    D[1].push_front(a);
    a.first = 1;
    a.second = 1;
    D[2].push_front(a);

    for (j = 3; j <= 10; j++)
        D[j] = D[j - 2] * a + D[j - 3];
    cin >> j;
    cout << endl;
    if (j != 1)
        print(D[j]);
    else
        cout << "0";
    cout << endl;
    return 0;
}
