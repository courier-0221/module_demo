#include <iostream>
#include <string.h>
using namespace std;

class mystring {
private:
    char* _data;
    int _len;

public:
    mystring() : _data(nullptr), _len(0) {}
    mystring(char* str) {
        if (str) {
            _len = strlen(str) + 1;
            _data = new char[_len];
            strcpy(_data, str);
        }
    }
    ~mystring() {
        if (_data) {
            delete [] _data;
            _data = nullptr;
        }
        _len = 0;
    }

    mystring(const mystring & obj) {
        if (obj._len > 0 && obj._data) {
            _len = obj._len;
            _data = new char[_len];
            strcpy(_data, obj._data);
        }
    }

    mystring& operator=(const mystring & obj) {
        if (obj._len > 0 && obj._data) {
            _len = obj._len;
            _data = new char[_len];
            strcpy(_data, obj._data);
        }
        return *this;
    }

    mystring(mystring && obj) {
        _len = obj._len;
        _data = obj._data;
        obj._data = nullptr;
        obj._len = 0;
    }

    mystring& operator=(mystring && obj) {
        _len = obj._len;
        _data = obj._data;
        obj._data = nullptr;
        obj._len = 0;
        return *this;
    }
};


int main() {
    return 0;
}