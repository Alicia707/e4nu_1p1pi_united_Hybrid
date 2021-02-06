#include <TF1.h>
#include <TH1D.h>
#include <TH2D.h>
#include <TFile.h>
#include <TGraph.h>
#include <TGraphErrors.h>
#include <TCanvas.h>
#include <TLatex.h>
#include <TStyle.h>
#include <TLine.h>
#include <TGaxis.h>

using namespace std;

void  test()
{
  TFile * whatever; //Creating TFile pointer TFile -> used to read and write files
  whatever = new TFile("C12_2261.root"); //Declaring whatever TFile pointer
  TH1F * histogram; //Creating 1-dimensional histogram (F->float)
  histogram = (TH1F*)whatever->Get("sub_cal_all_pimi"); //Declaring 1-dimensional histogram

  TH2F *mult_1p = (TH2F*)whatever->Get("h2_phot_pi_1p");

//new stuff
  histogram->SetLineColor(6); //1 ->black, 2->red, 3->green, 4->blue, 5->yellow, 6-> purple/pink
  histogram->SetMarkerColor(1); //changes color of center of marker
  histogram->SetAxisRange(0,2,"X"); //changes range of x or y axis
  gStyle->SetOptStat(0);//removes stat box

  histogram->GetXaxis()->SetTitle("TestX");
  histogram->GetXaxis()->SetTitleSize(.05);//Changes x-axis label size
  histogram->GetXaxis()->SetLabelSize(.05); //Changes unit size

  histogram->GetYaxis()->SetTitle("TestY");
  histogram->GetYaxis()->SetTitleSize(.05);
  histogram->GetYaxis()->SetTitleOffset(1);//Offsets up
//end new stuff

  TCanvas * canvas = new TCanvas("canvas","",500,300); //declaring new canvas with dimensions: 500 X 300 px
  mult_1p->Draw("COL TEXT"); //draws the histogram HIST-> normal histogram (1D), COL TEXT -> is a colored 2D HIST



}
