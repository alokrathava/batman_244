#ifndef SDDS_BASKET_H
#define SDDS_BASKET_H

#include <iostream>

namespace sdds {

    struct Fruit {
        char m_name[30 + 1];
        double m_qty;
    };

    class Basket {

        Fruit *m_fruits;
        int m_size;
        double m_price;

    public:

        Basket();

        Basket(Fruit *fruits, int size, double price);

        Basket(const Basket &src);

        Basket &operator=(const Basket &src);

        ~Basket();

        void setPrice(double price);

        operator bool() const;

        Basket &operator+=(const Fruit &fruit);

        friend std::ostream &operator<<(std::ostream &os, const Basket &basket);

    };

} // sdds

#endif //SDDS_BASKET_H
