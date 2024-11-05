
#include <TF1.h>
#include <TFile.h>
#include <TTree.h>
#include <TRandom3.h>
#include "momentum.h"

void write(Int_t nEvents){

    // Initialize an object
    momentum mymomentum;

    TF1 *f1 = new TF1("sinFunc", "sin(x)", 0, 100);
    TFile *rootfile = new TFile("tree_file.root", "recreate");

    // Create your TTree here
    TTree *tree_val = new TTree("momvals", "tree");
    TTree *tree_momx = new TTree("momx", "tree");
    TTree *tree_momy = new TTree("momy", "tree");
    TTree *tree_momz = new TTree("momz", "tree");


    // With branches
    tree_val->Branch("momentum_value", &mymomentum.momentum_val, "momentum_value/D");
    tree_momx->Branch("momentum_x", &mymomentum.px, "momentum_x/D");
    tree_momy->Branch("momentum_y", &mymomentum.py, "momentum_y/D");
    tree_momz->Branch("momentum_z", &mymomentum.pz, "momentum_z/D");


    // For-loop here
    for (Int_t i{0}; i<nEvents; i++){

        mymomentum.px = gRandom->Gaus(0,5);
        mymomentum.py = gRandom->Gaus(0,5);
        mymomentum.pz = gRandom->Gaus(0,5);

        mymomentum.momentum_magnitude(mymomentum.px, mymomentum.py, mymomentum.pz);
        
        tree_val->Fill();
        tree_momx->Fill();
        tree_momy->Fill();
        tree_momz->Fill();
    } 
    
    // save the tree/file
    rootfile->Write();

    // Delete the tree to save memory
    delete tree_val;
    delete tree_momx;
    delete tree_momy;
    delete tree_momz;

    // Checking that the code runs through
    std::cout << "End of write.cxx" << std::endl;
}