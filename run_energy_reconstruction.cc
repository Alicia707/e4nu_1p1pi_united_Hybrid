#include "energy_reconstruction.C"
#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
  if( argc < 4 )
  {
    cout<<"Please specify the target (3He, 56Fe, C12, 4He), the beam energy (2261 or 4461), and the Filter Selection (filtered/unfiltered)"<<endl;
    cout<<"================= Usage ==============="<<endl;
    cout<<"./run_energy_reconstruction.cc target beam_energy filter_selection"<<endl;
    exit(1);
  }
  // Inputs from the command line//
  std::string target = argv[1];
  std::string beam_en = argv[2];
  //Input for filter selection b/n genie filtered data or unfiltered data 9.16.20 - AM//
  std::string filter_selection = argv[3];

  energy_reconstruction t(target, beam_en, filter_selection);
  t.Loop();

  return 0;
}
