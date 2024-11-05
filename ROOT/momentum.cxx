#include <iostream>
#include "momentum.h"
#include <TH1.h>
#include <TF1.h>
#include <TRandom3.h>

ClassImp(momentum);

Double_t momentum::momentum_magnitude(Double_t px, Double_t py, Double_t pz) 
{ 
    Double_t mom = std::sqrt(std::pow(px,2) + std::pow(py,2) + std::pow(pz,2));
    momentum::momentum_val = mom;
    return 1;
}

std::vector<Double_t> momentum::set_moms(Double_t px, Double_t py, Double_t pz) {
    std::vector<Double_t> mom = {px, py, pz};
    momentum::moms = mom;
    return mom;
}

// default constructor - ROOT needs the default one where everything is set to 0
momentum::momentum()
{
}
// another constructor
momentum::momentum(Int_t variable)
{
    Double_t px = gRandom->Gaus(0,.02);
    Double_t py = gRandom->Gaus(0,.02);
    Double_t pz = gRandom->Gaus(0,.02);
    std::vector<Double_t> moms{px, py, pz};
    Double_t momentum_val;

}

// destructor
momentum::~momentum()
{
}

