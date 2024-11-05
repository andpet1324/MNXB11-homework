#include <TFile.h>
#include <TH1.h>
#include <TH2.h>
#include <TF1.h>
#include <TTree.h>
#include <TCanvas.h>
#include <iostream>
#include <TRandom3.h>
#include "momentum.h"

void read(){
    // initialize your object

    momentum mymomentum;

    // open your file
    auto file = TFile::Open("tree_file.root");
    // get your tree
    TTree *tree_val = static_cast<TTree*>(file->Get("momvals"));
    TTree *tree_momx = static_cast<TTree*>(file->Get("momx"));
    TTree *tree_momy = static_cast<TTree*>(file->Get("momy"));
    TTree *tree_momz = static_cast<TTree*>(file->Get("momz"));

    tree_val->SetBranchAddress("momentum_value", &mymomentum.momentum_val);
    tree_momx->SetBranchAddress("momentum_x", &mymomentum.px);
    tree_momy->SetBranchAddress("momentum_y", &mymomentum.py);
    tree_momz->SetBranchAddress("momentum_z", &mymomentum.pz);
    Int_t N = tree_momx->GetEntries();

    std::cout << "do we get here?";
    TH2F *h1 = new TH2F("h1", "2D Histogram;X-axis;Y-axis", 50, 0.0, 10.0, 50, -5.0, 5.0);
    for (Int_t i{0}; i<N; i++){ // loop over the whole tree
        tree_momx->GetEntry(i);
        tree_momy->GetEntry(i);
        h1->Fill(mymomentum.px, mymomentum.py);
    }

    TCanvas *canvas1 = new TCanvas("canvas1", "2DPlot Canvas", 800, 600);

    h1->Draw("COLZ");

    canvas1->Update();
    canvas1->SaveAs("2D_plot.png");

    TH2F *h2 = new TH2F("h2", "Scatter plot;(px*py)-axis;pz-axis", 50, 0.0, 10.0, 50, -5.0, 5.0);

    for (Int_t i{0}; i<N; i++){ // loop over the whole tree
        tree_val->GetEntry(i);
        Double_t mom = mymomentum.momentum_val;
        if (mom > 10){
        tree_momx->GetEntry(i);
        tree_momy->GetEntry(i);
        tree_momz->GetEntry(i);
        h2->Fill((mymomentum.px*mymomentum.py), mymomentum.pz);
        }
    }
    TCanvas *canvas2 = new TCanvas("canvas2", "Scatter Plot Canvas", 800, 600);

    h2->Draw("COLZ");

    canvas2->Update();
    canvas2->SaveAs("scatter_plot.png");
    

}