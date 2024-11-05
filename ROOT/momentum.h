#ifndef __MOMENTUM_H__
#define __MOMENTUM_H__
// some new code in here soon

#include <TObject.h>

class momentum : public TObject {
    public:
        momentum (); // default constructor
        momentum (Int_t variable); // some other constructor
        virtual ~momentum (); // destructor

        Double_t px;
        Double_t py;
        Double_t pz;
        Double_t momentum_val;
        std::vector<Double_t> moms;

        Double_t momentum_magnitude(Double_t px, Double_t py, Double_t pz);
        std::vector<Double_t> set_moms(Double_t px, Double_t py, Double_t pz);

    private:
        // some private members

    ClassDef(momentum, 1); // momentum
};

#endif //__MOMENTUM_H__

