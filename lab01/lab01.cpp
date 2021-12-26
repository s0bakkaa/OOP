#include <iostream>

typedef unsigned int ui;
typedef unsigned long long ll;

class BitString {
public:
    BitString() = default;

    BitString(BitString& cp) = default;

    BitString(ui fir, ll sec) : first(fir), second(sec) {};

    BitString operator&(const BitString& right) const {
        return { this->first & right.first, this->second & right.second };
    }

    BitString operator|(const BitString& right) const {
        return { this->first | right.first, this->second | right.second };
    }

    BitString operator^(const BitString& right) const {
        return { this->first ^ right.first, this->second ^ right.second };
    }

    BitString operator!() const {
        return { !this->first, !this->second };
    }

    BitString operator<<(int x) const {
        if (x >= 64) {
            return { second << (x - 64), 0 };
        }
        return { (first << x) | (second >> (64 - x)), second << x };
    }

    BitString operator>>(int x) const {
        if (x >= 64) {
            return { 0, first >> (x - 64) };
        }
        return { first >> x, (first << (64 - x)) | (second << x) };
    }

    int num_single_bits() {
        int cnt = 0;
        BitString cp(*this);
        for (; cp.first; cp.first << 1, cp.second << 1) {
            cnt += (int)cp.first & 1;
            cnt += (int)cp.second & 1;
        }
        return cnt;
    }

    bool operator<(BitString& rhs) {
        return this->num_single_bits() < rhs.num_single_bits();
    }
    bool operator>(BitString& rhs) {
        return this->num_single_bits() > rhs.num_single_bits();
    }
    bool substring(BitString& substr) const {
        BitString cp = *this & substr;
        return (cp.first != 0) && (cp.second != 0);
    }
    ui first_getter() {
        return this->first;
    }
    ll second_getter() {
        return this->second;
    }
    void first_setter(ui x) {
        first = x;
    }
    void second_setter(ll x) {
        second = x;
    }
private:
    ui first;
    ll second;
};

int main() {
    BitString a, b;
    std::cout << "Enter first 96-BitString:" << std::endl << "> ";
    ui first; 
    ll second;
    std::cin >> first >> second;
    a.first_setter(first); 
    a.second_setter(second);
    std::cout << "Enter second 96-BitString:" << std::endl << "> ";
    std::cin >> first >> second;
    b.first_setter(first); 
    b.second_setter(second);
    BitString ans = a & b;
    std::cout << "A & B:" << ans.first_getter() << "." << ans.second_getter();
    return 0;
}