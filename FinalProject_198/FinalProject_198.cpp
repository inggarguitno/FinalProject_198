#include <iostream>
using namespace std;

class bidangDatar {
private:
    int x, y;

public:
    bidangDatar() {
        x = 0;
        y = 0;
    }

    virtual void input() {}
    virtual float Luas() { return 0; }
    virtual float Keliling() { return 0; }
    virtual void cekUkuran() {}

    void setX(int a) {
        x = a;
    }

    int getX() {
        return x;
    }

    void setY(int b) {
        y = b;
    }

    int getY() {
        return y;
    }
};

class Lingkaran : public bidangDatar {
public:
    void input() {
        int r;
        cout << "Masukkan jejari : ";
        cin >> r;
        setX(r);
    }

    float Luas() {
        int r = getX();
        return 3.14 * r * r;
    }

    float Keliling() {
        int r = getX();
        return 2 * 3.14 * r;
    }

    void cekUkuran() {
        float keliling = Keliling();
        if (keliling > 40)
            cout << "Ukuran lingkaran adalah Besar" << endl;
        else if (keliling < 20)
            cout << "Ukuran lingkaran adalah Sedang" << endl;
        else if (keliling < 10)
            cout << "Ukuran lingkaran adalah Kecil" << endl;
    }
};

class Persegipanjang : public bidangDatar {
public:
    void input() {
        int p, l;
        cout << "Masukkan panjang : ";
        cin >> p;
        setX(p);
        cout << "Masukkan lebar : ";
        cin >> l;
        setY(l);
    }

    float Luas() {
        int p = getX();
        int l = getY();
        return p * l;
    }

    float Keliling() {
        int p = getX();
        int l = getY();
        return 2 * (p + l);
    }

    void cekUkuran() {
        float keliling = Keliling();
        if (keliling > 40)
            cout << "Ukuran Persegi Panjang adalah Besar" << endl;
        else if (keliling < 20)
            cout << "Ukuran Persegi Panjang adalah Sedang" << endl;
        else if (keliling < 10)
            cout << "Ukuran Persegi Panjang adalah Kecil" << endl;
    }
};

int main() {
    int pilihan;
    bidangDatar* obj;

    while (true) {
        cout << "Pertama di Run Setelah jejari diinput Setelah sisi diinput" << endl;
        cout << "1. Lingkaran" << endl;
        cout << "2. Persegi Panjang" << endl;
        cout << "3. Exit" << endl;
        cout << "Masukkan pilihan : ";
        cin >> pilihan;

        if (pilihan == 1) {
            obj = new Lingkaran();
            cout << "Lingkaran dibuat" << endl;
            obj->input();
            cout << "Luas Lingkaran = " << obj->Luas() << endl;
            cout << "Keliling Lingkaran = " << obj->Keliling() << endl;
            obj->cekUkuran();
        }
        else if (pilihan == 2) {
            obj = new Persegipanjang();
            cout << "Persegi Panjang dibuat" << endl;
            obj->input();
            cout << "Luas Persegi Panjang = " << obj->Luas() << endl;
            cout << "Keliling Persegi Panjang = " << obj->Keliling() << endl;
            obj->cekUkuran();
        }
        else if (pilihan == 3) {
            break;
        }
        else {
            cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }

        delete obj;
        obj = nullptr;
    }

    return 0;
}

