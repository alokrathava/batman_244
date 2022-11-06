#include <iomanip>
#include "Basket.h"

namespace sdds {

    Basket::Basket() {
        this->m_fruits = nullptr;
        this->m_size = 0;
        this->m_price = 0.0;
    }

    Basket::Basket(Fruit *fruits, int size, double price) {
        if (fruits != nullptr && size > 0 && price > 0) {
            this->m_fruits = new Fruit[size];
            for (int i = 0; i < size; i++) {
                this->m_fruits[i] = fruits[i];
            }
            this->m_size = size;
            this->m_price = price;
        } else {
            this->m_fruits = nullptr;
            this->m_size = 0;
            this->m_price = 0.0;
        }
    }

    Basket::Basket(const Basket &src) {
        if (src.m_fruits != nullptr) {
            this->m_fruits = new Fruit[src.m_size];
            for (int i = 0; i < src.m_size; i++) {
                this->m_fruits[i] = src.m_fruits[i];
            }
            this->m_size = src.m_size;
            this->m_price = src.m_price;
        } else {
            this->m_fruits = nullptr;
            this->m_size = 0;
            this->m_price = 0.0;
        }
    }

    Basket &Basket::operator=(const Basket &src) {
        if (this != &src) {
            if (src.m_fruits != nullptr) {
                this->m_fruits = new Fruit[src.m_size];
                for (int i = 0; i < src.m_size; i++) {
                    this->m_fruits[i] = src.m_fruits[i];
                }
                this->m_size = src.m_size;
                this->m_price = src.m_price;
            } else {
                delete[] this->m_fruits;
                this->m_fruits = nullptr;
                this->m_size = 0;
                this->m_price = 0.0;
            }
        }
        return *this;
    }

    Basket::~Basket() {
        delete[] this->m_fruits; // delete the array of fruits
        this->m_fruits = nullptr;
    }

    void Basket::setPrice(double price) {
        this->m_price = price;
    }

    Basket::operator bool() const {
        return this->m_size > 0;
    }

    Basket &Basket::operator+=(const Fruit &fruit) {
        Fruit *temp = new Fruit[this->m_size + 1];
        for (int i = 0; i < this->m_size; i++) {
            temp[i] = this->m_fruits[i];
        }
        temp[this->m_size] = fruit;
        delete[] this->m_fruits;
//        this->m_fruits = nullptr;
        this->m_fruits = temp;
        this->m_size++;
        return *this;
    }

    std::ostream &operator<<(std::ostream &os, const Basket &basket) {
        if (basket.m_size == 0) {
            os << "The basket is empty!" << std::endl;
        } else {
            os << "Basket Content:" << std::endl;
            for (int i = 0; i < basket.m_size; i++) {
                os << std::setw(10) << std::right << basket.m_fruits[i].m_name << ": " << std::setw(4) << std::fixed
                   << std::setprecision(2) << basket.m_fruits[i].m_qty << "kg" << std::endl;
            }
            os << "Price: " << std::setw(4) << std::fixed << std::setprecision(2) << basket.m_price << std::endl;
        }
        return os;
    }
} // sdds
