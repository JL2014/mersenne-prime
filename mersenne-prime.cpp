// g++ -o mersenne-prime mersenne-prime.cpp -L/usr/local/lib -lflint
// LD_LIBRARY_PATH=/usr/local/lib ./mersenne-prime

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>
#include <flint/flint.h>
#include <flint/fmpz.h>

using namespace std;

int main() {
    FILE *fp;
    ostringstream filename; 
    vector<string> mp { 
        "2", "3", "5", "7", "13", "17", "19", "31", "61", "89", "107", "127", 
        "521", "607", "1279", "2203", "2281", "3217", "4253", "4423", "9689",
        "9941", "11213", "19937", "21701", "23209", "44497", "86243", "110503",
        "132049", "216091", "756839", "859433", "1257787", "1398269", "2976221",
        "3021377", "6972593", "13466917", "20996011", "24036583", "25964951", 
        "30402457", "32582657", "37156667", "42643801", "43112609", "57885161",
        "74207281", "77232917", "82589933"
    };
    fmpz_t n;

    cout << "FLINT version : " << flint_version << endl;
    fmpz_init(n);
    for(int i=0; i<mp.size(); ++i) {
        fmpz_one(n);
        fmpz_mul_2exp(n, n, stoul(mp[i], nullptr, 0));
        fmpz_sub_ui(n, n, 1);

        filename.str("");
        filename << "M" << setfill('0') << setw(9) << mp[i];
        fp = fopen(filename.str().c_str(), "w");
        fmpz_fprint(fp, n);
        fclose(fp);
    }
    fmpz_clear(n);

    return EXIT_SUCCESS;
}
