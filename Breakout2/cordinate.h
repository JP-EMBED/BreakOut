#ifndef CORDINATE_H
#define CORDINATE_H


class Cordinate
{
    public:
        Cordinate(int x =0, int y=0);
        Cordinate(const Cordinate& copy);
        ~Cordinate();
        Cordinate& operator=(const Cordinate& rhs);
        int m_x;
        int m_y;
};

#endif
